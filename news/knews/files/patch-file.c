Use mkstemp instead of tmpnam. Copied from the tmpnam implementation :)

	-mi

--- src/file.c	Fri Jan  9 12:16:19 1998
+++ src/file.c	Fri Jul 13 10:41:01 2001
@@ -187,13 +187,12 @@
     int	fd;
+    static unsigned long tmpcount;
+    static char buf[L_tmpnam];
 
-    *name = tmpnam(NULL);
-    if (!*name)
-	fd = -1;
-    else {
+    (void)snprintf(buf, L_tmpnam, "%stmp.%lu.XXXXXX", P_tmpdir, tmpcount++);
+    *name = buf;
+    fd = mkstemp(buf);
+    if (fd < 0)
+	*name = NULL;
+    else
 	unlink(*name);
-	fd = open(*name, O_RDWR|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR);
-	if (fd < 0)
-	    *name = NULL;
-    }
-
     return fd;
