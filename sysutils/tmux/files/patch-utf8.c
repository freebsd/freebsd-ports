commit 65e4c57d3a554940ed5cada6dfeff403ae8d9572
Author: Nicholas Marriott <nicholas.marriott@gmail.com>
Date:   2016-04-29 12:47:15 +0100

    Only assume width 1 when wcwidth() returns -1 on non-OpenBSD platforms.

--- utf8.c.orig	2016-03-02 18:29:06 UTC
+++ utf8.c
@@ -115,8 +115,24 @@ utf8_width(wchar_t wc)
 	int	width;
 
 	width = wcwidth(wc);
-	if (width < 0 || width > 0xff)
+	if (width < 0 || width > 0xff) {
+		log_debug("Unicode %04x, wcwidth() %d", wc, width);
+
+#ifndef __OpenBSD__
+		/*
+		 * Many platforms (particularly and inevitably OS X) have no
+		 * width for relatively common characters (wcwidth() returns
+		 * -1); assume width 1 in this case. This will be wrong for
+		 * genuinely nonprintable characters, but they should be
+		 * rare. We may pass through stuff that ideally we would block,
+		 * but this is no worse than sending the same to the terminal
+		 * without tmux.
+		 */
+		if (width < 0)
+			return (1);
+#endif
 		return (-1);
+	}
 	return (width);
 }
 
