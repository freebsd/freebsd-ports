--- security/manager/ssl/src/nsKeygenHandler.cpp.orig	2005-07-20 21:31:22.000000000 +0200
+++ security/manager/ssl/src/nsKeygenHandler.cpp	2008-02-02 00:08:05.000000000 +0100
@@ -70,16 +70,25 @@
 
 //All possible key size choices.
 static SECKeySizeChoiceInfo SECKeySizeChoiceList[] = {
     { nsnull, 2048 },
     { nsnull, 1024 },
     { nsnull, 0 }, 
 };
 
+DERTemplate SECAlgorithmIDTemplate[] = {
+    { DER_SEQUENCE,
+	  0, NULL, sizeof(SECAlgorithmID) },
+    { DER_OBJECT_ID,
+	  offsetof(SECAlgorithmID,algorithm), },
+    { DER_OPTIONAL | DER_ANY,
+	  offsetof(SECAlgorithmID,parameters), },
+    { 0, }
+};
 
 DERTemplate CERTSubjectPublicKeyInfoTemplate[] = {
     { DER_SEQUENCE,
           0, nsnull, sizeof(CERTSubjectPublicKeyInfo) },
     { DER_INLINE,
           offsetof(CERTSubjectPublicKeyInfo,algorithm),
           SECAlgorithmIDTemplate, },
     { DER_BIT_STRING,
@@ -90,26 +99,16 @@
 DERTemplate CERTPublicKeyAndChallengeTemplate[] =
 {
     { DER_SEQUENCE, 0, nsnull, sizeof(CERTPublicKeyAndChallenge) },
     { DER_ANY, offsetof(CERTPublicKeyAndChallenge,spki), },
     { DER_IA5_STRING, offsetof(CERTPublicKeyAndChallenge,challenge), },
     { 0, }
 };
 
-DERTemplate SECAlgorithmIDTemplate[] = {
-    { DER_SEQUENCE,
-	  0, NULL, sizeof(SECAlgorithmID) },
-    { DER_OBJECT_ID,
-	  offsetof(SECAlgorithmID,algorithm), },
-    { DER_OPTIONAL | DER_ANY,
-	  offsetof(SECAlgorithmID,parameters), },
-    { 0, }
-};
-
 const SEC_ASN1Template SECKEY_PQGParamsTemplate[] = {
     { SEC_ASN1_SEQUENCE, 0, NULL, sizeof(PQGParams) },
     { SEC_ASN1_INTEGER, offsetof(PQGParams,prime) },
     { SEC_ASN1_INTEGER, offsetof(PQGParams,subPrime) },
     { SEC_ASN1_INTEGER, offsetof(PQGParams,base) },
     { 0, }
 };
 
