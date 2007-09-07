Index: libdesktopbsd/accesspoint.h
===================================================================
--- libdesktopbsd/accesspoint.h	(Revision 454)
+++ libdesktopbsd/accesspoint.h	(Revision 920)
@@ -1,7 +1,7 @@
 /*
  * This file is part of DesktopBSD, see the README file.
  *
- * Author: Peter Hofer <hofer.p@gmail.com>
+ * Author: Peter Hofer <ph@desktopbsd.net>
  *         (C) 2004, 2005
  *
  * Copyright: BSD, see the COPYING file included in this distribution
@@ -27,7 +27,7 @@
 #include <dev/wi/if_wavelan_ieee.h>
 #include <dev/wi/if_wireg.h>
 
-class QString;
+#include <qstring.h>
 
 /** @brief Wireless Access-Point class.
   *
@@ -45,23 +45,24 @@
 	};
 
 
-   AccessPoint(const  struct  wi_apinfo&);
+   AccessPoint(const struct ieee80211req_scan_result &, const QString &);
 
 	QString	getSSID()  const;
 
    /** @return Signal quality [dBm] */
-   int  getQuality()	const  { return apinfo.quality;	}
+	int  getQuality()	const  { return apinfo.isr_rssi / apinfo.isr_noise;	}
    /** @return Signal.        */
-   int  getSignal()	const  { return apinfo.signal;	}
+	int  getSignal()	const  { return apinfo.isr_rssi;								}
    /** @return Signal noise   */
-   int  getNoise()	const  { return apinfo.noise;		}
+	int  getNoise()	const  { return apinfo.isr_noise;							}
 
    QString  getBSSID()    const;
    int      getCapInfo()  const;
    double   getRate()     const;
 
 private:
-   struct  wi_apinfo  apinfo;
+	QString ssid;
+	struct ieee80211req_scan_result apinfo;
 };
 
 #endif  /* __ACCESSPOINT_H */
