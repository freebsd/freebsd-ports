--- src/utilities.C.orig	Sat Jan 22 16:15:24 2005
+++ src/utilities.C	Sat Jan 22 16:15:45 2005
@@ -275,7 +275,7 @@
     return stringdup("Windows User");
   }
 #else
-#if defined(ARCH_FREEBSD) || defined(ARCH_MACOSX) || defined(ARCH_LINUX) || defined(ARCH_LINUXALPHA) || defined(ARCH_LINUXAMD64) || defined(ARCH_LINUXPPC)
+#if defined(ARCH_FREEBSD) || defined(ARCH_FREEBSDAMD64) || defined(ARCH_MACOSX) || defined(ARCH_LINUX) || defined(ARCH_LINUXALPHA) || defined(ARCH_LINUXAMD64) || defined(ARCH_LINUXPPC)
   return stringdup(getlogin());
 #else
   return stringdup(cuserid(NULL));
