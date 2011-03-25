--- FreeBSD/Memory.h	2011-03-17 20:50:04.000000000 +0200
+++ FreeBSD/Memory.h	2010-11-09 11:06:08.000000000 +0200
@@ -27,19 +27,30 @@
 
 int updateMemory(void);
 
+void printMActive(const char* cmd);
+void printMActiveInfo(const char* cmd);
+void printMInactive(const char* cmd);
+void printMInactiveInfo(const char* cmd);
+void printMApplication(const char* cmd);
+void printMApplicationInfo(const char* cmd);
+void printMWired(const char* cmd);
+void printMWiredInfo(const char* cmd);
+void printMCached(const char* cmd);
+void printMCachedInfo(const char* cmd);
+void printMBuffers(const char* cmd);
+void printMBuffersInfo(const char* cmd);
 void printMFree(const char* cmd);
 void printMFreeInfo(const char* cmd);
-void printUsed(const char* cmd);
-void printUsedInfo(const char* cmd);
-void printBuffers(const char* cmd);
-void printBuffersInfo(const char* cmd);
-void printCached(const char* cmd);
-void printCachedInfo(const char* cmd);
-void printApplication(const char* cmd);
-void printApplicationInfo(const char* cmd);
+void printMUsed(const char* cmd);
+void printMUsedInfo(const char* cmd);
+
 void printSwapUsed(const char* cmd);
 void printSwapUsedInfo(const char* cmd);
 void printSwapFree(const char* cmd);
 void printSwapFreeInfo(const char* cmd);
+void printSwapIn(const char* cmd);
+void printSwapInInfo(const char* cmd);
+void printSwapOut(const char* cmd);
+void printSwapOutInfo(const char* cmd);
 
 #endif
