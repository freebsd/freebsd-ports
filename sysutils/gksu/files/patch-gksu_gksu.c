--- gksu/gksu.c.orig	Wed Mar 29 06:18:28 2006
+++ gksu/gksu.c	Mon May 22 16:29:36 2006
@@ -513,6 +513,7 @@
 
 pid_t test_lock(const char* fname)
 {
+   struct flock fl;
    int FD = open(fname, 0);
    if(FD < 0) {
       if(errno == ENOENT) {
@@ -523,7 +524,6 @@
 	 return(-1);
       }
    }
-   struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
@@ -543,6 +543,7 @@
 
 int get_lock(const char *File)
 {
+   struct flock fl;
    int FD = open(File,O_RDWR | O_CREAT | O_TRUNC,0640);
    if (FD < 0)
    {
@@ -560,13 +561,13 @@
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
@@ -575,7 +576,7 @@
 	 return dup(0);       // Need something for the caller to close
       }
 
-      int Tmp = errno;
+      Tmp = errno;
       close(FD);
       errno = Tmp;
       return -1;
@@ -773,6 +774,7 @@
   GtkWidget *dialog = GTK_WIDGET(data);
 
   int retvalue = 0;
+  int lock = 0;
 
   if (prompt)
     gksuui_dialog_set_prompt (GKSUUI_DIALOG(dialog), prompt);
@@ -796,7 +798,6 @@
       g_free (msg);
     }
 
-  int lock = 0;
   if (grab)
     lock = grab_keyboard_and_mouse (dialog);
   retvalue = gtk_dialog_run (GTK_DIALOG(dialog));
@@ -1220,6 +1221,7 @@
 
   if (print_pass)
     {
+      int lock = 0;
       if (!gksuui_dialog_get_message (GKSUUI_DIALOG(dialog)))
 	{
 	  gchar *msg =
@@ -1230,7 +1232,6 @@
 	  g_free (msg);
 	}
 
-      int lock = 0;
       if (grab)
 	lock = grab_keyboard_and_mouse (dialog);
       retvalue = gtk_dialog_run (GTK_DIALOG(dialog));
