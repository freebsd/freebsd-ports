--- libs/gcr/document.cc.orig	2016-11-23 13:05:34 UTC
+++ libs/gcr/document.cc
@@ -1794,7 +1794,6 @@ void Document::Save() const
 		if (error) {
 			g_message ("GIO error: %s", error->message);
 			g_error_free (error);
-			g_object_unref (file);
 			throw (int) 1;
 		}
 		buf->context = output;
