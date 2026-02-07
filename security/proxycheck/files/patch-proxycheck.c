--- proxycheck.c.orig	Fri Jun 13 03:07:12 2003
+++ proxycheck.c	Fri Jun 13 03:07:53 2003
@@ -974,7 +974,7 @@
     dstspec = strdup(pxybuf);
   }
 
-  dsbluser = egetenv("DSBL_USER", "anonimous");
+  dsbluser = egetenv("DSBL_USER", "anonymous");
   dsblpass = egetenv("DSBL_PASS", "");
   dsblfrom = egetenv("DSBL_FROM", dsbluser);
   dsblrcpt = egetenv("DSBL_RCPT", "listme@listme.dsbl.org");
@@ -1015,7 +1015,7 @@
   { "dsbl", dsblh, dsbld, dsble, dsbli, "[:smtpserver[:port]]",
     "attempt to submit proxy to DSBL-like system\n"
     "   DSBL settings are expected to be in environment:\n"
-    "\t$DSBL_USER - username (anonimous)\n"
+    "\t$DSBL_USER - username (anonymous)\n"
     "\t$DSBL_PASS - password (default is empty)\n"
     "\t$DSBL_COOKIE_HOST - cookie server (cookie.dsbl.org)\n"
     "\t$DSBL_COOKIE - already obtained DSBL cookie\n"
