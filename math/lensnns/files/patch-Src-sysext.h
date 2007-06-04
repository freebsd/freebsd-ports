--- Src/sysext.h.orig	Tue Dec  9 13:13:53 2003
+++ Src/sysext.h	Thu May 10 10:59:36 2007
@@ -3,10 +3,8 @@
 #ifndef SYSEXT_H
 #define SYSEXT_H
 
-/*
-#ifdef MACHINE_YOURMACHINE
-  include headers or define macros as necessary
-#endif
-*/
+#if BYTE_ORDER == LITTLE_ENDIAN
+#    define LITTLE_END
+#endif /* LITTLE_END */
 
 #endif /* SYSEXT_H */
