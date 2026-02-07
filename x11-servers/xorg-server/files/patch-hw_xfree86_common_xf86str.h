--- hw/xfree86/common/xf86str.h.orig	2022-01-02 23:41:56.000000000 +0100
+++ hw/xfree86/common/xf86str.h	2022-06-29 11:57:25.502421000 +0200
@@ -249,7 +249,7 @@ typedef struct _DriverRec {
  */
 
 /* Tolerate prior #include <linux/input.h> */
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #undef BUS_NONE
 #undef BUS_PCI
 #undef BUS_SBUS
