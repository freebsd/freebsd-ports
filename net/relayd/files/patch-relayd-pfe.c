--- relayd.orig/pfe.c	2011-05-22 01:06:39.464157989 +0200
+++ relayd/pfe.c	2011-05-22 01:09:30.589288807 +0200
@@ -17,6 +17,9 @@
  */
 
 #include <sys/param.h>
+#ifdef __FreeBSD__
+#include <sys/queue.h>
+#endif
 #include <sys/stat.h>
 #include <sys/socket.h>
 #include <sys/un.h>
@@ -185,12 +188,14 @@
 	case IMSG_CFG_VIRT:
 		config_getvirt(env, imsg);
 		break;
+#ifndef __FreeBSD__
 	case IMSG_CFG_ROUTER:
 		config_getrt(env, imsg);
 		break;
 	case IMSG_CFG_ROUTE:
 		config_getroute(env, imsg);
 		break;
+#endif
 	case IMSG_CFG_PROTO:
 		config_getproto(env, imsg);
 		break;
@@ -292,8 +297,10 @@
 	struct rdr	*rdr;
 	struct host	*host;
 	struct relay	*rlay;
+#ifndef __FreeBSD__
 	struct router	*rt;
 	struct netroute	*nr;
+#endif
 
 	if (env->sc_rdrs == NULL)
 		goto relays;
@@ -324,7 +331,11 @@
 	}
 relays:
 	if (env->sc_relays == NULL)
+#ifndef __FreeBSD__
 		goto routers;
+#else
+		goto end;
+#endif
 	TAILQ_FOREACH(rlay, env->sc_relays, rl_entry) {
 		rlay->rl_stats[env->sc_prefork_relay].id = EMPTY_ID;
 		imsg_compose_event(&c->iev, IMSG_CTL_RELAY, 0, 0, -1,
@@ -351,6 +362,7 @@
 				    0, 0, -1, host, sizeof(*host));
 	}
 
+#ifndef __FreeBSD__
 routers:
 	if (env->sc_rts == NULL)
 		goto end;
@@ -370,6 +382,7 @@
 				imsg_compose_event(&c->iev, IMSG_CTL_HOST,
 				    0, 0, -1, host, sizeof(*host));
 	}
+#endif
 
 end:
 	imsg_compose_event(&c->iev, IMSG_CTL_END, 0, 0, -1, NULL, 0);
@@ -622,8 +635,10 @@
 	struct table		*table;
 	struct ctl_id		 id;
 	struct imsg		 imsg;
+#ifndef __FreeBSD__
 	struct ctl_demote	 demote;
 	struct router		*rt;
+#endif
 
 	bzero(&id, sizeof(id));
 	bzero(&imsg, sizeof(imsg));
@@ -678,6 +693,7 @@
 		}
 	}
 
+#ifndef __FreeBSD__
 	TAILQ_FOREACH(rt, env->sc_rts, rt_entry) {
 		rt->rt_conf.flags &= ~(F_BACKUP);
 		rt->rt_conf.flags &= ~(F_DOWN);
@@ -685,6 +701,7 @@
 		if ((rt->rt_gwtable->conf.flags & F_CHANGED))
 			sync_routes(env, rt);
 	}
+#endif
 
 	TAILQ_FOREACH(table, env->sc_tables, entry) {
 		if (table->conf.check == CHECK_NOCHECK)
@@ -695,6 +712,7 @@
 		 */
 		table->conf.flags &= ~(F_CHANGED);
 
+#ifndef __FreeBSD__
 		/*
 		 * handle demotion.
 		 */
@@ -717,6 +735,7 @@
 		    sizeof(demote.group));
 		proc_compose_imsg(env->sc_ps, PROC_PARENT, -1, IMSG_DEMOTE, -1,
 		    &demote, sizeof(demote));
+#endif
 	}
 }
 
