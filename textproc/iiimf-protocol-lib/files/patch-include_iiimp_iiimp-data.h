--- include/iiimp/iiimp-data.h.orig	Sat Dec  6 02:19:44 2003
+++ include/iiimp/iiimp-data.h	Sat Dec  6 02:18:15 2003
@@ -7,7 +7,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
 #include <stdint.h>
 typedef unsigned char	uchar_t;
 typedef unsigned int	uint_t;
