===================================================================
RCS file: /var/www/SourceSup/cvs/sympa/sympa/src/bouncequeue.c,v
retrieving revision 1.4
retrieving revision 1.4.2.1
diff -u -r1.4 -r1.4.2.1
--- src/bouncequeue.c	2003/10/07 12:04:47	1.4
+++ src/bouncequeue.c	2005/01/27 08:54:02	1.4.2.1
@@ -1,5 +1,5 @@
 /* boucequeue.c - This program does the non-delivery deports spooling
-  RCS Identication ; $Revision: 1.4 $ ; $Date: 2003/10/07 12:04:47 $ 
+  RCS Identication ; $Revision: 1.4.2.1 $ ; $Date: 2005/01/27 08:54:02 $ 
 
   Sympa - SYsteme de Multi-Postage Automatique
   Copyright (c) 1997, 1998, 1999, 2000, 2001 Comite Reseau des Universites
@@ -30,6 +30,11 @@
 static char     buf[16384];
 static int      i, fd;
 
+/* For HP-UX */
+#ifndef EX_CONFIG
+# define EX_CONFIG 78
+#endif
+
 #ifndef CONFIG
 # define CONFIG		"/etc/sympa.conf"
 #endif
@@ -97,7 +102,7 @@
       exit(EX_NOPERM);
    }
    umask(027);
-   sprintf(qfile, "T.%s.%ld.%d", listname, time(NULL), getpid());
+   snprintf(qfile, sizeof(qfile), "T.%s.%ld.%d", listname, time(NULL), getpid());
    fd = open(qfile, O_CREAT|O_WRONLY, 0600);
    if (fd == -1)
       exit(EX_TEMPFAIL);
