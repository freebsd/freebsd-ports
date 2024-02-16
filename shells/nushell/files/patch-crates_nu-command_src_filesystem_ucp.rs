--- crates/nu-command/src/filesystem/ucp.rs.orig	2024-02-16 09:31:16 UTC
+++ crates/nu-command/src/filesystem/ucp.rs
@@ -141,9 +141,9 @@ impl Command for UCp {
         } else {
             uu_cp::OverwriteMode::Clobber(uu_cp::ClobberMode::Standard)
         };
-        #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos"))]
+        #[cfg(any(target_os = "linux", target_os = "freebsd" , target_os = "android", target_os = "macos"))]
         let reflink_mode = uu_cp::ReflinkMode::Auto;
-        #[cfg(not(any(target_os = "linux", target_os = "android", target_os = "macos")))]
+        #[cfg(not(any(target_os = "linux", target_os = "freebsd" , target_os = "android", target_os = "macos")))]
         let reflink_mode = uu_cp::ReflinkMode::Never;
         let mut paths: Vec<Spanned<NuPath>> = call.rest(engine_state, stack, 0)?;
         if paths.is_empty() {
@@ -281,7 +281,7 @@ fn make_attributes(preserve: Option<Value>) -> Result<
 fn make_attributes(preserve: Option<Value>) -> Result<uu_cp::Attributes, ShellError> {
     if let Some(preserve) = preserve {
         let mut attributes = uu_cp::Attributes {
-            #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos"))]
+            #[cfg(any(target_os = "linux", target_os = "freebsd" , target_os = "android", target_os = "macos"))]
             ownership: ATTR_UNSET,
             mode: ATTR_UNSET,
             timestamps: ATTR_UNSET,
@@ -296,7 +296,7 @@ fn make_attributes(preserve: Option<Value>) -> Result<
         // By default preseerve only mode
         Ok(uu_cp::Attributes {
             mode: ATTR_SET,
-            #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos"))]
+            #[cfg(any(target_os = "linux", target_os = "freebsd" , target_os = "android", target_os = "macos"))]
             ownership: ATTR_UNSET,
             timestamps: ATTR_UNSET,
             context: ATTR_UNSET,
@@ -332,7 +332,7 @@ fn parse_and_set_attribute(
         Value::String { val, .. } => {
             let attribute = match val.as_str() {
                 "mode" => &mut attribute.mode,
-                #[cfg(any(target_os = "linux", target_os = "android", target_os = "macos"))]
+                #[cfg(any(target_os = "linux", target_os = "freebsd" , target_os = "freebsd", target_os = "android", target_os = "macos"))]
                 "ownership" => &mut attribute.ownership,
                 "timestamps" => &mut attribute.timestamps,
                 "context" => &mut attribute.context,
