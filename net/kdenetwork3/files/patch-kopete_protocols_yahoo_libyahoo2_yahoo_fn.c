--- kopete/protocols/yahoo/libyahoo2/libyahoo2.c	14 Jan 2004 02:07:29 -0000	1.18
+++ kopete/protocols/yahoo/libyahoo2/libyahoo2.c	26 Jun 2004 00:37:08 -0000	1.18.2.3
@@ -1816,6 +1816,8 @@ static void yahoo_process_auth_0x0b(stru
 	 * challenge. */
 
 	shaUpdate(&ctx1, pass_hash_xor1, 64);
+	if (j >= 3 )
+		ctx1.sizeLo = 0x1ff;
 	shaUpdate(&ctx1, magic_key_char, 4);
 	shaFinal(&ctx1, digest1);
 
@@ -1905,6 +1907,8 @@ static void yahoo_process_auth_0x0b(stru
 	 * challenge. */
 
 	shaUpdate(&ctx1, crypt_hash_xor1, 64);
+	if (j >= 3 )
+		ctx1.sizeLo = 0x1ff;
 	shaUpdate(&ctx1, magic_key_char, 4);
 	shaFinal(&ctx1, digest1);
