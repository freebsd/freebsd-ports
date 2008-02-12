--- src/tsocks/tsocks.c.orig	2008-02-10 23:39:35.000000000 +0100
+++ src/tsocks/tsocks.c	2008-02-10 23:44:16.000000000 +0100
@@ -572,6 +572,7 @@
    int setevents = 0;
    int monitoring = 0;
    struct connreq *conn, *nextconn;
+   struct pollfd *ufds;
 
    /* If we're not currently managing any requests we can just 
     * leave here */
