--- components/autofill/content/renderer/password_form_conversion_utils.cc.orig	2019-12-16 21:50:45 UTC
+++ components/autofill/content/renderer/password_form_conversion_utils.cc
@@ -19,7 +19,11 @@
 #include "third_party/blink/public/web/web_form_control_element.h"
 #include "third_party/blink/public/web/web_input_element.h"
 #include "third_party/blink/public/web/web_local_frame.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 using blink::WebElement;
