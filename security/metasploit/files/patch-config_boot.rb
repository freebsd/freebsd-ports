Disable bootsnap's bytecode cache: its workaround for Ruby bug 22023 reads
source files honouring Encoding.default_internal, which this application
sets to binary.  Any source file with non-ASCII characters then fails to
load, for example tzinfo-data's country index, and msfconsole does not
start.  Fixed upstream in bootsnap 1.26.1 (rails/bootsnap PR 576); drop
this patch once devel/rubygem-bootsnap is updated.

--- config/boot.rb.orig
+++ config/boot.rb
@@ -85,7 +85,7 @@
     ignore_directories: [],
     development_mode: development_mode,
     load_path_cache: true, # Optimize the LOAD_PATH with a cache
-    compile_cache_iseq: true, # If coverage reports are inaccurate, disable this (ISeq caching bypasses Coverage tracing).
+    compile_cache_iseq: false, # If coverage reports are inaccurate, disable this (ISeq caching bypasses Coverage tracing).
     compile_cache_yaml: false, # Don't compile YAML into a cache
     readonly: false, # Update caches - https://github.com/Shopify/bootsnap/commit/b51397f96c33aa421fd5c29484fb9574df9eb451
   }
