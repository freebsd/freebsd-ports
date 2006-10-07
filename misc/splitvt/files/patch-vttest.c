--- vttest.c.orig	Sat Oct  7 15:38:17 2006
+++ vttest.c	Sat Oct  7 15:40:43 2006
@@ -87,9 +87,13 @@
 	setjmp(alarm_buf);
 #endif
 	while ( !alarmed && (x < 20) ) { 
-		if ( read(fd, &buff[x++], 1) <= 0 )
+		// Workaround for gcc41.  Without it, splitvt fails with
+		// "Can't initialize screen: Terminal type must be set to vt100".
+		if ( read(fd, &buff[x], 1) <= 0 )
 			break;
+		x++;
 	}
+	x++;
 	buff[x]='\0';		/* For printing, if we desire. */
   	if ( buff[0] == '\033' )	/* An escape sequence? :) */
 		rc=1;
