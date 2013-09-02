--- src/TimelineView.cxx.orig	2008-10-29 13:46:23.000000000 +0300
+++ src/TimelineView.cxx	2013-08-30 17:22:00.908622066 +0400
@@ -206,13 +206,15 @@
 			cl = get_clip( _x, _y );
 			if ( cl && ( _x < get_screen_position( cl->position(), cl->track()->stretchFactor() ) + 8 ) ) {
 				if ( current_cursor != FL_CURSOR_WE ) {
-					flmm_cursor( window(), &Flmm_Cursor_Shape(clip_a_cursor_crsr) );
+					Flmm_Cursor_Shape cs(clip_a_cursor_crsr);
+					flmm_cursor( window(), &cs );
 					//window()->cursor( FL_CURSOR_WE, fl_rgb_color(254,254,254), fl_rgb_color(1,1,1) );
 					current_cursor = FL_CURSOR_WE;
 				}
 			} else if ( cl &&  ( _x > get_screen_position( cl->position() + (cl->length()+1), cl->track()->stretchFactor() ) - 8 ) ) {
 				if ( current_cursor != FL_CURSOR_NE ) {
-					flmm_cursor( window(), &Flmm_Cursor_Shape(clip_b_cursor_crsr) );
+					Flmm_Cursor_Shape cs(clip_b_cursor_crsr);
+					flmm_cursor( window(), &cs );
 					current_cursor = FL_CURSOR_NE;
 				}
 			} else {
