--- cfg_file.y.orig	2012-07-09 09:01:08.000000000 +0800
+++ cfg_file.y	2013-02-12 11:33:52.000000000 +0800
@@ -609,7 +609,7 @@
 }
 
 /* Clear the VTUN_NAT_HACK flag which are not relevant to the current operation mode */
-inline void clear_nat_hack_flags(int svr)
+void clear_nat_hack_flags(int svr)
 {
 	if (svr)
 		llist_trav(&host_list,clear_nat_hack_server,NULL);
