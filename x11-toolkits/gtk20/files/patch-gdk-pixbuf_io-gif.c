--- gdk-pixbuf/io-gif.c.orig	Thu Nov  7 18:08:02 2002
+++ gdk-pixbuf/io-gif.c	Thu Nov  7 18:14:25 2002
@@ -534,13 +534,16 @@
 	return 0;
 }
 
-#define CHECK_LZW_SP() if(((guchar *)context->lzw_sp) >= (((guchar *)context->lzw_stack) + sizeof(context->lzw_stack))) { \
-        g_set_error (context->error,                  \
-                     GDK_PIXBUF_ERROR,                \
-                     GDK_PIXBUF_ERROR_CORRUPT_IMAGE,  \
-                     _("Stack overflow"));            \
-        return -2;                                    \
-}
+#define CHECK_LZWP_SP() G_STMT_START { \
+	if ((guchar *)context->lzw_sp >= \
+	    (guchar *)context->lzw_stack + sizeof (context->lzw_stack)) { \
+	    g_set_error (context->error, \
+	    	GDK_PIXBUF_ERROR, \
+		GDK_PIXBUF_ERROR_CORRUPT_IMAGE, \
+		_("Stack overflow")); \
+	    return -2; \
+	} \
+} G_STMT_END
 
 static int
 lzw_read_byte (GifContext *context)
