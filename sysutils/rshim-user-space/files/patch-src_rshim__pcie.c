--- src/rshim_pcie.c.orig	2020-04-15 08:20:11 UTC
+++ src/rshim_pcie.c
@@ -459,6 +459,8 @@ int rshim_pcie_enable(void *dev)
 
   close(fd);
   return rc;
+#else
+  return 0;
 #endif
 }
 
