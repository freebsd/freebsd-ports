--- cgiedit.c  Tue Jul 18 16:48:45 2006
+++ cgiedit.c  Sat Dec  9 14:49:16 2006
@@ -333,8 +337,10 @@
 #include "miscutil.h"
 #include "errlog.h"
 #include "loaders.h"
-#include "loadcfg.h"
+#ifdef FEATURE_TOGGLE
 /* loadcfg.h is for global_toggle_state only */
+#include "loadcfg.h"
+#endif /* def FEATURE_TOGGLE */
 #include "urlmatch.h"
 
 const char cgiedit_h_rcs[] = CGIEDIT_H_VERSION;
@@ -4232,7 +4238,7 @@
    return cgi_redirect(rsp, target);
 }
 
-
+#ifdef FEATURE_TOGGLE
 /*********************************************************************
  *
  * Function    :  cgi_toggle
@@ -4300,7 +4306,7 @@
 
    return template_fill_for_cgi(csp, template_name, exports, rsp);
 }
-
+#endif /* def FEATURE_TOGGLE */
 
 /*********************************************************************
  *
