--- Source/WebCore/platform/graphics/gstreamer/MediaPlayerPrivateGStreamerBase.cpp.orig	2015-02-12 01:22:34.449468000 +0100
+++ Source/WebCore/platform/graphics/gstreamer/MediaPlayerPrivateGStreamerBase.cpp	2015-02-12 01:24:42.777620000 +0100
@@ -316,7 +316,7 @@ void MediaPlayerPrivateGStreamerBase::mu
 #if USE(ACCELERATED_COMPOSITING) && USE(TEXTURE_MAPPER_GL) && !USE(COORDINATED_GRAPHICS)
 PassRefPtr<BitmapTexture> MediaPlayerPrivateGStreamerBase::updateTexture(TextureMapper* textureMapper)
 {
-    GMutexLocker lock(m_bufferMutex);
+    WebCore::GMutexLocker lock(m_bufferMutex);
     if (!m_buffer)
         return nullptr;
 
@@ -366,7 +366,7 @@ void MediaPlayerPrivateGStreamerBase::tr
     g_return_if_fail(GST_IS_BUFFER(buffer));
 
     {
-        GMutexLocker lock(m_bufferMutex);
+        WebCore::GMutexLocker lock(m_bufferMutex);
         gst_buffer_replace(&m_buffer, buffer);
     }
 
@@ -398,7 +398,7 @@ void MediaPlayerPrivateGStreamerBase::pa
     if (!m_player->visible())
         return;
 
-    GMutexLocker lock(m_bufferMutex);
+    WebCore::GMutexLocker lock(m_bufferMutex);
     if (!m_buffer)
         return;
 
