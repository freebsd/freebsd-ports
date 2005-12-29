--- libbalsa/mailbox_mbox.c.orig	Tue Dec 27 14:54:34 2005
+++ libbalsa/mailbox_mbox.c	Thu Dec 29 01:44:01 2005
@@ -26,6 +26,7 @@
 
 #include <gmime/gmime-stream-fs.h>
 
+#include <sys/stat.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -214,7 +215,7 @@ lbm_mbox_check_files(const gchar * path,
     } else if (create) {
         gint fd;
 
-        if ((fd = creat(path, S_IRUSR | S_IWUSR)) == -1) {
+	if ((fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR)) == -1) {
             g_warning("An error:\n%s\n occurred while trying to "
                       "create the mailbox \"%s\"\n",
                       strerror(errno), path);
