
$FreeBSD$

--- routers.c.orig
+++ routers.c
@@ -261,9 +261,11 @@
 		if (tmp->param_flags_reserved&ND_RA_FLAG_OTHER) {
 			fprintf(stderr,"OTHER ");
 		}
+/* no support for home agent in FreeBSD
 		if (tmp->param_flags_reserved&ND_RA_FLAG_HOME_AGENT) {
 			fprintf(stderr,"HOME_AGENT ");
 		}
+*/
 		fprintf(stderr,"]\n");
 		fprintf(stderr,"        router lifetime: %u\n", tmp->param_router_lifetime);
 		fprintf(stderr,"        reachable timer: %u\n", tmp->param_reachable_timer);
@@ -297,9 +299,11 @@
 			if (ptmp->param_flags_reserved&ND_OPT_PI_FLAG_AUTO) {
 				fprintf(stderr,"AUTO ");
 			}
+/* No suuportin FreeBSD yet
 			if (ptmp->param_flags_reserved&ND_OPT_PI_FLAG_RADDR) {
 				fprintf(stderr,"RADDR ");
 			}
+*/
 			fprintf(stderr,"]\n");
 			fprintf(stderr,"            valid time:     %u\n", ptmp->param_valid_time);
 			fprintf(stderr,"            preferred time: %u\n", ptmp->param_preferred_time);
