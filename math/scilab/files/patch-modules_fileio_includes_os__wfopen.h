--- modules/fileio/includes/os_wfopen.h.orig	2020-02-25 09:59:50 UTC
+++ modules/fileio/includes/os_wfopen.h
@@ -25,7 +25,7 @@
 #endif
 
 // Linux
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define os_wfopen       linux_fopen
 FILE* linux_fopen(const wchar_t* _pstFilename, const wchar_t* _pstMode);
 #endif
