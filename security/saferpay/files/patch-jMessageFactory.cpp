--- saferpay/jMessageFactory.cpp.orig	2008-12-19 13:15:19.000000000 +0100
+++ saferpay/jMessageFactory.cpp	2008-12-19 13:13:40.000000000 +0100
@@ -29,7 +29,7 @@
 		IDPJNI_THROW1("MessageFactory::Construct(): m_Handle != 0", IDP_E_UNEXPECTED)
 		return;
 	}
+	env->SetIntField(obj, fid, (jlong)CreateMessageFactory());
-	env->SetIntField(obj, fid, (jint)CreateMessageFactory());
 }
 
 JNIEXPORT void JNICALL Java_soplex_saferpay_MessageFactory_nDestruct
@@ -40,7 +40,7 @@
 	DestroyMessageFactory(p);
 }
 
+JNIEXPORT jlong JNICALL Java_soplex_saferpay_MessageFactory_nVerifyPayConfirm
-JNIEXPORT jint JNICALL Java_soplex_saferpay_MessageFactory_nVerifyPayConfirm
   (JNIEnv *env, jobject obj, jstring Data, jstring Signature)
 {
 	IDPCIMPL_MessageFactory *p = 0;
@@ -53,7 +53,7 @@
 
 	try
 	{
+		jlong r = (jlong)p->VerifyPayConfirm(mbstoSTRING(pszData), mbstoSTRING(pszSignature));
-		jint r = (jint)p->VerifyPayConfirm(mbstoSTRING(pszData), mbstoSTRING(pszSignature));
 		env->ReleaseStringUTFChars(Data, pszData);
 		env->ReleaseStringUTFChars(Signature, pszSignature);
 		return r;
@@ -104,7 +104,7 @@
 	env->ReleaseStringUTFChars(Path, pszPath);
 }
 
+JNIEXPORT jlong JNICALL Java_soplex_saferpay_MessageFactory_nCreatePayInit
-JNIEXPORT jint JNICALL Java_soplex_saferpay_MessageFactory_nCreatePayInit
   (JNIEnv *env, jobject obj)
 {
 	IDPCIMPL_MessageFactory *p = 0;
@@ -114,7 +114,7 @@
 
 	try
 	{
+		return (jlong)p->CreatePayInit();
-		return (jint)p->CreatePayInit();
 	}
 	catch(IDP_Exception e)
 	{
@@ -132,7 +132,7 @@
 	}
 }
 
+JNIEXPORT jlong JNICALL Java_soplex_saferpay_MessageFactory_nCreatePayComplete
-JNIEXPORT jint JNICALL Java_soplex_saferpay_MessageFactory_nCreatePayComplete
   (JNIEnv *env, jobject obj, jstring Id, jstring Token)
 {
 	IDPCIMPL_MessageFactory *p = 0;
@@ -145,7 +145,7 @@
 
 	try
 	{
+		jlong r = (jlong)p->CreatePayComplete(mbstoSTRING(pszId), mbstoSTRING(pszToken));
-		jint r = (jint)p->CreatePayComplete(mbstoSTRING(pszId), mbstoSTRING(pszToken));
 		env->ReleaseStringUTFChars(Id, pszId);
 		env->ReleaseStringUTFChars(Token, pszToken);
 		return r;
@@ -168,7 +168,7 @@
 	}
 }
 
+JNIEXPORT jlong JNICALL Java_soplex_saferpay_MessageFactory_nCreateRequest
-JNIEXPORT jint JNICALL Java_soplex_saferpay_MessageFactory_nCreateRequest
   (JNIEnv *env, jobject obj, jstring MsgType)
 {
 	IDPCIMPL_MessageFactory *p = 0;
@@ -180,7 +180,7 @@
 
 	try
 	{
+		jlong r = (jlong)p->CreateRequest(mbstoSTRING(pszMsgType));
-		jint r = (jint)p->CreateRequest(mbstoSTRING(pszMsgType));
 		env->ReleaseStringUTFChars(MsgType, pszMsgType);
 		return r;
 	}
