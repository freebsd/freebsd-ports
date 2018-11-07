--- src/if_media.c.orig	2004-09-27 13:08:59 UTC
+++ src/if_media.c
@@ -95,8 +95,13 @@ int get_if_speed (char *ifstring)
      *
      */
 
+#if __FreeBSD__ >= 2 
+    type = IFM_TYPE(ifmr.ifm_active);
+    physical = IFM_SUBTYPE(ifmr.ifm_active);
+#else
     type = ifmr.ifm_active & 0xf0;
     physical = ifmr.ifm_active & 0x0f;
+#endif
 
 #ifdef MEDIADEBUG
     printf("      all: %6d\n", ifmr.ifm_current);
@@ -160,22 +165,6 @@ int get_if_speed (char *ifstring)
                     break;
             } /* end switch physical */
             break;
-        /* FDDI interfaces */
-        /* fpa doesn't seem to support SIOCGIFMEDIA on FreeBSD
-         * so we won't get here but anyway ...
-         */
-        case IFM_FDDI:
-            switch (physical)
-            {
-                case IFM_FDDI_SMF:
-                case IFM_FDDI_MMF:
-                case IFM_FDDI_UTP:
-                    speed = 100 * 1000;
-                    break;
-                default:
-                    speed = ERR_IFACE_NO_SPEED;
-            }
-            break;
 #if WIRELESS
         /* IEEE 802.11 wireless interfaces */
         case IFM_IEEE80211:
