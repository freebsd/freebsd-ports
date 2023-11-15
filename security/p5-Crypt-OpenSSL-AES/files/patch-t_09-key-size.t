--- t/09-key-size.t.orig	2023-11-10 22:50:53 UTC
+++ t/09-key-size.t
@@ -19,9 +19,9 @@ ok($c->decrypt($c->encrypt("Hello World. 123")) eq "He
 ok($c->decrypt($encrypted) eq $plaintext, "decrypt with key length 32 (AES-256-ECB)");
 ok($c->decrypt($c->encrypt("Hello World. 123")) eq "Hello World. 123", "Simple String Encrypted/Decrypted Successfully with key length 32 AES-256-ECB");
 
-# echo -n "ABCDABCDABCDABCD"| openssl enc -nopad -e -aes-256-ecb -K '3031323330313233303132333031323330313233303132333031323330313233' | xxd -i
-# echo -n "ABCDABCDABCDABCD"| openssl enc -nopad -e -aes-192-ecb -K '303132333031323330313233303132333031323330313233'
-# echo -n "ABCDABCDABCDABCD"| openssl enc -nopad -e -aes-128-ecb -K '30313233303132333031323330313233' | xxd -i
+# echo -n "ABCDABCDABCDABCD"| SSLBIN enc -nopad -e -aes-256-ecb -K '3031323330313233303132333031323330313233303132333031323330313233' | xxd -i
+# echo -n "ABCDABCDABCDABCD"| SSLBIN enc -nopad -e -aes-192-ecb -K '303132333031323330313233303132333031323330313233'
+# echo -n "ABCDABCDABCDABCD"| SSLBIN enc -nopad -e -aes-128-ecb -K '30313233303132333031323330313233' | xxd -i
 
 #
 # test AES-192-ECB
