--- src/document/download.c.orig	Mon Dec 16 17:47:54 2002
+++ src/document/download.c	Tue Dec 24 14:06:00 2002
@@ -1,4 +1,4 @@
-/* Downloads managment */
+/* session.c -*-mode: c; c-basic-offset: 8-*-
 /* $Id: download.c,v 1.61 2002/12/16 22:47:54 zas Exp $ */
 
 #ifdef HAVE_CONFIG_H
@@ -583,6 +583,95 @@
 	}
 }
 
+int create_process(unsigned char *szfn)
+{
+	int pid, rgfd[ 2 ];
+	unsigned char *command = szfn;
+
+	pipe(rgfd);
+	if ((pid = fork()) < 0) {
+		close(rgfd[ 0 ]);
+		close(rgfd[ 1 ]);
+		return -1;
+	} else if (pid > 0) {
+		/* parent:
+		   1. The write "handle" returned to the caller is
+		   the canonical write end of the pipe pair.
+		   2. We close the "read" end since we are not using
+		   it and we don't want fd leakage.
+		   3. The first thing the child is going to do is
+		   fork and exit, so the process we want to run will
+		   belong to init, not us. It's gross, but more
+		   portable than becoming a session leader. So we wait.
+		*/
+		int status;
+
+		wait(&status);
+		close(rgfd[ 0 ]);
+		return rgfd[ 1 ];
+	} else {
+		/* child:
+		   at this point, if something goes wrong,
+		   there's really nothing we can do about it;
+		   the parent will get a SIGPIPE when it
+		   tries to write.
+		*/
+		int fdnull = open("/dev/null", O_WRONLY);
+
+		/* 
+		   fork again, so we are re-parented to init
+		   and avoid the whole SIGCHLD issue. if we
+		   aren't the chile, we die. We use _exit so 
+		   we don't flush any output buffers.
+		*/
+		if ((pid = fork()) != 0) {
+			_exit(0);
+		}
+
+		/* grandchild:
+		   If we got here, we are in the grandchild process,
+		   whose parent has died and been reaped. Our parent
+		   should be init (the primordial process).
+
+		   Before we exec the command, we need to set up
+		   stdin, stdout, and stderr.
+		   1. stdin gets a dup2 of the "read" end of the 
+		   pipe.
+		   2. stdout and stderr get copies of an fd opened
+		   to "/dev/null".
+		*/
+		dup2(rgfd[ 0 ], 0);
+		dup2(fdnull, 1);
+		dup2(fdnull, 2);
+		
+		/* 
+		   Now we can close everything that is still
+		   open, because we've dup'd what we needed.
+		*/
+		close(fdnull);
+		close(rgfd[ 0 ]);
+		close(rgfd[ 1 ]);
+
+		/* 
+		   Let the shell handle the command. We use
+		   a hard-coded /bin/sh to avoid someone setting
+		   SHELL to an odd value and causing damage.
+
+		   Any damage that is done to the user should be
+		   self-inflicted, not the result of a maliciously
+		   set environment var.
+		*/
+		execlp("/bin/sh", "/bin/sh", "-c", command, 0);
+
+		/* failure:
+		   If we get here, there's not much to do but die.
+		   We use _exit so we don't flush any output buffers.
+		*/
+		_exit(1);
+	}
+	/* Trust me, you can't get here. */
+}
+
 
 int
 create_download_file(struct terminal *term, unsigned char *fi, int safe, int resume)
@@ -601,6 +690,14 @@
 
 	wd = get_cwd();
 	set_cwd(term->cwd);
+	if (*fi == '|') {
+		/*
+		  This will hook any command that saves
+		  a file to disk and hijack it to write
+		  to the input of a process. Cool, huh?
+		*/
+		return create_process(fi + 1);
+	}
 
 	if (!get_opt_int("document.download.overwrite") || resume) {
 		file = expand_tilde(file);
