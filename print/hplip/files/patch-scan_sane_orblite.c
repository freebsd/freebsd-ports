--- scan/sane/orblite.c.orig	2019-10-22 06:25:58 UTC
+++ scan/sane/orblite.c
@@ -315,7 +315,7 @@ orblite_open (SANE_String_Const devicename, SANE_Handl
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
 
 
@@ -372,7 +373,7 @@ orblite_read (SANE_Handle handle, SANE_Byte * data, SA
 void
 orblite_cancel (SANE_Handle handle)
 {
-	return g_handle->bb_orblite_cancel(g_handle);
+	g_handle->bb_orblite_cancel(g_handle);
 }
 
 ////// sane_set_io_mode, get_select_fd, strstatus - UNIMPLEMENTED /////////////
