--- server/daemon.c.orig	2005-06-01 09:20:55.000000000 +0900
+++ server/daemon.c	2013-06-26 14:51:58.000000000 +0900
@@ -17,6 +17,8 @@
 #include "session.h"
 #include "sslave.h"

+#include <sys/select.h>
+
 /* -------------------- Local Vars ---------------------- */

 static int hup_recvd    = FALSE;
@@ -173,17 +175,16 @@
   signal(SIGCHLD, sigchld_handler);
 }

+#define	MAXSOCK	16
+
 int
 run_daemon()
 {
-#ifdef HAVE_IPV6
   struct sockaddr_storage client_addr;
-  struct sockaddr_in6     server_addr;
-#else
-  struct sockaddr_in    client_addr;
-  struct sockaddr_in    server_addr;
-#endif
-  int                   sockfd;
+  struct addrinfo hints, *res, *res0;
+  fd_set fds, fds0;
+  int			sockfd[MAXSOCK], nsock, maxsock, i;
+  char			servname[NI_MAXSERV];
   int                   newsockfd;
   int                   clilen;
   int                   childpid;
@@ -191,25 +192,39 @@
   int                   port         = get_port();
   int                   failure      = 0;

+  memset(&hints, 0, sizeof(hints));
+  hints.ai_family = PF_UNSPEC;
+  hints.ai_socktype = SOCK_STREAM;
+  hints.ai_flags = AI_PASSIVE | AI_NUMERICSERV;
+  snprintf(servname, sizeof(servname), "%d", port);
+  servname[sizeof(servname) - 1] = '\0';
+  failure = getaddrinfo(NULL, servname, &hints, &res0);
+
+  if (failure) {
+    log(L_LOG_ERR, CONFIG, "run_daemon: getaddrinfo().");
+    exit(1);
+  }
+  FD_ZERO(&fds0);
+  maxsock = nsock = 0;
+  for (res = res0; res && nsock < MAXSOCK; res = res->ai_next) {
+    if (res->ai_family != AF_INET
 #ifdef HAVE_IPV6
-  /* This will accept both IPv4 and IPv6 connections on any interface
-     including the loopback so that a local client can send to us. */
-  if ( ( sockfd = socket( AF_INET6, SOCK_STREAM, IPPROTO_TCP ) ) < 0 )
-#else
-  if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
+        && res->ai_family != AF_INET6
 #endif
-  {
-    log(L_LOG_ERR, CONFIG, "run_daemon: Can not open socket: %s",
+    )
+      continue;
+    sockfd[nsock] = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
+    if (sockfd[nsock] < 0) {
+      log(L_LOG_ERR, CONFIG, "run_daemon: Can not open socket: %s",
         strerror(errno));
-    exit (1);
-  }
-
-  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&one, sizeof(one))
+      continue;
+    }
+  if (setsockopt(sockfd[nsock], SOL_SOCKET, SO_REUSEADDR, (char *)&one, sizeof(one))
       < 0)
   {
     log(L_LOG_ERR, CONFIG,
         "run_daemon: Can not set socket options SO_REUSEADDR");
-    exit(1);
+    continue;
   }

 #ifdef NEED_LINGER
@@ -222,28 +237,31 @@
                sizeof(struct linger));
   }
 #endif  /* NEED_LINGER */
-
-  /* for now, we will bind to all IP interfaces (INADDR_ANY) */
-  /* Bind our local address so that the client can send to us */
-  bzero((char *)&server_addr, sizeof(server_addr));
-#ifdef HAVE_IPV6
-  server_addr.sin6_family = AF_INET6;
-  server_addr.sin6_port = htons(port);
-  server_addr.sin6_addr = in6addr_any;
-#else
-  server_addr.sin_family = AF_INET;
-  server_addr.sin_port = htons(port);
-  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
-#endif
-
-  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
-  {
-    log(L_LOG_ERR, CONFIG, "run_daemon: Can not bind socket: %s",
-        strerror(errno));
-    exit(1);
+    if (bind(sockfd[nsock], res->ai_addr, res->ai_addrlen) < 0) {
+      log(L_LOG_ERR, CONFIG, "run_daemon: Can not bind socket: %s",
+          strerror(errno));
+      close(sockfd[nsock]);
+      sockfd[nsock] = -1;
+      continue;
+    }
+    if (listen(sockfd[nsock], get_listen_queue_length()) == -1) {
+      log(L_LOG_ERR, CONFIG, "run_daemon: listen: %s",
+          strerror(errno));
+      close(sockfd[nsock]);
+      sockfd[nsock] = -1;
+      continue;
+    }
+    FD_SET(sockfd[nsock], &fds0);
+    if (maxsock < sockfd[nsock])
+      maxsock = sockfd[nsock];
+    nsock++;
   }
+  freeaddrinfo(res0);

-  listen(sockfd, get_listen_queue_length());
+  if (nsock == 0) {
+    log(L_LOG_ERR, CONFIG, "run_daemon: Can not open socket");
+    exit (1);
+  }

   no_zombies();

@@ -274,16 +292,32 @@
       hup_recvd = FALSE;
     }

+    newsockfd = -1;
+    memcpy(&fds, &fds0, sizeof(fds));
     clilen = sizeof(client_addr);
-    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &clilen);
-    if (newsockfd < 0)
-    {
-      if (errno == EINTR)
-      {
+    if (select(maxsock + 1, &fds, NULL, NULL, NULL) > 0) {
+      for (i = 0; i < nsock; i++) {
+        if (FD_ISSET(sockfd[i], &fds)) {
+          newsockfd = accept(sockfd[i], (struct sockaddr *) &client_addr,
+                             &clilen);
+          if (newsockfd < 0) {
+            if (errno != EINTR)
+              fprintf(stderr, "run_daemon: accept error: %s\n", strerror(errno));
+            continue;
+          } else
+            break;
+          }
+	}
+        if (newsockfd < 0) {
+          fprintf(stderr, "run_daemon: ignored\n");
+          continue;
+        }
+    } else {
+      if (errno != EINTR) {
+        fprintf(stderr, "run_daemon: select error: %s\n", strerror(errno));
+        exit(1);
+      } else
         continue;
-      }
-      fprintf(stderr, "run_daemon: accept error: %s\n", strerror(errno));
-      continue;
     }

     failure = 0;
@@ -312,7 +346,8 @@
         exit(1);
       }

-      close(sockfd);
+      for (i = 0; i < nsock; i++)
+        close(sockfd[i]);

       if (!authorized_client())
       {
