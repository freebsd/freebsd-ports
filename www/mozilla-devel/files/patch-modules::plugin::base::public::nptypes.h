--- modules/plugin/base/public/nptypes.h.orig	Tue Jul 13 18:15:51 2004
+++ modules/plugin/base/public/nptypes.h	Sun Jul 25 03:11:09 2004
@@ -70,6 +70,12 @@
   #if !defined(__cplusplus)
     typedef int bool;
   #endif
+#elif defined(__FreeBSD__)
+  #include <sys/types.h>
+
+  #if !defined(__cplusplus)
+    typedef int bool;
+  #endif
 #else
   /*
    * For those that ship a standard C99 stdint.h header file, include
