--- proc/sig.c.orig	2018-05-18 21:32:21 UTC
+++ proc/sig.c
@@ -87,7 +87,11 @@ static const mapstruct sigtable[] = {
   {"LOST",   SIGLOST},  /* Hurd-specific */
 #endif
   {"PIPE",   SIGPIPE},
+#ifdef __FreeBSD__
+  {"POLL",   SIGIO},
+#else
   {"POLL",   SIGPOLL},  /* IO */
+#endif
   {"PROF",   SIGPROF},
 #ifdef SIGPWR
   {"PWR",    SIGPWR},
@@ -145,7 +149,11 @@ int signal_name_to_number(const char *re
   if(!strncasecmp(name,"SIG",3)) name += 3;
 
   if(!strcasecmp(name,"CLD")) return SIGCHLD;
+#ifdef __FreeBSD__
+  if(!strcasecmp(name,"IO"))  return SIGIO;
+#else
   if(!strcasecmp(name,"IO"))  return SIGPOLL;
+#endif
   if(!strcasecmp(name,"IOT")) return SIGABRT;
 
   /* search the table */
