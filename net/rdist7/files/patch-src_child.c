--- src/child.c.orig	1998-11-10 04:18:57 UTC
+++ src/child.c
@@ -189,7 +189,7 @@ static void readchild(child)
 	CHILD *child;
 {
 	char rbuf[BUFSIZ];
-	int amt;
+	ssize_t amt;
 
 	debugmsg(DM_CALL, "[readchild(%s, %d, %d) start]", 
 		 child->c_name, child->c_pid, child->c_readfd);
@@ -208,7 +208,7 @@ static void readchild(child)
 	 */
 	while ((amt = read(child->c_readfd, rbuf, sizeof(rbuf))) > 0) {
 		/* XXX remove these debug calls */
-		debugmsg(DM_MISC, "[readchild(%s, %d, %d) got %d bytes]", 
+		debugmsg(DM_MISC, "[readchild(%s, %d, %d) got %lld bytes]", 
 			 child->c_name, child->c_pid, child->c_readfd, amt);
 
 		(void) xwrite(fileno(stdout), rbuf, amt);
@@ -217,7 +217,7 @@ static void readchild(child)
 			 child->c_name, child->c_pid, child->c_readfd);
 	}
 
-	debugmsg(DM_MISC, "readchild(%s, %d, %d) done: amt = %d errno = %d\n",
+	debugmsg(DM_MISC, "readchild(%s, %d, %d) done: amt = %lld errno = %d\n",
 		 child->c_name, child->c_pid, child->c_readfd, amt, errno);
 
 	/* 
