--- echoping.c.orig	2020-08-20 15:47:00 UTC
+++ echoping.c
@@ -38,6 +38,22 @@ struct result   results[MAX_ITERATIONS];
 struct timeval  good_results[MAX_ITERATIONS];
 extern int      tvcmp();
 
+boolean timeout_flag;
+static char *server;
+#ifdef LIBIDN
+static char *locale_server, *ace_server, *utf8_server;
+#endif
+
+static init_f plugin_init;
+static start_f plugin_start;
+static start_raw_f plugin_raw_start;
+static execute_f plugin_execute;
+static execute_f plugin_execute;
+static terminate_f plugin_terminate;
+
+struct timeval null_timeval;
+static struct timeval max_timeval;
+
 int
 main(argc, argv)
     int             argc;
