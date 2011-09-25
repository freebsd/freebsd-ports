--- subs.c.orig	2011-07-18 17:28:21.745080904 +0400
+++ subs.c	2011-07-18 19:39:18.999087202 +0400
@@ -121,7 +121,11 @@
 
     if (flags & O_CREAT) {
         va_start(ap, flags);
-        mode = va_arg(ap, mode_t);
+        /* Beware: default argument promotion. */
+        if (sizeof(int) > sizeof(mode_t))
+        	mode = va_arg(ap, int);
+        else
+        	mode = va_arg(ap, mode_t);
         va_end(ap);
     }
 
@@ -179,7 +183,11 @@
 
     if (flags & O_CREAT) {
         va_start(ap, flags);
-        mode = va_arg(ap, mode_t);
+        /* Beware: default argument promotion. */
+        if (sizeof(int) > sizeof(mode_t))
+        	mode = va_arg(ap, int);
+        else
+        	mode = va_arg(ap, mode_t);
         va_end(ap);
     }
 
