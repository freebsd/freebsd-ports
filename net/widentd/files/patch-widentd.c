--- widentd.c.orig
+++ widentd.c
@@ -41,9 +41,6 @@
 
 #define SERVICE			("ident")	/* 113 */
 
-int             verbose = 0;
-const char     *user = UID;
-const char     *os = OS;
 
 static void
 usage(void)
@@ -64,6 +61,9 @@ main(int argc, char **argv)
 	fd_set         *lst = malloc(FD_SETSIZE), *xst = malloc(FD_SETSIZE),
 	               *wst = malloc(FD_SETSIZE);
 	struct addrinfo *ports, *p;
+	int             verbose = 0;
+	const char     *user = UID;
+	const char     *os = OS;
 	const char	* node = NULL, * service = SERVICE;
 	struct addrinfo hints;
 	int s = -1;
