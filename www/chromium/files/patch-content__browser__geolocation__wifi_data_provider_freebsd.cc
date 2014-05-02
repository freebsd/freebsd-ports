--- ./content/browser/geolocation/wifi_data_provider_freebsd.cc.orig	2014-04-24 23:23:44.000000000 +0200
+++ ./content/browser/geolocation/wifi_data_provider_freebsd.cc	2014-04-24 23:23:44.000000000 +0200
@@ -0,0 +1,200 @@
+// Copyright (c) 2010 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+// For FreeBSD we use the getifaddrs(3) to obtain the list of interfaces
+// and then check for those with an 802.11 media type and able to return
+// a list of stations.  This is similar to ifconfig(8).
+
+#include "content/browser/geolocation/wifi_data_provider_freebsd.h"
+
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/sockio.h>
+#include <net/if.h>
+#include <net/if_media.h>
+#include <ifaddrs.h>
+#include <net80211/ieee80211_ioctl.h>
+#include <net/ethernet.h>
+
+#include "base/strings/utf_string_conversions.h"
+#include "content/browser/geolocation/wifi_data_provider_common.h"
+
+namespace content {
+namespace {
+// The time periods, in milliseconds, between successive polls of the wifi data.
+const int kDefaultPollingInterval = 10000;  // 10s
+const int kNoChangePollingInterval = 120000;  // 2 mins
+const int kTwoNoChangePollingInterval = 600000;  // 10 mins
+const int kNoWifiPollingIntervalMilliseconds = 20 * 1000; // 20s
+
+// Convert a wifi frequency to the corresponding channel.
+// Taken from wifi_data_provider_linux.cc where it says this was
+// adapted from geolocaiton/wifilib.cc in googleclient (internal to google).
+int frquency_to_channel(int frequency_Mhz) {
+	if (frequency_Mhz >= 2412 && frequency_Mhz <= 2472)  // Channels 1-13.
+		return (frequency_Mhz - 2407) / 5;
+	if (frequency_Mhz == 2484)
+		return 14;
+	if (frequency_Mhz > 5000 && frequency_Mhz < 6000)  // .11a bands.
+		return (frequency_Mhz - 5000) / 5;
+	// Ignore everything else.
+	return AccessPointData().channel;  // invalid channel
+}
+
+// Provides the wifi API binding for FreeBSD.
+class FreeBSDAccessPointData : public WifiDataProviderCommon::WlanApiInterface {
+public:
+	FreeBSDAccessPointData();
+	~FreeBSDAccessPointData();
+
+	// this does nothing
+	bool Init();
+
+	// get the AP data
+	virtual bool GetAccessPointData(WifiData::AccessPointDataSet* data);
+
+private:
+	DISALLOW_COPY_AND_ASSIGN(FreeBSDAccessPointData);
+};
+
+FreeBSDAccessPointData::FreeBSDAccessPointData() {
+}
+
+FreeBSDAccessPointData::~FreeBSDAccessPointData() {
+}
+
+bool FreeBSDAccessPointData::Init() {
+	return true;
+}
+
+bool FreeBSDAccessPointData::GetAccessPointData(WifiData::AccessPointDataSet* data) {
+	bool			res;
+	char			*dupn;
+	struct ifaddrs		*ifal, *ifa;
+	struct ifreq		ifr;
+	struct ifmediareq	ifmr;
+	struct ieee80211req 	i802r;
+	int			s;
+	char			iscanbuf[32*1024], *vsr;
+	unsigned		len;
+	AccessPointData		apd;
+
+	res = false;
+	if (getifaddrs(&ifal) < 0)
+		return res;
+
+	dupn = NULL;
+	for (ifa = ifal; ifa; ifa = ifa->ifa_next) {
+		memset(&ifr, 0, sizeof(ifr));
+
+		if (dupn != NULL && strcmp(dupn, ifa->ifa_name) == 0)
+			continue;
+		dupn = ifa->ifa_name;
+
+		strncpy(ifr.ifr_name, ifa->ifa_name, sizeof(ifr.ifr_name));
+		ifr.ifr_addr.sa_family = AF_LOCAL;
+
+		if ((s = socket(ifr.ifr_addr.sa_family, SOCK_DGRAM, 0)) < 0)
+			continue;
+
+		(void) memset(&ifmr, 0, sizeof(ifmr));
+		(void) strncpy(ifmr.ifm_name, ifa->ifa_name, sizeof(ifmr.ifm_name));
+
+		if (ioctl(s, SIOCGIFMEDIA, (caddr_t)&ifmr) < 0) {
+			close(s);
+			continue;
+		}
+		if (IFM_TYPE(ifmr.ifm_active) != IFM_IEEE80211) {
+			close(s);
+			continue;
+		}
+
+		(void) memset(&i802r, 0, sizeof(i802r));
+		(void) strncpy(i802r.i_name, ifa->ifa_name, sizeof(i802r.i_name));
+		i802r.i_type = IEEE80211_IOC_SCAN_RESULTS;
+		i802r.i_data = iscanbuf;
+		i802r.i_len = sizeof(iscanbuf);
+		if (ioctl(s, SIOCG80211, &i802r) < 0) {
+			close(s);
+			continue;
+		}
+
+		close(s);
+
+		vsr = (char *) i802r.i_data;
+		len = i802r.i_len;
+		while (len >= sizeof(struct ieee80211req_scan_result)) {
+			struct ieee80211req_scan_result *isr;
+			char		*id;
+			int		idlen;
+			char		ssid[IEEE80211_NWID_LEN+1];
+
+			isr = (struct ieee80211req_scan_result *) vsr;
+
+			if (isr->isr_meshid_len) {
+				id = vsr + isr->isr_ie_off + isr->isr_ssid_len;
+				idlen = isr->isr_meshid_len;
+			}
+			else {
+				id = vsr + isr->isr_ie_off;
+				idlen = isr->isr_ssid_len;
+			}
+			strncpy(ssid, id, idlen);
+			ssid[idlen] = '\0';
+			apd.ssid = base::UTF8ToUTF16(ssid);
+			apd.mac_address = MacAddressAsString16(isr->isr_bssid);
+			apd.radio_signal_strength = (isr->isr_rssi/2) + isr->isr_noise;
+			apd.signal_to_noise = apd.radio_signal_strength - isr->isr_noise;
+			apd.channel = frquency_to_channel(isr->isr_freq);
+			VLOG(1) << "FreeBSD access point: "
+				<< "SSID: " << apd.ssid << ", "
+				<< "MAC: " << apd.mac_address << ", "
+				<< "Strength: " << apd.radio_signal_strength << ":"
+					        << apd.signal_to_noise << ", "
+				<< "Channel: " << apd.channel;
+			data->insert(apd);
+			res = true;
+			len -= isr->isr_len;
+			vsr += isr->isr_len;
+		}
+        }
+
+	freeifaddrs(ifal);
+
+	return res;
+}
+
+}  // namespace
+
+// static
+WifiDataProviderImplBase* WifiDataProvider::DefaultFactoryFunction() {
+	return new FreeBSDWifiDataProvider();
+}
+
+FreeBSDWifiDataProvider::FreeBSDWifiDataProvider() {
+}
+
+FreeBSDWifiDataProvider::~FreeBSDWifiDataProvider() {
+}
+
+WifiDataProviderCommon::WlanApiInterface* FreeBSDWifiDataProvider::NewWlanApi() {
+
+	scoped_ptr<FreeBSDAccessPointData> wlan_api(new FreeBSDAccessPointData);
+	if (wlan_api->Init())
+		return wlan_api.release();
+
+	return NULL;
+}
+
+WifiPollingPolicy* FreeBSDWifiDataProvider::NewPollingPolicy() {
+	return new GenericWifiPollingPolicy<kDefaultPollingInterval,
+	    kNoChangePollingInterval,
+	    kTwoNoChangePollingInterval,
+	    kNoWifiPollingIntervalMilliseconds>;
+}
+
+} // namespace content
