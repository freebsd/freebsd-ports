diff -c /home/tg/work/FreeBSD/ports/local/rman/work/rman-3.1/rman.c.orig /home/tg/work/FreeBSD/ports/local/rman/work/rman-3.1/rman.c
--- /home/tg/work/FreeBSD/ports/local/rman/work/rman-3.1/rman.c.orig	Sun Mar 30 00:45:18 2003
+++ /home/tg/work/FreeBSD/ports/local/rman/work/rman-3.1/rman.c	Mon May 12 18:59:41 2003
@@ -3729,11 +3729,15 @@
 	   q=strchr(p, ' ');
 	   if (q!=NULL) *q++='\0';
 	   strcpy(manName, p);
-	   for (p=q; isspace(*p); p++) /*nada*/;
-	   if (*p) {
-		   q=strchr(p,' ');
-		   if (q!=NULL) *q++='\0';
-		   strcpy(manSect, p);
+	   if (q) {
+	     for (p=q; isspace(*p); p++) /*nada*/;
+	     if (*p) {
+		q=strchr(p,' ');
+		if (q!=NULL) *q++='\0';
+		strcpy(manSect, p);
+	     }
+	   } else {
+		strcpy(manSect, "?");
 	   }
 	 }
 	 sI=0;


