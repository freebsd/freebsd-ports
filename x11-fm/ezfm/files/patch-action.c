--- action.c.orig	2007-12-07 00:24:02.000000000 +0100
+++ action.c	2007-12-07 00:24:09.000000000 +0100
@@ -417,7 +417,7 @@
       execl("/bin/sh", "sh", "-c", cmdline, NULL);
       /* if we ever get to here, some thing went wrong */
       err= (errno >= 0 && errno <sys_nerr)? 
-        sys_errlist[errno] : "Unknown error";
+        (char *)sys_errlist[errno] : "Unknown error";
       write(STDERR_FILENO, err, strlen(err));
       _exit(127);
     }
