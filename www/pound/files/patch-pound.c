--- pound.c	Wed Mar 24 16:03:14 2004
+++ pound.c	Tue Mar 30 19:13:51 2004
@@ -742,10 +742,11 @@
                                     logmsg(LOG_WARNING, "HTTP arg: malloc");
                                     close(clnt);
                                 } else {
+                                    socklen_t namelen;
                                     arg->sock = clnt;
                                     arg->from_host = clnt_addr.sin_addr;
-                                    memset(&arg->to_host, 0, n = sizeof(arg->to_host));
-                                    getsockname(http_sock[i], (struct sockaddr *)&arg->to_host, &n);
+                                    memset(&arg->to_host, 0, namelen = sizeof(arg->to_host));
+                                    getsockname(http_sock[i], (struct sockaddr *)&arg->to_host, &namelen);
                                     arg->ctx = NULL;
                                     if(pthread_create(&thr, &attr, thr_http, (void *)arg)) {
                                         logmsg(LOG_WARNING, "HTTP pthread_create: %s", strerror(errno));
@@ -776,10 +777,11 @@
                                     logmsg(LOG_WARNING, "HTTPS arg: malloc");
                                     close(clnt);
                                 } else {
+                                    socklen_t namelen;
                                     arg->sock = clnt;
                                     arg->from_host = clnt_addr.sin_addr;
-                                    memset(&arg->to_host, 0, n = sizeof(arg->to_host));
-                                    getsockname(https_sock[i], (struct sockaddr *)&arg->to_host, &n);
+                                    memset(&arg->to_host, 0, namelen = sizeof(arg->to_host));
+                                    getsockname(https_sock[i], (struct sockaddr *)&arg->to_host, &namelen);
                                     arg->ctx = ctx[i];
                                     if(pthread_create(&thr, &attr, thr_http, (void *)arg)) {
                                         logmsg(LOG_WARNING, "HTTPS pthread_create: %s", strerror(errno));
