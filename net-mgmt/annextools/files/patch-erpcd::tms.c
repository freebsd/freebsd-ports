--- erpcd/tms.c.orig	Thu Dec 14 13:19:53 2006
+++ erpcd/tms.c	Thu Dec 14 13:20:07 2006
@@ -50,7 +50,7 @@
 /*
  * forwards
  */
-int tms_request();
+static int tms_request();
 #define REQUEST_INIT 1
 #define REQUEST_TERM 2
 
