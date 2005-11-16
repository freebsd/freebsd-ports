--- src/pstree.c.orig	Tue Oct 11 05:18:48 2005
+++ src/pstree.c	Wed Nov 16 17:31:59 2005
@@ -590,7 +590,7 @@
       {
 	if (!(path = malloc (strlen (PROC_BASE) + strlen (de->d_name) + 10)))
 	  exit (2);
-	sprintf (path, "%s/%d/stat", PROC_BASE, pid);
+	sprintf (path, "%s/%d/status", PROC_BASE, pid);
 	if ((file = fopen (path, "r")) != NULL)
 	  {
 	    empty = 0;
@@ -608,90 +608,10 @@
 		perror (path);
 		exit (1);
 	      }
-            fread(readbuf, BUFSIZ, 1, file) ;
-            if (ferror(file) == 0) 
-            {
-              memset(comm, '\0', COMM_LEN+1);
-              tmpptr = strrchr(readbuf, ')'); /* find last ) */
-              /* We now have readbuf with pid and cmd, and tmpptr+2
-               * with the rest */
-              /*printf("readbuf: %s\n", readbuf);*/
-              if (sscanf(readbuf, "%*d (%15[^)]", comm) == 1)
-              {
-                /*printf("tmpptr: %s\n", tmpptr+2);*/
-                if (sscanf(tmpptr+2, "%*c %d", &ppid) == 1)
-                {
-/*
-	    if (fscanf
-		(file, "%d (%s) %c %d", &dummy, comm, (char *) &dummy,
-		 &ppid) == 4)
- */
-		{
-		   DIR *taskdir;
-		   struct dirent *dt;
-		   char *taskpath;
-		   char *threadname;
-		   int thread;
-		   
-		   if (!(taskpath = malloc(strlen(path) + 10))) {
-		      exit (2);
-		   }
-		   sprintf (taskpath, "%s/task", path);
-		   
-		   if ((taskdir=opendir(taskpath))!=0) {
-		      /* if we have this dir, we're on 2.6 */
-		      if (!(threadname = malloc(strlen(comm) + 3))) {
-			 exit (2);
-		      }
-		      sprintf(threadname,"{%s}",comm);
-		      while ((dt = readdir(taskdir)) != NULL) {
-			 if ((thread=atoi(dt->d_name)) !=0) {
-			    if (thread != pid) {
-#ifdef WITH_SELINUX
-			       add_proc(threadname, thread, pid, st.st_uid, NULL, 0, scontext);
-#else  /*WITH_SELINUX*/
-			       add_proc(threadname, thread, pid, st.st_uid, NULL, 0);
-#endif /*WITH_SELINUX*/
-			    }
-			 }
-		      }
-		      free(threadname);
-		      (void) closedir(taskdir);
-		   }
-		   free(taskpath);
-		}
-
-		if (!print_args)
-#ifdef WITH_SELINUX
-		  add_proc(comm, pid, ppid, st.st_uid, NULL, 0, scontext);
-#else  /*WITH_SELINUX*/
-		  add_proc (comm, pid, ppid, st.st_uid, NULL, 0);
-#endif /*WITH_SELINUX*/
-		else
-		  {
-		    sprintf (path, "%s/%d/cmdline", PROC_BASE, pid);
-		    if ((fd = open (path, O_RDONLY)) < 0)
-		      {
-			perror (path);
-			exit (1);
-		      }
-		    if ((size = read (fd, buffer, (size_t) output_width)) < 0)
-		      {
-			perror (path);
-			exit (1);
-		      }
-		    (void) close (fd);
-		    if (size)
-		      buffer[size++] = 0;
-#ifdef WITH_SELINUX
-		    add_proc(comm, pid, ppid, st.st_uid, buffer, size, scontext);
-#else  /*WITH_SELINUX*/
-		    add_proc (comm, pid, ppid, st.st_uid, buffer, size);
-#endif /*WITH_SELINUX*/
-		  }
-		}
-	      }
+	    if (fscanf(file, "%s %*d %d", comm, &ppid) == 2) {
+		add_proc(comm,pid,ppid,st.st_uid,NULL,0);
 	    }
+
 	    (void) fclose (file);
 	  }
 	free (path);
