--- open.c.orig	Fri Jul 19 22:49:03 1996
+++ open.c	Wed Feb 11 12:30:24 2004
@@ -24,7 +24,12 @@
 
    int fd = 0;
    int opt, pid;
+#if defined(__FreeBSD__)
+   int vt_active;
+#else
    struct vt_stat vt;
+#define vt_active vt.v_active
+#endif
    struct passwd *pwnam=NULL;
    int vtno     = -1;
    char show    = FALSE;
@@ -33,7 +38,7 @@
    char do_wait	= FALSE;
    char as_user= FALSE;
    char vtname[sizeof VTNAME + 2]; /* allow 999 possible VTs */
-   char *cmd, *def_cmd = NULL;
+   char *cmd = NULL, *def_cmd = NULL;
 
    /*
     * I don't like using getopt for this, but otherwise this gets messy.
@@ -44,7 +49,11 @@
       switch (opt) {
 	case 'c':
 	  vtno = (int) atol(optarg);
+#if defined(__FreeBSD__)
+	  if (vtno <= 0 || vtno > 99) {	  
+#else
 	  if (vtno < 0 || vtno > 99) {	  
+#endif
 	    fprintf(stderr, "open: %s illegal vt number\n", optarg); 
 	    return 5;
 	  }
@@ -92,14 +101,23 @@
         return(3);
      }
 
+#if defined(__FreeBSD__)
+     if (ioctl(fd, VT_GETACTIVE, &vt_active) < 0) {
+	perror("open: can't get active VT\n");
+#else
      if (ioctl(fd, VT_GETSTATE, &vt) < 0) {
 	perror("open: can't get VTstate\n");
+#endif
         close(fd);
         return(4);
      }
    }
 
+#if defined(__FreeBSD__)
+   sprintf(vtname, VTNAME, vtno - 1);
+#else
    sprintf(vtname, VTNAME, vtno);
+#endif
 
 /* support for Spawn_Console; running from init
 added by Joshua Spoerri, Thu Jul 18 21:13:16 EDT 1996 */
@@ -110,7 +128,7 @@
 	dev_t console_dev;
 	ino_t console_ino;
 	uid_t console_uid;
-	char filename[NAME_MAX+12];
+	char filename[sizeof VTNAME + 2];
 
 	if (!(dp=opendir("/proc"))) {
 		perror("/proc");
@@ -118,7 +136,11 @@
 	}
 	
 	/* get the current tty */
-	sprintf(filename,"/dev/tty%d",vt.v_active);
+#if defined(__FreeBSD__)
+	sprintf(filename,VTNAME,vt_active - 1);
+#else
+	sprintf(filename,VTNAME,vt_active);
+#endif
 	if (stat(filename,&buf)) {
 		perror(filename);
 		exit(1);
@@ -204,15 +226,18 @@
         _exit (4); /* silently die */
       }
       dup(fd); dup(fd);
-
+	if (ioctl(fd, TIOCSCTTY, NULL) < 0)
+	  _exit(4);
       if (show) {
 	/* 
          * Can't tell anyone if any of these fail, so throw away
 	 * the return values 
          */
-        (void) ioctl(fd, VT_ACTIVATE, vtno);
+        if (ioctl(fd, VT_ACTIVATE, vtno) < 0)
+	    _exit(4);
         /* wait to be really sure we have switched */
-	(void) ioctl(fd, VT_WAITACTIVE, vtno);
+	if (ioctl(fd, VT_WAITACTIVE, vtno) < 0)
+	    _exit(4);
       }
       if(as_user)
 	 execlp("login","login","-f",pwnam->pw_name,NULL);
@@ -230,9 +255,11 @@
    if ( do_wait ) {
       wait(NULL);
       if (show) { /* Switch back... */
-	 (void) ioctl(fd, VT_ACTIVATE, vt.v_active);
+	 if (ioctl(fd, VT_ACTIVATE, vt_active) < 0)
+	    _exit(4);
 	 /* wait to be really sure we have switched */
-	 (void) ioctl(fd, VT_WAITACTIVE, vt.v_active);
+	 if (ioctl(fd, VT_WAITACTIVE, vt_active) < 0)
+	    _exit(4);
       }
    }
 
