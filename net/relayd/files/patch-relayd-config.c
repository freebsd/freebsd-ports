--- relayd.orig/config.c	2011-05-22 01:06:39.463154237 +0200
+++ relayd/config.c	2011-05-22 01:18:41.041076104 +0200
@@ -118,6 +118,7 @@
 		RB_INIT(&env->sc_proto_default.request_tree);
 		RB_INIT(&env->sc_proto_default.response_tree);
 	}
+#ifndef __FreeBSD__
 	if (what & CONFIG_RTS) {
 		if ((env->sc_rts =
 		    calloc(1, sizeof(*env->sc_rts))) == NULL)
@@ -130,7 +131,7 @@
 			return (-1);
 		TAILQ_INIT(env->sc_routes);
 	}
-
+#endif
 	return (0);
 }
 
@@ -143,8 +144,10 @@
 	struct address		*virt;
 	struct protocol		*proto;
 	struct relay		*rlay;
+#ifndef __FreeBSD__
 	struct netroute		*nr;
 	struct router		*rt;
+#endif
 	u_int			 what;
 
 	what = ps->ps_what[privsep_process] & reset;
@@ -181,6 +184,7 @@
 		}
 		env->sc_protocount = 0;
 	}
+#ifndef __FreeBSD__
 	if (what & CONFIG_RTS && env->sc_rts != NULL) {
 		while ((rt = TAILQ_FIRST(env->sc_rts)) != NULL) {
 			TAILQ_REMOVE(env->sc_rts, rt, rt_entry);
@@ -203,6 +207,7 @@
 		}
 		env->sc_routecount = 0;
 	}
+#endif
 }
 
 int
@@ -476,6 +481,7 @@
 	return (0);
 }
 
+#ifndef __FreeBSD__
 int
 config_setrt(struct relayd *env, struct router *rt)
 {
@@ -570,6 +576,7 @@
 
 	return (0);
 }
+#endif
 
 int
 config_setproto(struct relayd *env, struct protocol *proto)
