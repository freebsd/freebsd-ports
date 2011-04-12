--- ../../src/pkcs11wrapper.c.orig	2008-07-24 12:20:36.000000000 +0200
+++ ../../src/pkcs11wrapper.c	2011-04-12 10:53:02.000000000 +0200
@@ -1134,6 +1134,7 @@
 	jobject jAttribute;
 	CK_RV rv;
 	CK_ULONG error = 0;
+	CK_BBOOL array = FALSE;
   ModuleData *moduleData;
   CK_FUNCTION_LIST_PTR ckpFunctions;
   moduleData = getModuleEntry(env, obj);
@@ -1188,9 +1189,11 @@
 			for (j=0; j<length; j++){
 				ckAttributeArray[j].pValue = NULL_PTR;
 			}
+			array = TRUE;
 		}
 	}
 
+	if (array == TRUE) {
 	// get ulValueLen of the attributes of a CKF_ARRAY_ATTRIBUTE if present
 	rv = (*ckpFunctions->C_GetAttributeValue)(ckSessionHandle, ckObjectHandle, ckpAttributes, ckAttributesLength);
 	if(ckAssertReturnValueOK(env, rv) != CK_ASSERT_OK) {
@@ -1202,6 +1205,7 @@
 		free(ckpAttributes);
 		return ;
 	}
+	}
 
 	/* now, the ulValueLength field of each attribute should hold the exact buffer length needed
 	 * to allocate the needed buffers accordingly
@@ -4111,11 +4115,12 @@
 	jpTemp = (jchar*) malloc((*ckpLength) * sizeof(jchar));
   if (jpTemp == NULL) { *ckpArray = NULL_PTR; throwOutOfMemoryError(env); return 1; }
 	(*env)->GetCharArrayRegion(env, jArray, 0, *ckpLength, jpTemp);
-	*ckpArray = (CK_UTF8CHAR_PTR) malloc (*ckpLength * sizeof(CK_UTF8CHAR));
+	*ckpArray = (CK_UTF8CHAR_PTR) malloc ((*ckpLength + 1) * sizeof(CK_UTF8CHAR));
   if (*ckpArray == NULL) { free(jpTemp); throwOutOfMemoryError(env); return 2; }
 	for (i=0; i<(*ckpLength); i++) {
 		(*ckpArray)[i] = jCharToCKUTF8Char(jpTemp[i]);
 	}
+	(*ckpArray)[*ckpLength] = NULL_PTR;
 	free(jpTemp);
   return 0;
 }
