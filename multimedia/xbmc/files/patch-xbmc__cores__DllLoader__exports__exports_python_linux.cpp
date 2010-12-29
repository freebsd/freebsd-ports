--- xbmc/cores/DllLoader/exports/exports_python_linux.cpp.orig	2010-12-17 07:17:41.000000000 +0100
+++ xbmc/cores/DllLoader/exports/exports_python_linux.cpp	2010-12-27 20:00:59.000000000 +0100
@@ -34,7 +34,7 @@
 #endif
 #include "../DllLoaderContainer.h"
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 //
 // Use pthread's built-in support for TLS, it's more portable.
 //
@@ -105,7 +105,7 @@
 
 char* xbp_getcwd(char *buf, int size)
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   // Initialize thread local storage and local thread pointer.
   pthread_once(&keyOnce, MakeTlsKeys);
   if (xbp_cw_dir == 0)
@@ -124,7 +124,7 @@
 
 int xbp_chdir(const char *dirname)
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   // Initialize thread local storage and local thread pointer.
   pthread_once(&keyOnce, MakeTlsKeys);
 
@@ -139,7 +139,7 @@
   if (strlen(dirname) > MAX_PATH) return -1;
   strcpy(xbp_cw_dir, dirname);
 
-#if (defined USE_EXTERNAL_PYTHON)
+#if defined(USE_EXTERNAL_PYTHON)
   /* TODO: Need to figure out how to make system level Python make call to
    * XBMC's chdir instead of non-threadsafe system chdir
    */
@@ -220,7 +220,7 @@
 FILE* xbp_fopen64(const char *filename, const char *mode)
 {
   CStdString strName = _P(filename);
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   return fopen(strName.c_str(), mode);
 #else
   return fopen64(strName.c_str(), mode);
@@ -233,7 +233,7 @@
   return lstat(strName.c_str(), buf);
 }
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 int xbp_lstat64(const char * path, struct stat64 * buf)
 {
   CStdString strName = _P(path);
