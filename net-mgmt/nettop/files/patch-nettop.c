--- nettop.c.orig	Fri Nov  9 11:50:03 2001
+++ nettop.c	Fri Apr 21 18:19:58 2006
@@ -57,7 +57,7 @@
 #include <signal.h>
 #include <unistd.h>
 #include <limits.h>
-#ifdef sun
+#ifdef __FreeBSD__
 #include <netinet/in_systm.h>
 #endif
 #include <netinet/in.h>
@@ -361,6 +361,7 @@
 				}
 				break;
 			default:
+				break;
 			}
 		}
 	}
