--- programs/Xserver/hw/xfree86/common/compiler.h.orig	Thu May 15 14:49:26 2003
+++ programs/Xserver/hw/xfree86/common/compiler.h	Thu May 15 14:50:07 2003
@@ -514,7 +514,7 @@
    return ret;
 }
 
-#   elif (defined(linux) || defined(Lynx) || defined(sun) || defined(__OpenBSD__)) && defined(__sparc__)
+#   elif (defined(linux) || defined(Lynx) || defined(sun) || defined(__OpenBSD__) || defined(__FreeBSD__)) && defined(__sparc__)
 
 #    if !defined(Lynx)
 #     ifndef ASI_PL
