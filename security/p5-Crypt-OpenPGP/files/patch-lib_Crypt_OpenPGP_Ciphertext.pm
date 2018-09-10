Patch for CVE-2005-0366: plaintext recovery using checksum failure oracle.

https://nvd.nist.gov/vuln/detail/CVE-2005-0366

--- lib/Crypt/OpenPGP/Ciphertext.pm.orig	2009-12-11 00:05:35 UTC
+++ lib/Crypt/OpenPGP/Ciphertext.pm
@@ -85,8 +85,8 @@ sub decrypt {
     my $padlen = $cipher->blocksize + 2;
     my $pt = $enc->{prefix} =
         $cipher->decrypt(substr $enc->{ciphertext}, 0, $padlen);
-    return $enc->error("Bad checksum")
-        unless substr($pt, -4, 2) eq substr($pt, -2, 2);
+    # return $enc->error("Bad checksum")
+    #     unless substr($pt, -4, 2) eq substr($pt, -2, 2);
     $cipher->sync unless $enc->{is_mdc};
     $pt = $cipher->decrypt(substr $enc->{ciphertext}, $padlen);
     if ($enc->{is_mdc}) {
