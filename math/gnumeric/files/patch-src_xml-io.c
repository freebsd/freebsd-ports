--- src/xml-io.c.orig	Thu Jan  9 13:44:58 2003
+++ src/xml-io.c	Thu Jan  9 13:46:41 2003
@@ -67,7 +67,7 @@
 
 /* FIXME - tune the values below */
 /* libxml1 parser bug breaks multibyte characters on buffer margins */
-#define XML_INPUT_BUFFER_SIZE      1024*1024
+#define XML_INPUT_BUFFER_SIZE      (10*1024*1024)
 #define N_ELEMENTS_BETWEEN_UPDATES 20
 
 /* ------------------------------------------------------------------------- */
@@ -3350,7 +3350,7 @@
 	struct stat sbuf;
 	gint file_size;
 	ErrorInfo *open_error;
-	gchar buffer[XML_INPUT_BUFFER_SIZE];
+	gchar *buffer;
 	gint bytes;
 	xmlParserCtxtPtr pctxt;
 	xmlDocPtr res;
@@ -3387,6 +3387,7 @@
 	io_progress_message (context, _("Reading file..."));
 	io_progress_range_push (context, 0.0, 0.5);
 	value_io_progress_set (context, file_size, 0);
+	buffer = g_new (char, XML_INPUT_BUFFER_SIZE);                           
 	bytes = gzread (f, buffer, 4);
 	pctxt = xmlCreatePushParserCtxt (NULL, NULL, buffer, bytes, filename);
 
@@ -3395,6 +3396,7 @@
 		value_io_progress_update (context, lseek (fd, 0, SEEK_CUR));
 	}
 	xmlParseChunk (pctxt, buffer, 0, 1);
+	g_free (buffer);                                                        
 
 	res = pctxt->myDoc;
 	xmlFreeParserCtxt (pctxt);
