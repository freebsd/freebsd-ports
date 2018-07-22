--- components/autofill/content/renderer/password_form_conversion_utils.cc.orig	2018-06-13 00:10:12.000000000 +0200
+++ components/autofill/content/renderer/password_form_conversion_utils.cc	2018-07-18 23:26:07.424533000 +0200
@@ -34,7 +34,11 @@
 #include "third_party/blink/public/web/web_form_control_element.h"
 #include "third_party/blink/public/web/web_input_element.h"
 #include "third_party/blink/public/web/web_local_frame.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using blink::WebDocument;
 using blink::WebFormControlElement;
