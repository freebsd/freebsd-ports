
$FreeBSD$

--- plugins/uploadWizard/uploadWizard.c	2001/12/12 04:27:17	1.1
+++ plugins/uploadWizard/uploadWizard.c	2001/12/12 04:28:19
@@ -53,6 +53,7 @@
 
 /* screem stuff */
 #include "site.h"
+#include "support.h"
 #include "uploadWizard.h"
 
 int my_abortable_transfer_wrapper(struct site *site,
