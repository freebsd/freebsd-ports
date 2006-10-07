--- src/global.h.orig	Sat Oct  7 16:39:39 2006
+++ src/global.h	Sat Oct  7 16:40:05 2006
@@ -318,6 +318,8 @@
 
 /* General Trace Globals Declarations */
 
+#include "../include/pvmtev.h"
+
 extern	struct Pvmtevdid pvmtevdidlist[];
 
 extern	struct Pvmtevinfo pvmtevinfo[];
