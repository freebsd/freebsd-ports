--- Users/Users.pm.orig	2009-09-28 05:49:10.000000000 -0400
+++ Users/Users.pm	2009-10-11 15:09:31.000000000 -0400
@@ -443,7 +443,7 @@ sub del_user
 	
   if ($Utils::Backend::tool{"system"} eq "FreeBSD")
   {
-    @command = ($cmd_pw, "userdel", "-n", $$user[$LOGIN]);
+    @command = ($cmd_pw, "userdel", "-n", $$user[$LOGIN], "-r");
   }
   else
   {
@@ -551,9 +551,7 @@ sub add_user
     my $pwdpipe;
     my $home;
 
-    # FreeBSD doesn't create the home directory
     $home = $$user[$HOME];
-    &Utils::File::run ($tool_mkdir, "-p", $home);
 
     $command = "$cmd_pw useradd " .
         " -n \'" . $$user[$LOGIN] . "\'" .
@@ -561,7 +559,7 @@ sub add_user
         " -d \'" . $$user[$HOME]  . "\'" .
         " -g \'" . $$user[$GID]   . "\'" .
         " -s \'" . $$user[$SHELL] . "\'" .
-        " -H 0"; # pw(8) reads password from STDIN
+        " -m -h 0"; # pw(8) reads password from STDIN
 
 #    @command = ($cmd_pw, "useradd", "-n", $$user[$LOGIN],
 #                                    "-u", $$user[$UID],
@@ -573,6 +571,7 @@ sub add_user
     $pwdpipe = &Utils::File::run_pipe_write ($command);
     print $pwdpipe $$user[$PASSWD];
     &Utils::File::close_file ($pwdpipe);
+    &Utils::File::run ("chown -R " . $$user[$LOGIN] . " $home");
   }
   elsif ($Utils::Backend::tool{"system"} eq "SunOS")
   {
@@ -651,7 +650,7 @@ sub change_user
         " -d \'" . $$new_user[$HOME]  . "\'" .
         " -g \'" . $$new_user[$GID]   . "\'" .
         " -s \'" . $$new_user[$SHELL] . "\'" .
-        " -H 0"; # pw(8) reads password from STDIN
+        " -h 0"; # pw(8) reads password from STDIN
 
     $pwdpipe = &Utils::File::run_pipe_write ($command);
     print $pwdpipe $$new_user[$PASSWD];
