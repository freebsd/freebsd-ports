--- source3/winbindd/winbindd.c.orig	2026-01-20 15:42:54 UTC
+++ source3/winbindd/winbindd.c
@@ -1038,7 +1038,7 @@ static bool winbindd_setup_listeners(void)
 	if (pub_state->fd == -1) {
 		goto failed;
 	}
-	rc = listen(pub_state->fd, 5);
+	rc = listen(pub_state->fd, DEFAULT_LISTEN_BACKLOG);
 	if (rc < 0) {
 		goto failed;
 	}
@@ -1070,7 +1070,7 @@ static bool winbindd_setup_listeners(void)
 	if (priv_state->fd == -1) {
 		goto failed;
 	}
-	rc = listen(priv_state->fd, 5);
+	rc = listen(priv_state->fd, DEFAULT_LISTEN_BACKLOG);
 	if (rc < 0) {
 		goto failed;
 	}
