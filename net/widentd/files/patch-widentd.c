--- widentd.c.orig	2024-01-27 10:24:27 UTC
+++ widentd.c
@@ -51,7 +51,7 @@ main(int argc, char **argv)
 int
 main(int argc, char **argv)
 {
-	char            ch;
+	signed char     ch;
 	const int       yes = 1;
 	int             blog = BLOG;
 	unsigned int    i;
@@ -190,7 +190,7 @@ main(int argc, char **argv)
 
 		to.tv_sec = TIMEOUT;
 		to.tv_usec = 0;
-		memset(buff, sizeof(buff), 0);
+		memset(buff, (0), sizeof(buff));
 		do {
 			int             n;
 
