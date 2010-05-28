--- relayd/relayd.c.orig	2010-05-27 11:19:46.619119949 +0200
+++ relayd/relayd.c	2010-05-27 11:20:21.164983766 +0200
@@ -306,6 +306,8 @@
 #endif
 	event_dispatch();
 
+	main_shutdown(env);
+	/* NOTREACHED */
 	return (0);
 }
 
@@ -972,6 +974,7 @@
 	if (timercmp(&tv_next, &tv, >))
 		bcopy(&tv_next, &tv, sizeof(tv));
 
+	event_del(ev);
 	event_set(ev, fd, event, fn, arg);
 	event_add(ev, &tv);
 }
@@ -1129,6 +1132,7 @@
 	}
 	pn->key = strdup(pk->key);
 	if (pn->key == NULL) {
+		free(pn);
 		log_warn("out of memory");
 		return (NULL);
 	}
