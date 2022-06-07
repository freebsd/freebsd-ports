--- test/parallel/test-process-versions.js.orig	2022-05-08 01:48:13 UTC
+++ test/parallel/test-process-versions.js
@@ -45,7 +45,7 @@ assert(/^\d+\.\d+\.\d+(?:\.\d+)?-node\.\d+(?: \(candid
 assert(/^\d+$/.test(process.versions.modules));
 
 if (common.hasCrypto) {
-  assert(/^\d+\.\d+\.\d+[a-z]?(-fips)?$/.test(process.versions.openssl));
+  assert(/^\d+\.\d+\.\d+[a-z]?(-freebsd|-fips)?$/.test(process.versions.openssl));
 }
 
 for (let i = 0; i < expected_keys.length; i++) {
