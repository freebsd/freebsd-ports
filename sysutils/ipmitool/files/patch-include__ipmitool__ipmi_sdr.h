--- ./include/ipmitool/ipmi_sdr.h.orig	2009-02-25 15:38:52.000000000 -0500
+++ ./include/ipmitool/ipmi_sdr.h	2010-07-23 14:46:07.000000000 -0400
@@ -277,7 +277,7 @@
 					uint16_t settable:8;
 #endif
 				} read;
-			};
+			} type;
 		} threshold;
 	} type;
 } __attribute__ ((packed));
