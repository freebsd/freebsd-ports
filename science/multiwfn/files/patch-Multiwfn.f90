--- Multiwfn.f90.orig	2023-06-04 15:49:52 UTC
+++ Multiwfn.f90
@@ -13,7 +13,7 @@ real*8 tmpv1(3),tmpv2(3)
 
 !Special treatment for Intel compiler
 #if defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER)
-call kmp_set_warnings_off() !In rare case, "Cannot open message catalog "1041\libiomp5ui.dll"" may occurs, this calling avoid this problem, or user should set KMP_WARNINGS environment variable to 0
+!call kmp_set_warnings_off() !In rare case, "Cannot open message catalog "1041\libiomp5ui.dll"" may occurs, this calling avoid this problem, or user should set KMP_WARNINGS environment variable to 0
 #endif
 
 !Try to get input file name from argument, which should be the first argument
@@ -49,12 +49,12 @@ nthreads,nowdate(1:4),nowdate(5:6),nowdate(7:8),nowtim
 !For Windows version of ifort, use KMP_SET_STACKSIZE_S() to directly set stacksize of OpenMP threads according to ompstacksize in settings.ini, &
 !for other cases, the stacksize is determined by OMP_STACKSIZE environment variable, and we check if it has been defined here
 if (isys==1) then !Windows
-#if defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER)
-    call KMP_SET_STACKSIZE_S(ompstacksize)
-#else
-    CALL getenv('OMP_STACKSIZE',c200tmp)
-    if (c200tmp==" ") write(*,"(/,a)") " Warning: You should set OMP_STACKSIZE environment variable in Windows system to define stacksize of OpenMP threads!"
-#endif
+!#if defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER)
+!    call KMP_SET_STACKSIZE_S(ompstacksize)
+!#else
+!    CALL getenv('OMP_STACKSIZE',c200tmp)
+!    if (c200tmp==" ") write(*,"(/,a)") " Warning: You should set OMP_STACKSIZE environment variable in Windows system to define stacksize of OpenMP threads!"
+!#endif
 else if (isys==2) then !Linux/MacOS
     CALL getenv('OMP_STACKSIZE',c200tmp)
 #if defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER)
@@ -67,9 +67,9 @@ end if
 !write(*,"(' OpenMP stacksize for each thread: ',f10.2,' MB')") dfloat(KMP_GET_STACKSIZE_S())/1024/1024
 
 !Set number of cores used by calculation of MKL library (e.g. function matmul_blas)
-#if defined(INTEL_MKL)
-call mkl_set_num_threads(nthreads)
-#endif
+!#if defined(INTEL_MKL)
+!call mkl_set_num_threads(nthreads)
+!#endif
 
 
 !!-------- Load input file
@@ -791,4 +791,4 @@ do while(.true.) !Main loop
     
 end do !End main cycle
 
-end program
\ No newline at end of file
+end program
