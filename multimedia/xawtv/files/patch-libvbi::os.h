--- libvbi/os.h.orig	Sun Mar 10 13:20:37 2002
+++ libvbi/os.h	Sun Mar 10 13:19:45 2002
@@ -1,4 +1,4 @@
-#ifndef OS_H
+#if !defined(OS_H) && !defined(BSD)
 #define OS_H
 
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBsd__) \
