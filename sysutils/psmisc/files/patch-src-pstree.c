--- src/pstree.c.orig	Sat Apr 24 14:44:27 2004
+++ src/pstree.c	Sat Sep 10 03:02:07 2005
@@ -604,7 +604,7 @@
       {
 	if (!(path = malloc (strlen (PROC_BASE) + strlen (de->d_name) + 10)))
 	  exit (2);
-	sprintf (path, "%s/%d/stat", PROC_BASE, pid);
+	sprintf (path, "%s/%d/status", PROC_BASE, pid);
 	if ((file = fopen (path, "r")) != NULL)
 	  {
 	    empty = 0;
@@ -618,57 +618,9 @@
 		perror (path);
 		exit (1);
 	      }
-            fread(readbuf, BUFSIZ, 1, file) ;
-            if (ferror(file) == 0) 
-            {
-              memset(comm, '\0', COMM_LEN+1);
-              tmpptr = strrchr(readbuf, ')'); /* find last ) */
-              *tmpptr = '\0';
-              /* We now have readbuf with pid and cmd, and tmpptr+2
-               * with the rest */
-              /*printf("readbuf: %s\n", readbuf);*/
-              if (sscanf(readbuf, "%*d (%15c", comm) == 1)
-              {
-                /*printf("tmpptr: %s\n", tmpptr+2);*/
-                if (sscanf(tmpptr+2, "%*c %d", &ppid) == 1)
-                {
-/*
-	    if (fscanf
-		(file, "%d (%s) %c %d", &dummy, comm, (char *) &dummy,
-		 &ppid) == 4)
- */
-		if (!print_args)
-#ifdef FLASK_LINUX
-		  add_proc(comm, pid, ppid, st.st_uid, NULL, 0, sid);
-#else  /*FLASK_LINUX*/
-		  add_proc (comm, pid, ppid, st.st_uid, NULL, 0);
-#endif /*FLASK_LINUX*/
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
-#ifdef FLASK_LINUX
-		    add_proc(comm, pid, ppid, st.st_uid, buffer, size, sid);
-#else  /*FLASK_LINUX*/
-		    add_proc (comm, pid, ppid, st.st_uid, buffer, size);
-#endif /*FLASK_LINUX*/
-		  }
-		}
-	      }
+	    if (fscanf(file, "%s %*d %d", comm, &ppid) == 2) {
+                add_proc(comm,pid,ppid,st.st_uid,NULL,0);
 	    }
-	    (void) fclose (file);
 	  }
 	free (path);
       }
