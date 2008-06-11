--- misc.c.orig	Wed Dec 15 10:28:45 2004
+++ misc.c	Sat Oct  7 14:34:28 2006
@@ -7,10 +7,13 @@
 #include	<stdlib.h>
 #include	<string.h>
 #include	<signal.h>
+#include	<stdlib.h>
+#include	<string.h>
 
+#define HAVE_TERMIO_H
 
 #ifdef HAVE_TERMIO_H
-#include	<termio.h>
+#include	<termios.h>
 #else
 #include	<sys/ioctl.h>
 #endif  /* HAVE_TERMIO_H */
@@ -431,13 +434,13 @@
 /* Get the modes of the controlling tty and save them.  Saves
    ttymodes in tty_mode and returns -1 if ioctl fails. */
 
-struct termio tty_mode;  /* Save tty mode here */
+struct termios tty_mode;  /* Save tty mode here */
 static int tty_init=0;
 
 int tty_getmode(fd)
 int fd;
 {
-	d_zero((char *)&tty_mode, sizeof(struct termio));
+	d_zero((char *)&tty_mode, sizeof(struct termios));
 	tty_init=1;	/* Flag: we have initialized the tty_mode struct */
 
 	if ( ! isatty(fd) )
@@ -447,7 +450,7 @@
 	fprintf(stderr, "Getting tty modes for tty_mode.\r\n");
 #endif
 
-	if (ioctl(fd, TCGETA, (char *) &tty_mode) < 0)
+	if (tcgetattr(fd, &tty_mode) < 0)
 	{
 #ifdef DEBUG
 		perror("tty_getmode(): ioctl error");
@@ -464,14 +467,14 @@
 int tty_sane(fd)
 int fd;
 {
-	struct termio temp_mode;
+	struct termios temp_mode;
 
 	if ( ! isatty(fd) )
 		return(0);
 
 	if ( ! tty_init )
 	{
-		if (ioctl(fd, TCGETA, (char *) &tty_mode) < 0)
+		if (tcgetattr(fd, &tty_mode) < 0)
 			return(-1);  
 	}
 
@@ -491,7 +494,7 @@
 	temp_mode.c_cc[VEOF]=('D'^64);
 	
 	/* TCSETAW is important for letting tty input drain. */
-	if ( ioctl(fd, TCSETAW, (char *)&temp_mode) < 0 )
+	if ( tcsetattr(fd, TCSADRAIN, &temp_mode) < 0 )
 	{
 #ifdef DEBUG
 		perror("Can't set tty modes");
@@ -508,7 +511,7 @@
 int tty_raw(fd)
 int fd;     /* of tty device */
 {
-	struct termio temp_mode;
+	struct termios temp_mode;
 
 	if ( ! tty_init )
 		return(-1);
@@ -516,7 +519,7 @@
 	if ( ! isatty(fd) )
 		return(0);
 
-	if ( ioctl(fd, TCGETA, (char *)&temp_mode) < 0 )
+	if ( tcgetattr(fd, &temp_mode) < 0 )
 		return(-1);
 
 #ifdef SEVEN_BIT
@@ -524,14 +527,14 @@
 #else
 	temp_mode.c_iflag=(IGNBRK);		/* turn off all input control */
 #endif
-	temp_mode.c_oflag &= ~(OLCUC | ONLCR | OCRNL | ONLRET);
+	temp_mode.c_oflag &= ~(ONLCR | OCRNL | ONLRET);
 					/* disable output post-processing */
 	temp_mode.c_lflag = 0;
 	temp_mode.c_cc[VMIN]=1;		/* 1 or more chars satisfy read */
 	temp_mode.c_cc[VTIME]=0;	/* 10'ths of seconds between chars */
 
 	/* TCSETAW is important for letting tty input drain. */
-	if (ioctl(fd, TCSETAW, (char *) &temp_mode) < 0)
+	if (tcsetattr(fd, TCSADRAIN, &temp_mode) < 0)
 		return(-1);
 	return(0);
 }
@@ -550,7 +553,7 @@
 		return(0);
 
 	/* TCSETAW is important for letting tty input drain. */
-	if (ioctl(fd, TCSETAW, (char *) &tty_mode) < 0)
+	if (tcsetattr(fd, TCSADRAIN, &tty_mode) < 0)
 		return(-1);
 	return(0);
 }
