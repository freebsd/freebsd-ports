--- ./src/livecheck.c.orig	2012-03-09 11:12:44.000000000 +0100
+++ ./src/livecheck.c	2012-11-03 13:12:14.000000000 +0100
@@ -26,8 +26,15 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/timeb.h>
+#ifdef __FreeBSD__
+#include <sys/resource.h>
+#include <arpa/inet.h>
+#endif
 #include <netinet/ip.h>
 #include <stdlib.h>
+#ifdef __FreeBSD__
+#include <signal.h>
+#endif
 #include <fcntl.h>
 #include <string.h>
 
@@ -79,8 +86,13 @@
         }
 
         int is_host_check = service[0] == '\n';
+#ifndef __FreeBSD__
         struct timeb start;
         ftime(&start);
+#else
+        struct timeval start;
+        gettimeofday(&start);
+#endif
         char output[8192];
         int return_code;
 
@@ -175,8 +187,13 @@
                 }
             }
         }
+#ifndef __FreeBSD__
         struct timeb end;
         ftime(&end);
+#else
+        struct timeval end;
+        gettimeofday(&end);
+#endif
         char template[256];
         snprintf(template, sizeof(template), "%s/cXXXXXX", check_result_path);
         int fd = mkstemp(template);
@@ -199,10 +216,17 @@
             getpid(),
             is_host_check ? 0 : 1,
             latency,
+#ifndef __FreeBSD__
             (int)start.time,
             start.millitm,
             (int)end.time,
             end.millitm,
+#else
+            (int)start.tv_sec,
+            start.tv_usec / 1000,
+            (int)end.tv_sec,
+            end.tv_usec / 1000,
+#endif
             return_code,
             output);
         fchown(fd, real_uid, real_gid);
