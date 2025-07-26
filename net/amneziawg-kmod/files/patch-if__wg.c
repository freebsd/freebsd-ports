--- if_wg.c.orig	2025-07-22 17:38:01 UTC
+++ if_wg.c
@@ -278,21 +278,21 @@ static volatile unsigned long peer_counter = 0;
 static int clone_count;
 static uma_zone_t wg_packet_zone;
 static volatile unsigned long peer_counter = 0;
-static const char wgname[] = "wg";
+static const char wgname[] = "awg";
 static unsigned wg_osd_jail_slot;
 
 static struct sx wg_sx;
-SX_SYSINIT(wg_sx, &wg_sx, "wg_sx");
+SX_SYSINIT(wg_sx, &wg_sx, "awg_sx");
 
 static LIST_HEAD(, wg_softc) wg_list = LIST_HEAD_INITIALIZER(wg_list);
 
 static TASKQGROUP_DEFINE(wg_tqg, mp_ncpus, 1);
 
-MALLOC_DEFINE(M_WG, "WG", "wireguard");
+MALLOC_DEFINE(M_WG, "AWG", "amneziawg");
 
-VNET_DEFINE_STATIC(struct if_clone *, wg_cloner);
+VNET_DEFINE_STATIC(struct if_clone *, awg_cloner);
 
