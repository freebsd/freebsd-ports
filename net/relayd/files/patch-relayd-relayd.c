--- relayd/relayd.c.orig	2011-05-19 10:56:49.000000000 +0200
+++ relayd/relayd.c	2011-05-22 10:34:12.913164741 +0200
@@ -17,7 +17,12 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <openssl/rand.h>
+#else
 #include <sys/types.h>
+#endif
 #include <sys/queue.h>
 #include <sys/socket.h>
 #include <sys/wait.h>
@@ -39,7 +44,11 @@
 #include <unistd.h>
 #include <ctype.h>
 #include <pwd.h>
+#ifdef __FreeBSD__
+#include <sha.h>
+#else
 #include <sha1.h>
+#endif
 #include <md5.h>
 
 #include <openssl/ssl.h>
@@ -150,6 +159,11 @@
 	struct relayd		*env;
 	struct privsep		*ps;
 	const char		*conffile = CONF_FILE;
+#ifdef __FreeBSD__
+#if __FreeBSD_version > 800040
+	u_int32_t               rnd[256];
+#endif
+#endif
 
 	while ((c = getopt(argc, argv, "dD:nf:v")) != -1) {
 		switch (c) {
@@ -220,6 +234,16 @@
 	else
 		log_info("startup");
 
+#ifdef __FreeBSD__
+#if __FreeBSD_version > 800040
+	arc4random_stir();
+	arc4random_buf(rnd, sizeof(rnd));
+	RAND_seed(rnd, sizeof(rnd));
+#else
+	RAND_load_file("/dev/random",2048);
+#endif
+#endif
+
 	ps->ps_instances[PROC_RELAY] = env->sc_prefork_relay;
 	proc_init(ps, procs, nitems(procs));
 
@@ -258,7 +282,9 @@
 	if (parent_configure(env) == -1)
 		fatalx("configuration failed");
 
+#ifndef __FreeBSD__
 	init_routes(env);
+#endif
 
 	event_dispatch();
 
@@ -273,7 +299,9 @@
 {
 	struct table		*tb;
 	struct rdr		*rdr;
+#ifndef __FreeBSD__
 	struct router		*rt;
+#endif
 	struct protocol		*proto;
 	struct relay		*rlay;
 	int			 id;
@@ -284,8 +312,10 @@
 		config_settable(env, tb);
 	TAILQ_FOREACH(rdr, env->sc_rdrs, entry)
 		config_setrdr(env, rdr);
+#ifndef __FreeBSD__
 	TAILQ_FOREACH(rt, env->sc_rts, rt_entry)
 		config_setrt(env, rt);
+#endif
 	TAILQ_FOREACH(proto, env->sc_protos, entry)
 		config_setproto(env, proto);
 	TAILQ_FOREACH(rlay, env->sc_relays, rl_entry)
@@ -359,9 +389,11 @@
 
 	proc_kill(env->sc_ps);
 	control_cleanup(&env->sc_ps->ps_csock);
+#ifndef __FreeBSD__
 	carp_demote_shutdown();
 	if (env->sc_flags & F_DEMOTE)
 		carp_demote_reset(env->sc_demote_group, 128);
+#endif
 
 	free(env->sc_ps);
 	free(env);
@@ -375,12 +407,15 @@
 parent_dispatch_pfe(int fd, struct privsep_proc *p, struct imsg *imsg)
 {
 	struct relayd		*env = p->p_env;
+#ifndef __FreeBSD__
 	struct ctl_demote	 demote;
 	struct ctl_netroute	 crt;
+#endif
 	u_int		 	 v;
 	char			*str = NULL;
 
 	switch (imsg->hdr.type) {
+#ifndef __FreeBSD__
 	case IMSG_DEMOTE:
 		IMSG_SIZE_CHECK(imsg, &demote);
 		memcpy(&demote, imsg->data, sizeof(demote));
@@ -391,6 +426,7 @@
 		memcpy(&crt, imsg->data, sizeof(crt));
 		pfe_route(env, &crt);
 		break;
+#endif
 	case IMSG_CTL_RESET:
 		IMSG_SIZE_CHECK(imsg, &v);
 		memcpy(&v, imsg->data, sizeof(v));
@@ -432,9 +468,11 @@
 		proc_compose_imsg(ps, PROC_HCE, -1, IMSG_SCRIPT,
 		    -1, &scr, sizeof(scr));
 		break;
+#ifndef __FreeBSD__
 	case IMSG_SNMPSOCK:
 		(void)snmp_setsock(env, p->p_id);
 		break;
+#endif
 	case IMSG_CFG_DONE:
 		if (env->sc_reload)
 			env->sc_reload--;
@@ -645,6 +683,7 @@
 	return (NULL);
 }
 
+#ifndef __FreeBSD__
 struct netroute *
 route_find(struct relayd *env, objid_t id)
 {
@@ -666,6 +705,7 @@
 			return (rt);
 	return (NULL);
 }
+#endif
 
 struct host *
 host_findbyname(struct relayd *env, const char *name)
@@ -840,7 +880,11 @@
 {
 	switch (type) {
 	case DIGEST_SHA1:
+#ifdef __FreeBSD__
+		return (SHA1_Data(data, len, buf));
+#else
 		return (SHA1Data(data, len, buf));
+#endif
 		break;
 	case DIGEST_MD5:
 		return (MD5Data(data, len, buf));
@@ -1077,9 +1121,17 @@
 	    bnd->bnd_proto == IPPROTO_TCP ? SOCK_STREAM : SOCK_DGRAM,
 	    bnd->bnd_proto)) == -1)
 		goto fail;
+#ifdef SO_BINDANY
 	if (setsockopt(s, SOL_SOCKET, SO_BINDANY,
 	    &v, sizeof(v)) == -1)
 		goto fail;
+#else
+#ifdef IP_BINDANY
+	if (setsockopt(s, IPPROTO_IP, IP_BINDANY,
+	    &v, sizeof(v)) == -1)
+		goto fail;
+#endif
+#endif
 	if (bind(s, (struct sockaddr *)&bnd->bnd_ss,
 	    bnd->bnd_ss.ss_len) == -1)
 		goto fail;
