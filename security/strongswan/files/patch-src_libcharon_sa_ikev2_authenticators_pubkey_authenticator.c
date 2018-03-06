--- src/libcharon/sa/ikev2/authenticators/pubkey_authenticator.c.orig
+++ src/libcharon/sa/ikev2/authenticators/pubkey_authenticator.c
@@ -164,7 +164,7 @@ static array_t *select_signature_schemes(keymat_v2_t *keymat,
 			signature_scheme_t schemes[] = {
 				SIGN_RSA_EMSA_PKCS1_SHA2_384,
 				SIGN_RSA_EMSA_PKCS1_SHA2_256,
-			}, contained;
+			};
 			bool found;
 			int i, j;
 
@@ -174,8 +174,8 @@ static array_t *select_signature_schemes(keymat_v2_t *keymat,
 				found = FALSE;
 				for (j = 0; j < array_count(selected); j++)
 				{
-					array_get(selected, j, &contained);
-					if (scheme == contained)
+					array_get(selected, j, &config);
+					if (scheme == config->scheme)
 					{
 						found = TRUE;
 						break;
