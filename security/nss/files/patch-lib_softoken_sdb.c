--- lib/softoken/sdb.c.orig	2010-05-03 12:43:00.000000000 +0000
+++ lib/softoken/sdb.c	2010-05-03 13:09:55.000000000 +0000
@@ -827,16 +827,8 @@
 	goto loser;
     }
 
-    getStr = sqlite3_mprintf("");
-    for (i=0; getStr && i < count; i++) {
-	if (i==0) {
-	    newStr = sqlite3_mprintf("a%x", template[i].type);
-	} else {
-	    newStr = sqlite3_mprintf("%s, a%x", getStr, template[i].type);
-	}
-	sqlite3_free(getStr);
-	getStr = newStr;
-    }
+  for (i=0; i < count; i++) {
+    getStr = sqlite3_mprintf("a%x", template[i].type);
 
     if (getStr == NULL) {
 	error = CKR_HOST_MEMORY;
@@ -852,6 +844,11 @@
     }
 
     sqlerr = sqlite3_prepare_v2(sqlDB, newStr, -1, &stmt, NULL);
+    if (sqlerr == SQLITE_ERROR) {
+	template[i].ulValueLen = -1;
+	error = CKR_ATTRIBUTE_TYPE_INVALID;
+	continue;
+    } else
     if (sqlerr != SQLITE_OK) { goto loser; }
     sqlerr = sqlite3_bind_int(stmt, 1, object_id);
     if (sqlerr != SQLITE_OK) { goto loser; }
@@ -861,17 +858,15 @@
 	    PR_Sleep(SDB_BUSY_RETRY_TIME);
 	}
 	if (sqlerr == SQLITE_ROW) {
-	    for (i=0; i < count; i++) {
-		int column = i;
 	    	int blobSize;
 	    	const char *blobData;
 
-	    	blobSize = sqlite3_column_bytes(stmt, column);
-		blobData = sqlite3_column_blob(stmt, column);
+	    	blobSize = sqlite3_column_bytes(stmt, 0);
+		blobData = sqlite3_column_blob(stmt, 0);
 		if (blobData == NULL) {
 		    template[i].ulValueLen = -1;
 		    error = CKR_ATTRIBUTE_TYPE_INVALID; 
-		    continue;
+		    break;
 		}
 		/* If the blob equals our explicit NULL value, then the 
 		 * attribute is a NULL. */
@@ -884,15 +879,18 @@
 		    if (template[i].ulValueLen < blobSize) {
 			template[i].ulValueLen = -1;
 		    	error = CKR_BUFFER_TOO_SMALL;
-			continue;
+			break;
 		    }
 	    	    PORT_Memcpy(template[i].pValue, blobData, blobSize);
 		}
 		template[i].ulValueLen = blobSize;
-	    }
 	    found = 1;
 	}
     } while (!sdb_done(sqlerr,&retry));
+    sqlite3_reset(stmt);
+    sqlite3_finalize(stmt);
+    stmt = NULL;
+  }
 
 loser:
     /* fix up the error if necessary */
