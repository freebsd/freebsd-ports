--- src/util.rs.orig	2020-03-16 13:14:06 UTC
+++ src/util.rs
@@ -8,6 +8,7 @@ pub enum OS {
     FreeBSD,
     OpenBSD,
     NetBSD,
+    DragonflyBSD,
     Other
 }
 
@@ -23,11 +24,12 @@ impl OSInfo { 
             .output()?.stdout.iter()
             .for_each(|b| uname.push(*b as char));
         let os = match uname.replace("\n", "").trim().as_ref() {
-            "Linux"   => OS::Linux,
-            "FreeBSD" => OS::FreeBSD,
-            "NetBSD"  => OS::NetBSD,
-            "OpenBSD" => OS::OpenBSD,
-            &_        => OS::Other,
+            "Linux"     => OS::Linux,
+            "FreeBSD"   => OS::FreeBSD,
+            "NetBSD"    => OS::NetBSD,
+            "OpenBSD"   => OS::OpenBSD,
+            "DragonFly" => OS::DragonflyBSD,
+            &_          => OS::Other,
         };
 
         Ok(os)
