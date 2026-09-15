-- cc 1.4.x appends CFLAGS after build-script flags, so a -O2 from the
-- environment overrides the -O0 aws-lc-sys adds for jitterentropy.
-- Strip optimization flags from both CFLAGS and CFLAGS_${TARGET} before
-- building jitterentropy, and restore them afterwards.
-- https://github.com/aws/aws-lc-rs/issues/681

--- cargo-crates/aws-lc-sys-0.37.1/builder/cc_builder.rs.orig
+++ cargo-crates/aws-lc-sys-0.37.1/builder/cc_builder.rs
@@ -20,7 +20,7 @@
 use crate::nasm_builder::NasmBuilder;
 use crate::{
     cargo_env, disable_jitter_entropy, emit_warning, env_var_to_bool, execute_command,
-    get_crate_cc, get_crate_cflags, get_crate_cxx, is_no_asm, out_dir, requested_c_std,
+    get_crate_cc, get_crate_cflags, get_crate_cxx, is_no_asm, out_dir, requested_c_std, set_env,
     set_env_for_target, target, target_arch, target_env, target_os, target_vendor,
     test_clang_cl_command, CStdRequested, OutputLibType,
 };
@@ -431,17 +431,21 @@
         }
 
         if let Some(original_cflags) = get_crate_cflags() {
-            let mut new_cflags = original_cflags.clone();
+            let mut new_cflags = original_cflags
+                .split_whitespace()
+                .filter(|arg| !arg.starts_with("-O"))
+                .collect::<Vec<_>>()
+                .join(" ");
             if is_like_msvc {
                 new_cflags.push_str(" -Od");
             } else {
                 new_cflags.push_str(" -O0 -Wp,-U_FORTIFY_SOURCE");
             }
+            set_env("CFLAGS", &new_cflags);
             set_env_for_target("CFLAGS", &new_cflags);
             // cc-rs currently prioritizes flags provided by CFLAGS over the flags provided by the build script.
             // The environment variables used by the compiler are set when `get_compiler` is called.
             je_builder.get_compiler();
-            set_env_for_target("CFLAGS", &original_cflags);
         }
 
         je_builder.define("AWSLC", "1");
@@ -500,6 +504,8 @@
         // CPU Jitter Entropy is compiled separately due to needing specific flags
         let mut jitter_entropy_builder =
             self.prepare_jitter_entropy_builder(compiler.is_like_msvc());
+        let jitter_entropy_original_cflags = get_crate_cflags();
+
         jitter_entropy_builder.flag(format!(
             "{}{}",
             force_include_option,
@@ -568,9 +574,16 @@
         }
         if Some(true) != disable_jitter_entropy() {
             let jitter_entropy_object_files = jitter_entropy_builder.compile_intermediates();
+            if let Some(ref original_cflags) = jitter_entropy_original_cflags {
+                set_env("CFLAGS", original_cflags);
+                set_env_for_target("CFLAGS", original_cflags);
+            }
             for object in jitter_entropy_object_files {
                 cc_build.object(object);
             }
+        } else if let Some(ref original_cflags) = jitter_entropy_original_cflags {
+            set_env("CFLAGS", original_cflags);
+            set_env_for_target("CFLAGS", original_cflags);
         }
         let nasm_object_files = nasm_builder.compile_intermediates();
         for object in nasm_object_files {
