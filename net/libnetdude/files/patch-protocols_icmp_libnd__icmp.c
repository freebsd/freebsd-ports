
$FreeBSD$

--- protocols/icmp/libnd_icmp.c.orig	Sun Aug 22 16:12:53 2004
+++ protocols/icmp/libnd_icmp.c	Sun Aug 22 16:13:04 2004
@@ -266,7 +266,7 @@
 	return ((guchar *) icmphdr + 8 + icmphdr_adv->icmp_hun.ih_rtradv.irt_num_addrs * 8 <= libnd_packet_get_end(packet));
       }
 
-    default:
+    default: break;
     }
 
   return FALSE;
