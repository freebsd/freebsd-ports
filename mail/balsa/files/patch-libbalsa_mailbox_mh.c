--- libbalsa/mailbox_mh.c.orig	Mon Jul 26 02:11:26 2004
+++ libbalsa/mailbox_mh.c	Mon Jul 26 02:11:39 2004
@@ -27,6 +27,8 @@
 #define _POSIX_SOURCE          1
 #include <libgnome/gnome-i18n.h>
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
