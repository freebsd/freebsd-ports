--- leif/sampleja3/xaux_common/xaux_ext_common.c	Fri Mar 16 00:52:22 2001
+++ leif/sampleja3/xaux_common/xaux_ext_common.c	Wed Feb 16 20:43:12 2005
@@ -633,7 +633,7 @@
 
 #else /* defined(USE_DTACTIONINVOKE) */
 
-#define DTACTION_CMD    "/usr/dt/bin/dtaction"
+#define DTACTION_CMD    "/usr/local/bin/dtaction"
 
 static int help_available = 0;
 static char tmp_file[256];
@@ -803,7 +803,11 @@
     fprintf(fp, "%s%s\n", rdb.help_basepath, path_);
     fclose(fp);
 
+#ifdef __FreeBSD__
+    pid = vfork();
+#else
     pid = fork1();
+#endif
 
     if (pid == (pid_t) (-1)) {
         return;
@@ -834,6 +838,8 @@
 
 #ifdef linux
     pid = fork();
+#elif defined(__FreeBSD__)
+    pid = vfork();
 #else
     pid = fork1();
 #endif
@@ -853,7 +859,11 @@
     if (pid == (pid_t) (-1)) {
         return;
     } else if (0 == pid) {
+#ifdef __FreeBSD__
+        pid2 = vfork();
+#else
         pid2 = fork();
+#endif
         if(pid2 == -1) {
             _exit(1);
         } else if(pid2 == 0) {
