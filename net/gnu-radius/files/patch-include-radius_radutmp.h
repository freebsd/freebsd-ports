--- include/radius/radutmp.h.orig	2009-05-07 22:24:02.000000000 +0200
+++ include/radius/radutmp.h	2009-05-07 22:24:45.000000000 +0200
@@ -30,7 +30,7 @@
 #define P_ACCT_ENABLED  131
 
 #define RUT_NAMESIZE 32
-#define RUT_IDSIZE 16
+#define RUT_IDSIZE 32
 #define RUT_PNSIZE 24           /* Phone number size */
 
 struct radutmp {
