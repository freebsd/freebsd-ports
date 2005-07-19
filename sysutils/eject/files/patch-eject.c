--- eject.c.orig	Tue Jul 19 13:43:37 2005
+++ eject.c	Tue Jul 19 14:14:24 2005
@@ -122,7 +122,7 @@
 }
 
 /*
- *  check device is exists.
+ *  check whether device exists.
  */
 
 int
@@ -133,8 +133,14 @@
     int sts;
     struct stat sb;
 
-    if (asprintf(device, "/dev/%sc", name) == -1)
-	return sts;
+    if (strncmp("/dev/", name, strlen("/dev/")) == 0) {
+	    if (asprintf(device, "%s", name) == -1)
+		return sts;
+    }
+    else { 
+	    if (asprintf(device, "/dev/%s", name) == -1)
+		return sts;
+    }
     if (vflag || nflag) {
 	printf("%s: using device %s\n", program, device);
     }
@@ -174,11 +180,16 @@
     /* get proper mount information into the list */
     len = strlen(name);
     for (n = 0; n < mnts; n++) {
-	p = rindex(mntbuf[n].f_mntfromname, '/');
-	if (p == NULL) {
-	    continue;
+	if (strncmp("/dev/", name, strlen("/dev/")) == 0) 
+		p = mntbuf[n].f_mntfromname;
+	else {
+		p = rindex(mntbuf[n].f_mntfromname, '/');
+		if (p == NULL)
+		    continue;
+		++p;
 	}
-	for (i = 0, ++p, q = name; *p != '\0' && *q != '\0'; ++i, ++p, ++q) {
+
+	for (i = 0, p, q = name; *p != '\0' && *q != '\0'; ++i, ++p, ++q) {
 	    if (*p != *q) {
 		break;
 	    }
