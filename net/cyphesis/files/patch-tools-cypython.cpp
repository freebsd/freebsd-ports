--- tools/cypython.cpp.orig	2013-11-27 14:43:48.000000000 +0100
+++ tools/cypython.cpp	2013-11-27 14:43:56.000000000 +0100
@@ -32,6 +32,8 @@
 
 #include <varconf/config.h>
 
+#include <cstdio>
+
 #ifndef READLINE_CXX_SANE   // defined in config.h
 extern "C" {
 #endif
