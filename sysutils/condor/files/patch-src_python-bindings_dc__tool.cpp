--- src/python-bindings/dc_tool.cpp.orig	2014-11-26 11:22:10.000000000 -0600
+++ src/python-bindings/dc_tool.cpp	2014-12-27 16:40:45.000000000 -0600
@@ -7,6 +7,21 @@
 # include <pyport.h>
 # endif
 
+/*
+ * #include <Python.h> solves a ctype function overload issue, but causes
+ * a dprintf() conflict.  Redefining dprintf and getline prevents a collision
+ * with the definitions in stdio.h, #included from Python.h, so the condor
+ * versions are used instead.
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
