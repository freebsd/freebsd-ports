--- ospfd/ospf_vty.c.orig	2018-07-12 06:56:11 UTC
+++ ospfd/ospf_vty.c
@@ -2337,9 +2337,6 @@ DEFUN (no_ospf_timers_lsa_min_arrival,
 	return CMD_SUCCESS;
 }
 
-#if CONFDATE > 20180708
-CPP_NOTICE("ospf: `timers lsa arrival (0-1000)` deprecated 2017/07/08")
-#endif
 ALIAS_HIDDEN (ospf_timers_lsa_min_arrival,
               ospf_timers_lsa_arrival_cmd,
               "timers lsa arrival (0-1000)",
@@ -2348,9 +2345,6 @@ ALIAS_HIDDEN (ospf_timers_lsa_min_arrival,
               "ospf minimum arrival interval delay\n"
               "delay (msec) between accepted lsas\n");
 
-#if CONFDATE > 20180708
-CPP_NOTICE("ospf: `no timers lsa arrival (0-1000)` deprecated 2017/07/08")
-#endif
 ALIAS_HIDDEN (no_ospf_timers_lsa_min_arrival,
               no_ospf_timers_lsa_arrival_cmd,
               "no timers lsa arrival (0-1000)",
