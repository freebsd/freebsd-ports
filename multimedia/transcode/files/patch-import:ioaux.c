--- import/ioaux.c.orig	Thu Mar 27 19:14:55 2003
+++ import/ioaux.c	Thu Mar 27 19:17:21 2003
@@ -36,8 +36,14 @@
    while (r < len) {
       n = read (fd, buf + r, len - r);
 
-      if (n <= 0)
-	  return r;
+	  if (n == 0)
+		break;
+	  if (n < 0) {
+		if (errno == EINTR)
+		  continue;
+		else
+		  break;
+	  } 
       r += n;
    }
 
@@ -51,9 +57,12 @@
 
    while (r < len) {
       n = write (fd, buf + r, len - r);
-      if (n < 0)
-         return n;
-      
+      if (n < 0) {
+		if (errno == EINTR)
+		  continue;
+		else
+		  break;
+	  }
       r += n;
    }
    return r;
