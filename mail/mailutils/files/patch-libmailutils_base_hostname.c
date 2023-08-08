--- libmailutils/base/hostname.c.orig	2023-05-01 09:46:38 UTC
+++ libmailutils/base/hostname.c
@@ -23,6 +23,8 @@
 #include <unistd.h>
 #include <errno.h>
 #include <string.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netdb.h>
 #include <mailutils/alloc.h>
 
