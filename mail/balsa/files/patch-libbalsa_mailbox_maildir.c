--- libbalsa/mailbox_maildir.c.orig	Mon Jul 26 02:10:16 2004
+++ libbalsa/mailbox_maildir.c	Mon Jul 26 02:10:50 2004
@@ -27,6 +27,8 @@
 #include <libgnome/gnome-config.h>
 #include <libgnome/gnome-i18n.h>
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
