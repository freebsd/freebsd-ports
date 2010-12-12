--- saferpay/jMessageObject.h.orig	2008-12-19 13:17:21.000000000 +0100
+++ saferpay/jMessageObject.h	2008-12-19 13:16:20.000000000 +0100
@@ -52,7 +52,7 @@
  * Method:    nExecute
  * Signature: ()I;
  */
+JNIEXPORT jlong JNICALL Java_soplex_saferpay_MessageObject_nExecute
-JNIEXPORT jint JNICALL Java_soplex_saferpay_MessageObject_nExecute
   (JNIEnv *, jobject);
 
 /*

