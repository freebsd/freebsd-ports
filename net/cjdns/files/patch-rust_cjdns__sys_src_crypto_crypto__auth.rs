-- Fix expected payload in the wireguard interface unit tests.
-- The tests push a 12-byte payload (to keep the message 4-byte aligned) but
-- asserted an 11-byte string, causing the assertion to fail.
-- Upstreamed: https://github.com/cjdelisle/cjdns/pull/1279

--- rust/cjdns_sys/src/crypto/crypto_auth.rs.orig	2026-09-27 19:37:09 UTC
+++ rust/cjdns_sys/src/crypto/crypto_auth.rs
@@ -1911,7 +1911,7 @@ mod tests {
 
         bob_send.send(msg).unwrap();
 
-        assert_eq!(alice_received_text.lock().as_slice(), b"Hello World");
+        assert_eq!(alice_received_text.lock().as_slice(), b"Hello World ");
         assert!(bob_received_text.lock().is_empty()); // still empty
 
         // Message back Alice -> Bob
@@ -1921,7 +1921,7 @@ mod tests {
         assert!(res.is_ok());
 
         assert_eq!(bob_received_text.lock().as_slice(), b"Goodbye Universe");
-        assert_eq!(alice_received_text.lock().as_slice(), b"Hello World"); // still unchanged
+        assert_eq!(alice_received_text.lock().as_slice(), b"Hello World "); // still unchanged
     }
 
     #[test]
@@ -1990,7 +1990,7 @@ mod tests {
 
         bob_send.send(msg).unwrap();
 
-        assert_eq!(alice_received_text.lock().as_slice(), b"Hello World");
+        assert_eq!(alice_received_text.lock().as_slice(), b"Hello World ");
         assert!(bob_received_text.lock().is_empty()); // still empty
 
         // Message back Alice -> Bob
@@ -2000,6 +2000,6 @@ mod tests {
         assert!(res.is_ok());
 
         assert_eq!(bob_received_text.lock().as_slice(), b"Goodbye Universe");
-        assert_eq!(alice_received_text.lock().as_slice(), b"Hello World"); // still unchanged
+        assert_eq!(alice_received_text.lock().as_slice(), b"Hello World "); // still unchanged
     }
 }
