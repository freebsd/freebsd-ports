--- proc/sig.c.orig	2016-07-09 21:49:25 UTC
+++ proc/sig.c
@@ -82,7 +82,11 @@ static const mapstruct sigtable[] = {
   {"INT",    SIGINT},
   {"KILL",   SIGKILL},
   {"PIPE",   SIGPIPE},
+#ifdef __FreeBSD__
+  {"POLL",   SIGIO},
+#else
   {"POLL",   SIGPOLL},  /* IO */
+#endif
   {"PROF",   SIGPROF},
   {"PWR",    SIGPWR},
   {"QUIT",   SIGQUIT},
@@ -121,7 +125,11 @@ int signal_name_to_number(const char *re
   if(!strncasecmp(name,"SIG",3)) name += 3;
 
   if(!strcasecmp(name,"CLD")) return SIGCHLD;
+#ifdef __FreeBSD__
+  if(!strcasecmp(name,"IO"))  return SIGIO;
+#else
   if(!strcasecmp(name,"IO"))  return SIGPOLL;
+#endif
   if(!strcasecmp(name,"IOT")) return SIGABRT;
 
   /* search the table */
