--- qdvdauthor/log.h.orig	Fri Dec 30 03:28:24 2005
+++ qdvdauthor/log.h	Fri Dec 30 03:28:35 2005
@@ -40,7 +40,7 @@
 	void log (QString);
 	void log (type, QString);
 
-	void line (void *, unsigned long, const char *, const char *, long, type);
+	void line (void *, pthread_t, const char *, const char *, long, type);
 private:
 
 	int  m_enLogLevel;
