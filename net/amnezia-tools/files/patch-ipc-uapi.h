--- ipc-uapi.h.orig	2024-10-01 13:02:42 UTC
+++ ipc-uapi.h
@@ -111,7 +111,7 @@ static int userspace_set_device(struct wgdevice *dev)
 					continue;
 			} else
 				continue;
-			fprintf(f, "allowed_ip=%s/%d\n", ip, allowedip->cidr);
+			fprintf(f, "allowed_ip=%s%s/%d\n", (allowedip->flags & WGALLOWEDIP_REMOVE_ME) ? "-" : "", ip, allowedip->cidr);
 		}
 	}
 	fprintf(f, "\n");
