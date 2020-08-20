--- echoping.h.orig	2020-08-20 15:39:43 UTC
+++ echoping.h
@@ -121,7 +121,6 @@ struct result
   struct timeval timevalue;
 };
 
-boolean timeout_flag;
 struct echoping_struct
 {
   boolean udp;			/* Use the UDP protocol (TCP is the default) */
@@ -136,21 +135,15 @@ typedef struct echoping_struct echoping_options;
 /* Initializes the plugin with its arguments. Returns the port name or number or NULL if the plugin wants to use the raw interface. */
 typedef char *(*init_f) (const int argc, const char **argv,
 			 const echoping_options global_options);
-init_f plugin_init;
 typedef void (*start_f) (struct addrinfo *);
-start_f plugin_start;
 typedef void (*start_raw_f) ();
-start_raw_f plugin_raw_start;
 typedef int (*execute_f) ();
-execute_f plugin_execute;
 typedef void (*terminate_f) ();
-terminate_f plugin_terminate;
 #endif
 
 #endif
 
-struct timeval null_timeval;
-struct timeval max_timeval;
+extern struct timeval null_timeval;
 
 #define	ECHO_TCP_PORT	"echo"
 #define	DISCARD_TCP_PORT	"discard"
@@ -172,11 +165,6 @@ struct timeval max_timeval;
 #define USE_SMTP        6
 
 #define CHARGENERATED " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefg";
-
-char *server;
-#ifdef LIBIDN
-char *locale_server, *ace_server, *utf8_server;
-#endif
 
 /* My functions */
 
