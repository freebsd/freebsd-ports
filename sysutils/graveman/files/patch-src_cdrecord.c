--- src/cdrecord.c.orig	Fri May 27 19:37:14 2005
+++ src/cdrecord.c	Sun Jun 11 06:53:32 2006
@@ -187,7 +187,13 @@
   }
   
   Lstatus = g_io_channel_read_line(Astd, &Lbuffer, NULL, NULL, NULL);  
-  if (!Lbuffer) return TRUE;
+  if (!Lbuffer) {
+    if (Lstatus == G_IO_STATUS_EOF) {
+      *Lcont = 2;
+      return FALSE;
+    } else
+      return TRUE;
+  }
     
   g_strstrip(Lbuffer);  
 _DEB("scan lecteur = %s\n", Lbuffer);
