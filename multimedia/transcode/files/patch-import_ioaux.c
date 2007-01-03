--- import/ioaux.c.orig	Mon Jul  4 11:09:33 2005
+++ import/ioaux.c	Wed Jan  3 02:44:37 2007
@@ -261,6 +261,25 @@
       /* char device could be several things, depending on system */
       /* *BSD DVD device? v4l? bktr? sunau? */
       if(S_ISCHR(fbuf.st_mode)) {
+# ifdef __FreeBSD__
+	char rpath[PATH_MAX], *prpath;
+
+	prpath = realpath(name, &rpath);
+	if (prpath == NULL) {
+		warn("realpath(%s)", name);
+		return TC_PROBE_PATH_ABSPATH;
+	}
+
+        if (strstr(rpath, "bktr") != NULL || strstr(rpath, "tuner") || \
+         strstr(rpath, "vbi"))
+          return(TC_PROBE_PATH_BKTR);
+        else if (strstr(rpath, "dsp") || strstr(rpath, "audio") || \
+         strstr(rpath, "music"))
+          return(TC_PROBE_PATH_OSS);
+        else
+          return(TC_PROBE_PATH_ABSPATH);
+# endif
+
 	  switch (major(fbuf.st_rdev)) {
 #ifdef SYS_BSD
 # ifdef __OpenBSD__
@@ -270,14 +289,6 @@
                   return(TC_PROBE_PATH_SUNAU);
 	      case 49: /* bktr */
                   return(TC_PROBE_PATH_BKTR);
-# endif
-# ifdef __FreeBSD__
-              case 4: /* acd */
-                  return(TC_PROBE_PATH_ABSPATH);
-              case 229: /* bktr */
-                  return(TC_PROBE_PATH_BKTR);
-              case 0: /* OSS */
-                  return(TC_PROBE_PATH_OSS);
 # endif
               default: /* libdvdread uses "raw" disk devices here */
                   return(TC_PROBE_PATH_ABSPATH);
