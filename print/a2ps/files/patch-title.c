--- lib/title.c.orig	2015-09-25 08:26:23 UTC
+++ lib/title.c
@@ -88,6 +88,8 @@ title (stream, c, center_p, format, va_a
   if (center_p)
     for (padding = 0 ; padding < 79 - len ; padding += 2)
       putc (' ', stream);
+  va_end(args);
+  VA_START(args, format);
 # if HAVE_VPRINTF || _LIBC
   vfprintf (stream, format, args);
 # else
