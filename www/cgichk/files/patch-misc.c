--- misc.c.orig	2001-04-06 16:36:25.000000000 +0800
+++ misc.c	2011-09-06 11:17:27.000000000 +0800
@@ -83,16 +83,16 @@ void breakup_url(	char *_url,
 
 	*_port = defport;
 
-	if ( t = (char *)strstr(u, "://") )				// skip past http bit
+	if ((t = (char *)strstr(u, "://")))				// skip past http bit
 		u = t + 3;
 
 	// parse hostname and port
 
-	if (t = (char *)index(u, ':'))						// does host have a port #?
+	if ((t = (char *)index(u, ':')))						// does host have a port #?
 		hasport = 1;
 	
-	if (t = (char *)index(u, '/'))						// does host have path?
-		(char *)haspath = 1;
+	if ((t = (char *)index(u, '/')))						// does host have path?
+		haspath = 1;
 
 	if (hasport)
 		t = (char *)index(u, ':');
@@ -209,7 +209,7 @@ char *lowerstr(char *str)
 	return str;
 }
 /*----------------------------------------------------------------*/
-char *strnstr(const char *HAYSTACK, const char *NEEDLE)
+char *cgichk_strnstr(const char *HAYSTACK, const char *NEEDLE)
 {
   char	*h, *n, *res;
 
