--- components/autofill/content/renderer/password_form_conversion_utils.cc.orig	2018-08-01 00:08:37.000000000 +0200
+++ components/autofill/content/renderer/password_form_conversion_utils.cc	2018-08-04 17:44:14.098469000 +0200
@@ -38,7 +38,11 @@
 #include "third_party/blink/public/web/web_form_control_element.h"
 #include "third_party/blink/public/web/web_input_element.h"
 #include "third_party/blink/public/web/web_local_frame.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 using blink::WebFormControlElement;
