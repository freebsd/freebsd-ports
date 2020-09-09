--- dkimverify.h.orig	2008-09-15 00:22:00 UTC
+++ dkimverify.h
@@ -83,8 +83,8 @@ class SignatureInfo (public)
 	unsigned VerifiedBodyCount;
 	unsigned UnverifiedBodyCount;
 
-	EVP_MD_CTX m_Hdr_ctx;
-	EVP_MD_CTX m_Bdy_ctx;
+	EVP_MD_CTX *m_Hdr_ctx;
+	EVP_MD_CTX *m_Bdy_ctx;
 	SelectorInfo *m_pSelector;
 
 	int Status;
