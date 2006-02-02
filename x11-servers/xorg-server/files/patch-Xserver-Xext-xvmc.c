Index: programs/Xserver/Xext/xvmc.c
diff -u -p programs/Xserver/Xext/xvmc.c.orig programs/Xserver/Xext/xvmc.c
--- programs/Xserver/Xext/xvmc.c.orig	Sun Jul  3 17:53:36 2005
+++ programs/Xserver/Xext/xvmc.c	Thu Jan 26 14:22:20 2006
@@ -24,8 +24,8 @@
 
 #ifdef HAS_XVMCSHM
 #ifndef Lynx
-#include <sys/ipc.h>
 #include <sys/types.h>
+#include <sys/ipc.h>
 #include <sys/shm.h>
 #else
 #include <ipc.h>
