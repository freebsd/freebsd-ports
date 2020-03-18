--- src/memory.rs.orig	2020-03-16 13:12:22 UTC
+++ src/memory.rs
@@ -74,12 +74,15 @@ impl RAMInfo {
             self.used  = Some(used  / 1024_f64 / 1024_f64);
             self.total = Some(total / 1024_f64 / 1024_f64);
             return Ok(());
-        } else if os == &OS::FreeBSD || os == &OS::Other {
+        } else if os == &OS::FreeBSD || os == &OS::DragonflyBSD {
             let mut buffer = String::new();
             Command::new("sysctl").arg("-n").arg("hw.physmem")
                 .output().context(RAMErr)?.stdout.iter()
                 .for_each(|b| buffer.push(*b as char));
-            total = buffer.parse::<f64>().unwrap();
+
+            // remove non-integer chars from buffer
+            buffer = buffer.trim().replace("\n", "");
+            total = buffer.parse::<u64>().unwrap() as f64;
 
             let pagesize: f64;
             let inactive: f64;
