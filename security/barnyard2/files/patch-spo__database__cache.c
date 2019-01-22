--- src/output-plugins/spo_database_cache.c.orig	2018-10-06 12:40:44 UTC
+++ src/output-plugins/spo_database_cache.c
@@ -146,7 +146,7 @@ u_int32_t inserted_sigref_object_count =
  */
 u_int32_t cacheSignatureReferenceLookup(dbSignatureReferenceObj *iLookup,cacheSignatureReferenceObj *iHead)
 {
-    if( (iLookup == NULL))
+    if (iLookup == NULL)
     {
         /* XXX */
         FatalError("database [%s()], Called with dbReferenceSignatureObj[0x%x] cacheSignatureReferenceObj [0x%x] \n",
@@ -224,7 +224,7 @@ u_int32_t cacheEventSignatureLookup(cach
 u_int32_t cacheSignatureLookup(dbSignatureObj *iLookup,cacheSignatureObj *iHead)
 {
     
-    if( (iLookup == NULL))
+    if (iLookup == NULL)
     {
         /* XXX */
         FatalError("database [%s()], Called with dbSignatureObj[0x%x] cacheSignatureObj [0x%x] \n",
@@ -266,7 +266,7 @@ u_int32_t cacheSignatureLookup(dbSignatu
 cacheSignatureObj * cacheSignatureGetObject(dbSignatureObj *iLookup,cacheSignatureObj *iHead)
 {
 
-    if( (iLookup == NULL))
+    if (iLookup == NULL)
     {
         /* XXX */
         FatalError("database [%s()], Called with dbSignatureObj[0x%x] cacheSignatureObj [0x%x] \n",
@@ -325,7 +325,7 @@ u_int32_t cacheEventClassificationLookup
  */
 u_int32_t cacheClassificationLookup(dbClassificationObj *iLookup,cacheClassificationObj *iHead)
 {
-    if( (iLookup == NULL))
+    if (iLookup == NULL)
     {
 	/* XXX */
         FatalError("database [%s()], Called with dbClassiciationObj[0x%x] cacheClassificationObj [0x%x] \n",
@@ -510,7 +510,7 @@ u_int32_t dbSignatureReferenceLookup(dbS
  */
 u_int32_t dbReferenceLookup(dbReferenceObj *iLookup,cacheReferenceObj *iHead)
 {
-    if( (iLookup == NULL))
+    if (iLookup == NULL)
     {
         /* XXX */
         FatalError("database [%s()], Called with dbReferenceObj[0x%x] cacheReferenceObj [0x%x] \n",
@@ -561,7 +561,7 @@ u_int32_t dbReferenceLookup(dbReferenceO
  */
 u_int32_t dbSystemLookup(dbSystemObj *iLookup,cacheSystemObj *iHead)
 {
-    if( (iLookup == NULL))
+    if (iLookup == NULL)
     {
         /* XXX */
         FatalError("database [%s()], Called with dbSystemObj[0x%x] cacheSystemObj [0x%x] \n",
@@ -615,7 +615,7 @@ u_int32_t dbSystemLookup(dbSystemObj *iL
 u_int32_t dbSignatureLookup(dbSignatureObj *iLookup,cacheSignatureObj *iHead)
 {
     
-    if( (iLookup == NULL))
+    if (iLookup == NULL)
     {
         /* XXX */
         FatalError("database [%s()], Called with dbSignatureObj[0x%x] cacheSignatureObj [0x%x] \n",
@@ -702,7 +702,7 @@ u_int32_t dbSignatureLookup(dbSignatureO
  */
 u_int32_t dbClassificationLookup(dbClassificationObj *iLookup,cacheClassificationObj *iHead)
 {
-    if( (iLookup == NULL))
+    if (iLookup == NULL)
     {
         /* XXX */
         FatalError("database [%s()], Called with dbReferenceObj[0x%x] cacheClassificationObj [0x%x] \n",
@@ -5206,7 +5206,7 @@ u_int32_t SignatureReferenceCacheUpdateD
 	return 1;
     }
     
-    if( (iDBList == NULL))
+    if (iDBList == NULL)
     {
 	/* XXX */
 	/* No reference */
@@ -5410,7 +5410,7 @@ u_int32_t SignatureReferencePopulateData
 {
     u_int32_t row_validate = 0;
 
-    if( (data == NULL))
+    if (data == NULL)
     {
         /* XXX */
         return 1;
