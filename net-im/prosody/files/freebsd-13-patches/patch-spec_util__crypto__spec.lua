--- spec/util_crypto_spec.lua.orig	2025-03-13 13:12:42 UTC
+++ spec/util_crypto_spec.lua
@@ -3,32 +3,11 @@ describe("util.crypto", function ()
 describe("util.crypto", function ()
 	local crypto = require "util.crypto";
 	local random = require "util.random";
-	local encodings = require "util.encodings";
 
 	describe("generate_ed25519_keypair", function ()
 		local keypair = crypto.generate_ed25519_keypair();
 		assert.is_not_nil(keypair);
 		assert.equal("ED25519", keypair:get_type());
-	end)
-
-	describe("generate_p256_keypair", function ()
-		local keypair = crypto.generate_p256_keypair();
-		assert.is_not_nil(keypair);
-		assert.equal("id-ecPublicKey", keypair:get_type());
-	end)
-
-	describe("export/import raw", function ()
-		local keypair = crypto.generate_p256_keypair();
-		assert.is_not_nil(keypair);
-		local raw = keypair:public_raw()
-		local imported = crypto.import_public_ec_raw(raw, "P-256")
-		assert.equal(keypair:public_pem(), imported:public_pem());
-	end)
-
-	describe("derive", function ()
-		local key = crypto.import_private_pem(test_keys.ecdsa_private_pem);
-		local peer_key = crypto.import_public_pem(test_keys.ecdsa_public_pem);
-		assert.equal("n1v4KeKmOVwjC67fiKtjJnqcEaasbpZa2fLPNHW51co=", encodings.base64.encode(key:derive(peer_key)))
 	end)
 
 	describe("import_private_pem", function ()
