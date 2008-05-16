--- main/manager.c.orig	2008-04-02 15:49:38.000000000 +0300
+++ main/manager.c	2008-04-02 15:42:18.000000000 +0300
@@ -176,6 +176,7 @@
 	struct eventqent *eventq;
 	/* Timeout for ast_carefulwrite() */
 	int writetimeout;
+	int pending_event;
 	AST_LIST_ENTRY(mansession) list;
 };
 
@@ -2214,6 +2215,11 @@
 	fds[0].events = POLLIN;
 	do {
 		ast_mutex_lock(&s->__lock);
+		if (s->pending_event) {
+			s->pending_event = 0;
+			ast_mutex_unlock(&s->__lock);
+			return 0;
+		}
 		s->waiting_thread = pthread_self();
 		ast_mutex_unlock(&s->__lock);
 
@@ -2475,6 +2481,8 @@
 		ast_mutex_lock(&s->__lock);
 		if (s->waiting_thread != AST_PTHREADT_NULL)
 			pthread_kill(s->waiting_thread, SIGURG);
+		else
+			s->pending_event = 1;
 		ast_mutex_unlock(&s->__lock);
 	}
 	AST_LIST_UNLOCK(&sessions);
