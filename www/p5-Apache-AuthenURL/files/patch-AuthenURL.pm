--- AuthenURL.pm	Tue Nov  4 23:47:14 2003
+++ AuthenURL.pm	Sat Oct 23 14:58:56 2004
@@ -1,14 +1,31 @@
 # $Id: AuthenURL.pm,v 0.10 2003/11/04 15:47:13 jdg117 Exp $
 package Apache::AuthenURL;
+$Apache::AuthenURL::VERSION = '0.9';
+
 use strict;
-use Apache();
-use Apache::Constants qw(OK SERVER_ERROR AUTH_REQUIRED);
 use LWP::UserAgent;
-use vars qw($VERSION);
 
-my $prefix = "Apache::AuthenURL";
+BEGIN { local $@; eval { require Apache2; } }
 
-$VERSION = '0.9';
+use mod_perl;
+use constant MP2 => ($mod_perl::VERSION >= 1.99);
+use constant OK => 0;
+use constant SERVER_ERROR => 500;
+use constant AUTH_REQUIRED => 401;
+
+if (MP2) { 
+    require Apache::Access;
+    require Apache::Connection;
+    require Apache::Log;
+    require Apache::RequestRec;
+    require Apache::RequestUtil;
+}
+else {
+    require Apache::ModuleConfig;
+    require Apache::Constants;
+}
+
+my $prefix = "Apache::AuthenURL";
 
 my(%Config) = (
     'AuthenURL_url'		=> '',
@@ -31,20 +48,23 @@
  
 sub check {
     my($r, $attr) = @_;
+    return undef unless defined($r);
+
     my($res, $sent_pwd);
     ($res, $sent_pwd) = $r->get_basic_auth_pw;
     return $res if $res; #decline if not Basic
 
-    my $user = $r->connection->user;
-    my $passwd;
+    my $user = (MP2) ? $r->user : $r->connection->user;
+    my $uri = $r->uri;
+    my $method = $r->method;
 
     unless ( $attr->{method} ) {
-        $r->warn("$prefix is missing the METHOD (defaulting to GET) for URI: " . $r->uri);
+        $r->warn("$prefix is missing the METHOD (defaulting to GET) for URI: " . $uri);
         $attr->{method} = "GET";
     }
 
     unless ( $attr->{url} ) {
-        $r->log_reason("$prefix is missing the URL", $r->uri);
+        $r->log_error("$prefix is missing the URL for $uri");
         return SERVER_ERROR;
     }
 
@@ -55,14 +75,32 @@
         $lwp_ua->use_alarm(0);
         my $lwp_req = new HTTP::Request $attr->{method} => $attr->{url};
         unless( defined $lwp_req ) {
-            $r->log_reason("LWP failed to use METHOD: " . $attr->{method} . " to connect to URL: ".$attr->{url}, $r->uri);
+            $r->log_error("LWP failed to use METHOD: " . $attr->{method} . " to connect to URL: ".$attr->{url});
             return SERVER_ERROR;
         }
         
         $lwp_req->authorization_basic($user, $sent_pwd);
+
+        if ($attr->{method} eq 'POST') {
+            $lwp_req->header('Content-Type' => 'application/x-www-form-urlencoded');
+
+            require URI;
+            my $url = URI->new('http:');
+            $url->query_form(
+                user => $user,
+                password => $sent_pwd,
+                uri => $uri,
+                method => $method,
+            );
+
+            my $content = $url->query;
+            $lwp_req->header('Content-Length' => length($content));
+            $lwp_req->content($content);
+        }
+
         my $lwp_res = $lwp_ua->request($lwp_req);
         unless( $lwp_res->is_success ) {
-            $r->log_reason("LWP user $user: " . $attr->{url} . $lwp_res->status_line, $r->uri);
+            $r->log_error("LWP user $user: $attr->{url} fails with ".$lwp_res->status_line)."for $uri";
             $r->note_basic_auth_failure;
             return AUTH_REQUIRED;
         }
@@ -83,7 +121,7 @@
  #in .htaccess
  AuthName MyHTTPAuth
  AuthType Basic
- PerlAuthenHandler Apache::AuthenCache Apache::AuthenURL::handler Apache::AuthenCache::manage_cache
+ PerlAuthenHandler Apache::AuthenCache Apache::AuthenURL Apache::AuthenCache::manage_cache
 
  PerlSetVar AuthenURL_method HEAD		# a valid LWP method
  PerlSetVar AuthenURL_url https://somehost
@@ -99,6 +137,12 @@
 I wrote this module to work around the lack of DCE support for Solaris x86.
 DCE authentication in my application is handled using Gradient's DCE
 plug-in for Netscape Enterprise Server. The request is encrypted using SSL.
+
+=head1 NOTES
+
+If C<AuthenURL_method> is set to C<POST>, the request is sent with three
+parameters: C<user>, C<password> and C<uri>, in addition to the basic
+authentication headers common to all methods.
 
 =head1 ACKNOWLEDGEMENTS
 
