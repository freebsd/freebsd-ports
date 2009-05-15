--- src/check_bacula/authenticate.c.orig	2007-11-22 12:45:01.000000000 +0100
+++ src/check_bacula/authenticate.c	2009-05-14 20:45:52.000000000 +0200
@@ -57,7 +57,7 @@
 /* Response from SD */
 static char SDOKhello[]   = "3000 OK Hello\n";
 /* Response from FD */
-static char FDOKhello[] = "2000 OK Hello\n";
+static char FDOKhello[] = "2000 OK Hello";
 
 /* Forward referenced functions */
 
@@ -169,7 +169,7 @@
    }
    Dmsg1(110, "<stored: %s", fd->msg);
    stop_bsock_timer(tid);
-   if (strncmp(fd->msg, FDOKhello, sizeof(FDOKhello)) != 0) {
+   if (strncmp(fd->msg, FDOKhello, sizeof(FDOKhello)-1) != 0) {
       return 0;
    }
    return 1;
