--- Source/WebCore/platform/graphics/gstreamer/VideoSinkGStreamer.cpp.orig	2015-02-12 01:22:25.261692000 +0100
+++ Source/WebCore/platform/graphics/gstreamer/VideoSinkGStreamer.cpp	2015-02-12 01:24:34.127107000 +0100
@@ -118,7 +118,7 @@ static gboolean webkitVideoSinkTimeoutCa
     WebKitVideoSink* sink = reinterpret_cast<WebKitVideoSink*>(data);
     WebKitVideoSinkPrivate* priv = sink->priv;
 
-    GMutexLocker lock(priv->bufferMutex);
+    WebCore::GMutexLocker lock(priv->bufferMutex);
     GstBuffer* buffer = priv->buffer;
     priv->buffer = 0;
     priv->timeoutId = 0;
@@ -140,7 +140,7 @@ static GstFlowReturn webkitVideoSinkRend
     WebKitVideoSink* sink = WEBKIT_VIDEO_SINK(baseSink);
     WebKitVideoSinkPrivate* priv = sink->priv;
 
-    GMutexLocker lock(priv->bufferMutex);
+    WebCore::GMutexLocker lock(priv->bufferMutex);
 
     if (priv->unlocked)
         return GST_FLOW_OK;
@@ -279,7 +279,7 @@ static void webkitVideoSinkGetProperty(G
 
 static void unlockBufferMutex(WebKitVideoSinkPrivate* priv)
 {
-    GMutexLocker lock(priv->bufferMutex);
+    WebCore::GMutexLocker lock(priv->bufferMutex);
 
     if (priv->buffer) {
         gst_buffer_unref(priv->buffer);
@@ -305,7 +305,7 @@ static gboolean webkitVideoSinkUnlockSto
     WebKitVideoSinkPrivate* priv = WEBKIT_VIDEO_SINK(baseSink)->priv;
 
     {
-        GMutexLocker lock(priv->bufferMutex);
+        WebCore::GMutexLocker lock(priv->bufferMutex);
         priv->unlocked = false;
     }
 
@@ -330,7 +330,7 @@ static gboolean webkitVideoSinkStart(Gst
 {
     WebKitVideoSinkPrivate* priv = WEBKIT_VIDEO_SINK(baseSink)->priv;
 
-    GMutexLocker lock(priv->bufferMutex);
+    WebCore::GMutexLocker lock(priv->bufferMutex);
     priv->unlocked = false;
     return TRUE;
 }
