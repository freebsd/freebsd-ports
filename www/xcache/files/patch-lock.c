--- lock.c (revision 62)
+++ lock.c (revision 282)
@@ -92,5 +92,5 @@
 		}
 		size = strlen(tmpdir) + sizeof("/.xcache.lock") - 1 + 3 * 10 + 100;
-		myname = do_alloca(size);
+		myname = malloc(size);
 		snprintf(myname, size - 1, "%s%c.xcache.%d.%d.%d.lock", tmpdir, DEFAULT_SLASH, (int) getuid(), i ++, rand());
 		pathname = myname;
@@ -119,5 +119,5 @@
 
 	if (myname) {
-		free_alloca(myname);
+		free(myname);
 	}
 
