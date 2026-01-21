--- cmake/modules/FindSSE.cmake.orig	2026-01-19 17:31:05 UTC
+++ cmake/modules/FindSSE.cmake
@@ -42,8 +42,7 @@ elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    endif()
 elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    if(CPU MATCHES "amd64" OR CPU MATCHES "i.86")
-     execute_process(COMMAND dmesg
-                     COMMAND grep Features OUTPUT_VARIABLE CPUINFO)
+     execute_process(COMMAND sh -c "echo $_CPU_FEATURE" OUTPUT_VARIABLE CPUINFO)
 
      string(REGEX REPLACE "^.*(SSE).*$" "\\1" _SSE_THERE "${CPUINFO}")
      string(COMPARE EQUAL "SSE" "${_SSE_THERE}" _SSE_TRUE)
