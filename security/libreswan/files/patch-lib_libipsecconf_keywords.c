--- lib/libipsecconf/keywords.c.orig	2021-05-21 21:28:14 UTC
+++ lib/libipsecconf/keywords.c
@@ -28,6 +28,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <limits.h>
+#include <sys/socket.h>
 
 #include <libreswan.h>
 #include "constants.h"
