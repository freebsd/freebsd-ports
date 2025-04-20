--- packages/hurl/src/runner/xpath.rs.orig	2025-03-24 12:39:25 UTC
+++ packages/hurl/src/runner/xpath.rs
@@ -129,14 +129,6 @@
     }
 }
 
-extern "C" {
-    pub fn silentErrorFunc(
-        ctx: *mut ::std::os::raw::c_void,
-        msg: *const ::std::os::raw::c_char,
-        ...
-    );
-}
-
 /// Registers all XML namespaces from a document `doc` to a `context`.
 fn register_namespaces(doc: &libxml::tree::Document, context: &libxml::xpath::Context) {
     // We walk through the xml document to register each namespace,
@@ -165,11 +157,6 @@
     support_ns: bool,
 ) -> Result<Value, XPathError> {
     let context = libxml::xpath::Context::new(doc).expect("error setting context in xpath module");
-
-    // libxml2 prints to stdout warning and errors, so we mut it.
-    unsafe {
-        libxml::bindings::initGenericErrorDefaultFunc(&mut Some(silentErrorFunc));
-    }
 
     if support_ns {
         register_namespaces(doc, &context);
