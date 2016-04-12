--- components/autofill/core/browser/form_structure.cc.orig	2016-03-05 21:25:19.742524141 +0100
+++ components/autofill/core/browser/form_structure.cc	2016-03-05 21:25:31.566523885 +0100
@@ -35,7 +35,11 @@
 #include "components/rappor/rappor_service.h"
 #include "components/rappor/rappor_utils.h"
 #include "third_party/libxml/chromium/libxml_utils.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace autofill {
 namespace {
