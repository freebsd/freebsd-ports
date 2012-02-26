--- src/xine/k9xineplayer.h.orig
+++ src/xine/k9xineplayer.h
@@ -68,6 +68,7 @@ public:
     int positionAbs() {return m_posabs ;}
     int length() {return m_length;}
     xine_stream_t *getStream() { return stream;}
+    xine_video_port_t *getPort() { return vo_port;}
     bool isRunning() {return running;}
     WId wid() const { return m_wid;}
     QString title() const {return m_title;}
