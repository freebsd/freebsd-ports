--- lib/font/fontfile/dirfile.c.orig	Fri May 31 20:45:50 2002
+++ lib/font/fontfile/dirfile.c	Thu Feb  5 00:19:57 2004
@@ -286,6 +286,10 @@
 	    status = AllocError;
 	    break;
 	case NAME:
+	    if (strlen(lexToken) >= sizeof(alias)) {
+		status = BadFontPath;
+		break;
+	    }
 	    strcpy(alias, lexToken);
 	    token = lexAlias(file, &lexToken);
 	    switch (token) {
