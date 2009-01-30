
$FreeBSD$

--- libmetrics/freebsd/metrics.c.orig
+++ libmetrics/freebsd/metrics.c
@@ -106,7 +106,7 @@
 static size_t mibswap_size;
 static kvm_t *kd = NULL;
 static int pagesize;
-static int	  skipvfs;
+static int	  skipvfs = 1;
 
 /* Function prototypes */
 static long percentages(int cnt, int *out, register long *new,
@@ -881,7 +881,6 @@
 
 	netvfslist = makenetvfslist();
 	vfslist = makevfslist(netvfslist);
-	free(netvfslist);
 
 	mntsize = getmntinfo(&mntbuf, MNT_NOWAIT);
 	mntsize = regetmntinfo(&mntbuf, mntsize, vfslist);
@@ -899,6 +898,8 @@
 			*tot_avail += mntbuf[i].f_bavail / toru;
 		}
 	}
+	free(vfslist);
+	free(netvfslist);
 
 	return most_full;
 }
@@ -955,7 +956,7 @@
 		return (NULL);
 	if (fslist[0] == 'n' && fslist[1] == 'o') {
 		fslist += 2;
-		skipvfs = 1;
+		skipvfs = 0;
 	}
 	for (i = 0, nextcp = fslist; *nextcp; nextcp++)
 		if (*nextcp == ',')
@@ -1007,7 +1008,10 @@
 		goto done;
 	}
 
-	for (cnt = 0; cnt < maxvfsconf; xvfsp++) {
+	cnt = 0;
+	for (i = 0; i < maxvfsconf; i++, xvfsp++) {
+		if (xvfsp->vfc_typenum == 0)
+			continue;
 		if (xvfsp->vfc_flags & VFCF_NONLOCAL)
 			continue;
 
@@ -1057,10 +1061,13 @@
 	 * Count up the string lengths, we need a extra byte to hold
 	 * the between entries ',' or the NUL at the end.
 	 */
+	slen = 0;
 	for (i = 0; i < cnt; i++)
-		slen = strlen(listptr[i]) + 1;
-	/* Add 2 for initial "no". */
-	slen += 2;
+		slen += strlen(listptr[i]);
+	/* for ',' */
+	slen += cnt - 1;
+	/* Add 3 for initial "no" and the NUL. */
+	slen += 3;
 
 	if ((str = malloc(slen)) == NULL) {
 		warnx("malloc failed");
@@ -1069,10 +1076,11 @@
 
 	str[0] = 'n';
 	str[1] = 'o';
-	for (i = 0, strptr = str + 2; i < cnt; i++, strptr++) {
+	for (i = 0, strptr = str + 2; i < cnt; i++) {
+		if (i > 0)
+		    *strptr++ = ',';
 		strcpy(strptr, listptr[i]);
 		strptr += strlen(listptr[i]);
-		*strptr = ',';
 	}
 	*strptr = '\0';
 
