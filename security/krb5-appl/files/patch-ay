--- libpty/getpty.c.orig	2009-11-05 12:15:06.000000000 -0800
+++ libpty/getpty.c	2010-04-21 21:36:45.637180364 -0700
@@ -23,13 +23,26 @@
 #include "pty-int.h"
 #include <k5-platform.h>
 
+#ifdef __FreeBSD__
+#define PTYCHARS1      "pqrsPQRS"
+#define PTYCHARS2      "0123456789abcdefghijklmnopqrstuv"
+#endif
+
+#ifndef PTYCHARS1
+#define PTYCHARS1      "pqrstuvwxyzPQRST"
+#endif
+
+#ifndef PTYCHARS2
+#define PTYCHARS2      "0123456789abcdef"
+#endif
+
 long
 ptyint_getpty_ext(int *fd, char *slave, size_t slavelength, int do_grantpt)
 {
+    int ptynum;
+    char *cp1, *cp2;
 #if !defined(HAVE__GETPTY) && !defined(HAVE_OPENPTY)
-    char *cp;
     char *p;
-    int i,ptynum;
     struct stat stb;
     char slavebuf[1024];
 #endif
@@ -112,14 +125,14 @@
 	strncpy(slave, slavebuf, slavelength);
 	return 0;
     } else {
-    	for (cp = "pqrstuvwxyzPQRST";*cp; cp++) {
+    	for (cp1 = PTYCHARS1; *cp1 != '\0'; cp1++) {
 	    snprintf(slavebuf,sizeof(slavebuf),"/dev/ptyXX");
-	    slavebuf[sizeof("/dev/pty") - 1] = *cp;
+	    slavebuf[sizeof("/dev/pty") - 1] = *cp1;
 	    slavebuf[sizeof("/dev/ptyp") - 1] = '0';
 	    if (stat(slavebuf, &stb) < 0)
 		break;
-	    for (i = 0; i < 16; i++) {
-		slavebuf[sizeof("/dev/ptyp") - 1] = "0123456789abcdef"[i];
+	    for (cp2 = PTYCHARS2; *cp2 != '\0'; cp2++) {
+		slavebuf[sizeof("/dev/ptyp") - 1] = *cp2;
 		*fd = open(slavebuf, O_RDWR);
 		if (*fd < 0) continue;
 
