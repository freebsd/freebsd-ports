--- runjob.c.orig	2000-06-20 23:12:18 UTC
+++ runjob.c
@@ -39,26 +39,14 @@ static int
 temp_file()
 /* Open a temporary file and return its file descriptor */
 {
-    const int max_retries = 50;
-    char *name;
-    int fd, i;
+    int fd;
+    char name[] = "/tmp/anacron.XXXXXX";
+
+    fd = mkstemp(name);
 
-    i = 0;
-    name = NULL;
-    do
-    {
-	i++;
-	free(name);
-	name = tempnam(NULL, NULL);
-	if (name == NULL) die("Can't find a unique temporary filename");
-	fd = open(name, O_RDWR | O_CREAT | O_EXCL | O_APPEND,
-		  S_IRUSR | S_IWUSR);
-	/* I'm not sure we actually need to be so persistent here */
-    } while (fd == -1 && errno == EEXIST && i < max_retries);
-    
     if (fd == -1) die_e("Can't open temporary file");
     if (unlink(name)) die_e("Can't unlink temporary file");
-    free(name);
+
     fcntl(fd, F_SETFD, 1);    /* set close-on-exec flag */
     return fd;
 }
