--- src/inc.c.orig	Tue Aug 17 14:42:22 2004
+++ src/inc.c	Tue Aug 17 14:42:49 2004
@@ -532,6 +532,7 @@
 		progress_dialog_set_label(state->progress, _("Quitting"));
 		break;
 	default:
+		break;
 	}
 }
 
@@ -616,6 +617,7 @@
 		alertpanel_error(_("No disk space left."));
 		break;
 	default:
+		break;
 	}
 
 	return retval;
@@ -644,6 +646,7 @@
 		alertpanel_error(_("No disk space left."));
 		break;
 	default:
+		break;
 	}
 
 	return retval;
