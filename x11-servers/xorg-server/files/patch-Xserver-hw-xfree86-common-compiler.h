--- hw/xfree86/common/compiler.h.orig	2009-02-25 13:12:11.000000000 -0600
+++ hw/xfree86/common/compiler.h	2009-03-21 02:08:22.000000000 -0500
@@ -465,7 +465,7 @@
 extern unsigned int inw(unsigned long port);
 extern unsigned int inl(unsigned long port);
  
-#   elif defined(linux) && defined(__amd64__)
+#   elif defined(linux) || defined(__FreeBSD__) && defined(__amd64__)
  
 #    include <inttypes.h>
 
