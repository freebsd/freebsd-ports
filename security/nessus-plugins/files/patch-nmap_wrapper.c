--- plugins/nmap_wrapper/nmap_wrapper.c.orig	Wed Aug  7 16:59:06 2002
+++ plugins/nmap_wrapper/nmap_wrapper.c	Fri Aug 16 16:13:48 2002
@@ -612,14 +612,12 @@
  Hostinfos = hostinfos;
  
 #ifdef FAKE_PROGRESS_BAR
+ signal(SIGALRM, SIG_IGN);
+ alarm(0);
  signal(SIGALRM, update_progress_bar);
  alarm(1);
 #endif
  fp = ptycall_nmap (desc, NMAP, argv, &nmap_pid);
-#ifdef FAKE_PROGRESS_BAR
- signal(SIGALRM, SIG_IGN);
- alarm(0);
-#endif
  destroy_argv (argv);
  }
 
