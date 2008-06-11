--- vttest.c.orig	Sat Oct  7 15:38:17 2006
+++ vttest.c	Sat Oct  7 15:40:43 2006
@@ -15,8 +15,9 @@
 #include	<sys/types.h>
 #include	<stdio.h>
 #include	<fcntl.h>
+#define HAVE_TERMIO_H
 #ifdef HAVE_TERMIO_H 
-#include        <termio.h> 
+#include        <termios.h> 
 #else 
 #include	<setjmp.h> 
 #include	<signal.h> 
@@ -49,15 +50,15 @@
 {
 	char   buff[512];
 	int x=0, w, rc=0, fd;
-	struct termio ttold, ttraw;
+	struct termios ttold, ttraw;
 
 	/* Set the terminal in a raw mode */
 	if ( (fd=open("/dev/tty", O_RDWR, 0666)) < 0 )
 		return(0);
 
-	if ( ioctl(fd, TCGETA, (char *)&ttold) < 0 )
+	if ( tcgetattr(fd, &ttold) < 0 )
 		return(0);
-	(void) ioctl(fd, TCGETA, (char *)&ttraw);
+	(void) tcgetattr(fd, &ttraw);
 
 #ifdef HAVE_TERMIO_H
 #ifdef SEVEN_BIT
@@ -65,7 +66,7 @@
 #else
 	ttraw.c_iflag=(IGNBRK);   /* turn off all input control */
 #endif /* SEVEN_BIT */
-        ttraw.c_oflag &= ~(OLCUC | ONLCR | OCRNL | ONLRET);
+        ttraw.c_oflag &= ~(ONLCR | OCRNL | ONLRET);
                                         /* disable output post-processing */
         ttraw.c_lflag = 0;
         ttraw.c_cc[VMIN]=0;          /* 1 or more chars satisfy read */
@@ -75,7 +76,7 @@
 	ttraw.sg_flags &= ~ECHO;	/* turn ECHO off */
 #endif /* HAVE_TERMIO_H */
 
-        if (ioctl(fd, TCSETAW, (char *)&ttraw) < 0)
+        if (tcsetattr(fd, TCSADRAIN, &ttraw) < 0)
                 return(0);
 
   	write(fd,"\033[c", 3);	/* Vt100 test: ESC [ c */
@@ -87,9 +88,13 @@
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
@@ -98,7 +103,7 @@
 	alarm(0);
 	signal(SIGALRM, SIG_DFL);
 #endif
-        (void) ioctl(fd, TCSETAW, (char *)&ttold);
+        (void) tcsetattr(fd, TCSADRAIN, &ttold);
 	(void) close(fd);
 
 #ifdef not_defined		/* Print out the response for debugging */
