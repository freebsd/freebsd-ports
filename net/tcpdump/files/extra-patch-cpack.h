--- cpack.h.orig	Wed Dec 10 18:44:34 2003
+++ cpack.h	Tue Nov 25 04:08:43 2003
@@ -0,0 +1,53 @@
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
+#ifndef _CPACK_H
+#define _CPACK_H
+
+struct cpack_state {
+	u_int8_t					*c_buf;
+	u_int8_t					*c_next;
+	size_t						 c_len;
+	enum {CPACK_MODE_PACK, CPACK_MODE_UNPACK}	 c_mode;
+};
+
+int cpack_init_in(struct cpack_state *, u_int8_t *, size_t);
+int cpack_init_out(struct cpack_state *, size_t, size_t);
+
+int cpack_uint8(struct cpack_state *, u_int8_t *);
+int cpack_uint16(struct cpack_state *, u_int16_t *);
+int cpack_uint32(struct cpack_state *, u_int32_t *);
+int cpack_uint64(struct cpack_state *, u_int64_t *);
+
+#define cpack_int8(s, i)	cpack_uint8((s),  (u_int8_t*)(i))
+#define cpack_int16(s, i)	cpack_uint16((s), (u_int16_t*)(i))
+#define cpack_int32(s, i)	cpack_uint32((s), (u_int32_t*)(i))
+#define cpack_int64(s, i)	cpack_uint64((s), (u_int64_t*)(i))
+
+#endif /* _CPACK_H */
