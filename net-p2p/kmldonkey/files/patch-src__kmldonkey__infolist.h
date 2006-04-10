--- ./src/kmldonkey/infolist.h.orig	Sun Apr  9 13:19:37 2006
+++ ./src/kmldonkey/infolist.h	Sun Apr  9 13:19:01 2006
@@ -321,5 +321,6 @@
 QString humanReadableTime(time_t t, bool shortFormat);
 QString calculateETA(FileInfo* fi);
 QString humanReadablePriority(int pri);
+QString humanReadableFileNumber(int fileNo);
 
 #endif
