--- libpskc/tests/tst_basic.c.orig	2022-01-31 11:38:13 UTC
+++ libpskc/tests/tst_basic.c
@@ -70,7 +70,7 @@ main (void)
       return 1;
     }
 
-  if (PSKC_VERSION_NUMBER < 0x02060300 || PSKC_VERSION_NUMBER >= 0x03000000)
+  if (PSKC_VERSION_NUMBER < 0x02060200 || PSKC_VERSION_NUMBER >= 0x03000000)
     {
       printf ("PSKC_VERSION_NUMBER out of range?!\n");
       return 1;
