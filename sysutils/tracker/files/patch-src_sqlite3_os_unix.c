--- src/sqlite3/os_unix.c.orig	Sat Dec  9 21:35:39 2006
+++ src/sqlite3/os_unix.c	Sat Dec  9 21:36:02 2006
@@ -1110,9 +1110,7 @@
 ** Use the fdatasync() API only if the HAVE_FDATASYNC macro is defined.
 ** Otherwise use fsync() in its place.
 */
-#ifndef HAVE_FDATASYNC
 # define fdatasync fsync
-#endif
 
 /*
 ** Define HAVE_FULLFSYNC to 0 or 1 depending on whether or not
