--- ./agent/magent.sh.orig	2011-12-23 07:44:07.000000000 +0900
+++ ./agent/magent.sh	2014-08-14 01:59:33.545705026 +0900
@@ -116,10 +116,10 @@
 \$phostname = '$phostname';
 
 # Our domain name
-\$mydomain = '$mydomain';
+\$mydomain = '';
 
 # Hidden network (advertised host)
-\$hiddennet = '$hiddennet';
+\$hiddennet = '';
 
 # Directory where mail is spooled
 \$maildir = '$maildir';
