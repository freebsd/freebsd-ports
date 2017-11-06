- Make libnet_get_hwaddr() work with 802.1q interfaces in bpf (BSD).

Obtained from:	https://github.com/sam-github/libnet/commit/408fa2266a4af402152cc0f1e9a40b56477b995a

--- src/libnet_link_bpf.c.orig	2012-03-19 16:59:50 UTC
+++ src/libnet_link_bpf.c
@@ -316,7 +316,11 @@ libnet_get_hwaddr(libnet_t *l)
         if (ifm->ifm_type == RTM_IFINFO)
         {
             sdl = (struct sockaddr_dl *)(ifm + 1);
-            if (sdl->sdl_type != IFT_ETHER)
+            if (sdl->sdl_type != IFT_ETHER
+                && sdl->sdl_type != IFT_FASTETHER
+                && sdl->sdl_type != IFT_FASTETHERFX
+                && sdl->sdl_type != IFT_GIGABITETHERNET
+                && sdl->sdl_type != IFT_L2VLAN)
                 continue;
             if (strncmp(&sdl->sdl_data[0], l->device, sdl->sdl_nlen) == 0)
             {
@@ -326,6 +330,12 @@ libnet_get_hwaddr(libnet_t *l)
         }
     }
     free(buf);
+    if (next == end) {
+        snprintf(l->err_buf, LIBNET_ERRBUF_SIZE,
+                 "%s(): interface %s of known type not found.",
+                 __func__, l->device);
+        return NULL;
+    }
     return (&ea);
 }
 
