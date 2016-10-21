--- girara/macros.h.orig	2015-04-13 20:49:26 UTC
+++ girara/macros.h
@@ -69,4 +69,12 @@
     GIRARA_DO_PRAGMA(GCC diagnostic pop)
 #endif
 
+#ifndef GIRARA_OPTNONE
+# if defined(__clang__)
+#  define GIRARA_OPTNONE __attribute__ ((optnone))
+# else
+#  define GIRARA_OPTNONE
+# endif
+#endif
+
 #endif
