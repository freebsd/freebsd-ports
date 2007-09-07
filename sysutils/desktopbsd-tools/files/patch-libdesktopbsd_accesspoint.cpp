Index: libdesktopbsd/accesspoint.cpp
===================================================================
--- libdesktopbsd/accesspoint.cpp	(Revision 454)
+++ libdesktopbsd/accesspoint.cpp	(Revision 920)
@@ -1,47 +1,108 @@
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
+ 
+ /*
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
+ * $FreeBSD: /tmp/pcvs/ports/sysutils/desktopbsd-tools/files/Attic/patch-libdesktopbsd_accesspoint.cpp,v 1.1 2007-09-07 20:02:13 lme Exp $
+ */
 
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
 #include "accesspoint.h"
 
-#include <qstring.h>
 
 /** Initializes the access point with a wi_apinfo struct.
   * This creates a deep copy of the given struct so you
   * can safely delete it's wi_req struct afterwards.
   */
-AccessPoint::AccessPoint(const  struct  wi_apinfo&  apinfo) {
+AccessPoint::AccessPoint(const struct ieee80211req_scan_result&  apinfo, const QString & ssid) {
 	this->apinfo = apinfo;
+	this->ssid = ssid;
 }
 
 
 
 /** @return The station's SSID. */
 QString  AccessPoint::getSSID()  const {
-	return  QString::fromAscii(apinfo.name,  apinfo.namelen);
+	return ssid;
 }
 
 
 
 /** @returns The station's MAC address. */
 QString  AccessPoint::getBSSID()  const {
-	char  bssid[18];
-
-	snprintf(bssid,  sizeof(bssid),  "%02X:%02X:%02X:%02X:%02X:%02X",
-				apinfo.bssid[0] & 0xFF,
-				apinfo.bssid[1] & 0xFF,
-				apinfo.bssid[2] & 0xFF,
-				apinfo.bssid[3] & 0xFF,
-				apinfo.bssid[4] & 0xFF,
-				apinfo.bssid[5] & 0xFF);
-
-	return  bssid;
+	char *str = ether_ntoa((const struct ether_addr *) apinfo.isr_bssid);
+	
+	if(str == NULL)
+		return "INVALID";
+	
+	return QString(str).upper();
 }
 
 
@@ -50,10 +111,10 @@
 int  AccessPoint::getCapInfo()  const {
 	int  capinfo = None;
 
-	if(apinfo.capinfo & IEEE80211_CAPINFO_ESS)
+	if(apinfo.isr_capinfo & IEEE80211_CAPINFO_ESS)
 		capinfo |= ESS;
 
-	if(apinfo.capinfo & IEEE80211_CAPINFO_PRIVACY)
+	if(apinfo.isr_capinfo & IEEE80211_CAPINFO_PRIVACY)
 		capinfo |= WEP;
 
 	return  capinfo;
@@ -65,29 +126,14 @@
   *			is not 1, 2, 5.5 or 11 Mbps.
   */
 double  AccessPoint::getRate()  const {
-	double  rate;
-
-	switch(apinfo.rate) {
-		case WI_APRATE_1:
-		rate = 1;
-		break;
-
-		case WI_APRATE_2:
-		rate = 2;
-		break;
-
-		case WI_APRATE_5:
-		rate = 5.5;
-		break;
-
-		case WI_APRATE_11:
-		rate = 11;
-		break;
-
-		default:
-		rate = 0;
-		break;
+	int maxrate = -1;
+	
+	for (int i = 0; i < apinfo.isr_nrates; i++)
+	{
+		int rate = apinfo.isr_rates[i] & IEEE80211_RATE_VAL;
+		if (rate > maxrate)
+			maxrate = rate;
 	}
-
-	return  rate;
+	
+	return (double) maxrate / 2;
 }
