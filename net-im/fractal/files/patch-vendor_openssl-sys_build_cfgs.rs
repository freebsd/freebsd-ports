--- vendor/openssl-sys/build/cfgs.rs.orig	2018-12-22 10:43:42 UTC
+++ vendor/openssl-sys/build/cfgs.rs
@@ -13,6 +13,9 @@ pub fn get(openssl_version: Option<u64>, libressl_vers
         if libressl_version >= 0x2_07_00_00_0 {
             cfgs.push("libressl270");
         }
+        if libressl_version >= 0x2_07_01_00_0 {
+            cfgs.push("libressl271");
+        }
         if libressl_version >= 0x2_07_03_00_0 {
             cfgs.push("libressl273");
         }
@@ -21,6 +24,9 @@ pub fn get(openssl_version: Option<u64>, libressl_vers
         }
         if libressl_version >= 0x2_08_01_00_0 {
             cfgs.push("libressl281");
+        }
+        if libressl_version >= 0x2_09_01_00_0 {
+            cfgs.push("libressl291");
         }
     } else {
         let openssl_version = openssl_version.unwrap();
