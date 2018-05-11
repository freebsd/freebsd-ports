--- config.def.h.orig	2018-05-07 14:54:13 UTC
+++ config.def.h
@@ -38,7 +38,7 @@
 
 /* The path for the wide-character curses library. */
 #ifndef NCURSESW_INCLUDE_H
-    #if defined(__APPLE__) || (defined(BSD) && !defined(__linux__))
+    #if defined(__APPLE__) || (defined(BSD) && !defined(__linux__)) || defined(__FreeBSD__)
         #define NCURSESW_INCLUDE_H <curses.h>
     #else
         #define NCURSESW_INCLUDE_H <ncursesw/curses.h>
@@ -50,6 +50,8 @@
 #ifndef FORKPTY_INCLUDE_H
     #if defined(__APPLE__) || (defined(BSD) && !defined(__linux__))
         #define FORKPTY_INCLUDE_H <util.h>
+    #elif defined(__FreeBSD__)
+        #define FORKPTY_INCLUDE_H <libutil.h>
     #else
         #define FORKPTY_INCLUDE_H <pty.h>
     #endif
