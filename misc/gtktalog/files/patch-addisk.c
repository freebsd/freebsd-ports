--- src/gtktalog/addisk.c.ori	Tue Apr  9 00:12:25 2002
+++ src/gtktalog/addisk.c	Tue Apr  9 00:15:54 2002
@@ -240,7 +240,7 @@
 gboolean
 mount_disk (CONFIG * my_config)
 {
-#if defined(OS_LINUX) || defined(OS_NETBSD) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_NETBSD) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   int pid, status;
   char *args[3];
   int nargs;
@@ -290,20 +290,6 @@
 
   set_message_to_display (g_string_new (_("Mount failed! Disk in use?")));
   return (FALSE);
-#elif defined(OS_FREEBSD)
-  int status;
-  struct iso_args args;
-
-  args.export.ex_flags = MNT_EXRDONLY;
-  args.fspec = "/dev/cd0a";	// Will be changed
-  args.export.ex_root = -2;
-  status =
-    mount (MOUNT_CD9660, my_config->mount_point->str, MNT_RDONLY, &args);
-  /* error saved in errno variable, do something with it */
-  if (status == 0)
-    return (TRUE);
-  else
-    return (FALSE);
 #elif defined(OS_PPC_DARWIN)
   /*
    * with MacOS X, CD are mounted automatically so, 
@@ -319,7 +305,7 @@
 gboolean
 umount_disk (CONFIG * my_config)
 {
-#if defined(OS_LINUX) || defined(OS_NETBSD) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_NETBSD) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   int pid, status;
   int nargs;
   char *args[3];
@@ -361,14 +347,6 @@
       return (FALSE);
     }
   return (TRUE);
-#elif defined(OS_FREEBSD)
-  int status;
-
-  status = unmount (my_config->mount_point->str, NULL);
-  if (status == 0)
-    return (TRUE);
-  else
-    return (FALSE);
 #elif defined(OS_PPC_DARWIN)
   set_message_to_display (g_string_new (_("Umount failed! Disk in use?")));
   return (FALSE);
