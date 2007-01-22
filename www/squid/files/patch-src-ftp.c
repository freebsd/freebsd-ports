Patch for Squid bug #1857, obtained from Squid bugzilla 2007-01-15.

--- src/ftp.c.orig	Sun Feb 26 00:34:13 2006
+++ src/ftp.c	Mon Jan 15 19:46:29 2007
@@ -441,7 +441,7 @@
 	    ftpState->flags.dir_slash ? rfc1738_escape_part(ftpState->old_filepath) : ".");
     } else if (ftpState->typecode == 'D') {
 	const char *path = ftpState->flags.dir_slash ? ftpState->filepath : ".";
-	storeAppendPrintf(e, "<A HREF=\"%s/\">[As extended directory]</A>\n", html_quote(path));
+	storeAppendPrintf(e, "<A HREF=\"%s/\">[As extended directory]</A>\n", rfc1738_escape_part(path));
     }
     storeAppendPrintf(e, "<HR noshade size=\"1px\">\n");
     storeAppendPrintf(e, "<ADDRESS>\n");
@@ -689,8 +689,8 @@
 	snprintf(html, 8192, "%s\n", line);
 	return html;
     }
-    if (ftpState->flags.dir_slash)
-	snprintf(prefix, sizeof(prefix), "%s/", rfc1738_escape_part(ftpState->dirpath));
+    if (ftpState->flags.dir_slash && ftpState->dirpath && ftpState->typecode != 'D' )
+	snprintf(prefix, 2048, "%s/", rfc1738_escape_part(ftpState->dirpath));
     else
 	prefix[0] = '\0';
     /* Handle builtin <dirup> */
