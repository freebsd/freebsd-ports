--- cmake/cpu_extension.cmake.orig	2026-11-02 08:07:03 UTC
+++ cmake/cpu_extension.cmake
@@ -23,6 +23,11 @@ set (ENABLE_NUMA TRUE)
 
 set (ENABLE_NUMA TRUE)
 
+# FreeBSD does not have libnuma
+if (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+    set(ENABLE_NUMA OFF)
+endif()
+
 #
 # Check the compile flags
 #
@@ -32,6 +37,15 @@ if(MACOSX_FOUND)
     list(APPEND CXX_COMPILE_FLAGS
         "-Xpreprocessor" "-fopenmp"
         "-DVLLM_CPU_EXTENSION")
+elseif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+    list(APPEND CXX_COMPILE_FLAGS
+        "-fopenmp"
+        "-DVLLM_CPU_EXTENSION")
+
+    find_library(OPEN_MP
+        NAMES omp
+        REQUIRED
+    )
 else()
     list(APPEND CXX_COMPILE_FLAGS
         "-fopenmp"
@@ -59,12 +73,26 @@ if (NOT MACOSX_FOUND)
 endif()
 
 if (NOT MACOSX_FOUND)
-    execute_process(COMMAND cat /proc/cpuinfo
-                    RESULT_VARIABLE CPUINFO_RET
-                    OUTPUT_VARIABLE CPUINFO)
-    if (NOT CPUINFO_RET EQUAL 0)
-        message(FATAL_ERROR "Failed to check CPU features via /proc/cpuinfo")
+    # Try Linux /proc/cpuinfo first, then the FreeBSD linuxulator path
+    if (EXISTS "/proc/cpuinfo")
+        set(_cpuinfo_path "/proc/cpuinfo")
+    elseif (EXISTS "/compat/linux/proc/cpuinfo")
+        set(_cpuinfo_path "/compat/linux/proc/cpuinfo")
+    else()
+        set(_cpuinfo_path "")
     endif()
+    if (_cpuinfo_path)
+        execute_process(COMMAND cat ${_cpuinfo_path}
+                        RESULT_VARIABLE CPUINFO_RET
+                        OUTPUT_VARIABLE CPUINFO)
+        if (NOT CPUINFO_RET EQUAL 0)
+            message(FATAL_ERROR "Failed to check CPU features via ${_cpuinfo_path}")
+        endif()
+    else()
+        message(STATUS "No cpuinfo available; relying on CMAKE_SYSTEM_PROCESSOR for ISA detection")
+        set(CPUINFO " ")
+        set(_USE_SYSPROCESSOR_ISA TRUE)
+    endif()
 endif()
 
 
@@ -127,13 +155,22 @@ else()
         set(RVV_BF16_FOUND ON)
         message(STATUS "RVV BF16 support enabled via VLLM_CPU_RVV_BF16 environment variable")
     endif()
+
+    # Override ISA based on CMAKE_SYSTEM_PROCESSOR when cpuinfo not available
+    if(_USE_SYSPROCESSOR_ISA)
+        if(CMAKE_SYSTEM_PROCESSOR MATCHES "powerpc64le|powerpc64|powerpc")
+            set(POWER9_FOUND ON)
+            message(STATUS "Detected ${CMAKE_SYSTEM_PROCESSOR}; enabling POWER9 ISA")
+        endif()
+    endif()
 endif()
 
 if (CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64" OR ENABLE_X86_ISA)
     set(ENABLE_X86_ISA ON)
-    if (NOT (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND
-            CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 12.3))
-        message(FATAL_ERROR "X86 backend requires gcc/g++ >= 12.3")
+    if (NOT (
+            (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 12.3) OR
+            (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 15.0)))
+        message(FATAL_ERROR "X86 backend requires gcc/g++ >= 12.3 or clang >= 15.0")
     endif()
     # Work around a GCC 15 optimizer crash in oneDNN (tree-ssa-pre pass).
     # Keep this scoped to GCC 15+ so older toolchains are unaffected.
@@ -190,16 +227,17 @@ elseif (POWER9_FOUND OR POWER10_FOUND OR POWER11_FOUND
 elseif (POWER9_FOUND OR POWER10_FOUND OR POWER11_FOUND)
     message(STATUS "PowerPC detected")
     if (POWER9_FOUND)
-        list(APPEND CXX_COMPILE_FLAGS
+        set(POWER_ISA_FLAGS
             "-mvsx"
             "-mcpu=power9"
             "-mtune=power9")
     elseif (POWER10_FOUND OR POWER11_FOUND)
-        list(APPEND CXX_COMPILE_FLAGS
+        set(POWER_ISA_FLAGS
             "-mvsx"
             "-mcpu=power10"
             "-mtune=power10")
     endif()
+    list(APPEND CXX_COMPILE_FLAGS ${POWER_ISA_FLAGS})
 
 elseif (ASIMD_FOUND)
     message(STATUS "ARMv8 or later architecture detected")
@@ -401,6 +439,14 @@ if (ENABLE_X86_ISA OR (ASIMD_FOUND AND NOT APPLE_SILIC
     set(ONEDNN_ENABLE_MAX_CPU_ISA "ON")
     set(ONEDNN_ENABLE_CPU_ISA_HINTS "ON")
     set(ONEDNN_VERBOSE "ON")
+    if (POWER9_FOUND OR POWER10_FOUND OR POWER11_FOUND)
+        # oneDNN builds its ppc64 kernels with -mcpu=native by default, i.e. for
+        # the build host rather than for the ISA selected above. Where the
+        # compiler cannot resolve "native" (FreeBSD) this even degrades to the
+        # VSX-less baseline and the kernels fail to compile. Build them for the
+        # same ISA as the rest of the extension instead.
+        list(JOIN POWER_ISA_FLAGS " " ONEDNN_ARCH_OPT_FLAGS)
+    endif()
     set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
 
     set(VLLM_BUILD_TYPE ${CMAKE_BUILD_TYPE})
@@ -626,9 +672,9 @@ if (ENABLE_X86_ISA)
     message(STATUS "CPU extension (AVX512F) source files: ${VLLM_EXT_SRC_AVX512}")
     message(STATUS "CPU extension (AVX2) source files: ${VLLM_EXT_SRC_AVX2}")
 
-    set(_C_LIBS numa dnnl_ext)
-    set(_C_AVX512_LIBS numa dnnl_ext)
-    set(_C_AVX2_LIBS numa dnnl_ext)
+    set(_C_LIBS dnnl_ext)
+    set(_C_AVX512_LIBS dnnl_ext)
+    set(_C_AVX2_LIBS dnnl_ext)
 
     # AMX + AVX512F + AVX512BF16 + AVX512VNNI
     define_extension_target(
