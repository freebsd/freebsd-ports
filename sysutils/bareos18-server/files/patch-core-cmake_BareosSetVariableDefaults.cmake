--- core/cmake/BareosSetVariableDefaults.cmake	2019-05-10 11:53:19.620402000 -0500
+++ core/cmake/BareosSetVariableDefaults.cmake	2019-05-10 12:13:55.910452000 -0500
@@ -669,7 +669,11 @@
 SET(PACKAGE_URL "\"\"")
 SET(PACKAGE_VERSION "\"${BAREOS_NUMERIC_VERSION}\"")
 
-set(ENABLE_NLS 1)
+IF(DEFINED nls)
+  SET(ENABLE_NLS 1)
+ELSE()
+  SET(ENABLE_NLS 0)
+ENDIF()
 
 
 IF(HAVE_WIN32)
