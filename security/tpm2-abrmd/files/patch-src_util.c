--- src/util.c.orig	2025-02-22 21:59:15 UTC
+++ src/util.c
@@ -68,7 +68,7 @@ ssize_t
 /** Write as many of the size bytes from buf to fd as possible.
  */
 ssize_t
-write_all (GOutputStream *ostream,
+g_write_all (GOutputStream *ostream,
            const uint8_t *buf,
            const size_t   size)
 {
