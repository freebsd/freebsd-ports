--- Source/WebCore/platform/graphics/gstreamer/WebKitWebSourceGStreamer.cpp.orig	2015-02-12 01:22:42.081133000 +0100
+++ Source/WebCore/platform/graphics/gstreamer/WebKitWebSourceGStreamer.cpp	2015-02-12 01:25:08.298076000 +0100
@@ -346,7 +346,7 @@ static void webKitWebSrcSetProperty(GObj
 
     switch (propID) {
     case PROP_IRADIO_MODE: {
-        GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+        WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
         priv->iradioMode = g_value_get_boolean(value);
         break;
     }
@@ -364,7 +364,7 @@ static void webKitWebSrcGetProperty(GObj
     WebKitWebSrc* src = WEBKIT_WEB_SRC(object);
     WebKitWebSrcPrivate* priv = src->priv;
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     switch (propID) {
     case PROP_IRADIO_MODE:
         g_value_set_boolean(value, priv->iradioMode);
@@ -417,7 +417,7 @@ static gboolean webKitWebSrcStop(WebKitW
 
     ASSERT(isMainThread());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     bool seeking = priv->seekID;
 
@@ -476,7 +476,7 @@ static gboolean webKitWebSrcStart(WebKit
 
     ASSERT(isMainThread());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     priv->startID = 0;
     priv->corsAccessCheck = CORSNoCheck;
@@ -573,7 +573,7 @@ static GstStateChangeReturn webKitWebSrc
         return ret;
     }
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     switch (transition) {
     case GST_STATE_CHANGE_READY_TO_PAUSED:
         GST_DEBUG_OBJECT(src, "READY->PAUSED");
@@ -604,7 +604,7 @@ static gboolean webKitWebSrcQueryWithPar
         gst_query_parse_duration(query, &format, NULL);
 
         GST_DEBUG_OBJECT(src, "duration query in format %s", gst_format_get_name(format));
-        GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+        WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
         if (format == GST_FORMAT_BYTES && src->priv->size > 0) {
             gst_query_set_duration(query, format, src->priv->size);
             result = TRUE;
@@ -612,7 +612,7 @@ static gboolean webKitWebSrcQueryWithPar
         break;
     }
     case GST_QUERY_URI: {
-        GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+        WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
         gst_query_set_uri(query, src->priv->uri);
         result = TRUE;
         break;
@@ -653,7 +653,7 @@ static gchar* webKitWebSrcGetUri(GstURIH
     WebKitWebSrc* src = WEBKIT_WEB_SRC(handler);
     gchar* ret;
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     ret = g_strdup(src->priv->uri);
     return ret;
 }
@@ -668,7 +668,7 @@ static gboolean webKitWebSrcSetUri(GstUR
         return FALSE;
     }
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     g_free(priv->uri);
     priv->uri = 0;
@@ -704,7 +704,7 @@ static gboolean webKitWebSrcNeedDataMain
 
     ASSERT(isMainThread());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     // already stopped
     if (!priv->needDataID)
         return FALSE;
@@ -725,7 +725,7 @@ static void webKitWebSrcNeedDataCb(GstAp
 
     GST_DEBUG_OBJECT(src, "Need more data: %u", length);
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     if (priv->needDataID || !priv->paused) {
         return;
     }
@@ -739,7 +739,7 @@ static gboolean webKitWebSrcEnoughDataMa
 
     ASSERT(isMainThread());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     // already stopped
     if (!priv->enoughDataID)
         return FALSE;
@@ -760,7 +760,7 @@ static void webKitWebSrcEnoughDataCb(Gst
 
     GST_DEBUG_OBJECT(src, "Have enough data");
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     if (priv->enoughDataID || priv->paused) {
         return;
     }
@@ -774,7 +774,7 @@ static gboolean webKitWebSrcSeekMainCb(W
 
     ASSERT(isMainThread());
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     // already stopped
     if (!priv->seekID)
         return FALSE;
@@ -792,7 +792,7 @@ static gboolean webKitWebSrcSeekDataCb(G
     WebKitWebSrcPrivate* priv = src->priv;
 
     GST_DEBUG_OBJECT(src, "Seeking to offset: %" G_GUINT64_FORMAT, offset);
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     if (offset == priv->offset && priv->requestedOffset == priv->offset)
         return TRUE;
 
@@ -811,7 +811,7 @@ static gboolean webKitWebSrcSeekDataCb(G
 void webKitWebSrcSetMediaPlayer(WebKitWebSrc* src, WebCore::MediaPlayer* player)
 {
     ASSERT(player);
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     src->priv->player = player;
 }
 
@@ -841,7 +841,7 @@ char* StreamingClient::createReadBuffer(
 
     mapGstBuffer(buffer);
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     priv->buffer = adoptGRef(buffer);
     locker.unlock();
 
@@ -867,7 +867,7 @@ void StreamingClient::handleResponseRece
         return;
     }
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     priv->corsAccessCheck = corsAccessCheck;
 
@@ -966,7 +966,7 @@ void StreamingClient::handleDataReceived
     WebKitWebSrc* src = WEBKIT_WEB_SRC(m_src);
     WebKitWebSrcPrivate* priv = src->priv;
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
 
     GST_LOG_OBJECT(src, "Have %lld bytes of data", priv->buffer ? static_cast<long long>(gst_buffer_get_size(priv->buffer.get())) : length);
 
@@ -1035,7 +1035,7 @@ void StreamingClient::handleNotifyFinish
 
     GST_DEBUG_OBJECT(src, "Have EOS");
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     if (!priv->seekID) {
         locker.unlock();
         gst_app_src_end_of_stream(priv->appsrc);
@@ -1194,7 +1194,7 @@ void ResourceHandleStreamingClient::wasB
 
     GST_ERROR_OBJECT(src, "Request was blocked");
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     uri.reset(g_strdup(src->priv->uri));
     locker.unlock();
 
@@ -1208,7 +1208,7 @@ void ResourceHandleStreamingClient::cann
 
     GST_ERROR_OBJECT(src, "Cannot show URL");
 
-    GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
+    WebCore::GMutexLocker locker(GST_OBJECT_GET_LOCK(src));
     uri.reset(g_strdup(src->priv->uri));
     locker.unlock();
 
