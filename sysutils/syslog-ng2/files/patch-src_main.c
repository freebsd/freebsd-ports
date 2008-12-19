Patch for CVE-2008-5110

Obtained from: http://bugs.debian.org/cgi-bin/bugreport.cgi?msg=14;mbox=yes;bug=505791
Note: was not able to cleanly apply the original patch, so it was recreated
      by hand using the original submission contents

--- src/main.c.orig	2008-03-23 23:35:27.000000000 +0300
+++ src/main.c	2008-11-18 14:38:13.000000000 +0300
@@ -275,6 +275,13 @@
 {
   if (chroot_dir) 
     {
+      if (chdir(chroot_dir) < 0)
+        {
+          msg_error("Error during chdir() before chroot()",
+                    evt_tag_errno(EVT_TAG_OSERROR, errno),
+                    NULL);
+          return 0;
+        }
       if (chroot(chroot_dir) < 0) 
 	{
 	  msg_error("Error during chroot()",
