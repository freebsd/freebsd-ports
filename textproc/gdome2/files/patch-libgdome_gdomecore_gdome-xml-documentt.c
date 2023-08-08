Patch from Gentoo to fix libxml2 2.9 api change

Patch by Harris Landgarten.

The patch was submitted on bug 448236, following the announcement on
https://mail.gnome.org/archives/xml/2012-August/msg00005.html
--- libgdome/gdomecore/gdome-xml-documentt.c.orig	2003-07-13 10:47:54 UTC
+++ libgdome/gdomecore/gdome-xml-documentt.c
@@ -342,7 +342,11 @@ gdome_xml_dt_internalSubset (GdomeDocumentType *self, 
 	}
 	xmlNodeDumpOutput (out_buff, NULL, (xmlNode *)is, 0, 0, NULL);
 	xmlOutputBufferFlush(out_buff);
+#if LIBXML_VERSION < 20900
 	ret = g_strndup (out_buff->buffer->content, out_buff->buffer->use);
+#else
+	ret = g_strndup (xmlBufContent(out_buff->buffer), xmlBufUse(out_buff->buffer));
+#endif
 	(void)xmlOutputBufferClose(out_buff);
 
 	return gdome_xml_str_mkref_own (ret);
