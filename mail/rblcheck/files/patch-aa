--- rblcheck.c.orig	Thu Nov  8 14:05:27 2001
+++ rblcheck.c	Wed May  1 08:19:16 2002
@@ -28,8 +28,10 @@
 #include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/nameser.h>
+#include <arpa/inet.h>
 #include <resolv.h>
 #include <netdb.h>
+#include <unistd.h>
 
 /*-- PORTABILITY ------------------------------------------------------------*/
 
@@ -184,7 +186,7 @@
  * domain. If "txt" is non-zero, we perform a TXT record lookup. We
  * return the text returned from a TXT match, or an empty string, on
  * a successful match, or NULL on an unsuccessful match. */
-char * rblcheck( int a, int b, int c, int d, char * rbldomain, int txt )
+char * rblcheck( struct in_addr a, char * rbldomain, int txt )
 {
 	char * domain;
 	char * result = NULL;
@@ -195,12 +197,15 @@
 	const u_char * cend;
 	const u_char * rend;
 	int len;
+	u_char *p;
+	int i, j;
 
 	/* 16 characters max in a dotted-quad address, plus 1 for null */
 	domain = ( char * )malloc( 17 + strlen( rbldomain ) );
 
+	p = (u_char *)&a;
 	/* Create a domain name, in reverse. */
-	sprintf( domain, "%d.%d.%d.%d.%s", d, c, b, a, rbldomain );
+	sprintf( domain, "%d.%d.%d.%d.%s", p[3], p[2], p[1], p[0], rbldomain );
 
 	/* Make our DNS query. */
 	res_init();
@@ -242,8 +247,8 @@
 	cp = answer + sizeof( HEADER );
 	while( *cp != '\0' )
 	{
-		a = *cp++;
-		while( a-- )
+		i = *cp++;
+		while( i-- )
 			cp++;
 	}
 
@@ -258,8 +263,8 @@
 	cp += ( NS_INT16SZ * 2 ) + NS_INT32SZ;
 
 	/* Get the length and end of the buffer. */
-	NS_GET16( c, cp );
-	cend = cp + c;
+	NS_GET16( i, cp );
+	cend = cp + i;
 
 	/* Iterate over any multiple answers we might have. In
 	   this context, it's unlikely, but anyway. */
@@ -267,10 +272,10 @@
 	rend = result + RESULT_SIZE - 1;
 	while( cp < cend && rp < rend )
 	{
-		a = *cp++;
-		if( a != 0 )
-			for( b = a; b > 0 && cp < cend && rp < rend;
-			  b-- )
+		i = *cp++;
+		if( i != 0 )
+			for( j = i; j > 0 && cp < cend && rp < rend;
+			  j-- )
 			{
 				if( *cp == '\n' || *cp == '"' ||
 				  *cp == '\\' )
@@ -289,22 +294,39 @@
  * RBL listing, handling output of results if necessary. */
 int full_rblcheck( char * addr )
 {
-	int a, b, c, d;
+	struct hostent *ent;
+	struct in_addr a;
 	int count = 0;
+	int rblchecking = 0;
 	char * response;
 	struct rbl * ptr;
+	int fail;
+	int c;
 
 	for( ptr = rblsites; ptr != NULL; ptr = ptr->next )
 	{
-		if( sscanf( addr, "%d.%d.%d.%d", &a, &b, &c, &d ) != 4
-		  || a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255
-		  || d < 0 || d > 255 )
-		{
+		fail = 0;
+		if ((ent = gethostbyname(addr)) != NULL) {
+			memcpy(&a, ent->h_addr_list[0], sizeof(a));
+			if (ent->h_addr_list[1]) {
+				if (!quiet && rblchecking == 0)
+					fprintf(stderr,
+					    "%s resolved to mutiple addresses: ",
+					    addr);
+			}
+			if (!quiet && rblchecking++ == 0)
+				fprintf(stderr, "checking %s\n", inet_ntoa(a));
+		} else {
+			if (!inet_aton(addr, &a))
+				fail++;
+		}
+
+		if (fail) {
 			fprintf( stderr, "%s: warning: invalid address `%s'\n",
 			  progname, addr );
 			return 0;
 		}
-		response = rblcheck( a, b, c, d, ptr->site, txt );
+		response = rblcheck( a, ptr->site, txt );
 		if( !quiet || response )
 			printf( "%s %s%s%s%s%s%s", addr,
 			  ( !quiet && !response ? "not " : "" ),
