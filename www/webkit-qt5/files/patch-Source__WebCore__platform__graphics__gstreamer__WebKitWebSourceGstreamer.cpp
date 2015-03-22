GMutexLocker was added to glib in 2.44. Make sure we use the version from
WebCore.

--- Source/WebCore/platform/graphics/gstreamer/WebKitWebSourceGStreamer.cpp.orig	2015-03-22 17:02:03.015319000 +0100
+++ Source/WebCore/platform/graphics/gstreamer/WebKitWebSourceGStreamer.cpp	2015-03-22 17:04:05.587550000 +0100
@@ -354,7 +354,7 @@
 
     switch (propID) {
     case PROP_IRADIO_MODE: {
-        GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+        WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
         priv->iradioMode = g_value_get_boolean(value);
         break;
     }
@@ -376,7 +376,7 @@
     WebKitWebSrc* src = WEBKIT_WEB_SRC(object);
     WebKitWebSrcPrivate* priv = src->priv;
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     switch (propID) {
     case PROP_IRADIO_MODE:
         g_value_set_boolean(value, priv->iradioMode);
@@ -429,7 +429,7 @@
 
     ASSERT(isMainThread());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     bool seeking = priv->seekID;
 
@@ -493,7 +493,7 @@
 
     ASSERT(isMainThread());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     priv->startID = 0;
 
@@ -584,7 +584,7 @@
         return ret;
     }
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     switch (transition) {
     case GST_STATE_CHANGE_READY_TO_PAUSED:
         GST_DEBUG_OBJECT(src, "READY->PAUSED");
@@ -615,7 +615,7 @@
         gst_query_parse_duration(query, &format, NULL);
 
         GST_DEBUG_OBJECT(src, "duration query in format %s", gst_format_get_name(format));
-        GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+        WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
         if (format == GST_FORMAT_BYTES && src->priv->size > 0) {
             gst_query_set_duration(query, format, src->priv->size);
             result = TRUE;
@@ -623,7 +623,7 @@
         break;
     }
     case GST_QUERY_URI: {
-        GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+        WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
         gst_query_set_uri(query, src->priv->uri);
         result = TRUE;
         break;
@@ -668,7 +668,7 @@
     WebKitWebSrc* src = WEBKIT_WEB_SRC(handler);
     gchar* ret;
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     ret = g_strdup(src->priv->uri);
     return ret;
 }
@@ -683,7 +683,7 @@
         return FALSE;
     }
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     g_free(priv->uri);
     priv->uri = 0;
@@ -719,7 +719,7 @@
     WebKitWebSrc* src = WEBKIT_WEB_SRC(handler);
     gchar* ret;
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     ret = g_strdup(src->priv->uri);
     return ret;
 }
@@ -734,7 +734,7 @@
         return FALSE;
     }
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     g_free(priv->uri);
     priv->uri = 0;
@@ -772,7 +772,7 @@
 
     ASSERT(isMainThread());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     // already stopped
     if (!priv->needDataID)
         return FALSE;
@@ -793,7 +793,7 @@
 
     GST_DEBUG_OBJECT(src, "Need more data: %u", length);
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     if (priv->needDataID || !priv->paused) {
         return;
     }
@@ -807,7 +807,7 @@
 
     ASSERT(isMainThread());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     // already stopped
     if (!priv->enoughDataID)
         return FALSE;
@@ -828,7 +828,7 @@
 
     GST_DEBUG_OBJECT(src, "Have enough data");
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     if (priv->enoughDataID || priv->paused) {
         return;
     }
@@ -842,7 +842,7 @@
 
     ASSERT(isMainThread());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     // already stopped
     if (!priv->seekID)
         return FALSE;
@@ -860,7 +860,7 @@
     WebKitWebSrcPrivate* priv = src->priv;
 
     GST_DEBUG_OBJECT(src, "Seeking to offset: %" G_GUINT64_FORMAT, offset);
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     if (offset == priv->offset && priv->requestedOffset == priv->offset)
         return TRUE;
 
@@ -879,7 +879,7 @@
 void webKitWebSrcSetMediaPlayer(WebKitWebSrc* src, WebCore::MediaPlayer* player)
 {
     ASSERT(player);
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     src->priv->player = player;
     s_cachedResourceLoader = player->cachedResourceLoader();
 }
@@ -906,7 +906,7 @@
     mapGstBuffer(buffer);
 #endif
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     priv->buffer = adoptGRef(buffer);
     locker.unlock();
 
@@ -921,7 +921,7 @@
 
     GST_DEBUG_OBJECT(src, "Received response: %d", response.httpStatusCode());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     // If we seeked we need 206 == PARTIAL_CONTENT
     if (priv->requestedOffset && response.httpStatusCode() != 206) {
@@ -1020,7 +1020,7 @@
     WebKitWebSrc* src = WEBKIT_WEB_SRC(m_src.get());
     WebKitWebSrcPrivate* priv = src->priv;
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     GST_LOG_OBJECT(src, "Have %d bytes of data", priv->buffer ? getGstBufferSize(priv->buffer.get()) : length);
 
@@ -1074,7 +1074,7 @@
 
     GST_DEBUG_OBJECT(src, "Have EOS");
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     if (!priv->seekID) {
         locker.unlock();
         gst_app_src_end_of_stream(priv->appsrc);
@@ -1210,7 +1210,7 @@
 
     GST_ERROR_OBJECT(src, "Request was blocked");
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     uri.set(g_strdup(src->priv->uri));
     locker.unlock();
 
@@ -1224,7 +1224,7 @@
 
     GST_ERROR_OBJECT(src, "Cannot show URL");
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     uri.set(g_strdup(src->priv->uri));
     locker.unlock();
 
