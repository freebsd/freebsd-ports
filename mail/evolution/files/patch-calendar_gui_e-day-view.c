--- calendar/gui/e-day-view.c.orig	Mon Aug  2 13:04:10 2004
+++ calendar/gui/e-day-view.c	Mon Aug  2 13:04:59 2004
@@ -3235,7 +3235,7 @@
 	case GDK_SCROLL_DOWN:
 		e_day_view_scroll (day_view, -E_DAY_VIEW_WHEEL_MOUSE_STEP_SIZE);
 		return TRUE;
-	default:
+	default:;
 	}
 
 	return FALSE;
@@ -3255,7 +3255,7 @@
 	case GDK_SCROLL_DOWN:
 		e_day_view_scroll (day_view, -E_DAY_VIEW_WHEEL_MOUSE_STEP_SIZE);
 		return TRUE;
-	default:
+	default:;
 	}
 
 	return FALSE;
