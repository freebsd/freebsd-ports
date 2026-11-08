--- ipc-uapi.h.orig	2026-08-12 22:24:49 UTC
+++ ipc-uapi.h
@@ -147,7 +147,7 @@ static int userspace_set_device(struct wgdevice *dev)
 					continue;
 			} else
 				continue;
-			fprintf(f, "allowed_ip=%s/%d\n", ip, allowedip->cidr);
+			fprintf(f, "allowed_ip=%s%s/%d\n", (allowedip->flags & WGALLOWEDIP_REMOVE_ME) ? "-" : "", ip, allowedip->cidr);
 		}
 	}
 	fprintf(f, "\n");
