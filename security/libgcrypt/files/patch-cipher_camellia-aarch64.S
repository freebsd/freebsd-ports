https://github.com/gpg/libgcrypt/commit/09c27280cc09798d15369b3a143036b7ab5ddd69


From 09c27280cc09798d15369b3a143036b7ab5ddd69 Mon Sep 17 00:00:00 2001
From: Jussi Kivilinna <jussi.kivilinna@iki.fi>
Date: Mon, 14 Jan 2019 22:14:24 +0200
Subject: [PATCH] camellia-aarch64: do not export look-up table globally

* cipher/camellia-aarch64.S (_gcry_camellia_arm_tables): Remove
'.globl' export.
--

Reported-by: Martin Husemann <martin@NetBSD.org>
GnuPG-bug-id: 4317
Signed-off-by: Jussi Kivilinna <jussi.kivilinna@iki.fi>
---
 cipher/camellia-aarch64.S | 1 -
 1 file changed, 1 deletion(-)

diff --git a/cipher/camellia-aarch64.S b/cipher/camellia-aarch64.S
index b0e9a033..5c6ab020 100644
--- cipher/camellia-aarch64.S.orig	2020-03-18 18:23:07.296876000 +0100
+++ cipher/camellia-aarch64.S	2020-03-18 18:23:17.378524000 +0100
@@ -284,7 +284,6 @@ _gcry_camellia_arm_decrypt_block:
 .size _gcry_camellia_arm_decrypt_block,.-_gcry_camellia_arm_decrypt_block;
 
 /* Encryption/Decryption tables */
-.globl _gcry_camellia_arm_tables
 .type  _gcry_camellia_arm_tables,@object;
 .balign 32
 _gcry_camellia_arm_tables:
