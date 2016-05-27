--- tmate-ssh-client.c.orig	2016-03-29 03:30:07 UTC
+++ tmate-ssh-client.c
@@ -3,6 +3,7 @@
 #include <stdio.h>
 #include <event.h>
 #include <assert.h>
+#include <netinet/in.h>
 
 #include "tmate.h"
 #include "window-copy.h"
