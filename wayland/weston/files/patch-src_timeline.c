--- src/timeline.c.orig	2015-10-24 00:02:43 UTC
+++ src/timeline.c
@@ -59,7 +59,7 @@ weston_timeline_do_open(void)
 		const char *msg;
 
 		switch (errno) {
-		case ETIME:
+		case ETIMEDOUT:
 			msg = "failure in datetime formatting";
 			break;
 		default:
