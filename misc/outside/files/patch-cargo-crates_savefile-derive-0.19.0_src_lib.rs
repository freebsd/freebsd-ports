--- cargo-crates/savefile-derive-0.19.0/src/lib.rs.orig	2026-10-15 08:32:14 UTC
+++ cargo-crates/savefile-derive-0.19.0/src/lib.rs
@@ -96,7 +96,7 @@ fn implement_fields_serialize(
             output.push(
                 quote!(
                     unsafe {
-                        if #(#conditions)* {
+                        if cfg!(target_endian = "little") && #(#conditions)* {
                          #local_serializer.raw_write_region(self,&#deferred_from,&#deferred_to, local_serializer.file_version)?;
                         } else {
                             #(#fallbacks)*
