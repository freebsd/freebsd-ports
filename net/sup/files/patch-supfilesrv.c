--- supfilesrv.c.orig	Fri Oct 25 10:27:43 2002
+++ supfilesrv.c	Fri Oct 25 10:30:55 2002
@@ -254,7 +254,6 @@
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <sys/file.h>
-#include <sys/dir.h>
 #if	MACH
 #include <sys/ioctl.h>
 #endif
@@ -277,7 +276,6 @@
 #endif	/* lint */
 
 extern int errno;
-long time ();
 uid_t getuid ();
 
 int maxchildren;
@@ -1217,7 +1215,8 @@
 	register int x,fd;
 	register int fdtmp;
 	char sys_com[STRINGLENGTH], temp_file[STRINGLENGTH], rcs_file[STRINGLENGTH];
-        union wait status;
+        int status;
+	int wstat;
 	char *uconvert(),*gconvert();
 	int sendfile ();
 
@@ -1252,11 +1251,11 @@
                                         sprintf(sys_com, "co -q -p %s %s > %s 2> /dev/null\n", rcs_release, t->Tname, rcs_file);
 #endif
                                         /*loginfo("using rcs mode \"%s\"\n", sys_com);*/
-                                        status.w_status = system(sys_com);
-                                        if (status.w_status < 0 || status.w_retcode) {
+                                        status = system(sys_com);
+                                        if (WTERMSIG(status) < 0 || WEXITSTATUS(status)) {
                                                 /* Just in case */
                                                 unlink(rcs_file);
-                                                if (status.w_status < 0) {
+                                                if (WTERMSIG(status) < 0) {
                                                         goaway ("We died trying to \"%s\"", sys_com);
                                                         t->Tmode = 0;
                                                 }
@@ -1285,15 +1284,54 @@
 #endif
                         if (fd == -1) {
                                 if (docompress) {
-                                        tmpnam(temp_file);
-                                        sprintf(sys_com, "gzip -c < %s > %s\n", t->Tname, temp_file);
-                                        if (system(sys_com) != 0) {
-                                                /* Just in case */
-                                                unlink(temp_file);
-                                                goaway ("We died trying to \"%s\"", sys_com);
-                                                t->Tmode = 0;
-                                        }
-                                        fd = open (temp_file,O_RDONLY,0);
+					FILE *tf;
+					int pid;
+					int i;
+
+					tf = tmpfile();
+					if (tf == NULL) {
+						goaway("no temp file");
+						t->Tmode = 0;
+						goto out;
+					}
+					pid = fork();
+					switch (pid) {
+					case -1:	/* fail */
+						goaway("Could not fork");
+						t->Tmode = 0;
+						fclose(tf);
+						break;
+					case 0:		/* child */
+						close(1);
+						dup(fileno(tf));/* write end */
+						for(i = 3; i < 64; i++)
+							close(i);
+						execl("/usr/bin/gzip", "sup-gzip", "-c", t->Tname, 0);
+						execl("/usr/local/bin/gzip", "sup-gzip", "-c", t->Tname, 0);
+						execlp("gzip", "sup-gzip", "-c", t->Tname, 0);
+						perror("gzip");
+						_exit(1); /* pipe breaks */
+					default:	/* parent */
+						wait(&wstat);
+						if (WIFEXITED(wstat) &&
+						    WEXITSTATUS(wstat) > 0) {
+							fclose(tf);
+							goaway("gzip failed!");
+							t->Tmode = 0;
+							goto out;
+						}
+						if (WIFSIGNALED(wstat)) {
+							fclose(tf);
+							goaway("gzip died!");
+							t->Tmode = 0;
+							goto out;
+						}
+						fd = dup(fileno(tf));
+						fclose(tf);
+						lseek(fd, 0, 0);
+						break;
+					}
+			out:
                                 }
                                 else
                                         fd = open (t->Tname,O_RDONLY,0);
