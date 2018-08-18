--- components/autofill/content/renderer/password_form_conversion_utils.cc.orig	2018-05-09 21:05:44.000000000 +0200
+++ components/autofill/content/renderer/password_form_conversion_utils.cc	2018-08-16 09:39:51.905373000 +0200
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
