--- src/eb.h.orig	2020-08-23 11:39:07 UTC
+++ src/eb.h
@@ -290,7 +290,7 @@ extern char *sslCerts;		/* ssl certificates to validat
 extern int verifyCertificates;	/* is a certificate required for the ssl connection? */
 extern int displayLength;	// when printing a line
 extern int formatLineLength;	// when formatting html
-bool formatOverflow;
+extern bool formatOverflow;
 extern int webTimeout, mailTimeout;
 extern uchar browseLocal;
 extern bool sqlPresent;		/* Was edbrowse compiled with SQL built in? */
