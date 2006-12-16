--- src/radius.c.orig	Fri Dec 15 01:42:07 2006
+++ src/radius.c	Fri Dec 15 01:55:53 2006
@@ -922,7 +922,7 @@
 	      case RAD_MICROSOFT_MS_CHAP_ERROR:
 		/* there is a nullbyte on the first pos, don't know why */
 		if (((const char *)data)[0] == '\0') {
-		  ((const char *)data)++;
+		  data+=sizeof(const char);
 		  len--;
 		}
 		free(rad->mschap_error);
@@ -945,7 +945,7 @@
 		     * Only point at the String field if we don't think the
 		     * peer has misformatted the response.
 		     */
-		    ((const char *)data)++;
+		    data+=sizeof(const char);
 		    len--;
 		  } else
 		    Log(LG_RADIUS, ("[%s] RADIUS: %s: Warning: The MS-CHAP2-Success attribute is mis-formatted. Compensating",
