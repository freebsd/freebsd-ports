--- gnome-netinfo/callbacks.c.orig	Sat Dec  6 23:20:05 2003
+++ gnome-netinfo/callbacks.c	Sat Dec  6 23:20:14 2003
@@ -27,6 +27,7 @@
 #include <sys/wait.h>
 #include <unistd.h>
 #include <sys/types.h>
+#include <signal.h>
 
 #include "callbacks.h"
 #include "traceroute.h"
