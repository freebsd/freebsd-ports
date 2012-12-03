--- net/instaweb/util/hostname_util.cc.orig	2012-12-02 20:27:11.000000000 +0000
+++ net/instaweb/util/hostname_util.cc	2012-12-02 20:43:33.000000000 +0000
@@ -29,7 +29,8 @@
 namespace net_instaweb {
 
 GoogleString GetHostname() {
-  char hostname[HOST_NAME_MAX + 1];
+  int hnm = sysconf(_SC_HOST_NAME_MAX);
+  char hostname[hnm + 1];
   hostname[sizeof(hostname) - 1] = '\0';
 
   // This call really shouldn't fail, so crash if it does under Debug,
