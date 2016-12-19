--- ./lib/util/strtoid.c.orig	2016-12-18 05:52:23.000000000 -0800
+++ ./lib/util/strtoid.c	2016-12-19 13:48:01.268725000 -0800
@@ -80,7 +80,7 @@
     }
     if (errno == ERANGE) {
 	if (errstr != NULL) {
-	    if (llval == LLONG_MAX)) {
+	    if (llval == LLONG_MAX)
 		*errstr = N_("value too large");
 	    else
 		*errstr = N_("value too small");
