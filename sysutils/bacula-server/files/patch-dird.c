--- src/dird/dird.c	27 Dec 2003 13:14:12 -0000	1.41
+++ src/dird/dird.c	2 Jan 2004 17:21:21 -0000	1.42
@@ -197,10 +197,10 @@
       init_stack_dump();	      /* grab new pid */
    }
 
-   drop(uid, gid);		      /* reduce priveleges if requested */
-
    /* Create pid must come after we are a daemon -- so we have our final pid */
    create_pid_file(director->pid_directory, "bacula-dir", director->DIRport);
+
+   drop(uid, gid);		      /* reduce priveleges if requested */
 
 /* signal(SIGHUP, reload_config); */
