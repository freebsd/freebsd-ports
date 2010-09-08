--- OpenFilesScreen.h.orig	2010-01-26 03:57:03.000000000 +0800
+++ OpenFilesScreen.h	2010-01-26 03:57:19.000000000 +0800
@@ -28,7 +28,7 @@
 typedef struct OpenFiles_ProcessData_ {
    char* data[256];
    struct OpenFiles_FileData_* files;
-   bool failed;
+   int error;
 } OpenFiles_ProcessData;
 
 typedef struct OpenFiles_FileData_ {
