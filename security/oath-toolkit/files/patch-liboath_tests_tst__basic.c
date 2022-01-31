--- liboath/tests/tst_basic.c.orig	2022-01-31 11:26:43 UTC
+++ liboath/tests/tst_basic.c
@@ -57,7 +57,7 @@ main (void)
       return 1;
     }
 
-  if (OATH_VERSION_NUMBER < 0x02060300 || OATH_VERSION_NUMBER >= 0x03000000)
+  if (OATH_VERSION_NUMBER < 0x02060200 || OATH_VERSION_NUMBER >= 0x03000000)
     {
       printf ("OATH_VERSION_NUMBER out of range?!\n");
       return 1;
