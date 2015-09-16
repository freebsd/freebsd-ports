--- src/osdep/freebsd.c.orig	2011-09-24 22:05:54 UTC
+++ src/osdep/freebsd.c
@@ -389,7 +389,7 @@ static int do_fbsd_open(struct wif *wi, 
 
         memset(&ifr, 0, sizeof(ifr));
         strcpy(ifr.ifr_name, iface);
-        ifr.ifr_media = ifmr.ifm_current | IFM_IEEE80211_MONITOR;
+        ifr.ifr_media = ifmr.ifm_current;
         if (ioctl(s, SIOCSIFMEDIA, &ifr) == -1)
 		goto close_sock;
 
@@ -510,6 +510,39 @@ static int fbsd_set_mac(struct wif *wi, 
 	return ioctl(priv->pf_s, SIOCSIFLLADDR, ifr);
 }
 
+static int fbsd_set_mtu(struct wif *wi, int mtu)
+{
+	struct priv_fbsd *priv = wi_priv(wi);
+	struct ifreq *ifr = &priv->pf_ifr;
+
+	memset(ifr, 0, sizeof(struct ifreq));
+
+	strncpy(ifr->ifr_name, wi_get_ifname(wi), sizeof(ifr->ifr_name));
+	ifr->ifr_mtu = mtu;
+
+	if(ioctl(priv->pf_s, SIOCSIFMTU, ifr) < 0)
+		return -1;
+
+	return 0;
+}
+
+static int fbsd_get_mtu(struct wif *wi)
+{
+	struct priv_fbsd *priv = wi_priv(wi);
+	struct ifreq ifr;
+
+	memset(&ifr, 0, sizeof(struct ifreq));
+
+	ifr.ifr_addr.sa_family = AF_INET;
+
+	strncpy(ifr.ifr_name, wi_get_ifname(wi), sizeof(ifr.ifr_name));
+
+	if(ioctl(priv->pf_s, SIOCGIFMTU, (caddr_t)&ifr) < 0)
+		return -1;
+
+	return ifr.ifr_mtu;
+}
+
 static struct wif *fbsd_open(char *iface)
 {
 	struct wif *wi;
@@ -530,7 +563,9 @@ static struct wif *fbsd_open(char *iface
 	wi->wi_set_mac		= fbsd_set_mac;
 	wi->wi_get_rate		= fbsd_get_rate;
 	wi->wi_set_rate		= fbsd_set_rate;
-        wi->wi_get_monitor      = fbsd_get_monitor;
+	wi->wi_get_monitor	= fbsd_get_monitor;
+	wi->wi_get_mtu		= fbsd_get_mtu;
+	wi->wi_set_mtu		= fbsd_set_mtu;
 
 	/* setup iface */
 	fd = do_fbsd_open(wi, iface);
@@ -544,6 +579,8 @@ static struct wif *fbsd_open(char *iface
 	pf->pf_fd = fd;
         pf->pf_txparams.ibp_vers = IEEE80211_BPF_VERSION;
 	pf->pf_txparams.ibp_len = sizeof(struct ieee80211_bpf_params) - 6;
+	pf->pf_txparams.ibp_rate0 = 2;         /* 1 MB/s XXX */
+	pf->pf_txparams.ibp_try0 = 1;          /* no retransmits */
 	pf->pf_txparams.ibp_rate1 = 2;         /* 1 MB/s XXX */
 	pf->pf_txparams.ibp_try1 = 1;          /* no retransmits */
 	pf->pf_txparams.ibp_flags = IEEE80211_BPF_NOACK;
