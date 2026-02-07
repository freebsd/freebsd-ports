--- Authen/CyrusSASL.pm.orig	Mon Sep 24 15:41:30 2001
+++ Authen/CyrusSASL.pm	Fri Aug 26 13:34:21 2005
@@ -76,10 +76,13 @@
 }
 
 sub check_pwd {
-	my ($self, $name, $pwd) = @_;
+	my ($self, $name, $pwd, $service, $realm) = @_;
 	my ($req, $res, $sh);
 
-	$req = "$name\0$pwd\0";
+	$service = "imap" unless defined ($service);
+	$realm = "" unless defined ($realm);
+
+	$req = sprintf ("\0%c%s\0%c%s\0%c%s\0%c%s", length $name, $name, length $pwd, $pwd, length $service, $service, length $realm, $realm);
 	$res = ' ' x 1024;
 
 	# send request
@@ -93,7 +96,7 @@
 	# sock->recv does not work
 	#$self->{'sock'}->recv ($res, 1024, 0) or return SASL_FAIL;
 
-	if (substr($res, 0, 2) ne 'OK') {
+	if (substr($res, 2, 2) ne 'OK') {
 	  $! = substr($res, 3);
 	  return SASL_BADAUTH;
 	}
@@ -113,10 +116,10 @@
   use Authen::CyrusSASL;
   
   $p = new Authen::CyrusSASL(Type => SASL_AUTHD, Dir => '/var/run/saslauthd');
-  print "check=", $r->check_pwd('username', 'userpass'), "\n";
+  print "check=", $r->check_pwd('username', 'userpass', 'service', 'realm'), "\n";
 
   $p = new Authen::CyrusSASL(Type => SASL_PWCHECK, Dir => '/var/run/pwcheck');
-  print "check=", $r->check_pwd('username', 'userpass'), "\n";
+  print "check=", $r->check_pwd('username', 'userpass', 'service', 'realm'), "\n";
 
 =head1 DESCRIPTION
 
@@ -154,7 +157,7 @@
 
 =over 4
 
-=item check_pwd ( USERNAME, PASSWORD )
+=item check_pwd ( USERNAME, PASSWORD, SERVICE, REALM )
 
 Checks with the SASL server if the specified C<PASSWORD> is valid for user 
 C<USERNAME>. It returns SASL_OK if the C<PASSWORD> is correct,
