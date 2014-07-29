--- charset.c.orig	2010/10/30 02:38:17
+++ charset.c	2010/10/30 02:40:03
@@ -408,6 +408,10 @@
 control_char(c)
 	LWCHAR c;
 {
+#ifdef COLOR_LESS
+	if (c == ESC)
+		return 0;
+#endif
 	c &= 0377;
 	return (chardef[c] & IS_CONTROL_CHAR);
 }
@@ -423,6 +427,20 @@
 	/* {{ This buffer can be overrun if LESSBINFMT is a long string. }} */
 	static char buf[32];
 
+#ifdef COLOR_LESS
+	if(c == ESC)
+		sprintf(buf, "%c", ESC);
+	else
+	{
+		c &= 0377;
+		if (!control_char(c))
+			sprintf(buf, "%c", c);
+		else if (!control_char(c ^ 0100))
+			sprintf(buf, "^%c", c ^ 0100);
+		else
+			sprintf(buf, binfmt, c);
+	}
+#else
 	c &= 0377;
 	if ((c < 128 || !utf_mode) && !control_char(c))
 		SNPRINTF1(buf, sizeof(buf), "%c", (int) c);
@@ -446,6 +464,7 @@
 #endif
 	else
 		SNPRINTF1(buf, sizeof(buf), binfmt, c);
+#endif
 	return (buf);
 }
 
