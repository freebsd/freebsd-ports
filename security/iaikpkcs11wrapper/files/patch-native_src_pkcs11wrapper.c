--- ../../common/pkcs11wrapper.c.orig	2016-06-20 15:16:34 UTC
+++ ../../common/pkcs11wrapper.c
@@ -1258,6 +1258,7 @@ JNIEXPORT void JNICALL Java_iaik_pkcs_pk
 	jobject jAttribute;
 	CK_RV rv;
 	CK_ULONG error = 0;
+	CK_BBOOL array = FALSE;
   ModuleData *moduleData;
   CK_FUNCTION_LIST_PTR ckpFunctions;
 
@@ -1328,9 +1329,11 @@ JNIEXPORT void JNICALL Java_iaik_pkcs_pk
 			for (j=0; j<length; j++){
 				ckAttributeArray[j].pValue = NULL_PTR;
 			}
+			array = TRUE;
 		}
 	}
 
+	if (array == TRUE) {
 	// get ulValueLen of the attributes of a CKF_ARRAY_ATTRIBUTE if present
 	rv = (*ckpFunctions->C_GetAttributeValue)(ckSessionHandle, ckObjectHandle, ckpAttributes, ckAttributesLength);
 	if(ckAssertReturnValueOK(env, rv, __FUNCTION__) != CK_ASSERT_OK) {
@@ -1343,6 +1346,7 @@ JNIEXPORT void JNICALL Java_iaik_pkcs_pk
 	  TRACE0(tag_call, __FUNCTION__, "exiting ");
 		return ;
 	}
+	}
 
 	/* now, the ulValueLength field of each attribute should hold the exact buffer length needed
 	 * to allocate the needed buffers accordingly
@@ -4474,11 +4478,12 @@ int jCharArrayToCKUTF8CharArray(JNIEnv *
 	jpTemp = (jchar*) malloc((*ckpLength) * sizeof(jchar));
   if (jpTemp == NULL && (*ckpLength)!=0) { *ckpArray = NULL_PTR; throwOutOfMemoryError(env); return 1; }
 	(*env)->GetCharArrayRegion(env, jArray, 0, *ckpLength, jpTemp);
-	*ckpArray = (CK_UTF8CHAR_PTR) malloc (*ckpLength * sizeof(CK_UTF8CHAR));
+	*ckpArray = (CK_UTF8CHAR_PTR) malloc ((*ckpLength + 1) * sizeof(CK_UTF8CHAR));
   if (*ckpArray == NULL && (*ckpLength)!=0) { free(jpTemp); throwOutOfMemoryError(env); return 2; }
 	for (i=0; i<(*ckpLength); i++) {
 		(*ckpArray)[i] = jCharToCKUTF8Char(jpTemp[i]);
 	}
+	(*ckpArray)[*ckpLength] = NULL_PTR;
 	free(jpTemp);
   return 0;
 }
