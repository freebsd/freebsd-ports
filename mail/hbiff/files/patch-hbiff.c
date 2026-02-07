--- hbiff.c.orig	Sat Nov 22 19:17:50 1997
+++ hbiff.c	Sat Dec 26 14:11:06 1998
@@ -26,6 +26,7 @@
 #include <string.h>
 #include <signal.h>
 #include <time.h>
+#include <utime.h>
 #include <errno.h>
 
 extern int errno;
@@ -276,7 +277,7 @@
 /*
  |	default mail command
  */
-	mail_command = "xterm -e mailx";
+	mail_command = "xterm -e Mail";
 	x = 100;
 	y = 100;
 	sx = 50;
@@ -517,7 +518,7 @@
  |	if no font was specified, set font to "6x10"
  */
 	if (font_name == '\0')
-		font_name = "6x10";
+		font_name = "fixed";
 
 /*
  |	get the font information
@@ -544,7 +545,7 @@
 
 	if (mail_file[0] == '\0')
 	{
-		strcpy(mail_file, "/usr/mail/");
+		strcpy(mail_file, "/var/mail/");
 		strcat(mail_file, username);
 	}
 
@@ -815,9 +816,14 @@
  |	set up bitmaps for the different mailboxes 
  |	(no mail, old mail, or new mail)
  */
-	pix[0] = XCreateBitmapFromData(disp_ptr, window_id, nomail_bits, 64, 64, foreground, background, XDefaultDepth(disp_ptr, screen));
-	pix[1] = XCreateBitmapFromData(disp_ptr, window_id, newmail_bits, 64, 64, foreground, background, XDefaultDepth(disp_ptr, screen));
-	pix[2] = XCreateBitmapFromData(disp_ptr, window_id, oldmail_bits, 64, 64, foreground, background, XDefaultDepth(disp_ptr, screen));
+	pix[0] = XCreateBitmapFromData(disp_ptr, window_id, nomail_bits, 64, 64);
+	pix[1] = XCreateBitmapFromData(disp_ptr, window_id, newmail_bits, 64, 64);
+	pix[2] = XCreateBitmapFromData(disp_ptr, window_id, oldmail_bits, 64, 64);
+/*
+	pix[0] = XCreatePixmapFromBitmapData(disp_ptr, window_id, nomail_bits, 64, 64, foreground, background, XDefaultDepth(disp_ptr, screen));
+	pix[1] = XCreatePixmapFromBitmapData(disp_ptr, window_id, newmail_bits, 64, 64, foreground, background, XDefaultDepth(disp_ptr, screen));
+	pix[2] = XCreatePixmapFromBitmapData(disp_ptr, window_id, oldmail_bits, 64, 64, foreground, background, XDefaultDepth(disp_ptr, screen));
+*/
 
 /*
  |	set up values for window
