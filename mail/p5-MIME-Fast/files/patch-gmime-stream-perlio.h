--- gmime-stream-perlio.h.orig	Thu Dec 16 23:28:51 2004
+++ gmime-stream-perlio.h	Sat Feb 12 19:26:52 2005
@@ -36,11 +36,11 @@
 #include <gmime/gmime-stream.h>
 
 #define GMIME_TYPE_STREAM_PERLIO            (g_mime_stream_perlio_get_type ())
-#define GMIME_STREAM_PERLIO(obj)            (GMIME_CHECK_CAST ((obj), GMIME_TYPE_STREAM_PERLIO, GMimeStreamPerlIO))
-#define GMIME_STREAM_PERLIO_CLASS(klass)    (GMIME_CHECK_CLASS_CAST ((klass), GMIME_TYPE_STREAM_PERLIO, GMimeStreamPerlIOClass))
-#define GMIME_IS_STREAM_PERLIO(obj)         (GMIME_CHECK_TYPE ((obj), GMIME_TYPE_STREAM_PERLIO))
-#define GMIME_IS_STREAM_PERLIO_CLASS(klass) (GMIME_CHECK_CLASS_TYPE ((klass), GMIME_TYPE_STREAM_PERLIO))
-#define GMIME_STREAM_PERLIO_GET_CLASS(obj)  (GMIME_CHECK_GET_CLASS ((obj), GMIME_TYPE_STREAM_PERLIO, GMimeStreamPerlIOClass))
+#define GMIME_STREAM_PERLIO(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GMIME_TYPE_STREAM_PERLIO, GMimeStreamPerlIO))
+#define GMIME_STREAM_PERLIO_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GMIME_TYPE_STREAM_PERLIO, GMimeStreamPerlIOClass))
+#define GMIME_IS_STREAM_PERLIO(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GMIME_TYPE_STREAM_PERLIO))
+#define GMIME_IS_STREAM_PERLIO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GMIME_TYPE_STREAM_PERLIO))
+#define GMIME_STREAM_PERLIO_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GMIME_TYPE_STREAM_PERLIO, GMimeStreamPerlIOClass))
 
 typedef struct _GMimeStreamPerlIO GMimeStreamPerlIO;
 typedef struct _GMimeStreamPerlIOClass GMimeStreamPerlIOClass;
