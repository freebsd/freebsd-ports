--- ngrep.c.orig	2006-11-28 17:38:43.000000000 +0400
+++ ngrep.c	2014-12-12 11:14:13.000000000 +0400
@@ -97,6 +97,10 @@
 #include "regex-0.12/regex.h"
 #endif
 
+#ifdef HAVE_CAPSICUM
+#include <sys/capability.h>
+#endif /* HAVE CAPSICUM */
+
 #include "ngrep.h"
 
 
@@ -186,6 +190,10 @@ uint32_t ws_row, ws_col = 80, ws_col_for
 int main(int argc, char **argv) {
     int32_t c;
 
+#ifdef HAVE_CAPSICUM
+    cap_rights_t rights;
+#endif /* HAVE_CAPSICUM */
+
     signal(SIGINT,   clean_exit);
     signal(SIGABRT,  clean_exit);
 
@@ -416,6 +424,23 @@ int main(int argc, char **argv) {
         clean_exit(-1);
     }
 
+#ifdef HAVE_CAPSICUM
+    cap_rights_init(&rights, CAP_IOCTL, CAP_READ);
+    if (cap_rights_limit(pcap_fileno(pd), &rights) < 0 &&
+        errno != ENOSYS) {
+        fprintf(stderr, "unable to limit pcap descriptor");
+        clean_exit(-1);  
+        }
+
+    static const unsigned long cmds[] = { BIOCGSTATS };
+    if (cap_ioctls_limit(pcap_fileno(pd), cmds,
+        sizeof(cmds) / sizeof(cmds[0])) < 0 && errno != ENOSYS) {
+	fprintf(stderr, "unable to limit ioctls on pcap descriptor");
+        clean_exit(-1);
+	}
+
+#endif /* HAVE CAPSICUM */
+
     if (match_data) {
         if (bin_match) {
             uint32_t i = 0, n;
@@ -603,6 +628,20 @@ int main(int argc, char **argv) {
     drop_privs();
 #endif
 
+#ifdef HAVE_CAPSICUM
+    cap_rights_init(&rights);
+
+   if (cap_rights_limit(STDIN_FILENO, &rights) < 0 && errno != ENOSYS) {
+       fprintf(stderr, "can't limit stdin");
+       clean_exit(-1);
+   }
+
+   if (cap_enter() < 0 && errno != ENOSYS) {
+       fprintf(stderr, "can't enter capability mode");
+       clean_exit(-1);
+    }
+#endif /* HAVE_CAPSICUM */
+
     while (pcap_loop(pd, 0, (pcap_handler)process, 0));
 
     clean_exit(0);
