/var/run/dmesg.boot is not available in Poudriere jails and reading
it at build time also doesn't allow for any control, so pass in the
CPU features through the CPU_FEATURES environment variable.

--- cmake/modules/FindSSE.cmake.orig	2018-07-01 06:58:49 UTC
+++ cmake/modules/FindSSE.cmake
@@ -42,7 +42,7 @@ if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    endif()
 elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    if(CPU MATCHES "amd64" OR CPU MATCHES "i.86")
-     exec_program(cat ARGS "/var/run/dmesg.boot | grep Features" OUTPUT_VARIABLE CPUINFO)
+     exec_program(echo ARGS "$CPU_FEATURES" OUTPUT_VARIABLE CPUINFO)
 
      string(REGEX REPLACE "^.*(SSE).*$" "\\1" _SSE_THERE ${CPUINFO})
      string(COMPARE EQUAL "SSE" "${_SSE_THERE}" _SSE_TRUE)
