--- ofproto/ofproto-dpif.c.orig	2017-11-29 15:48:58 UTC
+++ ofproto/ofproto-dpif.c
@@ -73,6 +73,8 @@
 #include "util.h"
 #include "vlan-bitmap.h"
 
+#define	ERRNO_NO_LOCAL_MAPPING	-600
+
 VLOG_DEFINE_THIS_MODULE(ofproto_dpif);
 
 COVERAGE_DEFINE(ofproto_dpif_expired);
@@ -5695,7 +5697,11 @@ meter_set(struct ofproto *ofproto_, ofpr
         return OFPERR_OFPMMFC_OUT_OF_BANDS;
     case ENODEV: /* Unsupported band type */
         return OFPERR_OFPMMFC_BAD_BAND;
+#ifdef EBADRQC
     case EBADRQC: /* Rate must be non-zero */
+#else
+    case ERRNO_NO_LOCAL_MAPPING:
+#endif
         return OFPERR_OFPMMFC_BAD_RATE;
     default:
         return OFPERR_OFPMMFC_UNKNOWN;
