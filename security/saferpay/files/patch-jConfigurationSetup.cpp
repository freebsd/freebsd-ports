--- saferpay/jConfigurationSetup.cpp.orig	2008-12-19 13:13:09.000000000 +0100
+++ saferpay/jConfigurationSetup.cpp	2008-12-19 13:12:50.000000000 +0100
@@ -33,7 +33,7 @@
 			IDP_E_UNEXPECTED)
 		return;
 	}
+	env->SetIntField(obj, fid, (jlong)CreateConfigurationSetup());
-	env->SetIntField(obj, fid, (jint)CreateConfigurationSetup());
 }
 
 JNIEXPORT void JNICALL Java_soplex_saferpay_ConfigurationSetup_nDestruct
