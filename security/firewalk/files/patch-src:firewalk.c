--- src/firewalk.c.orig	Mon Aug 16 13:13:44 2004
+++ src/firewalk.c	Mon Aug 16 13:13:56 2004
@@ -188,8 +188,6 @@
                     case FW_SERIOUS_ERROR:
                         /* err msg set in fw_packet_capture() */
                         return (FW_SERIOUS_ERROR);
-                    default:
-                        /* empty */
                 }
             }
         }
