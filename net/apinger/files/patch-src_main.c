--- src/main.c.old	2008-07-10 22:36:21.000000000 +0200
+++ src/main.c	2008-07-10 22:36:53.000000000 +0200
@@ -96,7 +96,7 @@
 
 int icmp_sock;
 int icmp6_sock;
-int ident;
+uint16_t ident;
 
 struct timeval next_probe={0,0};
 
@@ -277,7 +277,7 @@
 		return 1;
 	}
 
-	ident=getpid();
+	ident=getpid() & 0xFFFF;
 	signal(SIGTERM,signal_handler);
 	signal(SIGINT,signal_handler);
 	signal(SIGHUP,signal_handler);
