--- layer0/MemoryUsage.cpp.orig	2022-11-27 20:14:03 UTC
+++ layer0/MemoryUsage.cpp
@@ -51,6 +51,8 @@ size_t memory_usage()
     GetProcessMemoryInfo(hProcess.get(), &pmc, sizeof(pmc));
   }
   return pmc.WorkingSetSize;
+#elif defined(__FreeBSD__)
+  return 0; // TODO implement memory_usage()
 #else
 #error "platform not handled"
 #endif
@@ -92,6 +94,8 @@ size_t memory_available()
   statex.dwLength = sizeof(statex);
   GlobalMemoryStatusEx(&statex);
   return statex.ullAvailPhys;
+#elif defined(__FreeBSD__)
+  return 0; // TODO: implement memory_available()
 #else
 #error "platform not handled"
 #endif
