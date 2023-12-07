--- init.c.orig
+++ init.c
@@ -58,8 +58,6 @@
 int             in_init = 0;	/* true when parsing init file */
 int             alt_cmd_key;	/* K_ when parse_command returns AC_KEYCMD */
 
-long            initial_memory_break;	/* for :debug statistics */
-
 int             first_time_user = 0;
 
 static int      init_err = 0;	/* errors in init file */
@@ -566,17 +564,8 @@
     struct mallinfo mallinfo(), mi;
 #endif
 
-    static long     prev_mem = 0;
-    long            cur_mem;
-
     clrdisp();
     tprintf("group=%s, nart=%ld\n\r", current_group->group_name, n_articles);
-
-    cur_mem = (((long) sbrk(0)) - initial_memory_break) / 1024;
-
-    tprintf("\nMemory usage: %ldk, previous: %ldk, change: %ldk\n\r",
-	    cur_mem, prev_mem, cur_mem - prev_mem);
-    prev_mem = cur_mem;
 
 #ifdef USE_MALLOC_H
     mi = mallinfo();
