--- src/common/slurm_sockaddr.c.orig	2026-01-29 00:01:06 UTC
+++ src/common/slurm_sockaddr.c
@@ -0,0 +1,89 @@
+#include "config.h"
+
+#include "src/common/slurm_sockaddr.h"
+
+#include <stddef.h>
+#include <stdint.h>
+#include <string.h>
+#include <sys/un.h>
+#include <netinet/in.h>
+
+/* Safe pathname length for AF_UNIX (avoids overruns). */
+static socklen_t _unix_sock_len(const struct sockaddr_un *un, socklen_t provided)
+{
+	/* Linux abstract namespace: sun_path[0] == '\0' => length is provided. */
+	if (provided >= (socklen_t)offsetof(struct sockaddr_un, sun_path) &&
+	    un->sun_path[0] == '\0') {
+			return provided;
+	}
+
+	size_t maxn = sizeof(un->sun_path);
+	size_t n = strnlen(un->sun_path, maxn);
+
+	/* include terminating NUL like classic pathname sockets */
+	socklen_t len = (socklen_t)(offsetof(struct sockaddr_un, sun_path) + n);
+	return len;
+}
+
+socklen_t slurm_sockaddr_fixlen(struct sockaddr *sa, socklen_t provided_len)
+{
+	if (!sa)
+	    return provided_len;
+
+	switch (sa->sa_family) {
+	case AF_INET: {
+		socklen_t len = (socklen_t)sizeof(struct sockaddr_in);
+#if defined(HAVE_STRUCT_SOCKADDR_IN_SIN_LEN)
+		((struct sockaddr_in *)sa)->sin_len = (uint8_t)len;
+#elif defined(HAVE_STRUCT_SOCKADDR_SA_LEN)
+		sa->sa_len = (uint8_t)len;
+#endif
+		return len;
+	}
+	case AF_INET6: {
+		socklen_t len = (socklen_t)sizeof(struct sockaddr_in6);
+#if defined(HAVE_STRUCT_SOCKADDR_IN6_SIN6_LEN)
+		((struct sockaddr_in6 *)sa)->sin6_len = (uint8_t)len;
+#elif defined(HAVE_STRUCT_SOCKADDR_SA_LEN)
+		sa->sa_len = (uint8_t)len;
+#endif
+		return len;
+	}
+	case AF_UNIX: {
+		struct sockaddr_un *un = (struct sockaddr_un *)sa;
+		socklen_t len = _unix_sock_len(un, provided_len);
+#if defined(HAVE_STRUCT_SOCKADDR_UN_SUN_LEN)
+		un->sun_len = (uint8_t)len;
+#elif defined(HAVE_STRUCT_SOCKADDR_SA_LEN)
+		sa->sa_len = (uint8_t)len;
+#endif
+		return len;
+	}
+	default:
+#if defined(HAVE_STRUCT_SOCKADDR_SA_LEN)
+		/* best effort: if caller provided a meaningful length, reflect it */
+		if (provided_len <= 255)
+		    sa->sa_len = (uint8_t)provided_len;
+#endif
+		return provided_len;
+	}
+}
+
+int slurm_sockaddr_copy_fix(struct sockaddr_storage *dst,
+			    const struct sockaddr *src,
+			    socklen_t src_len,
+			    socklen_t *out_len)
+{
+	if (!dst || !src || !out_len)
+	    return -1;
+
+	socklen_t n = src_len;
+	if (n > (socklen_t)sizeof(*dst))
+	    n = (socklen_t)sizeof(*dst);
+
+	memset(dst, 0, sizeof(*dst));
+	memcpy(dst, src, n);
+
+	*out_len = slurm_sockaddr_fixlen((struct sockaddr *)dst, n);
+	return 0;
+}
