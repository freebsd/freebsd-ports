--- lib/softoken/sftkdb.c.orig	2010-06-24 13:58:26.000000000 +0200
+++ lib/softoken/sftkdb.c	2010-06-24 13:58:37.000000000 +0200
@@ -509,18 +509,23 @@
 		  CK_ULONG count)
 {
     int i;
+    CK_RV crv;
     SFTKDBHandle *keyHandle = handle;
     SDB *keyTarget = NULL;
+    PRBool usingPeerDB = PR_FALSE;
+    PRBool inPeerDBTransaction = PR_FALSE;
 
     PORT_Assert(handle);
 
     if (handle->type != SFTK_KEYDB_TYPE) {
 	keyHandle = handle->peerDB;
+	usingPeerDB = PR_TRUE;
     }
 
     /* no key DB defined? then no need to sign anything */
     if (keyHandle == NULL) {
-	return CKR_OK;
+	crv = CKR_OK;
+	goto loser;
     }
 
     /* When we are in a middle of an update, we have an update database set, 
@@ -532,7 +537,17 @@
 
     /* skip the the database does not support meta data */
     if ((keyTarget->sdb_flags & SDB_HAS_META) == 0) {
-	return CKR_OK;
+	crv = CKR_OK;
+	goto loser;
+    }
+
+    /* If we had to switch databases, we need to initialize a transaction. */
+    if (usingPeerDB) {
+	crv = (*keyTarget->sdb_Begin)(keyTarget);
+	if (crv != CKR_OK) {
+	    goto loser;
+	}
+	inPeerDBTransaction = PR_TRUE;
     }
 
     for (i=0; i < count; i ++) {
@@ -546,23 +561,44 @@
 	    PZ_Lock(keyHandle->passwordLock);
 	    if (keyHandle->passwordKey.data == NULL) {
 		PZ_Unlock(keyHandle->passwordLock);
-		return CKR_USER_NOT_LOGGED_IN;
+		crv = CKR_USER_NOT_LOGGED_IN;
+		goto loser;
 	    }
 	    rv = sftkdb_SignAttribute(arena, &keyHandle->passwordKey, 
 				objectID, template[i].type,
 				&plainText, &signText);
 	    PZ_Unlock(keyHandle->passwordLock);
 	    if (rv != SECSuccess) {
-		return CKR_GENERAL_ERROR; /* better error code here? */
+		crv = CKR_GENERAL_ERROR; /* better error code here? */
+		goto loser;
 	    }
 	    rv = sftkdb_PutAttributeSignature(handle, keyTarget, 
 				objectID, template[i].type, signText);
 	    if (rv != SECSuccess) {
-		return CKR_GENERAL_ERROR; /* better error code here? */
+		crv = CKR_GENERAL_ERROR; /* better error code here? */
+		goto loser;
 	    }
 	}
     }
-    return CKR_OK;
+    crv = CKR_OK;
+
+    /* If necessary, commit the transaction */
+    if (inPeerDBTransaction) {
+	crv = (*keyTarget->sdb_Commit)(keyTarget);
+	if (crv != CKR_OK) {
+	    goto loser;
+	}
+	inPeerDBTransaction = PR_FALSE;
+    }
+
+loser:
+    if (inPeerDBTransaction) {
+	/* The transaction must have failed. Abort. */
+	(*keyTarget->sdb_Abort)(keyTarget);
+	PORT_Assert(crv != CKR_OK);
+	if (crv == CKR_OK) crv = CKR_GENERAL_ERROR;
+    }
+    return crv;
 }
 
 static CK_RV
@@ -766,6 +802,11 @@
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
@@ -827,6 +868,11 @@
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
