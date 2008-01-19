--- ../../src/pkcs11wrapper.c.orig	2008-01-17 12:49:35.000000000 +0100
+++ ../../src/pkcs11wrapper.c	2008-01-17 12:53:51.000000000 +0100
@@ -3965,11 +3965,12 @@
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
