--- gogoc-tsp/src/net/icmp_echo_engine.c~	2016-07-22 15:16:32.382995000 +0800
+++ gogoc-tsp/src/net/icmp_echo_engine.c	2016-07-22 15:16:44.244691000 +0800
@@ -238,7 +238,7 @@
   p_engine->clbk_recv = recv_clbk;
 
   // Initialize engine socket variables.
-  p_engine->icmp_echo_id = pal_getpid();
+  p_engine->icmp_echo_id = pal_getpid() % 65536;
   p_engine->icmp_saf = af;
   switch( p_engine->icmp_saf )
   {
