--- libxorp/popen.cc.orig	2018-07-10 12:54:42 UTC
+++ libxorp/popen.cc
@@ -424,7 +424,7 @@ popen2(const string& command, const list
 int
 pclose2(FILE *iop_out, bool dont_wait)
 {
-    register struct pid_s *cur, *last;
+    struct pid_s *cur, *last;
     int pstat = 0;
     pid_t pid = 0;
 
