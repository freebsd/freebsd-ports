--- tests/surface-screenshot.c.orig	2015-10-24 00:02:43 UTC
+++ tests/surface-screenshot.c
@@ -188,7 +188,7 @@ trigger_binding(struct weston_keyboard *
 		const char *msg;
 
 		switch (errno) {
-		case ETIME:
+		case ETIMEDOUT:
 			msg = "failure in datetime formatting";
 			break;
 		default:
