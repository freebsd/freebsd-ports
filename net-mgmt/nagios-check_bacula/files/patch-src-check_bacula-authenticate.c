--- src/check_bacula/authenticate.c.org	2009-09-28 16:16:01.000000000 +0200
+++ src/check_bacula/authenticate.c	2009-09-28 16:16:34.000000000 +0200
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
