--- src/conky.c.orig	2010-10-06 00:29:36.000000000 +0300
+++ src/conky.c	2010-10-10 00:06:31.000000000 +0300
@@ -2072,9 +2072,11 @@
 			OBJ(xmms2_percent) {
 				snprintf(p, p_max_size, "%2.0f", cur->xmms2.progress * 100);
 			}
+#ifdef X11
 			OBJ(xmms2_bar) {
 				new_bar(obj, p, p_max_size, (int) (cur->xmms2.progress * 255.0f));
 			}
+#endif /* X11 */
 			OBJ(xmms2_playlist) {
 				snprintf(p, p_max_size, "%s", cur->xmms2.playlist);
 			}
@@ -2150,6 +2152,7 @@
 				snprintf(p, p_max_size, "%s",
 					cur->audacious.items[AUDACIOUS_MAIN_VOLUME]);
 			}
+#ifdef X11
 			OBJ(audacious_bar) {
 				double progress;
 
@@ -2158,6 +2161,7 @@
 					atof(cur->audacious.items[AUDACIOUS_LENGTH_SECONDS]);
 				new_bar(obj, p, p_max_size, (int) (progress * 255.0f));
 			}
+#endif /* X11 */
 #endif /* AUDACIOUS */
 
 #ifdef BMPX
@@ -6007,7 +6011,7 @@
 
 void alarm_handler(void) {
 	if(childpid > 0) {
-		kill(childpid, SIGTERM);
+		kill(childpid, SIGKILL);
 	}
 }
 
