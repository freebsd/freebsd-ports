--- src/gnome-keyring-manager-util.c.orig	Wed May 18 16:41:35 2005
+++ src/gnome-keyring-manager-util.c	Sat Jul  2 02:12:38 2005
@@ -354,6 +354,10 @@ gkm_get_application_path (void)
  	{
 	  path = g_file_read_link ("/proc/self/exe", NULL);
 	}     
+#elif defined(__FreeBSD__)
+	{
+	  path = g_file_read_link ("/proc/curproc/file", NULL);
+	}
 #endif
     }
 
