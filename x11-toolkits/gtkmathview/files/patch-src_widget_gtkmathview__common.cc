--- src/widget/gtkmathview_common.cc.orig	2007-08-17 10:02:35 UTC
+++ src/widget/gtkmathview_common.cc
@@ -909,7 +909,7 @@ gtk_math_view_button_release_event(GtkWidget* widget, 
 	  math_view->select_state == SELECT_STATE_NO &&
 	  fabs(math_view->button_press_x - event->x) <= CLICK_SPACE_RANGE &&
 	  fabs(math_view->button_press_y - event->y) <= CLICK_SPACE_RANGE &&
-	  abs(math_view->button_press_time - event->time) <= CLICK_TIME_RANGE)
+	  abs((long)math_view->button_press_time - (long)event->time) <= CLICK_TIME_RANGE)
 	{
 	  // the mouse should have not moved more than one pixel in each direction
 	  // and the time elapsed from the press event should be no more than 250ms
@@ -969,7 +969,7 @@ gtk_math_view_motion_notify_event(GtkWidget* widget, G
       (math_view->select_state == SELECT_STATE_YES ||
        fabs(math_view->button_press_x - x) > CLICK_SPACE_RANGE ||
        fabs(math_view->button_press_y - y) > CLICK_SPACE_RANGE ||
-       abs(math_view->button_press_time - event->time) > CLICK_TIME_RANGE))
+       abs((long)math_view->button_press_time - (long)event->time) > CLICK_TIME_RANGE))
     {
       if (math_view->select_state == SELECT_STATE_NO)
 	{
