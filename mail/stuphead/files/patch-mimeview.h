--- src/mimeview.h.orig	Tue Aug 17 14:17:29 2004
+++ src/mimeview.h	Tue Aug 17 14:23:22 2004
@@ -76,6 +76,6 @@
 void mimeview_destroy		(MimeView	*mimeview);
 void mimeview_clear		(MimeView	*mimeview);
 void mimeview_change_view_type	(MimeView	*mimeview,
-				 ContentType	 type);
+				 MimeViewType	 type);
 
 #endif /* __MIMEVIEW_H__ */
