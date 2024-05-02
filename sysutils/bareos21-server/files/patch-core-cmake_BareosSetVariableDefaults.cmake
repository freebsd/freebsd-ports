--- core/cmake/BareosSetVariableDefaults.cmake	2024-02-28 05:24:21.000000000 -0500
+++ core/cmake/BareosSetVariableDefaults.cmake	2024-05-02 00:57:55.264449000 -0500
@@ -568,8 +568,10 @@
 set(PACKAGE_STRING "\"${CMAKE_PROJECT_NAME} ${BAREOS_NUMERIC_VERSION}\"")
 set(PACKAGE_VERSION "\"${BAREOS_NUMERIC_VERSION}\"")
 
-if(NOT DEFINED ENABLE_NLS)
-  set(ENABLE_NLS 1)
+if(nls)
+  SET(ENABLE_NLS 1)
+else()
+  SET(ENABLE_NLS 0)
 endif()
 
 if(HAVE_WIN32)
