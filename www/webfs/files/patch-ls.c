--- ls.c.orig	Thu Oct 18 03:37:27 2001
+++ ls.c	Wed Jan 30 08:29:37 2002
@@ -317,13 +317,13 @@
 	} else if (!S_ISREG(files[i]->s.st_mode)) {
 	    len += sprintf(buf+len,"     --  ");
 	} else if (files[i]->s.st_size < 1024*9) {
-	    len += sprintf(buf+len,"%4ld  B  ",
+	    len += sprintf(buf+len,"%4lld  B  ",
 			   files[i]->s.st_size);
 	} else if (files[i]->s.st_size < 1024*1024*9) {
-	    len += sprintf(buf+len,"%4ld kB  ",
+	    len += sprintf(buf+len,"%4lld kB  ",
 			   files[i]->s.st_size>>10);
 	} else {
-	    len += sprintf(buf+len,"%4ld MB  ",
+	    len += sprintf(buf+len,"%4lld MB  ",
 			   files[i]->s.st_size>>20);
 	}
 	
