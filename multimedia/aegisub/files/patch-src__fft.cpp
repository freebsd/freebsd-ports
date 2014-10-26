--- src/fft.cpp.orig
+++ src/fft.cpp
@@ -43,7 +43,7 @@
 
 void FFT::DoTransform (size_t n_samples,float *input,float *output_r,float *output_i,bool inverse) {
 	if (!IsPowerOfTwo(n_samples))
-		agi::InternalError(throw "FFT requires power of two input.");
+		throw agi::InternalError("FFT requires power of two input.");
 
 	// Inverse transform
 	float angle_num = 2.0f * 3.1415926535897932384626433832795f;
