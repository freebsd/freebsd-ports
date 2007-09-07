Index: libdesktopbsd/wirelessinterface.cpp
===================================================================
--- libdesktopbsd/wirelessinterface.cpp	(Revision 454)
+++ libdesktopbsd/wirelessinterface.cpp	(Revision 920)
@@ -1,13 +1,79 @@
 /*
  * This file is part of DesktopBSD, see the README file.
  *
- * Author: Peter Hofer <hofer.p@gmail.com>
- *			(C) 2004, 2005
+ * Author: Peter Hofer <ph@desktopbsd.net>
+ *			(C) 2004-2007
  *
  * Copyright: BSD, see the COPYING file included in this distribution
  *
  */
 
+/*
+ * Copyright 2001 The Aerospace Corporation.  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. The name of The Aerospace Corporation may not be used to endorse or
+ *    promote products derived from this software.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE AEROSPACE CORPORATION ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE AEROSPACE CORPORATION BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ *
+ * $FreeBSD: /tmp/pcvs/ports/sysutils/desktopbsd-tools/files/Attic/patch-libdesktopbsd_wirelessinterface.cpp,v 1.1 2007-09-07 20:02:13 lme Exp $
+ */
+
+/*-
+ * Copyright (c) 1997, 1998, 2000 The NetBSD Foundation, Inc.
+ * All rights reserved.
+ *
+ * This code is derived from software contributed to The NetBSD Foundation
+ * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,
+ * NASA Ames Research Center.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. All advertising materials mentioning features or use of this software
+ *    must display the following acknowledgement:
+ *	This product includes software developed by the NetBSD
+ *	Foundation, Inc. and its contributors.
+ * 4. Neither the name of The NetBSD Foundation nor the names of its
+ *    contributors may be used to endorse or promote products derived
+ *    from this software without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
+ * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
+ * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
+ * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
+ * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
+ * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
+ * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
+ * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
+ * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
+ * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
+ * POSSIBILITY OF SUCH DAMAGE.
+ */
+
 #include "wirelessinterface.h"
 
 #include <net/ethernet.h>
@@ -182,66 +248,40 @@
   *
   * @return QPtrList with the found access points.
   */
