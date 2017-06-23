--- components/autofill/content/renderer/password_form_conversion_utils.cc.orig	2017-06-05 19:03:05 UTC
+++ components/autofill/content/renderer/password_form_conversion_utils.cc
@@ -29,7 +29,11 @@
 #include "third_party/WebKit/public/web/WebFormControlElement.h"
 #include "third_party/WebKit/public/web/WebFrame.h"
 #include "third_party/WebKit/public/web/WebInputElement.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using blink::WebDocument;
 using blink::WebFormControlElement;
