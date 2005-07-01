--- datapipe.c.orig	Tue Jan  4 08:48:55 2000
+++ datapipe.c	Fri Jul  1 19:55:58 2005
@@ -59,6 +59,7 @@
   #include <unistd.h>
   #include <netdb.h>
   #include <strings.h>
+  #include <syslog.h>
   #define recv(x,y,z,a) read(x,y,z)
   #define send(x,y,z,a) write(x,y,z)
   #define closesocket(s) close(s)
@@ -77,7 +78,7 @@
   time_t activity;
 };
 
-#define MAXCLIENTS 20
+#define MAXCLIENTS 128
 #define IDLETIMEOUT 300
 
 
@@ -88,8 +89,12 @@
   SOCKET lsock;
   char buf[4096];
   struct sockaddr_in laddr, oaddr;
-  int i;
+  int i, lport, oport;
+  char *laddr_str, *oaddr_str;
   struct client_t clients[MAXCLIENTS];
+#if defined(DATAPIPE_REUSEADDR)
+  int opt = 1;
+#endif
 
 
 #if defined(__WIN32__) || defined(WIN32) || defined(_WIN32)
@@ -114,7 +119,7 @@
   /* determine the listener address and port */
   bzero(&laddr, sizeof(struct sockaddr_in));
   laddr.sin_family = AF_INET;
-  laddr.sin_port = htons((unsigned short) atol(argv[2]));
+  laddr.sin_port = htons((unsigned short)(lport=atol(argv[2])));
   laddr.sin_addr.s_addr = inet_addr(argv[1]);
   if (!laddr.sin_port) {
     fprintf(stderr, "invalid listener port\n");
@@ -128,12 +133,13 @@
     }    
     bcopy(n->h_addr, (char *) &laddr.sin_addr, n->h_length);
   }
+  laddr_str=strdup(inet_ntoa(laddr.sin_addr));
 
 
   /* determine the outgoing address and port */
   bzero(&oaddr, sizeof(struct sockaddr_in));
   oaddr.sin_family = AF_INET;
-  oaddr.sin_port = htons((unsigned short) atol(argv[4]));
+  oaddr.sin_port = htons((unsigned short)(oport=atol(argv[4])));
   if (!oaddr.sin_port) {
     fprintf(stderr, "invalid target port\n");
     return 25;
@@ -147,6 +153,7 @@
     }    
     bcopy(n->h_addr, (char *) &oaddr.sin_addr, n->h_length);
   }
+  oaddr_str=strdup(inet_ntoa(oaddr.sin_addr));
 
 
   /* create the listener socket */
@@ -154,6 +161,21 @@
     perror("socket");
     return 20;
   }
+  {
+	int j=1;
+	setsockopt(lsock, SOL_SOCKET, SO_REUSEADDR,
+		(const char *) &j, sizeof(j));
+	setsockopt(lsock, SOL_SOCKET, SO_KEEPALIVE,
+		(const char *) &j, sizeof(j));
+	setsockopt(lsock, SOL_SOCKET, SO_LINGER,
+		(const char *) &j, sizeof(j));
+  }
+#if defined(DATAPIPE_REUSEADDR)
+  if (setsockopt(lsock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
+    perror("setsockopt");
+    return 20;
+  }
+#endif
   if (bind(lsock, (struct sockaddr *)&laddr, sizeof(laddr))) {
     perror("bind");
     return 20;
@@ -164,13 +186,14 @@
   }
 
 
-  /* change the port in the listener struct to zero, since we will
+  /* change the port and address in the listener struct to zero, since we will
    * use it for binding to outgoing local sockets in the future. */
   laddr.sin_port = htons(0);
+  laddr.sin_addr.s_addr = INADDR_ANY;
 
 
   /* fork off into the background. */
-#if !defined(__WIN32__) && !defined(WIN32) && !defined(_WIN32)
+#if !defined(__WIN32__) && !defined(WIN32) && !defined(_WIN32) && !defined(DATAPIPE_NOFORK)
   if ((i = fork()) == -1) {
     perror("fork");
     return 20;
@@ -180,7 +203,10 @@
   setsid();
 #endif
 
-  
+  openlog(argv[0], LOG_NDELAY|LOG_CONS|LOG_PID, LOG_LOCAL4);
+  syslog( LOG_INFO, "Datapipe started: %s:%i -> %s:%i",
+    laddr_str, lport, oaddr_str, oport);
+                                  
   /* main polling loop. */
   while (1)
   {
@@ -203,15 +229,22 @@
           maxsock = (int) clients[i].osock;
       }      
     if (select(maxsock + 1, &fdsr, NULL, NULL, &tv) < 0) {
-      return 30;
+      syslog( LOG_INFO, "select, maxsock=%i", maxsock);
+      continue;
     }
 
 
     /* check if there are new connections to accept. */
     if (FD_ISSET(lsock, &fdsr))
     {
-      SOCKET csock = accept(lsock, NULL, 0);
-     
+      struct sockaddr_in raddr;
+      int len=sizeof(raddr);
+      SOCKET csock = accept(lsock, (struct sockaddr *)&raddr, &len);
+	if(csock >= 0) {
+      syslog( LOG_INFO, "Connection(%i) from %s:%i to %s:%i -> %s:%i",
+        csock, inet_ntoa(raddr.sin_addr), ntohs(raddr.sin_port),
+        laddr_str, lport, oaddr_str, oport);
+
       for (i = 0; i < MAXCLIENTS; i++)
         if (!clients[i].inuse) break;
       if (i < MAXCLIENTS)
@@ -219,16 +252,16 @@
         /* connect a socket to the outgoing host/port */
         SOCKET osock;
         if ((osock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
-          perror("socket");
+          syslog( LOG_INFO, "socket\n");
           closesocket(csock);
         }
         else if (bind(osock, (struct sockaddr *)&laddr, sizeof(laddr))) {
-          perror("bind");
+          syslog( LOG_INFO, "bind\n");
           closesocket(csock);
           closesocket(osock);
         }
         else if (connect(osock, (struct sockaddr *)&oaddr, sizeof(oaddr))) {
-          perror("connect");
+          syslog( LOG_INFO, "connect\n");
           closesocket(csock);
           closesocket(osock);
         }
@@ -239,9 +272,14 @@
           clients[i].inuse = 1;
         }
       } else {
-        fprintf(stderr, "too many clients\n");
+        syslog( LOG_INFO, "too many clients\n");
         closesocket(csock);
-      }        
+      }
+	} else {
+		syslog( LOG_INFO, "Connection accept error(%i) from %s:%i to %s:%i -> %s:%i",
+			csock, inet_ntoa(raddr.sin_addr), ntohs(raddr.sin_port),
+			laddr_str, lport, oaddr_str, oport);
+	}
     }
 
 
