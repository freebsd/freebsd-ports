--- saferpay/jMessageObject.cpp.orig	2008-12-19 13:17:10.000000000 +0100
+++ saferpay/jMessageObject.cpp	2008-12-19 13:16:25.000000000 +0100
@@ -30,7 +30,7 @@
 		IDPJNI_THROW1("MessageObject::Construct(): m_Handle != 0", IDP_E_UNEXPECTED)
 		return;
 	}
+	env->SetIntField(obj, fid, (jlong)CreateMessageObject());
-	env->SetIntField(obj, fid, (jint)CreateMessageObject());
 }
 
 JNIEXPORT void JNICALL Java_soplex_saferpay_MessageObject_nDestruct
@@ -169,7 +169,7 @@
 	}
 }
 
+JNIEXPORT jlong JNICALL Java_soplex_saferpay_MessageObject_nExecute
-JNIEXPORT jint JNICALL Java_soplex_saferpay_MessageObject_nExecute
   (JNIEnv *env, jobject obj)
 {
 	IDPCIMPL_MessageObject *p;
@@ -178,7 +178,7 @@
 
 	try
 	{
+		return (jlong)p->Execute();
-		return (jint)p->Execute();
 	}
 	catch(IDP_Exception e)
 	{
