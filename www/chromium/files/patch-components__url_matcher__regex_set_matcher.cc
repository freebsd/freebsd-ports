--- components/url_matcher/regex_set_matcher.cc.orig	2016-03-05 21:14:47.451567783 +0100
+++ components/url_matcher/regex_set_matcher.cc	2016-03-05 21:15:45.419563760 +0100
@@ -10,8 +10,13 @@
 #include "base/stl_util.h"
 #include "base/strings/string_util.h"
 #include "components/url_matcher/substring_set_matcher.h"
+#if defined(OS_BSD)
+#include <re2/filtered_re2.h>
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/filtered_re2.h"
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace url_matcher {
 
