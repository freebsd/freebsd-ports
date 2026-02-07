--- dclib/core/cssl.cpp.orig	2020-09-10 07:59:41 UTC
+++ dclib/core/cssl.cpp
@@ -429,7 +429,7 @@ CString CSSL::EncryptData( CSSLObject * SSLObject, CSt
 	CString res;
 	CByteArray bain,baout;
 	int i,tmplen;
-	EVP_CIPHER_CTX ctx;
+	EVP_CIPHER_CTX *ctx;
 
 	// sanity check
 	if ( !SSLObject || (s.IsEmpty()) )
@@ -437,8 +437,9 @@ CString CSSL::EncryptData( CSSLObject * SSLObject, CSt
 		return res;
 	}
 	
-	EVP_CIPHER_CTX_init(&ctx);
-	EVP_EncryptInit(&ctx, EVP_bf_cbc(), SSLObject->m_remotekey, SSLObject->m_remoteiv);
+	ctx = EVP_CIPHER_CTX_new();
+	EVP_CIPHER_CTX_init(ctx);
+	EVP_EncryptInit(ctx, EVP_bf_cbc(), SSLObject->m_remotekey, SSLObject->m_remoteiv);
 
 	// init input array
 	bain.SetSize(2);
@@ -448,13 +449,13 @@ CString CSSL::EncryptData( CSSLObject * SSLObject, CSt
 	// init output array
 	// input size + cipher_block_size for EVP_EncryptUpdate
 	// plus cipher_block_size for EVP_EncryptFinal
-	baout.SetSize( bain.Size() + ( 2 * EVP_CIPHER_CTX_block_size(&ctx) ) );
+	baout.SetSize( bain.Size() + ( 2 * EVP_CIPHER_CTX_block_size(ctx) ) );
 	//printf("CSSL::EncryptData: wrong old size=%lu new size=%lu\n",bain.Size()*2,baout.Size());
 	i = baout.Size();
 
-	if ( EVP_EncryptUpdate(&ctx, baout.Data(), &i, bain.Data(), bain.Size() ) )
+	if ( EVP_EncryptUpdate(ctx, baout.Data(), &i, bain.Data(), bain.Size() ) )
 	{
-		if ( EVP_EncryptFinal(&ctx, baout.Data()+i, &tmplen) )
+		if ( EVP_EncryptFinal(ctx, baout.Data()+i, &tmplen) )
 		{
 			i+=tmplen;
 			bain.SetSize(0);
@@ -465,7 +466,7 @@ CString CSSL::EncryptData( CSSLObject * SSLObject, CSt
 		}
 	}
 
-	EVP_CIPHER_CTX_cleanup(&ctx);
+	EVP_CIPHER_CTX_free(ctx);
 
 	return res;
 }
@@ -476,7 +477,7 @@ CString CSSL::DecryptData( CSSLObject * SSLObject, CSt
 	CString res;
 	CByteArray bain,baout;
 	int i,tmplen;
-	EVP_CIPHER_CTX ctx;
+	EVP_CIPHER_CTX *ctx;
 
 	// sanity check
 	if ( !SSLObject || (s.IsEmpty()) )
@@ -484,22 +485,23 @@ CString CSSL::DecryptData( CSSLObject * SSLObject, CSt
 		return res;
 	}
 	
-	EVP_CIPHER_CTX_init(&ctx);
-	EVP_DecryptInit(&ctx, EVP_bf_cbc(), SSLObject->m_localkey, SSLObject->m_localiv);
+	ctx = EVP_CIPHER_CTX_new();
+	EVP_CIPHER_CTX_init(ctx);
+	EVP_DecryptInit(ctx, EVP_bf_cbc(), SSLObject->m_localkey, SSLObject->m_localiv);
 
 	bain.SetSize(0);
 	bain.Append(s.Data(),s.Length());
 
 	if ( CBase64::Decode(&baout,&bain) > 0 )
 	{
-		bain.SetSize( baout.Size() + ( 2 * EVP_CIPHER_CTX_block_size(&ctx) ) );
+		bain.SetSize( baout.Size() + ( 2 * EVP_CIPHER_CTX_block_size(ctx) ) );
 		//printf("CSSL::DecryptData: wrong old size=%lu new size=%lu\n",baout.Size()*2,bain.Size());
 		i = 0;
 
-		if ( EVP_DecryptUpdate(&ctx, bain.Data(), &i, baout.Data(), (int)baout.Size() ) )
+		if ( EVP_DecryptUpdate(ctx, bain.Data(), &i, baout.Data(), (int)baout.Size() ) )
 		{
 			tmplen = 0;
-			if ( EVP_DecryptFinal(&ctx, bain.Data()+i, &tmplen) )
+			if ( EVP_DecryptFinal(ctx, bain.Data()+i, &tmplen) )
 			{
 				i+=tmplen;
 				res.Set((const char*)bain.Data()+2,i-2);
@@ -507,7 +509,7 @@ CString CSSL::DecryptData( CSSLObject * SSLObject, CSt
 		}
 	}
 
-	EVP_CIPHER_CTX_cleanup(&ctx);
+	EVP_CIPHER_CTX_free(ctx);
 
 	return res;
 }
