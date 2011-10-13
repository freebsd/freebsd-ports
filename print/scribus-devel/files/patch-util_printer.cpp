--- scribus/util_printer.cpp.orig	2011-10-13 19:28:10.000000000 +0200
+++ scribus/util_printer.cpp	2011-10-13 19:28:51.000000000 +0200
@@ -9,6 +9,7 @@
 
 #if defined( HAVE_CUPS )
  #include <cups/cups.h>
+ #include <cups/ppd.h>
 #elif defined(_WIN32)
  #include <windows.h>
  #include <winspool.h>
