--- src/lib/tls.rs.orig	2022-08-17 08:17:36 UTC
+++ src/lib/tls.rs
@@ -10,7 +10,7 @@ use rustls::{Certificate, Error, PrivateKey};
 use rustls::server::{ClientCertVerified, ClientCertVerifier, ResolvesServerCertUsingSni};
 use rustls::sign::{self, CertifiedKey};
 use rustls::{Certificate, Error, PrivateKey};
-use rustls_pemfile::{certs, pkcs8_private_keys};
+use rustls_pemfile::{certs, pkcs8_private_keys, rsa_private_keys};
 use tokio_rustls::rustls;
 use tokio_rustls::TlsAcceptor;
 
@@ -34,7 +34,22 @@ fn load_key(path: &str) -> io::Result<Vec<PrivateKey>>
 }
 
 fn load_key(path: &str) -> io::Result<Vec<PrivateKey>> {
-    pkcs8_private_keys(&mut std::io::BufReader::new(std::fs::File::open(path)?))
+    let mut private_keys = pkcs8_private_keys(&mut std::io::BufReader::new(std::fs::File::open(path)?));
+    let rsa_keys = rsa_private_keys(&mut std::io::BufReader::new(std::fs::File::open(path)?));
+    // It is common to use RSA keys that are not PKCS8-formatted
+    // we need to join both RSA and PKCS8 keys
+    if rsa_keys.is_ok()
+    {
+        if private_keys.is_ok()
+        {
+            let mut all_keys = private_keys.ok().unwrap_or_default();
+            all_keys.extend(rsa_keys.ok().unwrap_or_default());
+            private_keys = Ok(all_keys);
+        }
+        else
+            { private_keys = rsa_keys; }
+    }
+    private_keys
         .map_err(|_| io::Error::new(io::ErrorKind::InvalidInput, "invalid key"))
         .map(|mut keys| keys.drain(..).map(PrivateKey).collect())
 }
