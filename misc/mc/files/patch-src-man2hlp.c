--- src/man2hlp.c.orig	Tue Jan 21 05:23:42 2003
+++ src/man2hlp.c	Tue Jun 15 03:15:09 2004
@@ -611,8 +611,7 @@
 	/* Bold text or italics text */
 	if (buffer[0] == '.' && (buffer[1] == 'I' || buffer[1] == 'B'))
 	    for (buffer += 2; *buffer == ' ' || *buffer == '\t'; buffer++);
-	strncpy (old, buffer, sizeof (old) - 1);
-	old[sizeof (old) - 1] = 0;
+	g_strlcpy (old, buffer, sizeof (old));
 	link_flag = 3;
 	break;
     case 3:
