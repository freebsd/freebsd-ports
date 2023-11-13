--- source/Lib/EncoderLib/EncAdaptiveLoopFilter.cpp.orig	2023-11-13 02:43:14 UTC
+++ source/Lib/EncoderLib/EncAdaptiveLoopFilter.cpp
@@ -6290,7 +6290,9 @@ void EncAdaptiveLoopFilter::getBlkStatsCcAlf(AlfCovari
 
   int effStride = recStride << getComponentScaleY(compID, m_chromaFormat);
 
+#if defined( TARGET_SIMD_X86 ) && ENABLE_SIMD_OPT_ALF
   const bool useSimd = read_x86_extension_flags() > SCALAR;
+#endif
 
   Pel ELocal[MAX_NUM_CC_ALF_CHROMA_COEFF][16];
   Pel yLocal[4][4];
