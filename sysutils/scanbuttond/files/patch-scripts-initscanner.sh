--- scripts/initscanner.sh.orig	Sat Jun  4 12:37:24 2005
+++ scripts/initscanner.sh	Fri Mar 31 01:46:29 2006
@@ -9,5 +9,5 @@
 # Example:
 # scanimage -n
 # or
-# sane-find-scanners
+# sane-find-scanner  > /dev/null 2> /dev/null
 
