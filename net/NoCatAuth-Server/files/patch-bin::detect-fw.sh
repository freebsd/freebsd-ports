--- bin/detect-fw.sh.orig	Fri Aug  9 07:28:43 2002
+++ bin/detect-fw.sh	Wed Nov 19 15:51:16 2003
@@ -3,7 +3,7 @@
 export PATH=$PATH:/sbin:/usr/sbin:/usr/local/sbin
 
 # Have we been explicitly told which firewall scripts to install?
-if [ -n "$1" -a -n "$2" -a -d "$2/$1" ]; then
+if [ -n "$1" -a -n "$2" ]; then
     FIREWALL=$1
     shift
 
