--- tools/gpgparsemail.c.orig	Mon Jun 19 18:18:11 2006
+++ tools/gpgparsemail.c	Mon Jun 19 18:18:55 2006
@@ -24,6 +24,9 @@
    for the content of the line.  Several options are available to
    scrutinize the message.  S/MIME and OpenPGP support is included. */
 
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -145,6 +148,7 @@
   return p;
 }
 
+#ifndef HAVE_STPCPY
 static char *
 stpcpy (char *a,const char *b)
 {
@@ -154,7 +158,7 @@
   
   return (char*)a;
 }
-
+#endif
 
 static int
 run_gnupg (int smime, int sig_fd, int data_fd, int *close_list)
