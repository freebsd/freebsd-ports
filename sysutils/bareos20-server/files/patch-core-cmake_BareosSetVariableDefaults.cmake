--- core/cmake/BareosSetVariableDefaults.cmake	2020-01-31 16:21:15.864122000 -0500
+++ core/cmake/BareosSetVariableDefaults.cmake	2020-01-31 16:23:58.960984000 -0500
@@ -641,7 +641,11 @@
 set(PACKAGE_URL "\"\"")
 set(PACKAGE_VERSION "\"${BAREOS_NUMERIC_VERSION}\"")
 
-set(ENABLE_NLS 1)
+if(nls)
+  SET(ENABLE_NLS 1)
+else()
+  SET(ENABLE_NLS 0)
+endif()
 
 if(HAVE_WIN32)
 
