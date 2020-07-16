--- cmake/modules/FindSSE.cmake.orig	2020-05-19 20:46:12 UTC
+++ cmake/modules/FindSSE.cmake
@@ -42,7 +42,7 @@ if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    endif()
 elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    if(CPU MATCHES "amd64" OR CPU MATCHES "i.86")
-     exec_program(cat ARGS "/var/run/dmesg.boot | grep Features" OUTPUT_VARIABLE CPUINFO)
+     exec_program(echo ARGS "$_CPU_FEATURE" OUTPUT_VARIABLE CPUINFO)
 
      string(REGEX REPLACE "^.*(SSE).*$" "\\1" _SSE_THERE ${CPUINFO})
      string(COMPARE EQUAL "SSE" "${_SSE_THERE}" _SSE_TRUE)
