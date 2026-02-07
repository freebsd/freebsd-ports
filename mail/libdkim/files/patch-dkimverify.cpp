--- dkimverify.cpp.orig	2020-09-09 02:39:20 UTC
+++ dkimverify.cpp
@@ -43,8 +43,10 @@ SignatureInfo::SignatureInfo(bool s)
 {
 	VerifiedBodyCount = 0;
 	UnverifiedBodyCount = 0;
-	EVP_MD_CTX_init( &m_Hdr_ctx );
-	EVP_MD_CTX_init( &m_Bdy_ctx );
+	m_Hdr_ctx = EVP_MD_CTX_create();
+	m_Bdy_ctx = EVP_MD_CTX_create();
+	EVP_MD_CTX_init( m_Hdr_ctx );
+	EVP_MD_CTX_init( m_Bdy_ctx );
 	m_pSelector = NULL;
 	Status = DKIM_SUCCESS;
 	m_nHash = 0;
@@ -54,8 +56,8 @@ SignatureInfo::SignatureInfo(bool s)
 
 SignatureInfo::~SignatureInfo()
 {
-	EVP_MD_CTX_cleanup( &m_Hdr_ctx );
-	EVP_MD_CTX_cleanup( &m_Bdy_ctx );
+	EVP_MD_CTX_destroy( m_Hdr_ctx );
+	EVP_MD_CTX_destroy( m_Bdy_ctx );
 }
 
 
@@ -459,7 +461,7 @@ int CDKIMVerify::GetResults(void)
 				unsigned char md[EVP_MAX_MD_SIZE];
 				unsigned len = 0;
 
-				int res = EVP_DigestFinal( &i->m_Bdy_ctx, md, &len);
+				int res = EVP_DigestFinal( i->m_Bdy_ctx, md, &len);
 
 				if (!res || len != i->BodyHashData.length() || memcmp(i->BodyHashData.data(), md, len) != 0)
 				{
@@ -515,7 +517,7 @@ int CDKIMVerify::GetResults(void)
 
 			assert( i->m_pSelector != NULL );
 
-			int res = EVP_VerifyFinal( &i->m_Hdr_ctx, (unsigned char *) i->SignatureData.data(), i->SignatureData.length(), i->m_pSelector->PublicKey);
+			int res = EVP_VerifyFinal( i->m_Hdr_ctx, (unsigned char *) i->SignatureData.data(), i->SignatureData.length(), i->m_pSelector->PublicKey);
 
 			if (res == 1)
 			{
@@ -658,11 +660,11 @@ void SignatureInfo::Hash( const char* szBuffer, unsign
 
 	if (IsBody && !BodyHashData.empty())
 	{
-		EVP_DigestUpdate( &m_Bdy_ctx, szBuffer, nBufLength );
+		EVP_DigestUpdate( m_Bdy_ctx, szBuffer, nBufLength );
 	}
 	else
 	{
-		EVP_VerifyUpdate( &m_Hdr_ctx, szBuffer, nBufLength );
+		EVP_VerifyUpdate( m_Hdr_ctx, szBuffer, nBufLength );
 	}
 
 	if (m_SaveCanonicalizedData)
@@ -741,13 +743,13 @@ int CDKIMVerify::ProcessHeaders(void)
 		// initialize the hashes
 		if (sig.m_nHash == DKIM_HASH_SHA256)
 		{
-			EVP_VerifyInit( &sig.m_Hdr_ctx, EVP_sha256() );
-			EVP_DigestInit( &sig.m_Bdy_ctx, EVP_sha256() );
+			EVP_VerifyInit( sig.m_Hdr_ctx, EVP_sha256() );
+			EVP_DigestInit( sig.m_Bdy_ctx, EVP_sha256() );
 		}
 		else
 		{
-			EVP_VerifyInit( &sig.m_Hdr_ctx, EVP_sha1() );
-			EVP_DigestInit( &sig.m_Bdy_ctx, EVP_sha1() );
+			EVP_VerifyInit( sig.m_Hdr_ctx, EVP_sha1() );
+			EVP_DigestInit( sig.m_Bdy_ctx, EVP_sha1() );
 		}
 
 		// compute the hash of the header
@@ -1337,7 +1339,7 @@ int SelectorInfo::Parse( char* Buffer )
 			return DKIM_SELECTOR_PUBLIC_KEY_INVALID;
 
 		// make sure public key is the correct type (we only support rsa)
-		if (pkey->type == EVP_PKEY_RSA || pkey->type == EVP_PKEY_RSA2)
+		if (EVP_PKEY_id(pkey) == EVP_PKEY_RSA || EVP_PKEY_id(pkey) == EVP_PKEY_RSA2)
 		{
 			PublicKey = pkey;
 		}
