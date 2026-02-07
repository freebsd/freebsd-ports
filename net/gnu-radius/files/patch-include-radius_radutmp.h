--- include/radius/radutmp.h.orig	2008-12-15 08:03:24 UTC
+++ include/radius/radutmp.h
@@ -30,7 +30,7 @@
 #define P_ACCT_ENABLED  131
 
 #define RUT_NAMESIZE 32
-#define RUT_IDSIZE 16
+#define RUT_IDSIZE 32
 #define RUT_PNSIZE 24           /* Phone number size */
 
 struct radutmp {
