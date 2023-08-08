--- src/net/http.cpp.orig	2022-12-12 17:06:47 UTC
+++ src/net/http.cpp
@@ -365,7 +365,7 @@ template <typename Stream> Endpoint HttpIngress<Stream
      * relative_path specified;
      *     - relative_path will be forwarded without any change.
      */
-    auto target = req.target().to_string();
+    auto target = string{cbegin(req.target()), cend(req.target())};
     assertFalse(target.empty(), PichiError::BAD_PROTO, "Empty path");
     if (target[0] != '/') {
       // absolute_path specified, so convert it to relative one.
