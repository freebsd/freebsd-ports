--- src/net/icmp_echo_engine.c.orig	2017-06-16 09:08:10 UTC
+++ src/net/icmp_echo_engine.c
@@ -238,7 +238,7 @@ iee_ret_t IEE_init( void** pp_config, iee_mode_t eng_m
   p_engine->clbk_recv = recv_clbk;
 
   // Initialize engine socket variables.
-  p_engine->icmp_echo_id = pal_getpid();
+  p_engine->icmp_echo_id = pal_getpid() % 65536;
   p_engine->icmp_saf = af;
   switch( p_engine->icmp_saf )
   {
