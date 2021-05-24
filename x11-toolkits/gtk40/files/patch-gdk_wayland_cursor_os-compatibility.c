--- gdk/wayland/cursor/os-compatibility.c.orig	2021-05-04 01:43:41 UTC
+++ gdk/wayland/cursor/os-compatibility.c
@@ -31,10 +31,7 @@
 #include <errno.h>
 #include <string.h>
 #include <stdlib.h>
-
-#ifdef HAVE_MEMFD_CREATE
 #include <sys/mman.h>
-#endif
 
 #include "os-compatibility.h"
 
