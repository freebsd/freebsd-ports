--- grub/asmstub.c.orig	Sat Jan 24 01:52:56 2004
+++ grub/asmstub.c	Sat Jan 24 19:11:23 2004
@@ -779,7 +779,7 @@
 
       if (disks[drive].flags == -1)
 	{
-	  if (read_only || errno == EACCES || errno == EROFS)
+	  if (read_only || errno == EACCES || errno == EROFS || errno == EPERM)
 	    {
 	      disks[drive].flags = open (devname, O_RDONLY);
 	      if (disks[drive].flags == -1)
