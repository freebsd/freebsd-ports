--- plparse/totem-pl-parser-videosite.c.orig	2010-12-14 15:39:59.000000000 +0100
+++ plparse/totem-pl-parser-videosite.c	2011-10-22 22:45:40.317902126 +0200
@@ -75,7 +75,7 @@
 #ifdef HAVE_QUVI
 	QUVIcode rc;
 	quvi_t handle;
-	quvi_video_t v;
+	quvi_media_t v;
 	char *uri;
 	/* properties */
 	const char *video_uri;
@@ -100,13 +100,13 @@
 		return TOTEM_PL_PARSER_RESULT_ERROR;
 	}
 
-	getprop (QUVIPROP_VIDEOURL, video_uri);
-	if (quvi_getprop (v, QUVIPROP_VIDEOFILELENGTH, &length) == QUVI_OK)
+	getprop (QUVIPROP_MEDIAURL, video_uri);
+	if (quvi_getprop (v, QUVIPROP_MEDIACONTENTLENGTH, &length) == QUVI_OK)
 		length_str = g_strdup_printf ("%f", length);
 	else
 		length_str = NULL;
 	getprop (QUVIPROP_PAGETITLE, title);
-	getprop (QUVIPROP_VIDEOID, id);
+	getprop (QUVIPROP_MEDIAID, id);
 	getprop (QUVIPROP_PAGEURL, page_uri);
 	getprop (QUVIPROP_STARTTIME, starttime);