--- src/grg_pwd.c.orig	Sat Nov 23 20:32:53 2002
+++ src/grg_pwd.c	Sat Nov 23 20:34:32 2002
@@ -23,7 +23,6 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
-#include <linux/fd.h>
 #include <sys/ioctl.h>
 #include <signal.h>
 
@@ -129,7 +128,6 @@
   gint fd, len;
   gchar *file;
   GRG_KEY key = NULL;
-  struct floppy_drive_struct fstruct;
 
   fd = open ("/dev/fd0", O_RDONLY);
 
@@ -138,18 +136,6 @@
     {
       grg_msg (_("Please insert a disk in the first floppy drive"),
 	       GTK_MESSAGE_ERROR, dlg);
-      return NULL;
-    }
-
-  //check for write protection
-  ioctl (fd, FDGETDRVSTAT, &fstruct);
-
-  if ((fstruct.flags >> FD_DISK_WRITABLE_BIT) & 1)
-    {
-      grg_msg (_
-	       ("The disk is not write protected. For security reasons, I'll not use it."),
-	       GTK_MESSAGE_ERROR, dlg);
-      close (fd);
       return NULL;
     }
 
