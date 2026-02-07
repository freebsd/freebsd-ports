--- libtrueos/utils/netif.cpp.orig	2017-08-21 16:44:14 UTC
+++ libtrueos/utils/netif.cpp
@@ -146,11 +146,6 @@ QString NetworkInterface::mediaStatusAsString()
 
    switch (IFM_TYPE(ifm.ifm_active))
    {
-      case IFM_FDDI:
-      case IFM_TOKEN:
-         if (ifm.ifm_status & IFM_ACTIVE) status = "inserted";
-         else status = "no ring";
-         break;
       case IFM_IEEE80211:
          if (ifm.ifm_status & IFM_ACTIVE) status = "associated";
          else status = "no carrier";
