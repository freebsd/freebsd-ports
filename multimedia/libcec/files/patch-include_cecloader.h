--- include/cecloader.h.orig	2020-07-13 10:18:33 UTC
+++ include/cecloader.h
@@ -172,7 +172,7 @@ bool LibCecBootloader(const char *strLib = NULL)
     if (!g_libCEC)
     {
       std::cout << dlerror() << std::endl;
-      return NULL;
+      return false;
     }
   }
 
@@ -181,7 +181,7 @@ bool LibCecBootloader(const char *strLib = NULL)
   if (!LibCecBootloader)
   {
     std::cout << "cannot find CECStartBootloader" << std::endl;
-    return NULL;
+    return false;
   }
 
   bool bReturn = LibCecBootloader();
