--- components/autofill/content/renderer/password_form_conversion_utils.cc.orig	2017-09-05 21:05:17.000000000 +0200
+++ components/autofill/content/renderer/password_form_conversion_utils.cc	2017-09-06 19:05:07.569456000 +0200
@@ -31,7 +31,11 @@
 #include "third_party/WebKit/public/web/WebFormControlElement.h"
 #include "third_party/WebKit/public/web/WebInputElement.h"
 #include "third_party/WebKit/public/web/WebLocalFrame.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using blink::WebDocument;
 using blink::WebFormControlElement;