-#define	V_wg_cloner	VNET(wg_cloner)
+#define	V_awg_cloner	VNET(awg_cloner)
 #define	WG_CAPS		IFCAP_LINKSTATE
 
 struct wg_timespec64 {
@@ -386,10 +386,10 @@ static int wg_ioctl(if_t, u_long, caddr_t);
 static void wg_reassign(if_t, struct vnet *, char *unused);
 static void wg_init(void *);
 static int wg_ioctl(if_t, u_long, caddr_t);
-static void vnet_wg_init(const void *);
-static void vnet_wg_uninit(const void *);
-static int wg_module_init(void);
-static void wg_module_deinit(void);
+static void vnet_awg_init(const void *);
+static void vnet_awg_uninit(const void *);
+static int awg_module_init(void);
+static void awg_module_deinit(void);
 
 /* TODO Peer */
 static struct wg_peer *
@@ -408,7 +408,7 @@ wg_peer_alloc(struct wg_softc *sc, const uint8_t pub_k
 
 	cookie_maker_init(&peer->p_cookie, pub_key);
 
-	rw_init(&peer->p_endpoint_lock, "wg_peer_endpoint");
+	rw_init(&peer->p_endpoint_lock, "awg_peer_endpoint");
 
 	wg_queue_init(&peer->p_stage_queue, "stageq");
 	wg_queue_init(&peer->p_encrypt_serial, "txq");
@@ -428,9 +428,9 @@ wg_peer_alloc(struct wg_softc *sc, const uint8_t pub_k
 	peer->p_handshake_retries = 0;
 
 	GROUPTASK_INIT(&peer->p_send, 0, (gtask_fn_t *)wg_deliver_out, peer);
-	taskqgroup_attach(qgroup_wg_tqg, &peer->p_send, peer, NULL, NULL, "wg send");
+	taskqgroup_attach(qgroup_wg_tqg, &peer->p_send, peer, NULL, NULL, "awg send");
 	GROUPTASK_INIT(&peer->p_recv, 0, (gtask_fn_t *)wg_deliver_in, peer);
-	taskqgroup_attach(qgroup_wg_tqg, &peer->p_recv, peer, NULL, NULL, "wg recv");
+	taskqgroup_attach(qgroup_wg_tqg, &peer->p_recv, peer, NULL, NULL, "awg recv");
 
 	LIST_INIT(&peer->p_aips);
 	peer->p_aips_num = 0;
@@ -3286,26 +3286,26 @@ static void
 }
 
 static void
-vnet_wg_init(const void *unused __unused)
+vnet_awg_init(const void *unused __unused)
 {
 	struct if_clone_addreq req = {
 		.create_f = wg_clone_create,
 		.destroy_f = wg_clone_destroy,
 		.flags = IFC_F_AUTOUNIT,
 	};
-	V_wg_cloner = ifc_attach_cloner(wgname, &req);
+	V_awg_cloner = ifc_attach_cloner(wgname, &req);
 }
-VNET_SYSINIT(vnet_wg_init, SI_SUB_PROTO_IFATTACHDOMAIN, SI_ORDER_ANY,
-	     vnet_wg_init, NULL);
+VNET_SYSINIT(vnet_awg_init, SI_SUB_PROTO_IFATTACHDOMAIN, SI_ORDER_ANY,
+	     vnet_awg_init, NULL);
 
 static void
-vnet_wg_uninit(const void *unused __unused)
+vnet_awg_uninit(const void *unused __unused)
 {
-	if (V_wg_cloner)
-		ifc_detach_cloner(V_wg_cloner);
+	if (V_awg_cloner)
+		ifc_detach_cloner(V_awg_cloner);
 }
-VNET_SYSUNINIT(vnet_wg_uninit, SI_SUB_PROTO_IFATTACHDOMAIN, SI_ORDER_ANY,
-	       vnet_wg_uninit, NULL);
+VNET_SYSUNINIT(vnet_awg_uninit, SI_SUB_PROTO_IFATTACHDOMAIN, SI_ORDER_ANY,
+    vnet_awg_uninit, NULL);
 
 static int
 wg_prison_remove(void *obj, void *data __unused)
@@ -3352,14 +3352,14 @@ static int
 #endif
 
 static int
-wg_module_init(void)
+awg_module_init(void)
 {
 	int ret;
 	osd_method_t methods[PR_MAXMETHOD] = {
 		[PR_METHOD_REMOVE] = wg_prison_remove,
 	};
 
-	wg_packet_zone = uma_zcreate("wg packet", sizeof(struct wg_packet),
+	wg_packet_zone = uma_zcreate("awg packet", sizeof(struct wg_packet),
 	     NULL, NULL, NULL, NULL, 0, 0);
 
 	ret = crypto_init();
@@ -3378,15 +3378,15 @@ static void
 }
 
 static void
-wg_module_deinit(void)
+awg_module_deinit(void)
 {
 	VNET_ITERATOR_DECL(vnet_iter);
 	VNET_LIST_RLOCK();
 	VNET_FOREACH(vnet_iter) {
-		struct if_clone *clone = VNET_VNET(vnet_iter, wg_cloner);
+		struct if_clone *clone = VNET_VNET(vnet_iter, awg_cloner);
 		if (clone) {
 			ifc_detach_cloner(clone);
-			VNET_VNET(vnet_iter, wg_cloner) = NULL;
+			VNET_VNET(vnet_iter, awg_cloner) = NULL;
 		}
 	}
 	VNET_LIST_RUNLOCK();
@@ -3401,13 +3401,13 @@ static int
 }
 
 static int
-wg_module_event_handler(module_t mod, int what, void *arg)
+awg_module_event_handler(module_t mod, int what, void *arg)
 {
 	switch (what) {
 		case MOD_LOAD:
-			return wg_module_init();
+			return awg_module_init();
 		case MOD_UNLOAD:
-			wg_module_deinit();
+			awg_module_deinit();
 			break;
 		default:
 			return (EOPNOTSUPP);
@@ -3415,12 +3415,12 @@ wg_module_event_handler(module_t mod, int what, void *
 	return (0);
 }
 
-static moduledata_t wg_moduledata = {
-	"if_wg",
-	wg_module_event_handler,
+static moduledata_t awg_moduledata = {
+	"if_awg",
+	awg_module_event_handler,
 	NULL
 };
 
-DECLARE_MODULE(if_wg, wg_moduledata, SI_SUB_PSEUDO, SI_ORDER_ANY);
-MODULE_VERSION(if_wg, WIREGUARD_VERSION);
-MODULE_DEPEND(if_wg, crypto, 1, 1, 1);
+DECLARE_MODULE(if_awg, awg_moduledata, SI_SUB_PSEUDO, SI_ORDER_ANY);
+MODULE_VERSION(if_awg, WIREGUARD_VERSION);
+MODULE_DEPEND(if_awg, crypto, 1, 1, 1);
