--- src/main.c.orig	Tue Jan 23 04:45:05 2007
+++ src/main.c	Tue Jan 23 04:46:29 2007
@@ -168,7 +168,7 @@
     retval = pthread_create (&thrd_data[i].thrd,
 			     NULL,
 			     thrd_func,
-			     (void *)i);
+			     (void *)(intptr_t)i);
     if (retval != 0) {
       printf ("Hrm: error creating thread %d\n", i);
       exit (-1);
@@ -178,7 +178,7 @@
       retval = pthread_create (&thrd_data[i].monitor_thrd,
 			       NULL,
 			       monitor_thrd_func,
-			       (void *)i);
+			       (void *)(intptr_t)i);
       if (retval != 0) {
 	printf ("Hrm: error creating monitor thread %d\n", i);
 	exit (-1);
