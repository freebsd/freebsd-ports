--- tiger.c.orig	Tue May  8 06:31:30 2007
+++ tiger.c	Tue May  8 08:07:57 2007
@@ -646,12 +646,16 @@
 	TIGER_COMPRESS_MACRO(((const uint64_t *) str), ((uint64_t *) state));
 }
 
+static uint64_t init_state[3] = {
+	0x0123456789ABCDEFLL, 0xFEDCBA9876543210LL, 0xF096A5B4C3B2E187LL
+};
+
 void
 TIGERInit(tiger_context_t *tp)
 {
-	tp->ctx[0] = 0x0123456789ABCDEFLL;
-	tp->ctx[1] = 0xFEDCBA9876543210LL;
-	tp->ctx[2] = 0xF096A5B4C3B2E187LL;
+	tp->ctx[0] = init_state[0];
+	tp->ctx[1] = init_state[1];
+	tp->ctx[2] = init_state[2];
 }
 
 void
@@ -708,10 +712,27 @@
 	tiger_compress(((uint64_t *) temp), tp->ctx);
 }
 
+#define PUT_64BIT_BE(cp, value) do {					\
+	(cp)[0] = (value) >> 56;					\
+	(cp)[1] = (value) >> 48;					\
+	(cp)[2] = (value) >> 40;					\
+	(cp)[3] = (value) >> 32;					\
+	(cp)[4] = (value) >> 24;					\
+	(cp)[5] = (value) >> 16;					\
+	(cp)[6] = (value) >> 8;						\
+	(cp)[7] = (value); } while (0)
+
 void
 TIGERFinal(uint8_t *digest, tiger_context_t *tp)
 {
-	/* nothing to do - included for compatibility with SHA* interface */
+	int i;
+
+	if (tp->ctx[0] == init_state[0] && tp->ctx[1] == init_state[1] &&
+			tp->ctx[2] == init_state[2])
+		TIGERUpdate(tp, "", 0);
+
+	for (i = 0; i < 3; i++)
+		PUT_64BIT_BE(digest + i * 8, tp->ctx[i]);
 }
 
 static void
@@ -734,6 +755,9 @@
 	if (buf == NULL && (buf = malloc(41)) == NULL) {
 		return NULL;
 	}
+	if (tp->ctx[0] == init_state[0] && tp->ctx[1] == init_state[1] &&
+			tp->ctx[2] == init_state[2])
+		TIGERUpdate(tp, "", 0);
 
 	for (i = 0; i < 3; ++i)
 		print_uint64(buf + i * 16, tp->ctx[i]);

