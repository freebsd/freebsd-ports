--- src/stored/stored.c	23 Dec 2003 20:23:15 -0000	1.25
+++ src/stored/stored.c	2 Jan 2004 17:21:21 -0000	1.26
@@ -185,9 +185,9 @@
       init_stack_dump();	      /* pick up new pid */
    }
 
-   drop(uid, gid);
-
    create_pid_file(me->pid_directory, "bacula-sd", me->SDport);
+
+   drop(uid, gid);
 
    /* Ensure that Volume Session Time and Id are both
     * set and are both non-zero.
