--- lib/printlen.c.orig	1999-08-31 17:42:42 UTC
+++ lib/printlen.c
@@ -28,15 +28,12 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 unsigned long strtoul ();
 
 static int
-int_printflen (const char *format, va_list *args)
+int_printflen (const char *format, va_list ap)
 {
   const char *cp;
   int total_width = 0;
   int width = 0;
-  va_list ap;
 
-  memcpy (&ap, args, sizeof (va_list));
-
   for (cp = format ; *cp ; cp++)
     {
       if (*cp != '%')
@@ -99,7 +96,7 @@ int_printflen (const char *format, va_list *args)
 int
 vprintflen (const char *format,  va_list args)
 {
-  return int_printflen (format, &args);
+  return int_printflen (format, args);
 }
 
 int
