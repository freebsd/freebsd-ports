--- Users/Users.pm.orig	Thu Oct  5 09:27:21 2006
+++ Users/Users.pm	Sun Apr 22 23:05:41 2007
@@ -458,7 +458,7 @@
 	
   if ($Utils::Backend::tool{"system"} eq "FreeBSD")
   {
-    $command = "$cmd_pw userdel -n \'" . $$user[$LOGIN] . "\' ";
+    $command = "$cmd_pw userdel -n \'" . $$user[$LOGIN] . "\' -r ";
   }
   else
   {
@@ -538,10 +538,10 @@
   {
     my $pwdpipe;
     my $home;
+    my $user;
 
-    # FreeBSD doesn't create the home directory
     $home = $$user[$HOME];
-    &Utils::File::run ("$tool_mkdir -p $home");
+    $user = $$user[$LOGIN];
 
     $command = "$cmd_pw useradd " .
         " -n \'" . $$user[$LOGIN] . "\'" .
@@ -549,11 +549,12 @@
         " -d \'" . $$user[$HOME]  . "\'" .
         " -g \'" . $$user[$GID]   . "\'" .
         " -s \'" . $$user[$SHELL] . "\'" .
-        " -H 0"; # pw(8) reads password from STDIN
+        " -m -h 0"; # pw(8) reads password from STDIN
 
     $pwdpipe = &Utils::File::run_pipe_write ($command);
     print $pwdpipe $$user[$PASSWD];
     &Utils::File::close_file ($pwdpipe);
+    &Utils::File::run ("chown -R $user $home");
   }
   elsif ($Utils::Backend::tool{"system"} eq "SunOS")
   {
@@ -629,7 +630,7 @@
         " -d \'" . $$new_user[$HOME]  . "\'" .
         " -g \'" . $$new_user[$GID]   . "\'" .
         " -s \'" . $$new_user[$SHELL] . "\'" .
-        " -H 0"; # pw(8) reads password from STDIN
+        " -h 0"; # pw(8) reads password from STDIN
 
     $pwdpipe = &Utils::File::run_pipe_write ($command);
     print $pwdpipe $$new_user[$PASSWD];
