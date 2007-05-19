diff -u -p programs/Xserver/os/xprintf.c.orig programs/Xserver/os/xprintf.c
--- os/xprintf.c.orig	Sun Jul  3 17:53:52 2005
+++ os/xprintf.c	Thu Jan 26 12:47:37 2006
@@ -39,7 +39,7 @@
 # ifdef __va_copy
 #  define va_copy __va_copy
 # else
-#  error "no working va_copy was found"
+#  define va_copy(dest, src) ((dest) = (src))
 # endif
 #endif
     
