--- components/web_package/web_bundle_parser.cc.orig	2026-10-18 13:29:39 UTC
+++ components/web_package/web_bundle_parser.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#if 0
+// XXX crubit
 #include "components/web_package/web_bundle_parser.h"
 
 #include <algorithm>
@@ -544,3 +546,4 @@ bool WebBundleParser::CheckIfClosed() {
 }
 
 }  // namespace web_package
+#endif 
