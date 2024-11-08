diff --git amq/amq.c.orig amq/amq.c
--- amq/amq.c.orig
+++ amq/amq.c
@@ -79,7 +79,7 @@ enum show_opt {
 static void
 time_print(time_type tt)
 {
-  time_t t = (time_t)tt;
+  time_t t = (time_t)(intptr_t)tt;
   struct tm *tp = localtime(&t);
   printf("%02d/%02d/%04d %02d:%02d:%02d",
 	 tp->tm_mon + 1, tp->tm_mday,
