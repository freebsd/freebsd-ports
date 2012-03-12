--- ./xine/mediaobject.cpp.orig	2011-01-19 20:20:53.000000000 +0100
+++ ./xine/mediaobject.cpp	2012-03-12 11:12:12.254129363 +0100
@@ -443,7 +443,7 @@
     const int lastSize = m_titles.size();
     m_titles.clear();
     int num = 0;
-    char **mrls = xine_get_autoplay_mrls(m_stream->xine(), plugin, &num);
+    const char * const *mrls = xine_get_autoplay_mrls(m_stream->xine(), plugin, &num);
     for (int i = 0; i < num; ++i) {
         if (mrls[i]) {
             debug() << Q_FUNC_INFO << mrls[i];
