--- lib/softoken/sftkdb.c.orig	2010-05-18 16:12:16.000000000 +0200
+++ lib/softoken/sftkdb.c	2010-05-18 16:14:37.000000000 +0200
@@ -766,6 +766,11 @@
 	if (attr == NULL) {
 	    return CKR_TEMPLATE_INCOMPLETE;
 	}
+	if (attr->ulValueLen == 0) {
+	    /* key is to generic to determine that it's unique, usually
+	     * happens in the key gen case */
+	    return CKR_OBJECT_HANDLE_INVALID;
+	}
 	findTemplate[1] = *attr;
 	count = 2;
 	break;
@@ -827,6 +832,11 @@
     }
     crv = sftkdb_getFindTemplate(objectType, objTypeData,
 			findTemplate, &count, ptemplate, len);
+    if (crv == CKR_OBJECT_HANDLE_INVALID) {
+	/* key is to generic to determine that it's unique, usually
+         * happens in the key gen case, go ahead and just create it */
+	return CKR_OK;
+    }
     if (crv != CKR_OK) {
 	return crv;
     }
