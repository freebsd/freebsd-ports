
$FreeBSD$

--- config.c.orig	Fri Aug 20 13:43:20 2004
+++ config.c	Sat Sep  4 04:04:38 2004
@@ -133,7 +133,11 @@
 	if (error) {
 		log_warnx("could not parse \"%s\": %s", s,
 		    gai_strerror(error));
+#ifdef EAI_NODATA
 		if (error == EAI_AGAIN || error == EAI_NODATA)
+#else
+		if (error == EAI_AGAIN)
+#endif
 			return (0);
 		else
 			return (-1);
