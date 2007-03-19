--- libseahorse/seahorse-ssh-operation.c.orig	Sun Dec  3 23:21:01 2006
+++ libseahorse/seahorse-ssh-operation.c	Sun Dec  3 23:21:10 2006
@@ -24,6 +24,7 @@
 #include <sys/socket.h>
 #include <gnome.h>
 #include <fcntl.h>
+#include <signal.h>
 
 #include "seahorse-ssh-operation.h"
 #include "seahorse-util.h"
