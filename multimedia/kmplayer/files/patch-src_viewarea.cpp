--- src/viewarea.cpp.orig	2018-12-22 19:33:17 UTC
+++ src/viewarea.cpp
@@ -2535,7 +2535,7 @@ void VideoOutput::useIndirectWidget (bool inderect) {
             if (!m_plain_window) {
                 xcb_screen_t* scr = m_view->viewArea()->d->screen_of_display(connection, QX11Info::appScreen());
                 m_plain_window = xcb_generate_id(connection);
-                uint32_t values[] = { scr->black_pixel, m_input_mask };
+                uint32_t values[] = { scr->black_pixel, static_cast<uint32_t>(m_input_mask) };
 #if QT_VERSION >= 0x050600
                 int devicew = (int)(width() * devicePixelRatioF());
                 int deviceh = (int)(height() * devicePixelRatioF());
