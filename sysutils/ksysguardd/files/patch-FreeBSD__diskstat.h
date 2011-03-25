--- FreeBSD/diskstat.h	2011-03-17 20:50:04.000000000 +0200
+++ FreeBSD/diskstat.h	2011-02-19 23:17:29.000000000 +0200
@@ -38,4 +38,11 @@
 void printDiskStatPercent(const char* cmd);
 void printDiskStatPercentInfo(const char* cmd);
 
+void printDiskStatIUsed(const char* cmd);
+void printDiskStatIUsedInfo(const char* cmd);
+void printDiskStatIFree(const char* cmd);
+void printDiskStatIFreeInfo(const char* cmd);
+void printDiskStatIPercent(const char* cmd);
+void printDiskStatIPercentInfo(const char* cmd);
+
 #endif
