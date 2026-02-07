--- dkimsign.h.orig	2008-05-12 03:07:58 UTC
+++ dkimsign.h
@@ -60,13 +60,13 @@ class CDKIMSign : public CDKIMBase (protected)
 
 	int AssembleReturnedSig( char* szPrivKey );
 
-	EVP_MD_CTX m_Hdr_ietf_sha1ctx;		/* the header hash for ietf sha1  */
-	EVP_MD_CTX m_Hdr_ietf_sha256ctx;	/* the header hash for ietf sha256 */
+	EVP_MD_CTX *m_Hdr_ietf_sha1ctx;		/* the header hash for ietf sha1  */
+	EVP_MD_CTX *m_Hdr_ietf_sha256ctx;	/* the header hash for ietf sha256 */
 
-	EVP_MD_CTX m_Bdy_ietf_sha1ctx;		/* the body hash for ietf sha1  */
-	EVP_MD_CTX m_Bdy_ietf_sha256ctx;	/* the body hash for ietf sha256 */
+	EVP_MD_CTX *m_Bdy_ietf_sha1ctx;		/* the body hash for ietf sha1  */
+	EVP_MD_CTX *m_Bdy_ietf_sha256ctx;	/* the body hash for ietf sha256 */
 
-	EVP_MD_CTX m_allman_sha1ctx;		/* the hash for allman sha1  */
+	EVP_MD_CTX *m_allman_sha1ctx;		/* the hash for allman sha1  */
 
 	int m_Canon;				// canonization method
 
