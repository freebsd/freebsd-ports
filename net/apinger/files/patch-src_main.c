--- src/main.c.orig	2003-03-26 11:27:47 UTC
+++ src/main.c
@@ -96,7 +96,7 @@ char *config_file=CONFIG;
 
 int icmp_sock;
 int icmp6_sock;
-int ident;
+uint16_t ident;
 
 struct timeval next_probe={0,0};
 
@@ -277,7 +277,7 @@ char *graph_location="/apinger/";
 		return 1;
 	}
 
-	ident=getpid();
+	ident=getpid() & 0xFFFF;
 	signal(SIGTERM,signal_handler);
 	signal(SIGINT,signal_handler);
 	signal(SIGHUP,signal_handler);
