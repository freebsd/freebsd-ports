
$FreeBSD$

--- lib/libgmond.c.orig
+++ lib/libgmond.c
@@ -39,7 +39,7 @@
 static cfg_opt_t globals_opts[] = {
   CFG_BOOL("daemonize", 1, CFGF_NONE),
   CFG_BOOL("setuid", 1, CFGF_NONE),
-  CFG_STR("user", "nobody", CFGF_NONE),
+  CFG_STR("user", "ganglia", CFGF_NONE),
   /* later i guess we should add "group" as well */
   CFG_INT("debug_level", 0, CFGF_NONE),
   CFG_INT("max_udp_msg_len", 1472, CFGF_NONE),
@@ -125,7 +125,7 @@
    The values closely match ./gmond/metric.h definitions in 2.5.x */ \n\
 globals {                    \n\
   setuid = yes              \n\
-  user = nobody              \n\
+  user = ganglia              \n\
   cleanup_threshold = 300 /*secs */ \n\
 } \n\
 \n\
