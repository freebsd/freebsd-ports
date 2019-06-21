--- src/library/blas/xgemm.cc.orig	2016-01-05 17:04:55 UTC
+++ src/library/blas/xgemm.cc
@@ -75,19 +75,19 @@ bool isZero(Precision value);
 template<>
 bool isZero<float>( float value ) {
   return value == 0;
-};
+}
 template<>
 bool isZero<double>( double value ) {
   return value == 0;
-};
+}
 template<>
 bool isZero<FloatComplex>( FloatComplex value ) {
   return CREAL(value) == 0 && CIMAG(value) == 0;
-};
+}
 template<>
 bool isZero<DoubleComplex>( DoubleComplex value ) {
   return CREAL(value) == 0 && CIMAG(value) == 0;
-};
+}
 
 static char *getKernelName(cl_kernel clKernel)
 {
@@ -534,7 +534,7 @@ clblasGemm(
   if (needRowKernel)    makeGemmKernel(   rowClKernel, commandQueues[0],    rowKernelSource, sourceBuildOptions,    &rowKernelBinary,    rowKernelBinarySize, binaryBuildOptions);
   if (needColKernel)    makeGemmKernel(   colClKernel, commandQueues[0],    colKernelSource, sourceBuildOptions,    &colKernelBinary,    colKernelBinarySize, binaryBuildOptions);
   if (needCornerKernel) makeGemmKernel(cornerClKernel, commandQueues[0], cornerKernelSource, sourceBuildOptions, &cornerKernelBinary, cornerKernelBinarySize, binaryBuildOptions);
-  const size_t localWorkSize[2] = { workGroupNumRows, workGroupNumCols };
+  const size_t localWorkSize[2] = { workGroupNumRows, workGroupNumCols };;
   unsigned int numKernelsEnqueued = 0;
 
 /******************************************************************************
