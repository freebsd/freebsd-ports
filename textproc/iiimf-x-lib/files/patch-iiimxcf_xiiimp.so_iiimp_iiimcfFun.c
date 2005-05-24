--- iiimxcf/xiiimp.so/iiimp/iiimcfFun.c.orig	Fri May 13 18:18:29 2005
+++ iiimxcf/xiiimp.so/iiimp/iiimcfFun.c	Fri May 13 18:18:47 2005
@@ -61,7 +61,9 @@
 #include <iiimcf.h>
 #include <langinfo.h>
 #include <limits.h>
+#ifndef __FreeBSD__
 #include <values.h>
+#endif
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
 
