--- src/filed/filed.c	23 Dec 2003 20:23:15 -0000	1.21
+++ src/filed/filed.c	2 Jan 2004 17:21:21 -0000	1.22
@@ -211,10 +211,10 @@
       init_stack_dump();	      /* set new pid */
    }
 
-   drop(uid, gid);
-
    /* Maximum 1 daemon at a time */
    create_pid_file(me->pid_directory, "bacula-fd", me->FDport);
+
+   drop(uid, gid);
 
 #ifdef BOMB
    me += 1000000;
