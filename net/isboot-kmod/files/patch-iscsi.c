--- iscsi.c.orig	2015-09-23 05:51:43 UTC
+++ iscsi.c
@@ -1036,24 +1036,30 @@ isboot_append_param(pdu_t *pp, char *for
 	return (n);
 }
 
-#if __FreeBSD_version >= 1000050
+#if __FreeBSD_version < 1000050
+static void
+isboot_free_mbufext(void *p, void *optarg)
+#endif
+#if __FreeBSD_version >= 1000050 && __FreeBSD_version < 1100000
+#define EXT_FREE_OK 0
 static int
 isboot_free_mbufext(struct mbuf *m, void *p, void *optarg)
-#else
+#endif
+#if __FreeBSD_version >= 1100000
 static void
-isboot_free_mbufext(void *p, void *optarg)
+isboot_free_mbufext(struct mbuf *m, void *p, void *optarg)
 #endif
 {
 
 	ISBOOT_TRACE("isboot_free_mbufext\n");
 	if (p == NULL)
-#if __FreeBSD_version >= 1000050
+#if __FreeBSD_version >= 1000050 && __FreeBSD_version < 1100000
 		return (EXT_FREE_OK);
 #else
 		return;
 #endif
 	isboot_free_mext(p);
-#if __FreeBSD_version >= 1000050
+#if __FreeBSD_version >= 1000050 && __FreeBSD_version < 1100000
 	return (EXT_FREE_OK);
 #endif
 }
@@ -1072,7 +1078,7 @@ isboot_xmit_pdu(struct isboot_sess *sess
 	    + sizeof(pp->hdr_dig) > MHLEN) {
 		panic("AHS=%d is too large", pp->ahs_len);
 	}
-	MGETHDR(mh, M_TRYWAIT, MT_DATA);
+	MGETHDR(mh, M_WAITOK, MT_DATA);
 	mh->m_pkthdr.rcvif = NULL;
 	memcpy(mh->m_data, &pp->ipdu, ISCSI_BHS_LEN);
 	mh->m_len = ISCSI_BHS_LEN;
@@ -1099,7 +1105,7 @@ isboot_xmit_pdu(struct isboot_sess *sess
 		/* allocate external buffer and add it to mbuf */
 		ds_dd = isboot_malloc_mext(ISCSI_ALIGN(pp->ds_len)
 		    + sizeof(pp->ds_dig));
-		MGET(md, M_TRYWAIT, MT_DATA);
+		MGET(md, M_WAITOK, MT_DATA);
 #if __FreeBSD_version >= 800016
 		MEXTADD(md, (caddr_t)ds_dd, (ISCSI_ALIGN(pp->ds_len)
 			+ sizeof(pp->ds_dig)),
