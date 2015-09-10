--- src/python-bindings/secman.cpp.orig	2015-04-07 15:10:11 UTC
+++ src/python-bindings/secman.cpp
@@ -7,6 +7,21 @@
 # include <pyport.h>
 # endif
 
+/* 
+ * #include <Python.h> solves a ctype function overload issue, but causes
+ * a dprintf() conflict.  Redefining dprintf and getline disables them in
+ * in stdio.h, #included by Python.h, so they don't collide with the condor
+ * versions.
+ */
+
+#ifdef __FreeBSD__
+#define dprintf _hide_dprintf
+#define getline _hide_getline
+#include <Python.h>
+#undef getline
+#undef dprintf
+#endif
+
 #include "condor_common.h"
 
 #include <boost/python.hpp>
