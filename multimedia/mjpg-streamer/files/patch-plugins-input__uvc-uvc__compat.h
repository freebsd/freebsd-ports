--- plugins/input_uvc/uvc_compat.h.orig	2008-06-16 14:23:51.000000000 +0300
+++ plugins/input_uvc/uvc_compat.h	2013-08-24 04:49:30.000000000 +0300
@@ -26,14 +26,13 @@
 #ifndef _UVC_COMPAT_H
 #define _UVC_COMPAT_H
 
-#include <linux/version.h>
 #ifndef __KERNEL__
 #ifndef __user
 #define __user
 #endif
 #endif
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,18)
+#if 0
 /*
  * Extended control API
  */
@@ -85,7 +84,7 @@
 
 #endif
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,19)
+#if 0
 /*
  * Frame size and frame rate enumeration
  *
