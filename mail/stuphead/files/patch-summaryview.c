--- src/summaryview.c.orig	Tue Aug 17 14:15:52 2004
+++ src/summaryview.c	Tue Aug 17 14:16:29 2004
@@ -2522,6 +2522,7 @@
 		gtk_widget_grab_focus(summaryview->folderview->ctree);
 		return;
 	default:
+		break;
 	}
 
 	if (!summaryview->selected) {
@@ -2625,6 +2626,7 @@
 		summary_save_as(summaryview);
 		break;
 	default:
+		break;
 	}
 }
 
@@ -2692,6 +2694,7 @@
 		prefs_common.summary_col_subject = width;
 		break;
 	default:
+		break;
 	}
 }
 