-QPtrList<AccessPoint>  WirelessInterface::getAPs()  {
-	/* Status must be UP to be able to scan for ap's. */
+QPtrList<AccessPoint>  WirelessInterface::getAPs()
+{
+	QPtrList<AccessPoint> list;
+	
+	/* Some WiFi NICs need to be in link state UP to scan for networks */
+	up();
 
-	if(up() < 0  && !isUp())
-		/* up() failed and interface seems to be down,
-		* so a scan would return nothing anyway.
-		*/
-		return  QPtrList<AccessPoint>();
+	uint8_t buffer[24 * 1024];
+	struct ieee80211req *ireq = getIReq(IEEE80211_IOC_SCAN_RESULTS, (uint8_t **) buffer, sizeof buffer, 0);
+	if(ireq == NULL)
+		return list;
 
-	QPtrList<AccessPoint>  list;
+	int length = ireq->i_len;
+	if (length < sizeof(struct ieee80211req_scan_result))
+	{
+		delete ireq;
+		return list;
+	}
 
-	struct  wi_req  wreq;
-	bzero(&wreq, sizeof(wreq));
-	wreq.wi_len = WI_MAX_DATALEN;
-	wreq.wi_type = WI_RID_READ_APS;
+	uint8_t *current = buffer;
+	do
+	{
+		struct ieee80211req_scan_result *sr = (struct ieee80211req_scan_result *) current;
+		list.append(new AccessPoint(*sr, copySSID((u_int8_t *) (sr + 1), (size_t) sr->isr_ssid_len)));
 
-	if(wiGetVal(&wreq) < 0)
-		return  list;
-
-	struct  wi_apinfo  *apinfos;
-	apinfos = (struct  wi_apinfo *) (((char *) &wreq.wi_val) + sizeof(int));
-
-	int  cnt = * (int *) wreq.wi_val;
-	for(int i = cnt - 1;  i >= 0;  --i) {
-		bool  exists = false;
-		for(int  n = cnt - 1;  n > i  &&  !exists  ;  --n) {
-			exists |= (bcmp(apinfos[n].bssid,
-							apinfos[i].bssid,
-							sizeof(apinfos[0].bssid)) == 0);
-		}
-
-		if(!exists)
-			list.append(new  AccessPoint(apinfos[i]));
+		current += sr->isr_len;
+		length -= sr->isr_len;
 	}
-
-	return  list;
+	while (length >= sizeof(struct ieee80211req_scan_result));
+	
+	delete ireq;
+	return list;
 }
 
-int  WirelessInterface::wiGetVal(struct  wi_req  *wreq)  const {
-	if(wreq == NULL)
-		return  -1;
-
-	struct ifreq ifr;
-	int  s, ret;
-
-	bzero(&ifr, sizeof(ifr));
-
-	strlcpy(ifr.ifr_name, getName(), sizeof(ifr.ifr_name));
-	ifr.ifr_data = (caddr_t) wreq;
-
-	s = socket(AF_INET, SOCK_DGRAM, 0);
-	if(s == -1)
-		return  -1;
-
-	ret = ioctl(s, SIOCGWAVELAN, &ifr);
-	close(s);
-
-	return  ret;
-}
-
 /** Returns a list with all wireless network interfaces. */
 QPtrList<WirelessInterface>  WirelessInterface::getWirelessIfs() {
 	QPtrList<WirelessInterface>  lst;
@@ -285,9 +325,16 @@
 }
 
 
+/** @param data pointer to a pointer to a uint8_t array with minimum size 32 */
+struct ieee80211req  *WirelessInterface::getIReq(int  type,  uint8_t  **data)  const
+{
+	return getIReq(type, data, 0, -1);
+}
 
+
 /** @param data pointer to a pointer to a uint8_t array with minimum size 32 */
-struct ieee80211req  *WirelessInterface::getIReq(int  type,  uint8_t  **data)  const {
+struct ieee80211req  *WirelessInterface::getIReq(int type, uint8_t **data, size_t len, int16_t val)  const
+{
 	int  s = newSocket();
 	if(s < 0)
 		return  NULL;
@@ -297,7 +344,8 @@
 	strlcpy(ireq->i_name,  getName(),  sizeof ireq->i_name);
 	ireq->i_data = data;
 	ireq->i_type = type;
-	ireq->i_val = -1;
+	ireq->i_len = len;
+	ireq->i_val = val;
 
 	if(ioctl(s, SIOCG80211, ireq) < 0) {
 		close(s);
@@ -309,3 +357,53 @@
 	return  ireq;
 }
 
+
+QString WirelessInterface::copySSID(const u_int8_t *essid, const size_t essid_len) const
+{
+	char buf[IEEE80211_NWID_LEN + 1];
+	int bufsize = sizeof(buf) - 1;
+	bzero(buf, sizeof(buf));
+	
+	const u_int8_t *p; 
+	size_t maxlen;
+	int i;
+
+	if (essid_len > bufsize)
+		maxlen = bufsize;
+	else
+		maxlen = essid_len;
+	/* determine printable or not */
+	for (i = 0, p = essid; i < maxlen; i++, p++) {
+		if (*p < ' ' || *p > 0x7e)
+			break;
+	}
+	if (i != maxlen) {		/* not printable, print as hex */
+		
+		/* Check for hidden SSIDs (filled with zeroes) */
+		for(i = 0; i < maxlen; ++i)
+		{
+			if(*p != 0)
+				break;
+		}
+		if(i == maxlen)
+			return QString();
+		
+		if (bufsize < 3)
+			return "INVALID";
+		strlcpy(buf, "0x", bufsize);
+		bufsize -= 2;
+		p = essid;
+		for (i = 0; i < maxlen && bufsize >= 2; i++) {
+			sprintf(&buf[2+2*i], "%02x", p[i]);
+			bufsize -= 2;
+		}
+		if (i != essid_len)
+			memcpy(&buf[2+2*i-3], "...", 3);
+	} else {			/* printable, truncate as needed */
+		memcpy(buf, essid, maxlen);
+		if (maxlen != essid_len)
+			memcpy(&buf[maxlen-3], "...", 3);
+	}
+	
+	return QString(buf);
+}
