
$FreeBSD$

--- srclib/libmetrics/freebsd/metrics.c.orig
+++ srclib/libmetrics/freebsd/metrics.c
@@ -51,6 +51,8 @@
 #define UINT64_MAX	ULLONG_MAX
 #endif
 
+#define VFCF_NONLOCAL	(VFCF_NETWORK|VFCF_SYNTHETIC|VFCF_LOOPBACK)
+
 #define timertod(tvp) \
     ((double)(tvp)->tv_sec + (double)(tvp)->tv_usec/(1000*1000))
 
@@ -243,49 +245,40 @@
 g_val_t
 machine_type_func ( void )
 {
-   g_val_t val;
-   char machine_type[MAX_G_STRING_SIZE];
-   size_t len = MAX_G_STRING_SIZE;
-   if (sysctlbyname("hw.machine", &machine_type, &len, NULL, 0) == -1 || !len)
-        strncpy( val.str, "x86", MAX_G_STRING_SIZE );
+	g_val_t val;
+	size_t len = sizeof(val.str);
 
-   strncpy( val.str, machine_type, MAX_G_STRING_SIZE );
-   return val;
+	if (sysctlbyname("hw.machine", val.str, &len, NULL, 0) == -1 ||
+	    (len == 0))
+		strlcpy(val.str, "unknown", sizeof(val.str));
+
+	return val;
 }
 
 g_val_t
 os_name_func ( void )
 {
-   g_val_t val;
-   char osname[MAX_G_STRING_SIZE];
-   size_t len = MAX_G_STRING_SIZE;
-   if (sysctlbyname("kern.ostype", &osname, &len, NULL, 0) == -1 || !len)
-        strncpy( val.str, "FreeBSD", MAX_G_STRING_SIZE );
+	g_val_t val;
+	size_t len = sizeof(val.str);
 
-   strncpy( val.str, osname, MAX_G_STRING_SIZE );
- 
-   return val;
+	if (sysctlbyname("kern.ostype", val.str, &len, NULL, 0) == -1 ||
+	    (len == 0))
+		strlcpy(val.str, "FreeBSD (unknown)", sizeof(val.str));
+
+	return val;
 }        
 
 g_val_t
 os_release_func ( void )
 {
-   g_val_t val;
-   int mib[2];
-   size_t len;
-   char *prefix, buf[1024];
-
-   prefix = "";
-
-   mib[0] = CTL_KERN;
-   mib[1] = KERN_OSRELEASE;
-   len = sizeof(buf);
-   if (sysctl(mib, 2, &buf, &len, NULL, 0) == -1)
-        strncpy( val.str, "Unknown", MAX_G_STRING_SIZE );
+	g_val_t val;
+	size_t len = sizeof(val.str);
 
-   strncpy( val.str, buf, MAX_G_STRING_SIZE );
+	if (sysctlbyname("kern.osrelease", val.str, &len, NULL, 0) == -1 ||
+	    (len == 0))
+		strlcpy(val.str, "unknown", sizeof(val.str));
 
-   return val;
+	return val;
 }        
 
 /* Get the CPU state given by index, from kern.cp_time
@@ -910,8 +903,9 @@
 static char *
 makenetvfslist(void)
 {
-	char *str = NULL, *strptr, **listptr = NULL;
-	int cnt, i;
+	char	*str = NULL, *strptr, **listptr = NULL;
+	size_t	slen;
+	int	cnt, i;
 
 #if __FreeBSD_version > 500000
 	struct xvfsconf *xvfsp, *keep_xvfsp = NULL;
@@ -938,20 +932,22 @@
 		goto done;
 	}
 
-	for (cnt = 0, i = 0; i < maxvfsconf; i++) {
-		if (xvfsp->vfc_flags & (VFCF_NETWORK|VFCF_SYNTHETIC|VFCF_LOOPBACK)) {
-			listptr[cnt++] = strdup(xvfsp->vfc_name);
-			if (listptr[cnt-1] == NULL) {
-				warnx("malloc failed");
-				goto done;
-			}
+	for (cnt = 0; cnt < maxvfsconf; xvfsp++) {
+		if (xvfsp->vfc_flags & VFCF_NONLOCAL)
+			continue;
+
+		listptr[cnt] = strdup(xvfsp->vfc_name);
+		if (listptr[cnt] == NULL) {
+			warnx("malloc failed");
+			goto done;
 		}
-		xvfsp++;
+		cnt++;
 	}
 #else
 	int mib[3], maxvfsconf;
 	size_t miblen;
 	struct ovfsconf *ptr;
+	int fd;
 
 	mib[0] = CTL_VFS; mib[1] = VFS_GENERIC; mib[2] = VFS_MAXTYPENUM;
 	miblen=sizeof(maxvfsconf);
@@ -966,31 +962,45 @@
 		goto done;
 	}
 
-	for (ptr = getvfsent(); ptr; ptr = getvfsent())
-		if (ptr->vfc_flags & (VFCF_NETWORK|VFCF_SYNTHETIC|VFCF_LOOPBACK)) {
-			listptr[cnt++] = strdup(ptr->vfc_name);
-			if (listptr[cnt-1] == NULL) {
-				warnx("malloc failed");
-				goto done;
-			}
+	cnt = 0;
+	while ((ptr = getvfsent()) != NULL && cnt < maxvfsconf) {
+		if (ptr->vfc_flags & VFCF_NONLOCAL)
+			continue;
+
+		listptr[cnt] = strdup(ptr->vfc_name);
+		if (listptr[cnt] == NULL) {
+			warnx("malloc failed");
+			goto done;
 		}
+		cnt++;
+	}
 #endif
 
 	if (cnt == 0)
 		goto done;
 
-	if ((str = malloc(sizeof(char) * (32 * cnt + cnt + 2))) == NULL) {
+	/*
+	 * Count up the string lengths, we need a extra byte to hold
+	 * the between entries ',' or the NUL at the end.
+	 */
+	for (i = 0; i < cnt; i++)
+		slen = strlen(listptr[i]) + 1;
+	/* Add 2 for initial "no". */
+	slen += 2;
+
+	if ((str = malloc(slen)) == NULL) {
 		warnx("malloc failed");
 		goto done;
 	}
 
-	*str = 'n'; *(str + 1) = 'o';
+	str[0] = 'n';
+	str[1] = 'o';
 	for (i = 0, strptr = str + 2; i < cnt; i++, strptr++) {
-		strncpy(strptr, listptr[i], 32);
+		strcpy(strptr, listptr[i]);
 		strptr += strlen(listptr[i]);
 		*strptr = ',';
 	}
-	*(--strptr) = '\0';
+	*strptr = '\0';
 
 done:
 #if __FreeBSD_version > 500000
