--- smtpserver/smtpcmds.c	Mon Aug 19 19:19:54 2002
+++ smtpserver/smtpcmds.c.orig	Mon Aug 19 19:16:28 2002
@@ -223,7 +223,7 @@
     if (STYLE(SS->cfinfo, 'h')) {
       char argbuf[MAXHOSTNAMELEN+30];
       char *s;
-      sprintf(argbuf,"%s %s", SS->rhostname,
+      snprintf(argbuf, sizeof(argbuf), "%s %s", SS->rhostname,
 	      ((SS->ihostaddr && (SS->ihostaddr[0] != '\0'))
 	       ? SS->ihostaddr : "[0.0.0.0]"));
       if ((s = router(SS, RKEY_HELLO, 1, argbuf, strlen(argbuf))) == NULL)
