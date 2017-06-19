--- t/rsa.t.orig	2017-06-19 18:08:26 UTC
+++ t/rsa.t
@@ -4,7 +4,7 @@ use Test;
 use Crypt::OpenSSL::Random;
 use Crypt::OpenSSL::RSA;
 
-BEGIN { plan tests => 43 + (UNIVERSAL::can("Crypt::OpenSSL::RSA", "use_sha512_hash") ? 4*5 : 0) }
+BEGIN { plan tests => 46 + (UNIVERSAL::can("Crypt::OpenSSL::RSA", "use_sha512_hash") ? 4*5 : 0) }
 
 sub _Test_Encrypt_And_Decrypt
 {
@@ -83,6 +83,15 @@ my $private_key_string = $rsa->get_private_key_string(
 my $public_key_string = $rsa->get_public_key_string();
 
 ok($private_key_string and $public_key_string);
+
+my $enc_private_key_string_default = $rsa->get_private_key_string('12345');
+ok($enc_private_key_string_default);
+
+my $enc_private_key_string_des3 = $rsa->get_private_key_string('12345', 'des3-cbc');
+ok($enc_private_key_string_des3);
+
+my $enc_private_key_string_idea = $rsa->get_private_key_string('12345', 'IDEA');
+ok($enc_private_key_string_idea);
 
 my $plaintext = "The quick brown fox jumped over the lazy dog";
 my $rsa_priv = Crypt::OpenSSL::RSA->new_private_key($private_key_string);
