--- nwserv.c.orig	Thu Jan 23 23:54:21 2003
+++ nwserv.c	Thu Jan 23 23:54:55 2003
@@ -1269,9 +1269,6 @@
     fprintf(stderr, "You must have root permission !\n");
     exit(1);
   }
-#ifdef FREEBSD
-  set_emu_tli();
-#endif
   tzset();
   while (++j < argc)  {
     char *a=argv[j];
@@ -1341,6 +1338,9 @@
 #endif
   setgroups(0, NULL);
   init_tools(IN_PROG, init_mode);
+#ifdef FREEBSD
+  set_emu_tli();
+#endif
   set_sigs(0);
   get_ini(1);
 #if !IN_NWROUTED
