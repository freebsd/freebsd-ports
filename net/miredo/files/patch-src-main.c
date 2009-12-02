--- src/main.c~	2009-12-02 11:09:42.000000000 +0900
+++ src/main.c	2009-12-02 11:10:23.000000000 +0900
@@ -218,15 +218,13 @@
 	 * Those last 3 handles will be opened as /dev/null
 	 * by later daemon().
 	 */
-	errno = 0;
-	if (closefrom (3) && (errno != EBADF))
-		return -1;
+	closefrom (3);
 
 	/*
 	 * Make sure 0, 1 and 2 are open.
 	 */
 	val = dup (2);
-	if (val < 3)
+	if (val != 3)
 		return -1;
 	close (val);
 
