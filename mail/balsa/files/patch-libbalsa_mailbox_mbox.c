--- libbalsa/mailbox_mbox.c.orig	Wed Nov 24 21:05:03 2004
+++ libbalsa/mailbox_mbox.c	Wed Nov 24 21:06:54 2004
@@ -27,6 +27,7 @@
 #include <libgnome/libgnome.h>
 #include <gmime/gmime-stream-fs.h>
 
+#include <sys/stat.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -195,7 +196,7 @@
 	if(!create)
 	    return(-1);
 
-	if ((fd = creat(path, S_IRUSR | S_IWUSR)) == -1) {
+	if ((fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR)) == -1) {
 	    g_warning("An error:\n%s\n occured while trying to "
 		      "create the mailbox \"%s\"\n",
 		      strerror(errno), path);
