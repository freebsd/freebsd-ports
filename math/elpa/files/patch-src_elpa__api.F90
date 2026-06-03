--- src/elpa_api.F90.orig	2025-02-07 12:00:51 UTC
+++ src/elpa_api.F90
@@ -1122,7 +1122,7 @@ module elpa_api
     !c> // /src/elpa_api.F90    
     !c> int elpa_init(int api_version);
     function elpa_init(api_version) result(error) bind(C, name="elpa_init")
-      use elpa_utilities, only : error_unit
+      use, intrinsic :: iso_fortran_env, only : error_unit
       use, intrinsic :: iso_c_binding
       integer(kind=c_int), intent(in), value :: api_version
       integer(kind=c_int)                    :: error
@@ -1194,10 +1194,18 @@ module elpa_api
     !c_no> #endif
 
     subroutine elpa_uninit(error)
+#ifdef WITH_NVIDIA_GPU_VERSION
       use cuda_functions
+#endif
+#ifdef WITH_AMD_GPU_VERSION
       use hip_functions
+#endif
+#ifdef WITH_OPENMP_OFFLOAD_GPU_VERSION
       use openmp_offload_functions
+#endif
+#ifdef WITH_SYCL_GPU_VERSION
       use sycl_functions
+#endif
       !use elpa_gpu, only : gpuDeviceArray, gpublasHandleArray, my_stream
       use elpa_omp
       implicit none
@@ -1293,7 +1301,7 @@ module elpa_api
     !> \param   error       integer, optional: error code, which can be queried with elpa_strerr()
     !> \result  string      string: the string representation
     function elpa_int_value_to_string(name, value, error) result(string)
-      use elpa_utilities, only : error_unit
+      use, intrinsic :: iso_fortran_env, only : error_unit
       implicit none
       character(kind=c_char, len=*), intent(in) :: name
       integer(kind=c_int), intent(in) :: value
@@ -1342,7 +1350,7 @@ module elpa_api
     !> \result  value       integer: the integer representation of the string
     function elpa_int_string_to_value(name, string, error) result(value)
       use elpa_generated_fortran_interfaces
-      use elpa_utilities, only : error_unit
+      use, intrinsic :: iso_fortran_env, only : error_unit
       implicit none
       character(kind=c_char, len=*), intent(in)         :: name
       character(kind=c_char, len=*), intent(in), target :: string
