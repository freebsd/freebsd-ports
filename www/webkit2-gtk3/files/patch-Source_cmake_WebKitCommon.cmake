--- Source/cmake/WebKitCommon.cmake.orig	2021-09-22 23:05:58 UTC
+++ Source/cmake/WebKitCommon.cmake
@@ -106,9 +106,9 @@ if (NOT HAS_RUN_WEBKIT_COMMON)
         endif ()
     elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(i[3-6]86|x86)")
         set(WTF_CPU_X86 1)
-    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "ppc")
+    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc|powerpc)")
         set(WTF_CPU_PPC 1)
-    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "ppc64")
+    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc64|powerpc64)")
         set(WTF_CPU_PPC64 1)
     elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "ppc64le")
         set(WTF_CPU_PPC64LE 1)
