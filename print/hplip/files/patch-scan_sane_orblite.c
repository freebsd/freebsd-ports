--- scan/sane/orblite.c.orig	2023-06-25 13:07:58 UTC
+++ scan/sane/orblite.c
@@ -19,6 +19,7 @@
 #undef NDEBUG
 #include "orblitei.h"
 #include "orblite.h"//Added New
+#include <dlfcn.h>
 #include <math.h>
 #include "utils.h"
 #include "io.h"
@@ -195,7 +196,6 @@ static int bb_unload(SANE_THandle ps)
 
 static int bb_unload(SANE_THandle ps)
 {
-   _DBG("Calling orblite bb_unload: \n");
    if (ps->bb_handle)
    {
       dlclose(ps->bb_handle);
@@ -315,7 +315,7 @@ orblite_close (SANE_Handle handle)
 void
 orblite_close (SANE_Handle handle)
 {
-	return g_handle->bb_orblite_close(g_handle);
+	g_handle->bb_orblite_close(g_handle);
 }
 
 
@@ -331,6 +331,7 @@ if (option >= optCount && option < optLast)
 		return &g_handle->Options[option];
 	}
 	//return g_handle->bb_orblite_get_option_descriptor(g_handle, option);
+	return NULL;
 }
 
 
@@ -372,7 +373,7 @@ orblite_cancel (SANE_Handle handle)
 void
 orblite_cancel (SANE_Handle handle)
 {
-	return g_handle->bb_orblite_cancel(g_handle);
+	g_handle->bb_orblite_cancel(g_handle);
 }
 
 ////// sane_set_io_mode, get_select_fd, strstatus - UNIMPLEMENTED /////////////
