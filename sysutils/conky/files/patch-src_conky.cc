--- src/conky.cc.orig	2016-07-20 16:53:48 UTC
+++ src/conky.cc
@@ -129,7 +129,7 @@
 #include <microhttpd.h>
 #endif
 
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD_kernel__) && (__FreeBSD_kernel__ + 0)
 #include <bsd/bsd.h>
 #endif
 
@@ -728,13 +728,6 @@ int percent_print(char *buf, int size, u
 	return spaced_print(buf, size, "%u", pad_percents.get(*state), value);
 }
 
-#if defined(__FreeBSD__)
-unsigned long long llabs(long long num) {
-       if(num < 0) return -num;
-       else return num;
-}
-#endif
-
 /* converts from bytes to human readable format (K, M, G, T)
  *
  * The algorithm always divides by 1024, as unit-conversion of byte
@@ -1811,8 +1804,8 @@ int draw_each_line_inner(char *s, int sp
 #endif /* BUILD_X11 */
 				case GOTO:
 					if (current->arg >= 0) {
-						cur_x = (int) current->arg;
 #ifdef BUILD_X11
+						cur_x = (int) current->arg;
 						//make sure shades are 1 pixel to the right of the text
 						if(draw_mode == BG) cur_x++;
 #endif /* BUILD_X11 */
@@ -1934,7 +1927,9 @@ static void draw_text(void)
 
 static void draw_stuff(void)
 {
+#ifdef BUILD_X11
 	text_offset_x = text_offset_y = 0;
+#endif
 #ifdef BUILD_IMLIB2
 	cimlib_render(text_start_x, text_start_y, window.width, window.height);
 #endif /* BUILD_IMLIB2 */
