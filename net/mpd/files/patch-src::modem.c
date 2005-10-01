Index: src/modem.c
===================================================================
RCS file: /cvsroot/mpd/mpd/src/modem.c,v
retrieving revision 1.4
retrieving revision 1.4.2.2
diff -u -r1.4 -r1.4.2.2
--- src/modem.c	5 Dec 2002 22:01:40 -0000	1.4
+++ src/modem.c	10 Jan 2005 23:14:03 -0000	1.4.2.2
@@ -610,10 +617,12 @@
   /* Concat prefix and message */
   va_start(args, fmt);
   vsnprintf(buf, sizeof(buf), fmt, args);
+  va_end(args);
   if (*buf != ' ')
     snprintf(buf, sizeof(buf), "[%s] chat: ", lnk->name);
   else
     *buf = '\0';
+  va_start(args, fmt);
   vsnprintf(buf + strlen(buf), sizeof(buf) - strlen(buf), fmt, args);
   va_end(args);
 
