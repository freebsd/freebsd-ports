--- xdiskusage.C.orig	2015-02-10 00:29:18.000000000 +0100
+++ xdiskusage.C	2016-02-14 11:57:10.798244000 +0100
@@ -28,6 +28,9 @@
 #elif defined(__bsdi__)
 # define DF_COMMAND "df"
 # define DU_COMMAND "du -x"
+#elif defined(__FreeBSD__)
+# define DF_COMMAND "df -k -t noprocfs,devfs,fdescfs"
+# define DU_COMMAND "du -kx"
 #elif defined(SVR4) || defined(__sun)
 # define DF_COMMAND "/bin/df -k"
 # define DU_COMMAND "/bin/du -kd"
