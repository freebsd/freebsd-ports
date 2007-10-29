Index: libdesktopbsd/wirelessinterface.h
===================================================================
--- libdesktopbsd/wirelessinterface.h	(Revision 454)
+++ libdesktopbsd/wirelessinterface.h	(Revision 920)
@@ -1,7 +1,7 @@
 /*
  * This file is part of DesktopBSD, see the README file.
  *
- * Author: Peter Hofer <hofer.p@gmail.com>
+ * Author: Peter Hofer <ph@desktopbsd.net>
  *         (C) 2004, 2005
  *
  * Copyright: BSD, see the COPYING file included in this distribution
@@ -47,9 +47,10 @@
 	static  QPtrList<WirelessInterface>  getWirelessIfs();
 
 private:
-	int  wiGetVal(struct  wi_req *)  const;
 	int  set80211(int,  int,  int,  uint8_t *)  const;
 	struct ieee80211req  *getIReq(int,  uint8_t **)  const;
+	struct ieee80211req  *getIReq(int, uint8_t **, size_t, int16_t) const;
+	QString copySSID(const uint8_t *, const size_t) const;
 
 	int     hexToNumber(char)  const;
 };
