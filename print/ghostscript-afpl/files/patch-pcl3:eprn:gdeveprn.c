--- pcl3/eprn/gdeveprn.c.orig	Sun Mar 25 13:59:11 2001
+++ pcl3/eprn/gdeveprn.c	Tue Apr 10 17:53:03 2001
@@ -81,6 +81,9 @@
 #include "gstypes.h"	/* needed by gsstate.h */
 #include "gsstate.h"	/* needed by icstate.h */
 #include "icstate.h"	/* for struct gs_context_state_s */
+#if !defined(GS_REVISION) || GS_REVISION >= 700
+#include "iapi.h"	/* needed by iminst.h */
+#endif
 #include "iminst.h"	/* for struct gs_main_instance_s */
 #include "imain.h"	/* for gs_main_instance_default() */
 #include "gscoord.h"	/* for gs_setdefaultmatrix() */
