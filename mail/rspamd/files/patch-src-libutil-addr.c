diff --git a/src/libutil/addr.c b/src/libutil/addr.c
index 4af1dd6..62ef647 100644
--- src/libutil/addr.c
+++ src/libutil/addr.c
@@ -99,7 +99,7 @@ rspamd_parse_inet_address (rspamd_inet_addr_t *target, const char *src)
 		rspamd_strlcpy (target->addr.su.sun_path, src,
 				sizeof (target->addr.su.sun_path));
 #ifdef FREEBSD
-		target->addr.su.sun_len = SUN_LEN (addr);
+		target->addr.su.sun_len = SUN_LEN (&target->addr.su);
 #endif
 	}
 	else if (inet_pton (AF_INET6, src, &target->addr.s6.sin6_addr) == 1) {
