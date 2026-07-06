--- include/radius/radutmp.h.orig	2025-12-11 11:21:32 UTC
+++ include/radius/radutmp.h
@@ -27,7 +27,7 @@
 #define P_ACCT_ENABLED  131
 
 #define RUT_NAMESIZE 32
-#define RUT_IDSIZE 16
+#define RUT_IDSIZE 32
 #define RUT_PNSIZE 24           /* Phone number size */
 
 struct radutmp {
