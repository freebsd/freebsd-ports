--- src/kmplayerpartbase.cpp.orig	Mon Jul 19 23:52:11 2004
+++ src/kmplayerpartbase.cpp	Tue Jul 20 00:01:41 2004
@@ -716,7 +716,7 @@
 }
 
 QString KMPlayerSource::mime () const {
-    return m_currenturl == m_refurls.end () ? QString () : m_currenturl->mime;
+    return (m_refurls.end () == m_currenturl) ? QString () : m_currenturl->mime;
 }
 
 void KMPlayerSource::setMime (const QString & m) {
