
$FreeBSD$

--- wpa_ctrl.c.orig
+++ wpa_ctrl.c
@@ -88,7 +88,7 @@
 	}
 
 	ctrl->local.sun_family = AF_UNIX;
-	snprintf(ctrl->local.sun_path, sizeof(ctrl->local.sun_path),
+	snprintf(ctrl->local.sun_path, sizeof(ctrl->local.sun_path) - 1,
 		 "/tmp/wpa_ctrl_%d-%d", getpid(), counter++);
 	if (bind(ctrl->s, (struct sockaddr *) &ctrl->local,
 		    sizeof(ctrl->local.sun_family) +
@@ -99,10 +99,9 @@
 	}
 
 	ctrl->dest.sun_family = AF_UNIX;
-	strncpy(ctrl->dest.sun_path, ctrl_path, sizeof(ctrl->dest.sun_path));
+	strncpy(ctrl->dest.sun_path, ctrl_path, sizeof(ctrl->dest.sun_path) - 1);
 	if (connect(ctrl->s, (struct sockaddr *) &ctrl->dest,
-		    sizeof(ctrl->dest.sun_family) +
-		    strlen(ctrl->dest.sun_path)) < 0) {
+		    sizeof(ctrl->dest)) < 0) {
 		close(ctrl->s);
 		unlink(ctrl->local.sun_path);
 		free(ctrl);
