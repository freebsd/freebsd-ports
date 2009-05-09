--- ./fwcutter.c.orig	2008-02-13 11:46:26.000000000 -0600
+++ ./fwcutter.c	2009-05-07 01:24:22.345157339 -0500
@@ -38,7 +38,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
-#ifdef __DragonFly__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 #include <sys/endian.h>
 #else
 #include <byteswap.h>
@@ -48,7 +48,7 @@
 #include "fwcutter.h"
 #include "fwcutter_list.h"
 
-#ifdef __DragonFly__
+#if defined(__DragonFly__) || defined(__FreeBSD__)
 #define V3_FW_DIRNAME	"v3"
 #define V4_FW_DIRNAME	"v4"
 #else
