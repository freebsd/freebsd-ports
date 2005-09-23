--- libbalsa/mailbox_mbox.c.orig	Tue Sep 20 13:01:57 2005
+++ libbalsa/mailbox_mbox.c	Thu Sep 22 20:32:25 2005
@@ -26,6 +26,7 @@
 
 #include <gmime/gmime-stream-fs.h>
 
+#include <sys/stat.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -215,7 +216,7 @@ libbalsa_mailbox_mbox_create(const gchar
 	if(!create)
 	    return(-1);
 
-	if ((fd = creat(path, S_IRUSR | S_IWUSR)) == -1) {
+	if ((fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR)) == -1) {
 	    g_warning("An error:\n%s\n occurred while trying to "
 		      "create the mailbox \"%s\"\n",
 		      strerror(errno), path);
