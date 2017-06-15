--- src/vmod_xkey.c.orig	2016-10-26 07:41:48 UTC
+++ src/vmod_xkey.c
@@ -130,7 +130,7 @@ xkey_ptrcmp(const struct xkey_ptrkey *k1
 }
 
 static struct xkey_hashhead *
-xkey_hashhead_new()
+xkey_hashhead_new(void)
 {
 	struct xkey_hashhead *head;
 
@@ -166,7 +166,7 @@ xkey_hashhead_delete(struct xkey_hashhea
 }
 
 static struct xkey_ochead *
-xkey_ochead_new()
+xkey_ochead_new(void)
 {
 	struct xkey_ochead *head;
 
@@ -201,7 +201,7 @@ xkey_ochead_delete(struct xkey_ochead **
 }
 
 static struct xkey_oc *
-xkey_oc_new()
+xkey_oc_new(void)
 {
 	struct xkey_oc *oc;
 
@@ -352,7 +352,7 @@ xkey_remove(struct xkey_ochead **pochead
 }
 
 static void
-xkey_cleanup()
+xkey_cleanup(void)
 {
 	struct xkey_hashkey *hashkey;
 	struct xkey_hashhead *hashhead;
@@ -396,7 +396,7 @@ xkey_cleanup()
 /**************************/
 
 static void
-xkey_cb_insert(struct worker *wrk, struct objcore *objcore, void *priv)
+xkey_cb_insert(struct worker *wrk, struct objcore *objcore)
 {
 	SHA256_CTX sha_ctx;
 	unsigned char digest[DIGEST_LEN];
@@ -404,8 +404,6 @@ xkey_cb_insert(struct worker *wrk, struc
 	const char hdr_h2[] = "X-HashTwo:";
 	const char *ep, *sp;
 
-	(void)priv;
-
 	CHECK_OBJ_NOTNULL(objcore, OBJCORE_MAGIC);
 
 	HTTP_FOREACH_PACK(wrk, objcore, sp) {
@@ -435,13 +433,10 @@ xkey_cb_insert(struct worker *wrk, struc
 }
 
 static void
-xkey_cb_remove(struct worker *wrk, struct objcore *objcore, void *priv)
+xkey_cb_remove(struct objcore *objcore)
 {
 	struct xkey_ochead *ochead;
 
-	(void)wrk;
-	(void)priv;
-
 	CHECK_OBJ_NOTNULL(objcore, OBJCORE_MAGIC);
 
 	AZ(pthread_mutex_lock(&mtx));
@@ -451,28 +446,50 @@ xkey_cb_remove(struct worker *wrk, struc
 	AZ(pthread_mutex_unlock(&mtx));
 }
 
+#if defined VARNISH_PLUS || !defined OEV_INSERT
 static void __match_proto__(exp_callback_f)
 xkey_cb(struct worker *wrk, struct objcore *objcore,
     enum exp_event_e event, void *priv)
 {
 
-	(void)wrk;
-	(void)objcore;
-	(void)event;
-	(void)priv;
+	CHECK_OBJ_NOTNULL(wrk, WORKER_MAGIC);
+	CHECK_OBJ_NOTNULL(objcore, OBJCORE_MAGIC);
+	AZ(priv);
 
 	switch (event) {
 	case EXP_INSERT:
 	case EXP_INJECT:
-		xkey_cb_insert(wrk, objcore, priv);
+		xkey_cb_insert(wrk, objcore);
 		break;
 	case EXP_REMOVE:
-		xkey_cb_remove(wrk, objcore, priv);
+		xkey_cb_remove(objcore);
 		break;
 	default:
 		WRONG("enum exp_event_e");
 	}
 }
+#else
+static void __match_proto__(obj_event_f)
+xkey_cb(struct worker *wrk, void *priv, struct objcore *oc, unsigned ev)
+{
+
+	CHECK_OBJ_NOTNULL(wrk, WORKER_MAGIC);
+	CHECK_OBJ_NOTNULL(oc, OBJCORE_MAGIC);
+	AZ(priv);
+	AN(ev);
+
+	switch (ev) {
+	case OEV_INSERT:
+		xkey_cb_insert(wrk, oc);
+		break;
+	case OEV_EXPIRE:
+		xkey_cb_remove(oc);
+		break;
+	default:
+		WRONG("Unexpected event");
+	}
+}
+#endif
 
 /**************************/
 
@@ -507,24 +524,36 @@ purge(VRT_CTX, VCL_STRING key, VCL_INT d
 		CHECK_OBJ_NOTNULL(oc->objcore, OBJCORE_MAGIC);
 		if (oc->objcore->flags & OC_F_BUSY)
 			continue;
+#if defined HAVE_OBJCORE_EXP
+		if (do_soft && oc->objcore->exp.ttl <=
+		    (ctx->now - oc->objcore->exp.t_origin))
+			continue;
+#else
 		if (do_soft &&
-		    oc->objcore->exp.ttl <= (ctx->now - oc->objcore->exp.t_origin))
+		    oc->objcore->ttl <= (ctx->now - oc->objcore->t_origin))
 			continue;
+#endif
 #ifdef VARNISH_PLUS
-		/* Varnish Plus interface for EXP_Rearm() is different. */
 		if (do_soft)
 			EXP_Rearm(ctx->req->wrk, oc->objcore, ctx->now, 0,
 			    oc->objcore->exp.grace, oc->objcore->exp.keep);
 		else
-			EXP_Rearm(ctx->req->wrk, oc->objcore, oc->objcore->exp.t_origin, 0,
-			    0, 0);
-#else
+			EXP_Rearm(ctx->req->wrk, oc->objcore,
+			    oc->objcore->exp.t_origin, 0, 0, 0);
+#elif defined HAVE_OBJCORE_EXP
 		if (do_soft)
 			EXP_Rearm(oc->objcore, ctx->now, 0,
 			    oc->objcore->exp.grace, oc->objcore->exp.keep);
 		else
-			EXP_Rearm(oc->objcore, oc->objcore->exp.t_origin, 0,
-			    0, 0);
+			EXP_Rearm(oc->objcore, oc->objcore->exp.t_origin,
+			    0, 0, 0);
+#else
+		if (do_soft)
+			EXP_Rearm(oc->objcore, ctx->now, 0,
+			    oc->objcore->grace, oc->objcore->keep);
+		else
+			EXP_Rearm(oc->objcore, oc->objcore->t_origin,
+			    0, 0, 0);
 #endif
 
 		i++;
@@ -554,11 +583,15 @@ vmod_event(VRT_CTX, struct vmod_priv *pr
 	switch (e) {
 	case VCL_EVENT_LOAD:
 		AZ(pthread_mutex_lock(&mtx));
-		if (n_init == 0) {
+		if (n_init == 0)
+#if defined VARNISH_PLUS || !defined OEV_INSERT
 			xkey_cb_handle =
 			    EXP_Register_Callback(xkey_cb, NULL);
-			AN(xkey_cb_handle);
-		}
+#else
+			xkey_cb_handle = ObjSubscribeEvents(xkey_cb, NULL,
+			    OEV_INSERT|OEV_EXPIRE);
+#endif
+		AN(xkey_cb_handle);
 		n_init++;
 		AZ(pthread_mutex_unlock(&mtx));
 		break;
@@ -566,10 +599,14 @@ vmod_event(VRT_CTX, struct vmod_priv *pr
 		AZ(pthread_mutex_lock(&mtx));
 		assert(n_init > 0);
 		n_init--;
+		AN(xkey_cb_handle);
 		if (n_init == 0) {
 			/* Do cleanup */
-			AN(xkey_cb_handle);
+#if defined VARNISH_PLUS || !defined OEV_INSERT
 			EXP_Deregister_Callback(&xkey_cb_handle);
+#else
+			ObjUnsubscribeEvents(&xkey_cb_handle);
+#endif
 			AZ(xkey_cb_handle);
 			xkey_cleanup();
 		}
