--- iiimxcf/xiiimp.so/iiimp/iiimpAux.c.orig	Sat Dec  6 04:07:05 2003
+++ iiimxcf/xiiimp.so/iiimp/iiimpAux.c	Sat Dec  6 04:07:42 2003
@@ -61,7 +61,7 @@
 #include <strings.h>
 #include <ctype.h>
 #include <sys/param.h>
-#ifndef linux
+#if !defined(linux) && !defined(__FreeBSD__)
 #include <synch.h>
 #endif
 
