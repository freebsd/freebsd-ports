--- ./include/mpeg4ip.h.orig	2006-08-07 19:27:00.000000000 +0100
+++ ./include/mpeg4ip.h	2010-07-14 18:47:44.000000000 +0100
@@ -58,6 +58,8 @@
 // file 
 #include "mpeg4ip_version.h"
 
+#include <mp4v2/mp4v2.h>
+
 #ifdef _WIN32
 #include "mpeg4ip_win32.h"
 #include "mpeg4ip_version.h"
@@ -178,6 +180,7 @@
 #define LLU  U64
 
 #include <stdarg.h>
+/* from mp4v2/mp4v2.h
 typedef void (*error_msg_func_t)(int loglevel,
 				 const char *lib,
 				 const char *fmt,
@@ -186,6 +189,7 @@
 				   const char *lib,
 				   const char *fmt,
 				   ...);
+*/
 #ifndef HAVE_IN_PORT_T
 typedef uint16_t in_port_t;
 #endif
@@ -271,6 +275,7 @@
 
 #ifndef __cplusplus
 
+/* from mp4v2/mp4v2.h
 #ifndef bool
  #if SIZEOF_BOOL == 8
   typedef uint64_t bool;
@@ -292,6 +297,7 @@
  #define true TRUE
  #endif
 #endif
+*/
 
 #endif
 
