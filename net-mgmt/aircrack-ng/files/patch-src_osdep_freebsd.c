--- src/osdep/freebsd.c.orig	2011-09-25 00:05:54.000000000 +0200
+++ src/osdep/freebsd.c	2013-09-29 13:49:18.588462319 +0200
@@ -53,7 +53,9 @@ struct priv_fbsd {
 	unsigned char			pf_buf[4096];
 	unsigned char			*pf_next;
 	int				pf_totlen;
+#if __FreeBSD_version > 700018
         struct ieee80211_bpf_params	pf_txparams;
+#endif
 
 	/* setchan */
 	int				pf_s;
@@ -280,13 +282,16 @@ static int fbsd_read(struct wif *wi, uns
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
 
@@ -294,12 +299,19 @@ static int fbsd_write(struct wif *wi, un
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
@@ -389,7 +401,7 @@ static int do_fbsd_open(struct wif *wi, 
 
         memset(&ifr, 0, sizeof(ifr));
         strcpy(ifr.ifr_name, iface);
-        ifr.ifr_media = ifmr.ifm_current | IFM_IEEE80211_MONITOR;
+        ifr.ifr_media = ifmr.ifm_current;
         if (ioctl(s, SIOCSIFMEDIA, &ifr) == -1)
 		goto close_sock;
 
@@ -542,13 +554,17 @@ static struct wif *fbsd_open(char *iface
 	/* setup private state */
 	pf = wi_priv(wi);
 	pf->pf_fd = fd;
+#if __FreeBSD_version > 700018
         pf->pf_txparams.ibp_vers = IEEE80211_BPF_VERSION;
 	pf->pf_txparams.ibp_len = sizeof(struct ieee80211_bpf_params) - 6;
+	pf->pf_txparams.ibp_rate0 = 2;         /* 1 MB/s XXX */
+	pf->pf_txparams.ibp_try0 = 1;          /* no retransmits */
 	pf->pf_txparams.ibp_rate1 = 2;         /* 1 MB/s XXX */
 	pf->pf_txparams.ibp_try1 = 1;          /* no retransmits */
 	pf->pf_txparams.ibp_flags = IEEE80211_BPF_NOACK;
 	pf->pf_txparams.ibp_power = 100;       /* nominal max */
 	pf->pf_txparams.ibp_pri = WME_AC_VO;   /* high priority */
+#endif
 
 	return wi;
 }
