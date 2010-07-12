--- src/common.c.orig
+++ src/common.c
@@ -84,9 +84,10 @@ char *strndup(const char *s, size_t n)
 }
 #endif /* HAVE_STRNDUP */
 
-void update_uname(void)
+int update_uname(void)
 {
 	uname(&info.uname_s);
+	return 0;
 }
 
 double get_time(void)
@@ -268,7 +269,7 @@ void format_seconds_short(char *buf, unsigned int n, long seconds)
  * Populated while initialising text objects in construct_text_object(). */
 static struct update_cb {
 	struct update_cb *next;
-	void (*func)(void);
+	int (*func)(void);
 	pthread_t thread;
 	sem_t start_wait, end_wait;
 
@@ -286,7 +287,7 @@ static int threading_started = 0;
 
 /* Register an update callback. Don't allow duplicates, to minimise side
  * effects and overhead. */
-void add_update_callback(void (*func)(void))
+void add_update_callback(int (*func)(void))
 {
 	struct update_cb *uc = &update_cb_head;
 
@@ -376,7 +377,12 @@ static void *run_update_callback(void *data)
 	while (1) {
 		if (sem_wait(&ucb->start_wait)) pthread_exit(NULL);
 		if (ucb->running == 0) pthread_exit(NULL);
-		(*ucb->func)();
+		if((*ucb->func)()) {
+			ucb->next = ucb;	//this is normally not be possible, so we use it to show that there was a critical error
+			sem_post(&ucb->end_wait);
+			sem_post(&ucb->end_wait);
+			pthread_exit(NULL);
+		}
 		if (sem_post(&ucb->end_wait)) pthread_exit(NULL);
 	}
 }
@@ -411,8 +417,14 @@ void update_stuff(void)
 	}
 	/* need to synchronise here, otherwise locking is needed (as data
 	 * would be printed with some update callbacks still running) */
-	for (uc = update_cb_head.next; uc; uc = uc->next)
+	for (uc = update_cb_head.next; uc; uc = uc->next) {
 		sem_wait(&uc->end_wait);
+		if(uc == uc->next) {
+			pthread_join(uc->thread, NULL);
+			free(uc);
+			exit(EXIT_FAILURE);
+		}
+	}
 
 	/* XXX: move the following into the update_meminfo() functions? */
 	if (no_buffers) {
