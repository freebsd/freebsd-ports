--- crypt.c.orig	2011-07-25 22:15:54.000000000 +0200
+++ crypt.c	2011-07-25 22:15:56.000000000 +0200
@@ -32,18 +32,18 @@ creadfile(char *save, int  eraseflg)
     int fildes;
     int pid;
 
-    if (eraseflg && strcmp(save, curfile) && modcheck(" first")) return;
+    if (eraseflg && strcmp(save, curfile) && modcheck(" first")) return (0);
 
     if ((fildes = open(findhome(save), O_RDONLY, 0)) < 0) {
 	error ("Can't read file \"%s\"", save);
-	return;
+	return (-1);
     }
 
     if (eraseflg) erasedb();
 
     if (pipe(pipefd) < 0) {
 	error("Can't make pipe to child");
-	return;
+	return (-1);
     }
 
     deraw(1);
@@ -68,7 +68,7 @@ creadfile(char *save, int  eraseflg)
 	    (void) kill(pid, 9);
 	    error("Can't fdopen file \"%s\"", save);
 	    (void)close(pipefd[0]);
-	    return;
+	    return (-1);
 	}
     }
 
@@ -86,6 +86,7 @@ creadfile(char *save, int  eraseflg)
 	(void) strcpy(curfile, save);
 	modflg = 0;
     }
+    return (0);
 }
 
 int
