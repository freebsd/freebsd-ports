--- global.c.orig	Mon Jun 10 10:29:25 2002
+++ global.c	Mon Jun 10 10:30:51 2002
@@ -585,20 +585,20 @@
     off_t len1, len2;
 
     if ((fd1 = open(work, O_RDONLY, 0)) < 0) {
-	nn_exitmsg("%s %s", work, strerror(errno));
+	msg("%s %s", work, strerror(errno));
 	return(2);
     }
     if ((fd2 = open(copy, O_RDONLY, 0)) < 0) {
-	nn_exitmsg("%s %s", copy, strerror(errno));
+	msg("%s %s", copy, strerror(errno));
 	return(2);
     }
 
     if (fstat(fd1, &sb1)) {
-	nn_exitmsg("%s %s", work, strerror(errno));
+	msg("%s %s", work, strerror(errno));
 	return(2);
     }
     if (fstat(fd2, &sb2)) {
-	nn_exitmsg("%s %s", copy, strerror(errno));
+	msg("%s %s", copy, strerror(errno));
 	return(2);
     }
 
