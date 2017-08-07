--- src/scanner.c	2016-11-10 04:58:06.000000000 -0500
+++ src/scanner.c	2017-08-06 21:58:23.868844000 -0500
@@ -33,6 +33,7 @@
 #include <assert.h>
 #include <unistd.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/un.h>
@@ -586,7 +587,6 @@
 openvas_scanner_connect_unix ()
 {
   struct sockaddr_un addr;
-  int len;
 
   openvas_scanner_socket = socket (AF_UNIX, SOCK_STREAM, 0);
   if (openvas_scanner_socket == -1)
@@ -596,10 +596,12 @@
       return -1;
     }
 
+  memset(&addr, 0, sizeof(struct sockaddr_un));
+
   addr.sun_family = AF_UNIX;
-  strncpy (addr.sun_path, openvas_scanner_unix_path, 108);
-  len = strlen (addr.sun_path) + sizeof (addr.sun_family);
-  if (connect (openvas_scanner_socket, (struct sockaddr *) &addr, len) == -1)
+  strlcpy(addr.sun_path, openvas_scanner_unix_path, sizeof(addr.sun_path));
+
+  if (connect (openvas_scanner_socket, (struct sockaddr *) &addr, SUN_LEN(&addr)) == -1)
     {
       g_warning ("%s: Failed to connect to scanner (%s): %s\n", __FUNCTION__,
                  openvas_scanner_unix_path, strerror (errno));
