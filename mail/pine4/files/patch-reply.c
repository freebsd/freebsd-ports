--- pine/reply.c.orig	Wed Jan 24 18:35:05 2001
+++ pine/reply.c	Sun Feb 11 12:15:03 2001
@@ -4967,23 +4967,24 @@
 char *
 generate_message_id()
 {
-    static short osec = 0, cnt = 0;
+    struct timeval tp;
+    struct timezone tzp;
+    static short osec = 0;
+    static char cnt;
     char        *id;
     time_t       now;
     struct tm   *now_x;
 
     now   = time((time_t *)0);
     now_x = localtime(&now);
-    id    = (char *)fs_get(128 * sizeof(char));
+    id    = (char *)fs_get(384 * sizeof(char));
 
-    if(now_x->tm_sec == osec){
-	cnt++;
-    }else{
-	cnt = 0;
-	osec = now_x->tm_sec;
-    }
-    sprintf(id,"<Pine.%.4s.%.20s.%02d%02d%02d%02d%02d%02d%X.%d@%.50s>",
-	    SYSTYPE, pine_version, (now_x->tm_year) % 100, now_x->tm_mon + 1,
+    cnt = 'A';
+    if(gettimeofday(&tp, &tzp) == 0)
+	    cnt += (time_t)tp.tv_usec % ('Z' - 'A');
+
+    sprintf(id,"<%d%02d%02d%02d%02d%02d.%c%d@%s>",
+	    (now_x->tm_year) + 1900, now_x->tm_mon + 1,
 	    now_x->tm_mday, now_x->tm_hour, now_x->tm_min, now_x->tm_sec, 
 	    cnt, getpid(), ps_global->hostname);
 
