--- src/folderview.c.orig	Tue May 29 11:43:47 2001
+++ src/folderview.c	Tue Aug 17 14:10:12 2004
@@ -1060,6 +1093,7 @@
 		BREAK_ON_MODIFIER_KEY();
 		summary_pass_key_press_event(folderview->summaryview, event);
 	default:
+		break;
 	}
 }
 
@@ -1127,6 +1161,7 @@
 		prefs_common.folder_col_total = width;
 		break;
 	default:
+		break;
 	}
 }
 
