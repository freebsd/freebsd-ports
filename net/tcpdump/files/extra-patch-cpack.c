--- cpack.c.orig	Wed Dec 10 18:44:31 2003
+++ cpack.c	Thu Aug 14 01:25:27 2003
@@ -0,0 +1,181 @@
+/*-
+ * Copyright (c) 2003, 2004 David Young.  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. The name of David Young may not be used to endorse or promote
+ *    products derived from this software without specific prior
+ *    written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY DAVID YOUNG ``AS IS'' AND ANY
+ * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
+ * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
+ * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL DAVID
+ * YOUNG BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
+ * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
+ * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
+ * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
+ * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
+ * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
+ * OF SUCH DAMAGE.
+ */
+
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
+#include <stdlib.h>
+#include <tcpdump-stdinc.h>
+
+#include "cpack.h"
+
+static u_char *
+cpack_next_boundary(u_char *p, size_t alignment)
+{
+	size_t misalignment = (u_int)p % alignment;
+
+	if (misalignment == 0)
+		return p;
+
+	return p + (alignment - misalignment);
+}
+
+/* Advance to the next wordsize boundary. Return NULL if fewer than
+ * wordsize bytes remain in the buffer after the boundary.  Otherwise,
+ * return a pointer to the boundary.
+ */
+static u_char *
+cpack_align_and_reserve(struct cpack_state *cs, size_t wordsize)
+{
+	u_char *next;
+
+	/* Ensure alignment. */
+	next = cpack_next_boundary(cs->c_next, wordsize);
+
+	/* Too little space for wordsize bytes? */
+	if (next - cs->c_buf + wordsize > cs->c_len)
+		return NULL;
+
+	return next;
+}
+
+int
+cpack_init_in(struct cpack_state *cs, u_int8_t *buf, size_t buflen)
+{
+	memset(cs, 0, sizeof(*cs));
+	cs->c_mode = CPACK_MODE_UNPACK;
+	cs->c_buf = buf;
+	cs->c_len = buflen;
+	cs->c_next = cs->c_buf;
+
+	return 0;
+}
+
+int
+cpack_init_out(struct cpack_state *cs, size_t buflen, size_t max_alignment)
+{
+	u_int8_t *buf;
+	size_t len;
+
+	memset(cs, 0, sizeof(*cs));
+	cs->c_mode = CPACK_MODE_PACK;
+	len = buflen + max_alignment - 1;
+
+	if ((cs->c_buf = malloc(len)) == NULL)
+		return -1;
+
+	/* Correct alignment. */
+	buf = cpack_next_boundary(cs->c_buf, max_alignment);
+	cs->c_len = len - (buf - cs->c_buf);
+	cs->c_buf = buf;
+	cs->c_next = cs->c_buf;
+
+	return 0;
+}
+
+/* (Un)pack a 64-bit unsigned integer. */
+int
+cpack_uint64(struct cpack_state *cs, u_int64_t *u)
+{
+	u_char *next;
+
+	if ((next = cpack_align_and_reserve(cs, sizeof(*u))) == NULL)
+		return -1;
+
+	/* (Un)pack depending on mode. */
+	if (cs->c_mode == CPACK_MODE_PACK)
+		*(u_int64_t*)next = *u;
+	else
+		*u = *(u_int64_t*)next;
+
+	/* Move pointer past the u_int64_t. */
+	cs->c_next = next + sizeof(*u);
+	return 0;
+}
+
+/* (Un)pack a 32-bit unsigned integer. */
+int
+cpack_uint32(struct cpack_state *cs, u_int32_t *u)
+{
+	u_char *next;
+
+	if ((next = cpack_align_and_reserve(cs, sizeof(*u))) == NULL)
+		return -1;
+
+	/* (Un)pack depending on mode. */
+	if (cs->c_mode == CPACK_MODE_PACK)
+		*(u_int32_t*)next = *u;
+	else
+		*u = *(u_int32_t*)next;
+
+	/* Move pointer past the u_int32_t. */
+	cs->c_next = next + sizeof(*u);
+	return 0;
+}
+
+/* (Un)pack a 16-bit unsigned integer. */
+int
+cpack_uint16(struct cpack_state *cs, u_int16_t *u)
+{
+	u_char *next;
+
+	if ((next = cpack_align_and_reserve(cs, sizeof(*u))) == NULL)
+		return -1;
+
+	/* (Un)pack depending on mode. */
+	if (cs->c_mode == CPACK_MODE_PACK)
+		*(u_int16_t*)next = *u;
+	else
+		*u = *(u_int16_t*)next;
+
+	/* Move pointer past the u_int16_t. */
+	cs->c_next = next + sizeof(*u);
+	return 0;
+}
+
+/* (Un)pack an 8-bit unsigned integer. */
+int
+cpack_uint8(struct cpack_state *cs, u_int8_t *u)
+{
+	/* No space left? */
+	if (cs->c_next - cs->c_buf >= cs->c_len)
+		return -1;
+
+	/* (Un)pack depending on mode. */
+	if (cs->c_mode == CPACK_MODE_PACK)
+		*cs->c_next = *u;
+	else
+		*u = *cs->c_next;
+
+	/* Move pointer past the u_int8_t. */
+	cs->c_next++;
+	return 0;
+}
+
