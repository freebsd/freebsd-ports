$FreeBSD$

--- smbval/smbencrypt.c.orig	Fri Jan 10 01:29:40 2003
+++ smbval/smbencrypt.c	Fri Jan 10 01:29:44 2003
@@ -24,7 +24,6 @@
 #include <arpa/inet.h>
 #include <dirent.h>
 #include <string.h>
-#include <sys/vfs.h>
 #include <netinet/in.h>
 #include <ctype.h>
 #include "smblib-priv.h"
