--- src/display-x11.cc.orig	2024-04-24 13:56:28 UTC
+++ src/display-x11.cc
@@ -683,7 +683,9 @@ bool handle_event<x_event_handler::BORDER_CROSSING>(
     conky::display_output_x11 *surface, Display *display, XEvent &ev,
     bool *consumed, void **cookie) {
   if (ev.type != EnterNotify && ev.type != LeaveNotify) return false;
+#ifdef BUILD_XINPUT
   if (window.xi_opcode != 0) return true;  // handled by mouse_input already
+#endif
 
   bool not_over_conky = ev.xcrossing.x_root <= window.x ||
                         ev.xcrossing.y_root <= window.y ||
@@ -692,11 +694,13 @@ bool handle_event<x_event_handler::BORDER_CROSSING>(
 
   if ((not_over_conky && ev.xcrossing.type == LeaveNotify) ||
       (!not_over_conky && ev.xcrossing.type == EnterNotify)) {
+#ifdef BUILD_MOUSE_EVENTS
     llua_mouse_hook(mouse_crossing_event(
         ev.xcrossing.type == EnterNotify ? mouse_event_t::AREA_ENTER
                                          : mouse_event_t::AREA_LEAVE,
         ev.xcrossing.x, ev.xcrossing.y, ev.xcrossing.x_root,
         ev.xcrossing.y_root));
+#endif
   }
   return true;
 }
