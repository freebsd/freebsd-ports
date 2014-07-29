--- physconv.c.orig	1998-08-30 15:58:16.000000000 -0500
+++ physconv.c	2009-06-25 22:22:21.000000000 -0500
@@ -260,12 +260,16 @@
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
@@ -797,7 +801,7 @@
 				} else {
 					showdims(&d);
 					printf("Convert to: ");
-					gets(buf);
+					fgets(buf, sizeof(buf), stdin);
 					trimspc(buf);
 					if (buf[0]=='?') {
 						showdims(&d);
