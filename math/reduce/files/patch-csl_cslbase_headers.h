Index: csl/cslbase/headers.h
===================================================================
--- csl/cslbase/headers.h	(revision 1603)
+++ csl/cslbase/headers.h	(working copy)
@@ -97,6 +97,17 @@
 #define PRIxPTR "llx"
 #endif
 
+/*
+ * This is necessary to for timeval in BSD systems.
+ */
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if (defined(BSD) && (BSD >= 199103))
+#include <sys/time.h>
+#endif
+
 #ifndef UNDER_CE
 /*
  * The test for UNDER_CE is a little odd here, but when I once compiled a
