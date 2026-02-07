--- physconv.c.orig	1998-08-30 13:58:16 UTC
+++ physconv.c
@@ -32,7 +32,7 @@
 #include "physdecl.h"
 
 #ifdef __PROTOTYPES__
-LOCAL void getline(FILE *fp, char *buf);
+LOCAL void get_line(FILE *fp, char *buf);
 LOCAL int evalxpon(char *s);
 LOCAL void fixplural(char *s);
 LOCAL int output_dims(FILE *fp, int const d[MAXDIM]);
@@ -86,7 +86,7 @@ EXPORT struct dimstruct *dimension_list=
 
 /*-----Functions-----*/
 
-LOCAL void getline(fp,buf)	/* Get a line from the file & doctor it up */
+LOCAL void get_line(fp,buf)	/* Get a line from the file & doctor it up */
 FILE *fp;
 char *buf;
 {
@@ -260,12 +260,16 @@ char const *s;
 {	/* read in lines from fp and do each as if typed from console */
 	FILE *fp;
 	char buf[SMALLBUF];
+	char *fullpath;
 	int oldecho;
 #ifdef TRACE
 	int oldtrace;
 #endif
 
-	if ((fp = fopen(s,"r"))==NULL) {
+	fullpath = calloc( strlen( SHAREDIR ) + strlen( s ) + 1, 1 );
+	bcopy(SHAREDIR, fullpath, strlen(SHAREDIR));
+	(void) strcat(fullpath, s);
+	if ((fp = fopen(fullpath,"r"))==NULL) {
 		printf("Can't open %s\n",s);
 		return;
 	}
@@ -276,7 +280,7 @@ char const *s;
 #endif
 	echo = FALSE;
 	while (TRUE) {
-		getline(fp,buf);
+		get_line(fp,buf);
 		if (!buf[0])
 			break;
 		do_cmd(buf);
@@ -797,7 +801,7 @@ char const *s;
 				} else {
 					showdims(&d);
 					printf("Convert to: ");
-					gets(buf);
+					fgets(buf, sizeof(buf), stdin);
 					trimspc(buf);
 					if (buf[0]=='?') {
 						showdims(&d);
