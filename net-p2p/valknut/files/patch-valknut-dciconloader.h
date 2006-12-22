--- valknut/dciconloader.h.orig	Fri Dec 22 19:17:43 2006
+++ valknut/dciconloader.h	Fri Dec 22 19:18:00 2006
@@ -122,7 +122,7 @@
 	
 private:
 	/** */
-	QPixmap DCIconLoader::LoadPixmap( QString file );
+	QPixmap LoadPixmap( QString file );
 
 	/** */
 	PixmapMap m_PixmapMap;
