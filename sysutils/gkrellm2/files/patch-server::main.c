Index: server/main.c
diff -u server/main.c.orig server/main.c
--- server/main.c.orig	Wed Jan 29 14:21:19 2003
+++ server/main.c	Wed Jan 29 14:21:37 2003
@@ -661,8 +661,6 @@
 	read_config();
 	get_args(argc, argv);
 
-	drop_privilleges();
-
 	if (detach_flag)
 		detach_from_terminal();
 	else
@@ -674,6 +672,7 @@
 		}
 
 	gkrellm_sys_main_init();
+	drop_privilleges();
 	g_thread_init(NULL);
 
 	_GK.start_time = time(0);
