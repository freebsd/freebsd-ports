--- upsdown/upsdown.c.orig	Wed May 18 10:14:00 2005
+++ upsdown/upsdown.c	Wed Jan 25 13:47:45 2006
@@ -154,22 +154,28 @@
       /* ＣＯＭポートのクローズ */
       close (pd);
 
+#if 0
       sprintf(command, "halt %s", arg_buf_wo_p);
       system(command);
       sleep (10);
+#endif
     }
   else if (pow == '1')
     {				/* input power restored */
       /* ＣＯＭポートのクローズ */
       close (pd);
+#if 0
       system ("reboot -i -d -p");
+#endif
     }
   else
     {				/* manual shutdown */
       /* ＣＯＭポートのクローズ */
       close (pd);
+#if 0
       sprintf(command, "halt %s", arg_buf);
       system(command);
+#endif
     }
 
   exit (0);
