--- cmakeFindModules/FindSSE.cmake.orig	2018-04-06 09:25:15 UTC
+++ cmakeFindModules/FindSSE.cmake
@@ -1,11 +1,12 @@
 # Check if SSE instructions are available on the machine where 
 # the project is compiled.
 
-IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
-   EXEC_PROGRAM(cat ARGS "/proc/cpuinfo" OUTPUT_VARIABLE CPUINFO)
+IF(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+   #EXEC_PROGRAM(cat ARGS "/proc/cpuinfo" OUTPUT_VARIABLE CPUINFO)
 
-   STRING(REGEX REPLACE "^.*(sse2).*$" "\\1" SSE_THERE ${CPUINFO})
-   STRING(COMPARE EQUAL "sse2" "${SSE_THERE}" SSE2_TRUE)
+   #STRING(REGEX REPLACE "^.*(sse2).*$" "\\1" SSE_THERE ${CPUINFO})
+   #STRING(COMPARE EQUAL "sse2" "${SSE_THERE}" SSE2_TRUE)
+   SET(SSE2_TRUE TRUE)
    IF (SSE2_TRUE)
       set(SSE2_FOUND true CACHE BOOL "SSE2 available on host")
    ELSE (SSE2_TRUE)
@@ -13,8 +14,8 @@ IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
    ENDIF (SSE2_TRUE)
 
    # /proc/cpuinfo apparently omits sse3 :(
-   STRING(REGEX REPLACE "^.*[^s](sse3).*$" "\\1" SSE_THERE ${CPUINFO})
-   STRING(COMPARE EQUAL "sse3" "${SSE_THERE}" SSE3_TRUE)
+   #STRING(REGEX REPLACE "^.*[^s](sse3).*$" "\\1" SSE_THERE ${CPUINFO})
+   #STRING(COMPARE EQUAL "sse3" "${SSE_THERE}" SSE3_TRUE)
    IF (NOT SSE3_TRUE)
       STRING(REGEX REPLACE "^.*(T2300).*$" "\\1" SSE_THERE ${CPUINFO})
       STRING(COMPARE EQUAL "T2300" "${SSE_THERE}" SSE3_TRUE)
