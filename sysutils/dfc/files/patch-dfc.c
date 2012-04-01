--- ./dfc.c.orig	2012-03-31 16:22:26.000000000 +0200
+++ ./dfc.c	2012-04-01 10:18:26.366658586 +0200
@@ -6,8 +6,10 @@
  * Displays free disk space in an elegant manner.
  */
 #define _BSD_SOURCE
+#ifndef __FreeBSD__
 #define _POSIX_C_SOURCE 2
 #define _XOPEN_SOURCE 500
+#endif
 
 #define STRMAXLEN 24
 
@@ -15,14 +17,23 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <err.h>
 
+#ifndef __FreeBSD__
 #include <mntent.h>
+#endif
 #include <string.h>
 
+#include <sys/types.h>
 #include <sys/param.h>
 #include <sys/statvfs.h>
 #include <sys/ioctl.h>
 
+#ifdef __FreeBSD__
+#include <sys/ucred.h>
+#include <sys/mount.h>
+#endif
+
 #include "dfc.h"
 
 /* set flags for options */
@@ -384,9 +395,15 @@
 fetch_info(struct list *lst)
 {
 	FILE *mtab;
+	struct fsmntinfo *fmi;
+#ifdef __FreeBSD__
+	int nummnt;
+	struct statfs *entbuf;
+	struct statfs vfsbuf, **fs;
+#else
 	struct mntent *entbuf;
 	struct statvfs vfsbuf;
-	struct fsmntinfo *fmi;
+#endif
 
 	/* init fsmntinfo */
 	if ((fmi = malloc(sizeof(struct fsmntinfo))) == NULL) {
@@ -396,6 +413,14 @@
 	}
 	*fmi = fmi_init();
 
+#ifdef __FreeBSD__
+	if ((nummnt = getmntinfo(&entbuf, MNT_WAIT)) <= 0)
+		err(EXIT_FAILURE, "Error while getting the list of mountpoints");
+
+	for (fs = &entbuf; nummnt--; (*fs)++) {
+		vfsbuf = **fs;
+
+#else
 	/* open mtab file */
 	if ((mtab = fopen("/etc/mtab", "r")) == NULL) {
 		perror("Error while opening mtab file ");
@@ -421,7 +446,27 @@
 				/* NOTREACHED */
 			}
 		} else {
+#endif
 			/* infos from getmntent */
+#ifdef __FreeBSD__
+			if ((fmi->fsname = strdup(shortenstr(
+						trk(entbuf->f_mntfromname),
+						STRMAXLEN))) == NULL) {
+				fmi->fsname = "unknown";
+			}
+			if ((fmi->dir = strdup(shortenstr(
+						trk(entbuf->f_mntonname),
+						STRMAXLEN))) == NULL) {
+				fmi->dir = "unknown";
+			}
+			if ((fmi->type = strdup(shortenstr(
+						trk(entbuf->f_fstypename),
+						9))) == NULL) {
+				fmi->type = "unknown";
+			}
+			/* TODO add the options */
+			fmi->opts = "non";
+#else
 			if ((fmi->fsname = strdup(shortenstr(
 						trk(entbuf->mnt_fsname),
 						STRMAXLEN))) == NULL) {
@@ -438,16 +483,17 @@
 			if ((fmi->opts = strdup(trk(entbuf->mnt_opts))) == NULL) {
 				fmi->opts = "none";
 			}
+#endif
 
 			/* infos from statvfs */
 			fmi->bsize	= vfsbuf.f_bsize;
-			fmi->frsize	= vfsbuf.f_frsize;
+			fmi->frsize	= 0; /*vfsbuf.f_frsize;*/
 			fmi->blocks	= vfsbuf.f_blocks;
 			fmi->bfree	= vfsbuf.f_bfree;
 			fmi->bavail	= vfsbuf.f_bavail;
 			fmi->files	= vfsbuf.f_files;
 			fmi->ffree	= vfsbuf.f_ffree;
-			fmi->favail	= vfsbuf.f_favail;
+			fmi->favail	= 0; /*vfsbuf.f_favail;*/
 
 			/* pointer to the next element */
 			fmi->next = NULL;
@@ -465,11 +511,13 @@
 						lst->typemaxlen);
 			}
 		}
+#ifndef __FreeBSD__
 	}
 
 	/* we need to close the mtab file now */
 	if (fclose(mtab) == EOF)
 		perror("Could not close mtab file ");
+#endif
 }
 
 /*
@@ -563,9 +611,15 @@
 				(void)printf(" ");
 		}
 
+#ifdef __FreeBSD__
+		size = p->bsize * p->blocks;
+		avail = p->bsize * p->bavail;
+		used = p->bsize * (p->blocks - p->bfree);
+#else
 		size = (double)p->blocks *(double)p->frsize;
 		avail = (double)p->bavail * (double)p->frsize;
 		used = size - avail;
+#endif
 
 		/* calculate the % used */
 		if ((int)size == 0)
