--- rude/main.c.orig	Mon Jun 23 17:38:44 2003
+++ rude/main.c	Mon Jun 23 17:40:18 2003
@@ -204,9 +204,7 @@
    */
   if((user_id == 0) && (priority > 0)){
     /* Try to lock the memory to avoid paging delays */
-    if(mlockall(MCL_CURRENT | MCL_FUTURE) < 0){
-      RUDEBUG1("rude: memory lock failed: %s\n", strerror(errno));
-    }
+      RUDEBUG1("rude: memory lock unsupported\n");
 
     /* Switch to Round-Robin-Real-Time Scheduling */
     p.sched_priority = priority;
@@ -242,8 +240,6 @@
       RUDEBUG7("rude: program priority restored\n");
     }
 
-    /* Release the locked memory */
-    munlockall();
   }
 
  rude_exit1:
@@ -275,7 +271,6 @@
     }
   }
 
-  munlockall();
   clean_up();
   exit(ret_val);
 } /* main() */
