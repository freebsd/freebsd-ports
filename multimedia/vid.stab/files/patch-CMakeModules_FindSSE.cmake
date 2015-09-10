--- CMakeModules/FindSSE.cmake.orig	2014-03-12 19:42:49 UTC
+++ CMakeModules/FindSSE.cmake
@@ -40,6 +40,36 @@ IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
    ELSE (SSE41_TRUE)
       set(SSE4_1_FOUND false CACHE BOOL "SSE4.1 available on host")
    ENDIF (SSE41_TRUE)
+ELSEIF(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+   EXEC_PROGRAM(make ARGS "-V MACHINE_CPU" OUTPUT_VARIABLE CPUINFO)
+
+   STRING(REGEX MATCH "(^|[^s])sse2" SSE2_TRUE ${CPUINFO})
+   IF (SSE2_TRUE)
+      set(SSE2_FOUND true CACHE BOOL "SSE2 available on host")
+   ELSE (SSE2_TRUE)
+      set(SSE2_FOUND false CACHE BOOL "SSE2 available on host")
+   ENDIF (SSE2_TRUE)
+
+   STRING(REGEX MATCH "(^|[^s])sse3" SSE3_TRUE ${CPUINFO})
+   IF (SSE3_TRUE)
+      set(SSE3_FOUND true CACHE BOOL "SSE3 available on host")
+   ELSE (SSE3_TRUE)
+      set(SSE3_FOUND false CACHE BOOL "SSE3 available on host")
+   ENDIF (SSE3_TRUE)
+
+   STRING(REGEX MATCH "ssse3" SSSE3_TRUE ${CPUINFO})
+   IF (SSSE3_TRUE)
+      set(SSSE3_FOUND true CACHE BOOL "SSSE3 available on host")
+   ELSE (SSSE3_TRUE)
+      set(SSSE3_FOUND false CACHE BOOL "SSSE3 available on host")
+   ENDIF (SSSE3_TRUE)
+
+   STRING(REGEX MATCH "sse41" SSE41_TRUE ${CPUINFO})
+   IF (SSE41_TRUE)
+      set(SSE4_1_FOUND true CACHE BOOL "SSE4.1 available on host")
+   ELSE (SSE41_TRUE)
+      set(SSE4_1_FOUND false CACHE BOOL "SSE4.1 available on host")
+   ENDIF (SSE41_TRUE)
 ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    EXEC_PROGRAM("/usr/sbin/sysctl -n machdep.cpu.features" OUTPUT_VARIABLE
       CPUINFO)
