--- components/url_matcher/url_matcher_factory.cc.orig	2020-11-13 06:36:42 UTC
+++ components/url_matcher/url_matcher_factory.cc
@@ -16,7 +16,11 @@
 #include "base/values.h"
 #include "components/url_matcher/url_matcher_constants.h"
 #include "components/url_matcher/url_matcher_helpers.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace url_matcher {
 
