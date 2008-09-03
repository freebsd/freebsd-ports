--- makesnortsam.sh.old	2008-08-03 00:04:24.000000000 -0300
+++ makesnortsam.sh	2008-08-03 00:04:57.000000000 -0300
@@ -11,8 +11,8 @@
 #        Under Solaris, the OPSEC stuff is linked dynamically.
 #        On other platforms, statically.
 
-BSDTHREADLIB='-lc_r'
-#BSDTHREADLIB='-lpthread'
+#BSDTHREADLIB='-lc_r'
+BSDTHREADLIB='-lpthread'
 
 systype=`uname`
 
