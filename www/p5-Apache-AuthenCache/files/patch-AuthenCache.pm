--- AuthenCache.pm	Tue Jun 24 02:44:48 2003
+++ AuthenCache.pm	Sat Oct 23 15:20:00 2004
@@ -263,8 +263,26 @@
 
 # Required libraries
 use strict;
+BEGIN { local $@; eval { require Apache2; } }
 use mod_perl ();
-use Apache::Constants qw(OK AUTH_REQUIRED DECLINED DONE);
+use constant MP2 => $mod_perl::VERSION < 1.99 ? 0 : 1;
+BEGIN { 
+  if (MP2) {
+    require Apache2;
+    require Apache::Access;
+    require Apache::RequestRec;
+    require Apache::RequestUtil;
+    require Apache::RequestIO;
+    require Apache::ServerUtil;
+    require Apache::Const;
+    Apache::Const->import(-compile => qw(OK AUTH_REQUIRED DECLINED DONE));
+    require APR::Table;
+  } else {
+    require Apache;
+    require Apache::Constants;
+    Apache::Constants->import(qw(OK AUTH_REQUIRED DECLINED DONE));
+  }
+}
 use Apache::Log ();
 use Cache::FileCache;
 use Time::Object;
@@ -294,14 +312,21 @@
   my $auth_name = $r->auth_name;
 
   # Clear for paranoid security precautions
-  $r->notes('AuthenCache' => 'miss');
+  my %notes = ('AuthenCache' => 'miss');
+  if (MP2) {
+    my $table = APR::Table::make($r->pool, 1);
+    $table->set(%notes);
+    $r->notes($table);
+  } else {
+    $r->notes(%notes);
+  }
 
   # Get response and password
   my($res, $passwd_sent) = $r->get_basic_auth_pw;
   return $res if $res; # e.g. HTTP_UNAUTHORIZED
 
   # Get username
-  my $user_sent = $r->connection->user;
+  my $user_sent = MP2 ? $r->user : $r->connection->user;
   # If the user left the username field blank, we must catch it and DECLINE
   # for the downstream handler
   unless ($user_sent) {
@@ -373,7 +398,14 @@
     # } else {
     $r->log->debug("handler: user in cache and password matches; ",
 		   "returning OK and setting notes");
-    $r->notes('AuthenCache' => 'hit');
+    %notes = ('AuthenCache' => 'hit');
+    if (MP2) {
+      my $table = APR::Table::make($r->pool, 1);
+      $table->set(%notes);
+      $r->notes($table);
+    } else {
+      $r->notes(%notes);
+    }
     #}
     return OK;
   } # End if()
@@ -406,7 +438,7 @@
     # The below test is dubious. I'm putting it in as a hack around the
     # problems with set_handlers not working quite right until 1.26 is
     # released (according to Doug MacEachern).
-  my $cache_result = $r->notes('AuthenCache');
+  my $cache_result = MP2 ? $r->notes->get('AuthenCache') : $r->notes('AuthenCache');
   if ($cache_result eq 'hit') {
     $r->log->debug("manage_cache: upstream cache hit for username=",
 		   "$user_sent");
