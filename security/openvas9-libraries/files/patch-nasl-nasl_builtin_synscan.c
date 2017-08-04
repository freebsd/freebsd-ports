--- nasl/nasl_builtin_synscan.c.orig	2015-08-03 10:14:31 UTC
+++ nasl/nasl_builtin_synscan.c
@@ -692,7 +692,7 @@ scan (struct arglist * env, char* hostna
   if (IN6_IS_ADDR_V4MAPPED (dst6))
     {
       family = AF_INET;
-      dst.s_addr = dst6->s6_addr32[3];
+      memcpy(&dst.s_addr, &dst6->s6_addr[12], 4);
       soc = rawsocket (AF_INET);
     }
   else
@@ -797,7 +797,7 @@ plugin_run_synscan (lex_ctxt * lexic)
   struct timeval  tv;
 #endif
 
-  inaddr.s_addr = dst6->s6_addr32[3];
+  memcpy(&inaddr.s_addr, &dst6->s6_addr[12], 4);
   dst = &inaddr;
 
   if (islocalhost (dst))
