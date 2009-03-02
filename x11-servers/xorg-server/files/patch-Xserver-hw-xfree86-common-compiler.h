--- hw/xfree86/common/compiler.h.orig	2009-03-02 12:21:23.000000000 -0600
+++ hw/xfree86/common/compiler.h	2009-03-02 12:21:29.000000000 -0600
@@ -498,7 +498,7 @@
 extern unsigned int inw(unsigned long port);
 extern unsigned int inl(unsigned long port);
  
-#   elif defined(linux) && (defined(__amd64__) || defined(__x86_64__))
+#   elif defined(linux) || defined(__FreeBSD__) && (defined(__amd64__) || defined(__x86_64__))
  
 #    include <inttypes.h>
 
