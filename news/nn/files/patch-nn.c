--- nn.c.orig
+++ nn.c
@@ -74,7 +74,6 @@
 extern int      seq_cross_filtering;
 extern char    *news_active;
 extern long     unread_articles;
-extern long     initial_memory_break;
 extern int      first_time_user;
 extern int      also_cross_postings;
 
@@ -745,7 +744,6 @@
     int             say_welcome = 0, cmd;
     flag_type       access_mode = 0;
     char           *mask = NULL;
-    initial_memory_break = (long) sbrk(0);
 
 #ifdef USE_MALLOC_H
 
