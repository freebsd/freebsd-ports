--- src/osdep/freebsd.c.orig	2008-06-10 02:55:09.000000000 +0700
+++ src/osdep/freebsd.c	2008-08-11 20:01:53.000000000 +0700
@@ -53,7 +53,9 @@
 	unsigned char			pf_buf[4096];
 	unsigned char			*pf_next;
 	int				pf_totlen;
+#if __FreeBSD_version > 700018
         struct ieee80211_bpf_params	pf_txparams;
+#endif
 
 	/* setchan */
 	int				pf_s;
@@ -280,13 +282,16 @@
 static int fbsd_write(struct wif *wi, unsigned char *h80211, int len,
 		      struct tx_info *ti)
 {
+#if __FreeBSD_version > 700018
         struct iovec iov[2];
+#endif
 	struct priv_fbsd *pf = wi_priv(wi);
 	int rc;
 
 	/* XXX make use of ti */
 	if (ti) {}
 
+#if __FreeBSD_version > 700018
 	iov[0].iov_base = &pf->pf_txparams;
 	iov[0].iov_len = pf->pf_txparams.ibp_len;
 
@@ -294,12 +299,19 @@
         iov[1].iov_len = len;
 
 	rc = writev(pf->pf_fd, iov, 2);
+#else
+	rc = write(pf->pf_fd, h80211, len);
+#endif
 	if (rc == -1)
 		return rc;
+#if __FreeBSD_version > 700018
 	if (rc < (int) iov[0].iov_len)
 		return 0;
 
 	return rc - iov[0].iov_len;
+#else
+	return 0;
+#endif
 }
 
 static int fbsd_set_channel(struct wif *wi, int chan)
@@ -542,6 +554,7 @@
 	/* setup private state */
 	pf = wi_priv(wi);
 	pf->pf_fd = fd;
+#if __FreeBSD_version > 700018
         pf->pf_txparams.ibp_vers = IEEE80211_BPF_VERSION;
 	pf->pf_txparams.ibp_len = sizeof(struct ieee80211_bpf_params) - 6;
 	pf->pf_txparams.ibp_rate1 = 2;         /* 1 MB/s XXX */
@@ -549,6 +562,7 @@
 	pf->pf_txparams.ibp_flags = IEEE80211_BPF_NOACK;
 	pf->pf_txparams.ibp_power = 100;       /* nominal max */
 	pf->pf_txparams.ibp_pri = WME_AC_VO;   /* high priority */
+#endif
 
 	return wi;
 }
