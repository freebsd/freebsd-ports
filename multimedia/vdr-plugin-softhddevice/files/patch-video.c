--- a/video.c
+++ b/video.c
@@ -101,7 +101,9 @@
 //#include <xcb/xcb_image.h>
 //#include <xcb/xcb_event.h>
 #include <xcb/xcb_atom.h>
+#if 0
 #include <xcb/xcb_icccm.h>
+#endif
 #ifdef XCB_ICCCM_NUM_WM_SIZE_HINTS_ELEMENTS
 #include <xcb/xcb_ewmh.h>
 #else // compatibility hack for old xcb-util
