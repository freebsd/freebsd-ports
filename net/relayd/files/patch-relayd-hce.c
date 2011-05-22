--- relayd.orig/hce.c	2011-05-22 01:06:39.461146172 +0200
+++ relayd/hce.c	2011-05-22 01:08:01.230992828 +0200
@@ -80,7 +80,9 @@
 	/* Allow maximum available sockets for TCP checks */
 	socket_rlimit(-1);
 
+#ifndef __FreeBSD__
 	snmp_init(env, PROC_PARENT);
+#endif
 }
 
 void
@@ -263,8 +265,10 @@
 		    print_availability(host->check_cnt, host->up_cnt));
 	}
 
+#ifndef __FreeBSD__
 	if (host->last_up != host->up)
 		snmp_hosttrap(env, table, host);
+#endif
 
 	host->last_up = host->up;
 
@@ -350,9 +354,11 @@
 	case IMSG_CFG_HOST:
 		config_gethost(env, imsg);
 		break;
+#ifndef __FreeBSD__
 	case IMSG_SNMPSOCK:
 		snmp_getsock(env, imsg);
 		break;
+#endif
 	case IMSG_CFG_DONE:
 		config_getcfg(env, imsg);
 		hce_setup_events();
