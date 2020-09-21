In svt-hevc 1.5.0, they payload-array (1024 bytes) is part of the structure,
rather than a pointer to be allocated separately.

This patch should allow compiling x265 against both older (1.4.x) and 1.5.x
versions of the dependency.

See https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=248479

	-mi

--- source/encoder/api.cpp	2020-05-29 13:39:35.000000000 -0400
+++ source/encoder/api.cpp	2020-08-06 22:51:30.227635000 -0400
@@ -451,5 +451,7 @@
                 if (pic_in->rpu.payloadSize)
                 {
+#if ! SVT_CHECK_VERSION(1, 5, 0)
                     inputData->dolbyVisionRpu.payload = X265_MALLOC(uint8_t, 1024);
+#endif
                     memcpy(inputData->dolbyVisionRpu.payload, pic_in->rpu.payload, pic_in->rpu.payloadSize);
                     inputData->dolbyVisionRpu.payloadSize = pic_in->rpu.payloadSize;
@@ -458,5 +460,7 @@
                 else
                 {
+#if ! SVT_CHECK_VERSION(1, 5, 0)
                     inputData->dolbyVisionRpu.payload = NULL;
+#endif
                     inputData->dolbyVisionRpu.payloadSize = 0;
                 }
@@ -696,5 +700,7 @@
             svt_print_summary(enc);
             EB_H265_ENC_INPUT *inputData = (EB_H265_ENC_INPUT*)encoder->m_svtAppData->inputPictureBuffer->pBuffer;
+#if ! SVT_CHECK_VERSION(1, 5, 0)
             if (inputData->dolbyVisionRpu.payload) X265_FREE(inputData->dolbyVisionRpu.payload);
+#endif
 
             X265_FREE(inputData);
@@ -2052,5 +2058,7 @@
 
     EB_H265_ENC_INPUT *inputData = (EB_H265_ENC_INPUT*)inputPtr->pBuffer;
+#if ! SVT_CHECK_VERSION(1, 5, 0)
     inputData->dolbyVisionRpu.payload = NULL;
+#endif
     inputData->dolbyVisionRpu.payloadSize = 0;
 
