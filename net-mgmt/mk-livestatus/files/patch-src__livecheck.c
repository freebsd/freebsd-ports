--- ./src/livecheck.c.orig	2013-06-10 14:49:02.000000000 +0200
+++ ./src/livecheck.c	2013-06-16 22:13:23.000000000 +0200
@@ -27,8 +27,14 @@
 #include <sys/wait.h>
 #include <sys/timeb.h>
 #include <sys/resource.h>
+#ifdef __FreeBSD__
+#include <arpa/inet.h>
+#endif
 #include <netinet/ip.h>
 #include <stdlib.h>
+#ifdef __FreeBSD__
+#include <signal.h>
+#endif
 #include <fcntl.h>
 #include <string.h>
 
@@ -80,8 +86,13 @@
         }
 
         int is_host_check = service[0] == '\n';
+#ifndef __FreeBSD__
         struct timeb start;
         ftime(&start);
+#else
+        struct timeval start;
+        gettimeofday(&start);
+#endif
         char output[16384];
         int return_code;
         // Optimization(1):
@@ -188,8 +199,13 @@
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
@@ -212,10 +228,17 @@
             getpid(),
             0,
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
             return_code);
         char *ptr_output = output;
         char *ptr_walk   = output;
