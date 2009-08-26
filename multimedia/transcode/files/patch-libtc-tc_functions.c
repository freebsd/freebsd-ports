--- libtc/tc_functions.c.orig	2008-08-09 17:24:38.000000000 -0400
+++ libtc/tc_functions.c	2009-02-01 22:13:42.000000000 -0500
@@ -534,6 +534,15 @@
         /* char device could be several things, depending on system */
         /* *BSD DVD device? v4l? bktr? sunau? */
         if(S_ISCHR(fbuf.st_mode)) {
+#ifdef __FreeBSD__
+            if (strstr(name, "bktr") || strstr(name, "tuner") || strstr(name, "wbi"))
+                return TC_PROBE_PATH_BKTR;
+            else if (strstr(name, "dsp") || strstr(name, "audio") || strstr(name, "music"))
+                return TC_PROBE_PATH_OSS;
+            else
+                return TC_PROBE_PATH_ABSPATH;
+#endif
+
             switch (major(fbuf.st_rdev)) {
 #ifdef OS_BSD
 # ifdef __OpenBSD__
@@ -544,14 +553,6 @@
                 case 49: /* bktr */
                     return TC_PROBE_PATH_BKTR;
 # endif
-# ifdef __FreeBSD__
-                case 4: /* acd */
-                    return TC_PROBE_PATH_ABSPATH;
-                case 229: /* bktr */
-                    return TC_PROBE_PATH_BKTR;
-                case 0: /* OSS */
-                    return TC_PROBE_PATH_OSS;
-# endif
                 default: /* libdvdread uses "raw" disk devices here */
                     return TC_PROBE_PATH_ABSPATH;
 #else
