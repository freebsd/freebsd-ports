--- components/autofill/content/renderer/password_form_conversion_utils.cc.orig	2016-03-05 21:26:25.526530088 +0100
+++ components/autofill/content/renderer/password_form_conversion_utils.cc	2016-03-05 21:26:38.502521878 +0100
@@ -26,7 +26,11 @@
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
