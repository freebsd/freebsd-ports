--- components/url_matcher/url_matcher_factory.cc.orig	2016-03-05 21:16:31.699560757 +0100
+++ components/url_matcher/url_matcher_factory.cc	2016-03-05 21:16:54.155559498 +0100
@@ -15,7 +15,11 @@
 #include "base/values.h"
 #include "components/url_matcher/url_matcher_constants.h"
 #include "components/url_matcher/url_matcher_helpers.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace url_matcher {
 
