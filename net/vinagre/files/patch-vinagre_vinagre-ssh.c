--- vinagre/vinagre-ssh.c.orig	2011-09-18 22:03:12.000000000 +0200
+++ vinagre/vinagre-ssh.c	2011-09-18 22:03:20.000000000 +0200
@@ -44,7 +44,7 @@ static const int SSH_READ_TIMEOUT = 40; 
 
 #ifdef HAVE_GRANTPT
 /* We only use this on systems with unix98 ptys */
-#define USE_PTY 1
+//#define USE_PTY 1
 #endif
 
 typedef enum {
