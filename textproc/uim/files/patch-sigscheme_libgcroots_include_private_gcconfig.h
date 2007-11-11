--- sigscheme/libgcroots/include/private/gcconfig.h.orig	2007-01-06 12:00:59.000000000 +0900
+++ sigscheme/libgcroots/include/private/gcconfig.h	2007-11-04 18:15:32.000000000 +0900
@@ -320,6 +320,10 @@
 #   define I386
 #   define mach_type_known
 # endif
+# if defined(FREEBSD) && (defined(__amd64__))
+#   define X86_64
+#   define mach_type_known
+# endif
 # if defined(__NetBSD__) && (defined(i386) || defined(__i386__))
 #   define I386
 #   define mach_type_known
