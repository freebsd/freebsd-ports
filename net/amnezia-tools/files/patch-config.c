--- config.c.orig	2024-10-01 13:02:42 UTC
+++ config.c
@@ -337,6 +337,20 @@ static bool validate_netmask(struct wgallowedip *allow
 	return true;
 }
 
+static inline void parse_ip_prefix(struct wgpeer *peer, uint32_t *flags, char **mask)
+{
+	/* If the IP is prefixed with either '+' or '-' consider this an
+	 * incremental change. Disable WGPEER_REPLACE_ALLOWEDIPS. */
+	switch ((*mask)[0]) {
+	case '-':
+		*flags |= WGALLOWEDIP_REMOVE_ME;
+		/* fall through */
+	case '+':
+		peer->flags &= ~WGPEER_REPLACE_ALLOWEDIPS;
+		++(*mask);
+	}
+}
+
 static inline bool parse_allowedips(struct wgpeer *peer, struct wgallowedip **last_allowedip, const char *value)
 {
 	struct wgallowedip *allowedip = *last_allowedip, *new_allowedip;
@@ -353,10 +367,18 @@ static inline bool parse_allowedips(struct wgpeer *pee
 	}
 	sep = mutable;
 	while ((mask = strsep(&sep, ","))) {
+		uint32_t flags = 0;
 		unsigned long cidr;
 		char *end, *ip;
 
+		parse_ip_prefix(peer, &flags, &mask);
+
 		saved_entry = strdup(mask);
+		if (!saved_entry) {
+			perror("strdup");
+			free(mutable);
+			return false;
+		}
 		ip = strsep(&mask, "/");
 
 		new_allowedip = calloc(1, sizeof(*new_allowedip));
@@ -387,6 +409,7 @@ static inline bool parse_allowedips(struct wgpeer *pee
 		else
 			goto err;
 		new_allowedip->cidr = cidr;
+		new_allowedip->flags = flags;
 
 		if (!validate_netmask(new_allowedip))
 			fprintf(stderr, "Warning: AllowedIP has nonzero host part: %s/%s\n", ip, mask);
