--- mDNSCore/mDNS.c.orig	2010-11-18 09:05:40.000000000 +0800
+++ mDNSCore/mDNS.c	2011-01-11 11:51:28.000000000 +0800
@@ -4021,7 +4021,7 @@
 		}
 	
 	// Call the platform code to enable/disable sleep
-	mDNSPlatformSetAllowSleep(m, allowSleep);
+	//mDNSPlatformSetAllowSleep(m, allowSleep);
 	}
 
 mDNSlocal void SendSPSRegistration(mDNS *const m, NetworkInterfaceInfo *intf, const mDNSOpaque16 id)
