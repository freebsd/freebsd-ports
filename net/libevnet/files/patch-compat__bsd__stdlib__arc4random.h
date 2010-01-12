--- ./compat/bsd/stdlib/arc4random.h.orig	2009-11-29 07:02:28.000000000 +0200
+++ ./compat/bsd/stdlib/arc4random.h	2010-01-12 23:27:24.000000000 +0200
@@ -379,11 +379,11 @@
 
 
 #ifndef HAVE_ARC4RANDOM_BUF
-#if defined __OpenBSD__
+#if defined __OpenBSD__ || defined __FreeBSD__
 
-#include <sys/param.h>	/* OpenBSD */
+#include <sys/param.h>	/* OpenBSD, FreeBSD */
 
-#if OpenBSD >= 200811
+#if OpenBSD >= 200811  || __FreeBSD_version >= 800107
 #define HAVE_ARC4RANDOM_BUF	1
 #else
 #define HAVE_ARC4RANDOM_BUF	0
