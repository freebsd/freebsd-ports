--- src/3rdparty/chromium/components/update_client/update_query_params.cc.orig	2019-05-23 14:39:34.000000000 +0200
+++ src/3rdparty/chromium/components/update_client/update_query_params.cc	2019-10-29 02:42:47.135055000 +0100
@@ -38,6 +38,8 @@
     "fuchsia";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
@@ -55,6 +57,8 @@
     "mips64el";
 #elif defined(__mips__)
     "mipsel";
+#elif defined(__powerpc64__)
+    "ppc64";
 #else
 #error "unknown arch"
 #endif
@@ -127,6 +131,8 @@
   return "mips32";
 #elif defined(ARCH_CPU_MIPS64EL)
   return "mips64";
+#elif defined(ARCH_CPU_PPC64)
+  return "ppc64";
 #else
 // NOTE: when adding new values here, please remember to update the
 // comment in the .h file about possible return values from this function.
