--- vbsfilter-1.3.c.neu.orig	Wed Feb 14 10:45:06 2001
+++ vbsfilter-1.3.c	Wed Feb 14 12:40:38 2001
@@ -2,6 +2,10 @@
 #include <stdio.h>
 #include <string.h>
 #include <sysexits.h>
+#include <ctype.h>
+#include <stdlib.h>
+#include <netdb.h>
+#include <unistd.h>
 #include "libmilter/mfapi.h"
 
 /*
@@ -172,7 +176,7 @@
 sfsistat mlfi_body(SMFICTX *ctx, u_char *bodyp, size_t bodylen) {
 	struct mlfiPriv *priv = MLFIPRIV;
 	
-	priv->body = (char *) realloc(priv->body, priv->len + bodylen);
+	priv->body = (char *) realloc(priv->body, priv->len + bodylen + 1);
 
 	if (!priv->body) {
 		/* can't accept this message right now */
@@ -181,6 +185,7 @@
 
 	memcpy((u_char*)(priv->body+priv->len), bodyp, bodylen);
 	priv->len += bodylen;
+	priv->body[priv->len] = 0;
 
 	/* continue processing */
 	return SMFIS_CONTINUE;
