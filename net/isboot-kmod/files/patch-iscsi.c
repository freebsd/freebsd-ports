--- iscsi.c.orig	2022-05-11 20:19:06 UTC
+++ iscsi.c
@@ -210,10 +210,12 @@ static struct isboot_sess isboot_g_sess;
 #define ISBOOT_TRACE(...) do { printf(__VA_ARGS__); } while (0)
 #define ISBOOT_TRACEDUMP(LABEL, BUF, LEN) \
 	do { isboot_dump((LABEL), (BUF), (LEN)); } while (0)
+#define	__trace_used
 #else
 #define ISBOOT_ERROR(...) do { printf(__VA_ARGS__); } while (0)
 #define ISBOOT_TRACE(...)
 #define ISBOOT_TRACEDUMP(LABEL, BUF, LEN)
+#define	__trace_used __unused
 #endif
 
 #ifdef ISBOOT_OPT_PREFERRED_HEADER_DIGEST
@@ -1179,13 +1181,11 @@ isboot_recv_pdu(struct isboot_sess *sess, pdu_t *pp)
 	struct uio uio;
 	uint8_t *bhs;
 	uint32_t crc32c;
-	uint32_t total;
 	int error;
 	int flags;
 	int ahs_len, ds_len;
 
 	memset(&uio, 0, sizeof(uio));
-	total = 0;
 
 	/* BHS */
 	flags = MSG_WAITALL;
@@ -1201,7 +1201,6 @@ isboot_recv_pdu(struct isboot_sess *sess, pdu_t *pp)
 	}
 	m_copydata(mp, 0, ISCSI_BHS_LEN, (caddr_t)&pp->ipdu.bhs);
 	m_freem(mp);
-	total += ISCSI_BHS_LEN;
 	bhs = (uint8_t *)&pp->ipdu.bhs;
 	ahs_len = DGET8(&bhs[4]);
 	ahs_len *= 4;
@@ -1246,7 +1245,6 @@ isboot_recv_pdu(struct isboot_sess *sess, pdu_t *pp)
 		    (caddr_t)pp->ahs_addr);
 		m_freem(mp);
 		pp->ahs_len = ahs_len;
-		total += ISCSI_ALIGN(ahs_len);
 	}
 
 	/* HD */
@@ -1265,7 +1263,6 @@ isboot_recv_pdu(struct isboot_sess *sess, pdu_t *pp)
 		m_copydata(mp, 0, sizeof(pp->hdr_dig),
 		    (caddr_t)&pp->hdr_dig);
 		m_freem(mp);
-		total += sizeof(pp->hdr_dig);
 	}
 
 	/* DATA */
@@ -1285,7 +1282,6 @@ isboot_recv_pdu(struct isboot_sess *sess, pdu_t *pp)
 		    (caddr_t)pp->ds_addr);
 		m_freem(mp);
 		pp->ds_len = ds_len;
-		total += ISCSI_ALIGN(ds_len);
 	}
 
 	/* DD */
@@ -1304,7 +1300,6 @@ isboot_recv_pdu(struct isboot_sess *sess, pdu_t *pp)
 		m_copydata(mp, 0, sizeof(pp->ds_dig),
 		    (caddr_t)&pp->ds_dig);
 		m_freem(mp);
-		total += sizeof(pp->ds_dig);
 	}
 
 	/* check digest */
@@ -1579,7 +1574,7 @@ isboot_rsp_login(struct isboot_sess *sess, pdu_t *pp)
 	uint32_t ExpCmdSN, MaxCmdSN;
 	uint16_t tsih;
 	int T_bit;
-	int CSG, NSG;
+	int NSG;
 	int StatusClass, StatusDetail;
 	int error;
 
@@ -1597,7 +1592,6 @@ isboot_rsp_login(struct isboot_sess *sess, pdu_t *pp)
 	}
 
 	T_bit = BGET8(&rsp[1], 7);
-	CSG = BGET8W(&rsp[1], 3, 2);
         NSG = BGET8W(&rsp[1], 1, 2);
 	tsih = DGET16(&rsp[14]);
 
