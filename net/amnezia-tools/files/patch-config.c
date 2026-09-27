--- config.c.orig	2026-08-12 22:24:49 UTC
+++ config.c
@@ -260,7 +260,7 @@ static inline bool parse_endpoint(struct sockaddr *end
 		 *
 		 * So this is what we do, except FreeBSD removed EAI_NODATA some time ago, so that's conditional.
 		 */
-		if (ret == EAI_NONAME || ret == EAI_FAIL ||
+		if (ret == EAI_FAIL ||
 			#ifdef EAI_NODATA
 				ret == EAI_NODATA ||
 			#endif
@@ -319,6 +319,23 @@ static bool validate_netmask(struct wgallowedip *allow
 	return true;
 }
 
+#ifdef __FreeBSD__
+static inline void parse_ip_prefix(struct wgpeer *peer, uint32_t *flags, char **mask)
+{
+	/* FreeBSD supports incremental AllowedIP changes. A leading '-' removes
+	 * the prefix, while '+' adds it without replacing the peer's other
+	 * AllowedIPs. */
+	switch ((*mask)[0]) {
+	case '-':
+		*flags |= WGALLOWEDIP_REMOVE_ME;
+		/* fall through */
+	case '+':
+		peer->flags &= ~WGPEER_REPLACE_ALLOWEDIPS;
+		++(*mask);
+	}
+}
+#endif
+
 static inline bool parse_allowedips(struct wgpeer *peer, struct wgallowedip **last_allowedip, const char *value)
 {
 	struct wgallowedip *allowedip = *last_allowedip, *new_allowedip;
@@ -335,10 +352,19 @@ static inline bool parse_allowedips(struct wgpeer *pee
 	}
 	sep = mutable;
 	while ((mask = strsep(&sep, ","))) {
+		uint32_t flags = 0;
 		unsigned long cidr;
 		char *end, *ip;
 
+#ifdef __FreeBSD__
+		parse_ip_prefix(peer, &flags, &mask);
+#endif
 		saved_entry = strdup(mask);
+		if (!saved_entry) {
+			perror("strdup");
+			free(mutable);
+			return false;
+		}
 		ip = strsep(&mask, "/");
 
 		new_allowedip = calloc(1, sizeof(*new_allowedip));
@@ -369,6 +395,7 @@ static inline bool parse_allowedips(struct wgpeer *pee
 		else
 			goto err;
 		new_allowedip->cidr = cidr;
+		new_allowedip->flags = flags;
 
 		if (!validate_netmask(new_allowedip))
 			fprintf(stderr, "Warning: AllowedIP has nonzero host part: %s/%s\n", ip, mask);
