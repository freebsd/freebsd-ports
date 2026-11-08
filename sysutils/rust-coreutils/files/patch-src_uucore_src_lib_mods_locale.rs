--- src/uucore/src/lib/mods/locale.rs.orig	2026-09-18 12:30:59 UTC
+++ src/uucore/src/lib/mods/locale.rs
@@ -228,16 +228,24 @@ fn find_uucore_locales_dir(utility_locales_dir: &Path)
         .canonicalize()
         .unwrap_or_else(|_| utility_locales_dir.to_path_buf());
 
-    // Walk up: locales -> printenv -> uu -> src
-    let uucore_locales = normalized_dir
-        .parent()? // printenv
-        .parent()? // uu
-        .parent()? // src
-        .join("uucore")
-        .join("locales");
+    // In the source tree, walk up: locales -> printenv -> uu -> src
+    let in_source_tree = normalized_dir
+        .parent() // printenv
+        .and_then(Path::parent) // uu
+        .and_then(Path::parent) // src
+        .map(|src| src.join("uucore").join("locales"));
 
-    // Only return if the directory actually exists
-    uucore_locales.exists().then_some(uucore_locales)
+    // Next to an installed binary, the directory sits beside the one of the
+    // utility: <locales>/printenv -> <locales>/uucore
+    let installed = normalized_dir
+        .parent()
+        .map(|locales| locales.join("uucore"));
+
+    // Only return a directory that actually exists
+    [in_source_tree, installed]
+        .into_iter()
+        .flatten()
+        .find(|dir| dir.exists())
 }
 
 /// Create a bundle that combines common and utility-specific strings
