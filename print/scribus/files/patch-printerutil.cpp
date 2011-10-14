--- scribus/printerutil.cpp.orig	2011-10-14 20:38:57.000000000 +0200
+++ scribus/printerutil.cpp	2011-10-14 20:39:11.000000000 +0200
@@ -9,6 +9,7 @@
 
 #if defined( HAVE_CUPS )
  #include <cups/cups.h>
+ #include <cups/ppd.h>
 #elif defined(_WIN32)
  #include <windows.h>
  #include <winspool.h>