@@ -2200,10 +2194,7 @@ isboot_action(struct cam_sim *sim, union ccb *ccb)
 static void
 isboot_action(struct cam_sim *sim, union ccb *ccb)
 {
-	struct isboot_sess *sess;
-
 	ISBOOT_TRACE("isboot action %x\n", ccb->ccb_h.func_code);
-	sess = (struct isboot_sess *)cam_sim_softc(sim);
 
 	switch (ccb->ccb_h.func_code) {
 	case XPT_SCSI_IO:
@@ -2291,14 +2282,12 @@ isboot_poll(struct cam_sim *sim)
 static void
 isboot_poll(struct cam_sim *sim)
 {
-	struct isboot_sess *sess;
 	static int poll_out = 0;
 
 	if (poll_out == 0) {
 		poll_out = 1;
 		ISBOOT_TRACE("isboot poll\n");
 	}
-	sess = (struct isboot_sess *)cam_sim_softc(sim);
 	/* called after crash dump */
 	/* XXX need flush? */
 }
@@ -2681,14 +2670,13 @@ isboot_rsp_scsi(struct isboot_sess *sess, pdu_t *pp)
 	uint8_t *sp;
 	struct isboot_task *taskp;
 	union ccb *ccb;
-	uint32_t ITT, SNT;
-	uint32_t StatSN;
-	uint32_t ExpCmdSN, MaxCmdSN;
-	uint32_t ExpDataSN;
+	uint32_t ITT;
+	uint32_t StatSN __trace_used;
+	uint32_t ExpCmdSN __trace_used, MaxCmdSN __trace_used;
+	uint32_t ExpDataSN __trace_used;
 	int status, response;
-	int o_bit, u_bit, O_bit, U_bit;
+	int o_bit __trace_used, u_bit __trace_used, O_bit, U_bit;
 	int residual;
-	int bidi_residual;
 	int len, sense_len;
 
 	ITT = DGET32(&rsp[16]);
@@ -2718,11 +2706,9 @@ isboot_rsp_scsi(struct isboot_sess *sess, pdu_t *pp)
 	mtx_unlock_spin(&sess->sn_mtx);
 
 	ITT = DGET32(&rsp[16]);
-	SNT = DGET32(&rsp[20]);
 	ExpCmdSN = DGET32(&rsp[28]);
 	MaxCmdSN = DGET32(&rsp[32]);
 	ExpDataSN = DGET32(&rsp[36]);
-	bidi_residual = DGET32(&rsp[40]);
 	residual = DGET32(&rsp[44]);
 
 	if (pp->ds_len > 2) {
@@ -2822,12 +2808,11 @@ isboot_rsp_read_data(struct isboot_sess *sess, pdu_t *
 	struct isboot_task *taskp;
 	union ccb *ccb;
 	uint8_t *data;
-	uint32_t ITT, TTT;
-	uint32_t StatSN;
-	uint32_t ExpCmdSN, MaxCmdSN;
-	uint32_t DataSN, ExpDataSN;
+	uint32_t ITT;
+	uint32_t StatSN __trace_used;
+	uint32_t ExpCmdSN __trace_used, MaxCmdSN __trace_used;
+	uint32_t DataSN __trace_used, ExpDataSN;
 	uint32_t TL;
-	int error;
 	int offset;
 	int status, response;
 	int len;
@@ -2856,7 +2841,6 @@ isboot_rsp_read_data(struct isboot_sess *sess, pdu_t *
 	len = pp->ds_len;
 	status = 0;
 	response = 0;
-	error = 0;
 
 	F_bit = BGET8(&rsp[1], 7);
 	S_bit = BGET8(&rsp[1], 0);
@@ -2877,7 +2861,6 @@ isboot_rsp_read_data(struct isboot_sess *sess, pdu_t *
 		StatSN = 0;
 	}
 	ITT = DGET32(&rsp[16]);
-	TTT = DGET32(&rsp[20]);
 	ExpCmdSN = DGET32(&rsp[28]);
 	MaxCmdSN = DGET32(&rsp[32]);
 	DataSN = DGET32(&rsp[36]);
@@ -2975,9 +2958,8 @@ isboot_rsp_r2t(struct isboot_sess *sess, pdu_t *pp)
 	uint8_t *data;
 	uint64_t LUN;
 	uint32_t ITT, TTT;
-	uint32_t R2TSN;
 	uint32_t StatSN;
-	uint32_t ExpCmdSN, MaxCmdSN;
+	uint32_t ExpCmdSN __trace_used, MaxCmdSN __trace_used;
 	uint32_t DataSN;
 	uint32_t TL;
 	int error;
@@ -3013,7 +2995,6 @@ isboot_rsp_r2t(struct isboot_sess *sess, pdu_t *pp)
 	TTT = DGET32(&rsp[20]);
 	ExpCmdSN = DGET32(&rsp[28]);
 	MaxCmdSN = DGET32(&rsp[32]);
-	R2TSN = DGET32(&rsp[36]);
 	offset = DGET32(&rsp[40]);
 	len = DGET32(&rsp[44]);
 
@@ -3123,12 +3104,10 @@ isboot_rsp_nopin(struct isboot_sess *sess, pdu_t *pp)
 isboot_rsp_nopin(struct isboot_sess *sess, pdu_t *pp)
 {
 	uint8_t *rsp = (uint8_t *)&pp->ipdu.bhs;
-	uint64_t LUN;
 	uint32_t ITT, TTT;
-	uint32_t StatSN;
-	uint32_t ExpCmdSN, MaxCmdSN;
+	uint32_t StatSN __trace_used;
+	uint32_t ExpCmdSN __trace_used, MaxCmdSN __trace_used;
 
-	LUN = DGET64(&rsp[8]);
 	ITT = DGET32(&rsp[16]);
 	TTT = DGET32(&rsp[20]);
 	StatSN = DGET32(&rsp[24]);
@@ -3166,13 +3145,12 @@ isboot_execute(struct isboot_sess *sess, pdu_t *pp)
 isboot_execute(struct isboot_sess *sess, pdu_t *pp)
 {
 	uint8_t *bhs = (uint8_t *)&pp->ipdu.bhs;
-	int immediate, opcode;
+	int opcode;
 	int rc;
 
 	if (pp == NULL)
 		return (EINVAL);
 
-	immediate = BGET8W(&bhs[0], 6, 1);
 	opcode = BGET8W(&bhs[0], 5, 6);
 
 	ISBOOT_TRACE("isboot_execute opcode=0x%x\n", opcode);
