--- saferpay/jMessageFactory.h.orig	2008-12-19 13:15:44.000000000 +0100
+++ saferpay/jMessageFactory.h	2008-12-19 13:13:46.000000000 +0100
@@ -12,7 +12,7 @@
  * Method:    nVerifyPayConfirm
  * Signature: (Ljava/lang/String;Ljava/lang/String;)I
  */
+JNIEXPORT jlong JNICALL Java_soplex_saferpay_MessageFactory_nVerifyPayConfirm
-JNIEXPORT jint JNICALL Java_soplex_saferpay_MessageFactory_nVerifyPayConfirm
   (JNIEnv *, jobject, jstring, jstring);
 
 /*
@@ -44,7 +44,7 @@
  * Method:    nCreatePayInit
  * Signature: ()I
  */
+JNIEXPORT jlong JNICALL Java_soplex_saferpay_MessageFactory_nCreatePayInit
-JNIEXPORT jint JNICALL Java_soplex_saferpay_MessageFactory_nCreatePayInit
   (JNIEnv *, jobject);
 
 /*
@@ -52,7 +52,7 @@
  * Method:    nCreatePayComplete
  * Signature: (Ljava/lang/String;Ljava/lang/String;)I
  */
+JNIEXPORT jlong JNICALL Java_soplex_saferpay_MessageFactory_nCreatePayComplete
-JNIEXPORT jint JNICALL Java_soplex_saferpay_MessageFactory_nCreatePayComplete
   (JNIEnv *, jobject, jstring Id, jstring Token);
 
 /*
@@ -60,7 +60,7 @@
  * Method:    nCreateRequest
  * Signature: (Ljava/lang/String;)I
  */
+JNIEXPORT jlong JNICALL Java_soplex_saferpay_MessageFactory_nCreateRequest
-JNIEXPORT jint JNICALL Java_soplex_saferpay_MessageFactory_nCreateRequest
   (JNIEnv *env, jobject obj, jstring MsgType);
 
 #ifdef __cplusplus
