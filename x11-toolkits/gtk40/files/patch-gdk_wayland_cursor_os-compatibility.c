--- gdk/wayland/cursor/os-compatibility.c.orig	2024-09-13 14:11:36 UTC
+++ gdk/wayland/cursor/os-compatibility.c
@@ -32,10 +32,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <glib.h>
-
-#ifdef HAVE_MEMFD_CREATE
 #include <sys/mman.h>
-#endif
 
 #include "os-compatibility.h"
 
