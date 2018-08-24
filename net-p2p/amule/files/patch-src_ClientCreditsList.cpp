From 27c13f3e622b8a3eaaa05bb62b0149604bdcc9e8 Mon Sep 17 00:00:00 2001
From: Tommy Jerry Mairo <tommy.mairo@gmail.com>
Date: Wed, 21 Mar 2018 19:56:28 +0100
Subject: [PATCH] Bugfix: API mismatch with crypto++ 6.0.0

--- src/ClientCreditsList.cpp.orig	2016-09-16 07:55:06 UTC
+++ src/ClientCreditsList.cpp
@@ -312,7 +312,7 @@ void CClientCreditsList::InitalizeCrypting()
 		// calculate and store public key
 		CryptoPP::RSASSA_PKCS1v15_SHA_Verifier pubkey(*static_cast<CryptoPP::RSASSA_PKCS1v15_SHA_Signer *>(m_pSignkey));
 		CryptoPP::ArraySink asink(m_abyMyPublicKey, 80);
-		pubkey.DEREncode(asink);
+		pubkey.GetMaterial().Save(asink);
 		m_nMyPublicKeyLen = asink.TotalPutLength();
 		asink.MessageEnd();
 	} catch (const CryptoPP::Exception& e) {
