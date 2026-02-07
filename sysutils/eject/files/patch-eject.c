--- eject.c.orig	2010-03-19 23:03:17.000000000 -0300
+++ eject.c	2010-03-19 23:03:25.000000000 -0300
@@ -52,6 +52,7 @@
 int fflag;	/* force unmount filesystem */
 int nflag;	/* not execute operation */
 int vflag;	/* verbose operation */
+int tflag;	/* close tray */
 
 /*
  *  simple eject program
@@ -69,10 +70,10 @@
     char *err;
     char *defdev;
 
-    fflag = nflag = vflag = 0;
+    fflag = nflag = vflag = tflag = 0;
     defdev = getenv("EJECT");
 
-    while ((ch = getopt(argc, argv, "fnv?")) != EOF) {
+    while ((ch = getopt(argc, argv, "fnvt?")) != EOF) {
 	switch (ch) {
 	  case 'f' :
 	    fflag = 1;
@@ -83,6 +84,9 @@
 	  case 'v' :
 	    vflag = 1;
 	    break;
+	  case 't' :
+	    tflag = 1;
+	    break;
 	  case '?' :
 	  default :
 	    usage();
@@ -104,6 +108,39 @@
     if (sts < 0) {
 	perror(program);
 	exit(1);
+    } else {
+         int c;
+         free(name);
+         char *dev_bak = malloc(MAXPATHLEN);
+         if ((c = readlink(device, dev_bak, MAXPATHLEN))>0) {
+              dev_bak[c] = '\0';
+              name = dev_bak;
+         } else {
+              free(dev_bak);
+	      name = device;
+         }
+         if (strncmp(device, "/dev/", 5) != 0)
+         {
+              int mnts;
+              struct statfs *mntbuf;
+              mnts = getmntinfo(&mntbuf, MNT_NOWAIT);
+              if (mnts == 0) {
+                  perror(program);
+                  exit(1);
+              }
+              for (ch = 0; ch < mnts; ch++) {
+                  if (strcmp(mntbuf[ch].f_mntonname, name) == 0) {
+                      device = strdup(mntbuf[ch].f_mntfromname);
+                      name = strdup(mntbuf[ch].f_mntfromname);
+                      break;
+                  }
+              }
+              if (strncmp(device, "/dev/", 5) != 0)
+              {
+                  perror(program);
+                  exit(1);
+              }
+         }
     }
 
     sts = unmount_fs(name, &err);
@@ -130,16 +167,24 @@
     char *name;
     char **device;
 {
-    int sts;
+    int sts = 0, i;
     struct stat sb;
-
-    if (asprintf(device, "/dev/%sc", name) == -1)
-	return sts;
-    if (vflag || nflag) {
-	printf("%s: using device %s\n", program, device);
-    }
-    sts = stat(*device, &sb);
-
+    const char* dev_list[] = { "/dev/%sc", "/dev/%s", "%s" };
+    for (i = 0; i < 3; i++) {
+         if ((sts = asprintf(device, dev_list[i], name)) == -1)
+              return sts;
+         if (vflag || nflag) {
+              printf("%s: trying device %s\n", program, *device);
+         }
+         sts = stat(*device, &sb);
+         if (sts) { /* stat failed, try next */
+              free(*device);
+              continue;
+         } else {
+              break;
+         }
+     }
+    
     return sts;
 }
 
@@ -174,7 +219,7 @@
     /* get proper mount information into the list */
     len = strlen(name);
     for (n = 0; n < mnts; n++) {
-	p = rindex(mntbuf[n].f_mntfromname, '/');
+	p = mntbuf[n].f_mntfromname - 1;
 	if (p == NULL) {
 	    continue;
 	}
@@ -256,14 +301,26 @@
     }
     if (!nflag) {
 	if (vflag) {
-	    printf("%s: ejecting media from %s\n", program, name);
+	    if (tflag) { 
+		printf("%s: track close on %s\n", program, name);
+	    } else {
+		printf("%s: ejecting media from %s\n", program, name);
+	    }
 	}
 	sts = ioctl(fd, CDIOCALLOW);
 	if (sts >= 0) {
-	    sts = ioctl(fd, CDIOCEJECT);
+	     if (tflag) {
+	   	sts = ioctl(fd, CDIOCCLOSE);
+	    } else {
+	   	sts = ioctl(fd, CDIOCEJECT);
+	    }
 	}
-    } else {
-	printf("%s: ejecting media from %s\n", program, name);
+     } else {
+	    if (tflag) { 
+		printf("%s: track close on %s\n", program, name);
+	    } else {
+		printf("%s: ejecting media from %s\n", program, name);
+	    }
 	sts = 0;
     }
     close(fd);
@@ -278,6 +335,6 @@
 void
 usage(void)
 {
-    fprintf(stderr, "usage: %s [-fnv] device\n", program);
+    fprintf(stderr, "usage: %s [-fnvt] device\n", program);
     exit(1);
 }
