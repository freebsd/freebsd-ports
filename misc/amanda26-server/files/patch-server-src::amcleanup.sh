--- server-src/amcleanup.sh.orig	2009-01-05 07:37:09.000000000 +0900
+++ server-src/amcleanup.sh	2009-01-05 07:37:26.000000000 +0900
@@ -75,7 +75,7 @@
 #   after receiving SIGTERM,  if yes send SIGKILL  
 #
 
-function killpid() {
+killpid() {
 
 killPID=$1
 SIGTERM=15
