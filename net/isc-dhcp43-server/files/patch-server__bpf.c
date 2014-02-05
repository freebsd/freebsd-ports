--- common/bpf.c.orig	2010-10-22 10:38:06.623559939 +0400
+++ common/bpf.c	2010-10-22 10:38:26.436563986 +0400
@@ -577,6 +577,7 @@
 	 */
         switch (sa->sdl_type) {
                 case IFT_ETHER:
+                case IFT_L2VLAN:
                         hw->hlen = sa->sdl_alen + 1;
                         hw->hbuf[0] = HTYPE_ETHER;
                         memcpy(&hw->hbuf[1], LLADDR(sa), sa->sdl_alen);
