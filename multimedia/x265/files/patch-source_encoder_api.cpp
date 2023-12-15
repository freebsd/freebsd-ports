In svt-hevc 1.5.0, they payload-array (1024 bytes) is part of the structure,
rather than a pointer to be allocated separately.

This patch should allow compiling x265 against both older (1.4.x) and 1.5.x
versions of the dependency.

See https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=248479

	-mi

--- source/encoder/api.cpp.orig	2023-06-27 14:11:49 UTC
+++ source/encoder/api.cpp
@@ -449,14 +449,18 @@ int x265_encoder_encode(x265_encoder *enc, x265_nal **
 
                 if (pic_in->rpu.payloadSize)
                 {
+#if ! SVT_CHECK_VERSION(1, 5, 0)
                     inputData->dolbyVisionRpu.payload = X265_MALLOC(uint8_t, 1024);
+#endif
                     memcpy(inputData->dolbyVisionRpu.payload, pic_in->rpu.payload, pic_in->rpu.payloadSize);
                     inputData->dolbyVisionRpu.payloadSize = pic_in->rpu.payloadSize;
                     inputData->dolbyVisionRpu.payloadType = NAL_UNIT_UNSPECIFIED;
                 }
                 else
                 {
+#if ! SVT_CHECK_VERSION(1, 5, 0)
                     inputData->dolbyVisionRpu.payload = NULL;
+#endif
                     inputData->dolbyVisionRpu.payloadSize = 0;
                 }
 
@@ -702,7 +706,9 @@ void x265_encoder_close(x265_encoder *enc)
 
             svt_print_summary(enc);
             EB_H265_ENC_INPUT *inputData = (EB_H265_ENC_INPUT*)encoder->m_svtAppData->inputPictureBuffer->pBuffer;
+#if ! SVT_CHECK_VERSION(1, 5, 0)
             if (inputData->dolbyVisionRpu.payload) X265_FREE(inputData->dolbyVisionRpu.payload);
+#endif
 
             X265_FREE(inputData);
             X265_FREE(encoder->m_svtAppData->inputPictureBuffer);
@@ -2063,7 +2069,9 @@ int svt_initialise_input_buffer(x265_encoder *enc)
     inputPtr->pBuffer = (unsigned char*)x265_malloc(sizeof(EB_H265_ENC_INPUT));
 
     EB_H265_ENC_INPUT *inputData = (EB_H265_ENC_INPUT*)inputPtr->pBuffer;
+#if ! SVT_CHECK_VERSION(1, 5, 0)
     inputData->dolbyVisionRpu.payload = NULL;
+#endif
     inputData->dolbyVisionRpu.payloadSize = 0;
 
 
