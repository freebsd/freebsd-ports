--- gksu/gksu.c.orig	Wed Oct 26 14:50:43 2005
+++ gksu/gksu.c	Tue Nov 15 00:28:41 2005
@@ -499,6 +499,7 @@
 
 pid_t test_lock(const char* fname)
 {
+   struct flock fl;
    int FD = open(fname, 0);
    if(FD < 0) {
       if(errno == ENOENT) {
@@ -509,7 +510,6 @@
 	 return(-1);
       }
    }
-   struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
@@ -529,6 +529,7 @@
 
 int get_lock(const char *File)
 {
+   struct flock fl;
    int FD = open(File,O_RDWR | O_CREAT | O_TRUNC,0640);
    if (FD < 0)
    {
@@ -546,13 +547,13 @@
    fcntl(FD,F_SETFD, FD_CLOEXEC);
       
    // Aquire a write lock
-   struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    if (fcntl(FD,F_SETLK,&fl) == -1)
    {
+      int Tmp;
       if (errno == ENOLCK)
       {
 	 g_warning(_("Not using locking for nfs mounted lock file %s"), File);
@@ -561,7 +562,7 @@
 	 return dup(0);       // Need something for the caller to close	 
       }      
       
-      int Tmp = errno;
+      Tmp = errno;
       close(FD);
       errno = Tmp;
       return -1;
@@ -759,6 +760,7 @@
   GtkWidget *dialog = GTK_WIDGET(data);
 
   int retvalue = 0;
+  int lock = 0;
 
   if (prompt)
     gksuui_dialog_set_prompt (GKSUUI_DIALOG(dialog), prompt);
@@ -782,7 +784,6 @@
       g_free (msg);
     }
 
-  int lock = 0;
   if (grab)
     lock = grab_keyboard_and_mouse (dialog);
   retvalue = gtk_dialog_run (GTK_DIALOG(dialog));
@@ -1206,6 +1207,7 @@
 
   if (print_pass)
     {
+      int lock = 0;
       if (!gksuui_dialog_get_message (GKSUUI_DIALOG(dialog)))
 	{
 	  gchar *msg = 
@@ -1216,7 +1218,6 @@
 	  g_free (msg);
 	}
 
-      int lock = 0;
       if (grab)
 	lock = grab_keyboard_and_mouse (dialog);
       retvalue = gtk_dialog_run (GTK_DIALOG(dialog));
