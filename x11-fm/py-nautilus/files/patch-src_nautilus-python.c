--- src/nautilus-python.c.orig	2011-06-08 17:41:34.000000000 +0200
+++ src/nautilus-python.c	2011-06-08 17:42:25.000000000 +0200
@@ -217,8 +217,8 @@ nautilus_python_init_python (void)
 	if (Py_IsInitialized())
 		return TRUE;
 
-  	debug("g_module_open " PY_LIB_LOC "/libpython" PYTHON_VERSION "." G_MODULE_SUFFIX ".1.0");
-	libpython = g_module_open(PY_LIB_LOC "/libpython" PYTHON_VERSION "." G_MODULE_SUFFIX ".1.0", 0);
+  	debug("g_module_open " PY_LIB_LOC "/libpython" PYTHON_VERSION "." G_MODULE_SUFFIX ".1");
+	libpython = g_module_open(PY_LIB_LOC "/libpython" PYTHON_VERSION "." G_MODULE_SUFFIX ".1", 0);
 	if (!libpython)
 		g_warning("g_module_open libpython failed: %s", g_module_error());
 
