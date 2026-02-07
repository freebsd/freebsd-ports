Do not use O_WRONLY, if we plan on reading from this file again!

	-mi

--- src/resource.c	Fri Jan  9 12:16:21 1998
+++ src/resource.c	Fri Jul 13 12:21:46 2001
@@ -556,3 +556,3 @@
 	fprintf(stderr, "Knews: creating config file %s\n", path);
-	fd = open_mkdir(path, O_WRONLY|O_TRUNC|O_EXCL|O_CREAT, True);
+	fd = open_mkdir(path, O_RDWR|O_TRUNC|O_EXCL|O_CREAT, True);
 	if (fd < 0) {
