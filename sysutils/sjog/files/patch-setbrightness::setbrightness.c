--- setbrightness/setbrightness.c.orig	Fri Nov 15 12:59:59 2002
+++ setbrightness/setbrightness.c	Fri Nov 15 13:02:36 2002
@@ -4,41 +4,52 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifndef __FreeBSD__
 #include <sys/io.h>
+#endif
 #include <sys/mman.h>
 #include <dirent.h>
 #include <ctype.h>
-#include <malloc.h>
 #include <string.h>
 #include <signal.h>
+#ifndef __FreeBSD__
 #include <getopt.h>
 #include <linux/pci.h>
+#endif
 #include <sys/time.h>
+#ifdef __FreeBSD__
+#include <machine/cpufunc.h>
+#include "../src/sonypi.h"
+#endif
 
 
 #define BRIGHTNESS 0x96
 #define DATA_REG 0x62
 #define CST_REG  0x66
 
+#ifndef __FreeBSD__
 typedef unsigned short u16;
+#define OUTW outw
+#define OUTB outb
+#endif
 
 static void ecr_set(u16 value)
 {
 	while (inw(CST_REG) & 3) usleep(1);
-	outw(0x81, CST_REG);
+	OUTW(0x81, CST_REG);
 	while (inw(CST_REG) & 2) usleep(1);
-	outw(BRIGHTNESS, DATA_REG);
+	OUTW(BRIGHTNESS, DATA_REG);
 	while (inw(CST_REG) & 2) usleep(1);
-	outw(value, DATA_REG);
+	OUTW(value, DATA_REG);
 	while (inw(CST_REG) & 2) usleep(1);
 }
 
 static u16 ecr_get()
 {
 	while (inw(CST_REG) & 3) usleep(1);
-	outb(0x80, CST_REG);
+	OUTB(0x80, CST_REG);
 	while (inw(CST_REG) & 2) usleep(1);
-	outb(BRIGHTNESS, DATA_REG);
+	OUTB(BRIGHTNESS, DATA_REG);
 	while (inw(CST_REG) & 2) usleep(1);
 	return (inw(DATA_REG)&255);
 }
@@ -52,14 +63,17 @@
 int main(int argc, char *argv[])
 {
 
+#ifndef __FreeBSD__
 	ioperm(DATA_REG, 0x08, 1); 
+#endif
         if( geteuid() != 0 )
                 fprintf(stdout, "You must be root to use %s\n", argv[0]);
 
         else if( argc == 2 && strcmp(argv[1], "--read") == 0) 
+	{
+	    iopl(3);
 	    printf("%d\n", ecr_get());
-
-        else if( argc != 2 || !isdigit(argv[1][0])) 
+        } else if( argc != 2 || !isdigit(argv[1][0])) 
                 usage();
 
         else
