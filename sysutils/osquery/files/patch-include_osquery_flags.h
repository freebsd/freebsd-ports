--- include/osquery/flags.h.orig	2015-05-05 00:16:41 UTC
+++ include/osquery/flags.h
@@ -19,7 +19,11 @@
 
 #include <osquery/core.h>
 
+#ifdef FREEBSD
+#define GFLAGS_NAMESPACE gflags
+#elif !defined(GFLAGS_NAMESPACE)
 #define GFLAGS_NAMESPACE google
+#endif
 
 namespace boost {
 /// We define a lexical_cast template for boolean for Gflags boolean string
