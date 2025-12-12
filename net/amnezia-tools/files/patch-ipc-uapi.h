--- ipc-uapi.h.orig	2025-09-03 14:11:13 UTC
+++ ipc-uapi.h
@@ -126,7 +126,7 @@ static int userspace_set_device(struct wgdevice *dev)
 					continue;
 			} else
 				continue;
-			fprintf(f, "allowed_ip=%s/%d\n", ip, allowedip->cidr);
+			fprintf(f, "allowed_ip=%s%s/%d\n", (allowedip->flags & WGALLOWEDIP_REMOVE_ME) ? "-" : "", ip, allowedip->cidr);
 		}
 	}
 	fprintf(f, "\n");
