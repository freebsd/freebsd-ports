--- RSA.pm.orig	2017-06-19 18:08:26 UTC
+++ RSA.pm
@@ -14,8 +14,31 @@ $VERSION = '0.28';
 
 bootstrap Crypt::OpenSSL::RSA $VERSION;
 
+sub new_private_key {
+
+    my ($self, $keystring, $passin) = @_;
+
+    if (length ($passin) > 0 ) {
+        return $self->_new_enc_private_key($keystring, $passin);
+    }
+    return $self->_new_private_key($keystring);
+}
+
+sub get_private_key_string {
+
+    my ($self, $passout, $cipher) = @_;
+
+    if (length ($passout) > 0 && length ($cipher) > 0) {
+        return $self->_get_enc_private_key_string($passout, $cipher);
+    } elsif (length $passout > 0) { 
+        return $self->_get_enc_private_key_string($passout, "aes-256-cbc");
+    }
+    return $self->_get_private_key_string();
+}
+
 BEGIN { eval { require Crypt::OpenSSL::Bignum; }; }
 
+
 1;
 
 __END__
@@ -96,7 +119,9 @@ sub new_public_key
     }
 }
 
-=item new_private_key
+=item new_private_key(privkey_string)
+=cut
+=item new_private_key(privkey_string, password)
 
 Create a new Crypt::OpenSSL::RSA object by loading a private key in
 from an string containing the Base64/DER encoding of the PKCS1
@@ -179,8 +204,14 @@ header and footer lines:
 and is the format that is produced by running C<openssl rsa -pubout>.
 
 =item get_private_key_string
+=cut
+=item get_enc_private_key_string(password)
+=cut
+=item get_enc_private_key_string(password, cipher)
 
-Return the DER-encoded PKCS1 representation of the private key.
+Return the unencripted or encripted DER-encoded PKCS1 representation
+of the private key. For stoping of potential leak unencrypted private key
+if cipher name is unknown will use DES3 (DES-EDE3) cipher.
 
 =item encrypt
 
