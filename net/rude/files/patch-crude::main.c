--- crude/main.c.orig	Thu Jun 13 14:15:21 2002
+++ crude/main.c	Mon Jun 23 17:49:02 2003
@@ -294,9 +294,7 @@
    */
   if((user_id == 0) && (priority > 0)){
     /* Try to lock the memory to avoid paging delays */
-    if(mlockall(MCL_CURRENT | MCL_FUTURE) < 0){
-      RUDEBUG1("crude: memory lock failed: %s\n", strerror(errno));
-    }
+      RUDEBUG1("crude: memory lock unsupported\n");
 
     /* Switch to Round-Robin-Real-Time Scheduling */
     p.sched_priority = priority;
@@ -346,8 +344,6 @@
       RUDEBUG7("crude: program priority restored\n");
     }
 
-    /* Release the locked memory */
-    munlockall();
   }                                                                             
 
   if(ps_flag){ print_stats(); }
@@ -663,8 +659,8 @@
 
     /* print average delay as sign and absolute value */
     if ( (sec < 0) || (usec < 0) ) {
-      sec  = llabs( sec );
-      usec = llabs( usec );
+      sec  = -1*( sec );
+      usec = -1*( usec );
       printf("Delay: average = -%lld.%06llu   ", sec, usec);
     } else {
       printf("Delay: average = %lld.%06llu   ", sec, usec);
