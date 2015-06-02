--- Src/Modules/zpty.c.orig	2015-06-02 06:51:05.604875000 +0200
+++ Src/Modules/zpty.c	2015-06-02 00:07:36.672596000 +0200
@@ -154,7 +154,7 @@ getptycmd(char *name)
     return NULL;
 }
 
-#ifdef USE_DEV_PTMX
+#if defined(HAVE_POSIX_OPENPT) || defined(USE_DEV_PTMX)
 
 #ifdef HAVE_SYS_STROPTS_H
 #include <sys/stropts.h>
