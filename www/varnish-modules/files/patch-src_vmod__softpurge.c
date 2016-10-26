--- src/vmod_softpurge.c.orig	2016-10-26 07:31:42 UTC
+++ src/vmod_softpurge.c
@@ -60,6 +60,7 @@ vmod_softpurge(VRT_CTX)
 	now = ctx->req->t_prev;
 	Lck_Lock(&oh->mtx);
 	assert(oh->refcnt > 0);
+#if defined VARNISH_PLUS || defined OC_EF_DYING
 	VTAILQ_FOREACH(oc, &oh->objcs, list) {
 		CHECK_OBJ_NOTNULL(oc, OBJCORE_MAGIC);
 		assert(oc->objhead == oh);
@@ -73,16 +74,30 @@ vmod_softpurge(VRT_CTX)
 		spc -= sizeof *ocp;
 		ocp[nobj++] = oc;
 	}
+#else
+	VTAILQ_FOREACH(oc, &oh->objcs, hsh_list) {
+		CHECK_OBJ_NOTNULL(oc, OBJCORE_MAGIC);
+		assert(oc->objhead == oh);
+		if (oc->flags & (OC_F_BUSY|OC_F_DYING))
+			continue;
+		if (spc < sizeof *ocp)
+			break;
+		oc->refcnt++;
+		spc -= sizeof *ocp;
+		ocp[nobj++] = oc;
+	}
+#endif
 	Lck_Unlock(&oh->mtx);
 
 	for (n = 0; n < nobj; n++) {
 		oc = ocp[n];
 		CHECK_OBJ_NOTNULL(oc, OBJCORE_MAGIC);
-#ifdef VARNISH_PLUS
-		/* Varnish Plus interface for EXP_Rearm() is different. */
+#if defined VARNISH_PLUS
 		EXP_Rearm(ctx->req->wrk, oc, now, 0, oc->exp.grace, oc->exp.keep);
-#else
+#elif defined HAVE_OBJCORE_EXP
 		EXP_Rearm(oc, now, 0, oc->exp.grace, oc->exp.keep);
+#else
+		EXP_Rearm(oc, now, 0, oc->grace, oc->keep);
 #endif
 		(void)HSH_DerefObjCore(ctx->req->wrk, &oc);
 
