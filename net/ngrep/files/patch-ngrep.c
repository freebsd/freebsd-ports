--- ngrep.c.orig	2025-11-07 06:35:47 UTC
+++ ngrep.c
@@ -93,10 +93,15 @@
 #include <sys/ioctl.h>
 #endif
 
-#include <pcap.h>
-
 #include "config.h"
 
+#if USE_CAPSICUM
+#include <sys/capsicum.h>
+#include <net/bpf.h>
+#endif /* USE_CAPSICUM */
+
+#include <pcap.h>
+
 #if USE_IPv6 && !defined(_WIN32) && !defined(_WIN64)
 #include <netinet/ip6.h>
 #include <netinet/icmp6.h>
@@ -217,6 +222,10 @@ int main(int argc, char **argv) {
     int32_t c;
     const char *extra = "";
 
+#if USE_CAPSICUM
+    cap_rights_t rights;
+#endif /* USE_CAPSICUM */
+
     signal(SIGINT,   clean_exit);
     signal(SIGABRT,  clean_exit);
 
@@ -461,6 +470,27 @@ int main(int argc, char **argv) {
         free(filter);
     }
 
+#if USE_CAPSICUM
+    {
+        int pcap_fd = pcap_fileno(pd);
+        cap_rights_init(&rights, CAP_IOCTL, CAP_READ);
+        if (pcap_fd >= 0 &&
+            cap_rights_limit(pcap_fd, &rights) < 0 &&
+            errno != ENOSYS) {
+            fprintf(stderr, "unable to limit pcap descriptor");
+            clean_exit(2);
+        }
+
+        static const unsigned long cmds[] = { BIOCGSTATS };
+        if (pcap_fd >= 0 &&
+            cap_ioctls_limit(pcap_fd, cmds,
+            sizeof(cmds) / sizeof(cmds[0])) < 0 && errno != ENOSYS) {
+            fprintf(stderr, "unable to limit ioctls on pcap descriptor");
+            clean_exit(2);
+        }
+    }
+#endif /* USE_CAPSICUM */
+
     /* Setup matcher */
 
     if (match_data) {
@@ -491,6 +521,22 @@ int main(int argc, char **argv) {
 #if !defined(_WIN32) && !defined(_WIN64) && USE_DROPPRIVS
     drop_privs();
 #endif
+
+#if USE_CAPSICUM
+    tzset();
+
+    cap_rights_init(&rights);
+
+    if (cap_rights_limit(STDIN_FILENO, &rights) < 0 && errno != ENOSYS) {
+        fprintf(stderr, "can't limit stdin");
+        clean_exit(1);
+    }
+
+    if (cap_enter() < 0 && errno != ENOSYS) {
+        fprintf(stderr, "can't enter capability mode");
+        clean_exit(2);
+    }
+#endif /* USE_CAPSICUM */
 
     while (pcap_loop(pd, -1, (pcap_handler)process, 0));
 
