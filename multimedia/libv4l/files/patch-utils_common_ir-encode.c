--- utils/common/ir-encode.c.orig	2020-04-09 16:29:54 UTC
+++ utils/common/ir-encode.c
@@ -34,17 +34,18 @@ static int nec_encode(enum rc_proto proto, unsigned sc
 	const int nec_unit = 562500;
 	int n = 0;
 
-	void add_byte(unsigned bits)
-	{
-		int i;
-		for (i=0; i<8; i++) {
-			buf[n++] = NS_TO_US(nec_unit);
-			if (bits & (1 << i))
-				buf[n++] = NS_TO_US(nec_unit * 3);
-			else
-				buf[n++] = NS_TO_US(nec_unit);
-		}
-	}
+#define	add_byte(__bits)						\
+	do {								\
+		const unsigned bits = (__bits);				\
+		int i;							\
+		for (i=0; i<8; i++) {					\
+			buf[n++] = NS_TO_US(nec_unit);			\
+			if (bits & (1U << i))				\
+				buf[n++] = NS_TO_US(nec_unit * 3);	\
+			else						\
+				buf[n++] = NS_TO_US(nec_unit);		\
+		}							\
+	} while (0)
 
 	buf[n++] = NS_TO_US(nec_unit * 16);
 	buf[n++] = NS_TO_US(nec_unit * 8);
@@ -73,7 +74,7 @@ static int nec_encode(enum rc_proto proto, unsigned sc
 	}
 
 	buf[n++] = NS_TO_US(nec_unit);
-
+#undef add_bits
 	return n;
 }
 
@@ -108,19 +109,21 @@ static int sanyo_encode(enum rc_proto proto, unsigned 
 {
 	const int sanyo_unit = 562500;
 
-	void add_bits(int bits, int count)
-	{
-		int i;
-		for (i=0; i<count; i++) {
-			*buf++ = NS_TO_US(sanyo_unit);
+#define	add_bits(__bits, __count)					\
+	do {								\
+		const unsigned bits = (__bits);				\
+		const int count = (__count);				\
+		int i;							\
+		for (i=0; i<count; i++) {				\
+			*buf++ = NS_TO_US(sanyo_unit);			\
+									\
+			if (bits & (1U << i))				\
+				*buf++ = NS_TO_US(sanyo_unit * 3);	\
+			else						\
+				*buf++ = NS_TO_US(sanyo_unit);		\
+		}							\
+	} while (0)
 
-			if (bits & (1 << i))
-				*buf++ = NS_TO_US(sanyo_unit * 3);
-			else
-				*buf++ = NS_TO_US(sanyo_unit);
-		}
-	}
-
 	*buf++ = NS_TO_US(sanyo_unit * 16);
 	*buf++ = NS_TO_US(sanyo_unit * 8);
 
@@ -130,7 +133,7 @@ static int sanyo_encode(enum rc_proto proto, unsigned 
 	add_bits(~scancode, 8);
 
 	*buf = NS_TO_US(sanyo_unit);
-
+#undef add_bits
 	return 87;
 }
 
@@ -138,19 +141,21 @@ static int sharp_encode(enum rc_proto proto, unsigned 
 {
 	const int sharp_unit = 40000;
 
-	void add_bits(int bits, int count)
-	{
-		int i;
-		for (i=0; i<count; i++) {
-			*buf++ = NS_TO_US(sharp_unit * 8);
+#define	add_bits(__bits, __count)					\
+	do {								\
+		const unsigned bits = (__bits);				\
+		const int count = (__count);				\
+		int i;							\
+		for (i=0; i<count; i++) {				\
+			*buf++ = NS_TO_US(sharp_unit * 8);		\
+									\
+			if (bits & (1U << i))				\
+				*buf++ = NS_TO_US(sharp_unit * 50);	\
+			else						\
+				*buf++ = NS_TO_US(sharp_unit * 25);	\
+		}							\
+	} while (0)
 
-			if (bits & (1 << i))
-				*buf++ = NS_TO_US(sharp_unit * 50);
-			else
-				*buf++ = NS_TO_US(sharp_unit * 25);
-		}
-	}
-
 	add_bits(scancode >> 8, 5);
 	add_bits(scancode, 8);
 	add_bits(1, 2);
@@ -162,7 +167,7 @@ static int sharp_encode(enum rc_proto proto, unsigned 
 	add_bits(~scancode, 8);
 	add_bits(~1, 2);
 	*buf++ = NS_TO_US(sharp_unit * 8);
-
+#undef add_bits
 	return (13 + 2) * 4 + 3;
 }
 
@@ -171,19 +176,21 @@ static int sony_encode(enum rc_proto proto, unsigned s
 	const int sony_unit = 600000;
 	int n = 0;
 
-	void add_bits(int bits, int count)
-	{
-		int i;
-		for (i=0; i<count; i++) {
-			if (bits & (1 << i))
-				buf[n++] = NS_TO_US(sony_unit * 2);
-			else
-				buf[n++] = NS_TO_US(sony_unit);
+#define	add_bits(__bits, __count)					\
+	do {								\
+		const unsigned bits = (__bits);				\
+		const int count = (__count);				\
+		int i;							\
+		for (i=0; i<count; i++) {				\
+			if (bits & (1U << i))				\
+				buf[n++] = NS_TO_US(sony_unit * 2);	\
+			else						\
+				buf[n++] = NS_TO_US(sony_unit);		\
+									\
+			buf[n++] = NS_TO_US(sony_unit);			\
+		}							\
+	} while (0)
 
-			buf[n++] = NS_TO_US(sony_unit);
-		}
-	}
-
 	buf[n++] = NS_TO_US(sony_unit * 4);
 	buf[n++] = NS_TO_US(sony_unit);
 
@@ -204,7 +211,7 @@ static int sony_encode(enum rc_proto proto, unsigned s
 	default:
 		return 0;
 	}
-
+#undef add_bits
 	/* ignore last space */
 	return n - 1;
 }
@@ -214,34 +221,38 @@ static int rc5_encode(enum rc_proto proto, unsigned sc
 	const unsigned int rc5_unit = 888888;
 	unsigned n = 0;
 
-	void advance_space(unsigned length)
-	{
-		if (n % 2)
-			buf[n] += length;
-		else
-			buf[++n] = length;
-	}
+#define	advance_space(__length)				\
+	do {						\
+		const unsigned length = (__length);	\
+		if (n % 2)				\
+			buf[n] += length;		\
+		else					\
+			buf[++n] = length;		\
+	} while (0)
 
-	void advance_pulse(unsigned length)
-	{
-		if (n % 2)
-			buf[++n] = length;
-		else
-			buf[n] += length;
-	}
+#define	advance_pulse(__length)				\
+	do {						\
+		const unsigned length = (__length);	\
+		if (n % 2)				\
+			buf[++n] = length;		\
+		else					\
+			buf[n] += length;		\
+	} while (0)
 
-	void add_bits(int bits, int count)
-	{
-		while (count--) {
-			if (bits & (1 << count)) {
-				advance_space(NS_TO_US(rc5_unit));
-				advance_pulse(NS_TO_US(rc5_unit));
-			} else {
-				advance_pulse(NS_TO_US(rc5_unit));
-				advance_space(NS_TO_US(rc5_unit));
-			}
-		}
-	}
+#define	add_bits(__bits, __count)					\
+	do {								\
+		const unsigned bits = (__bits);				\
+		int count = (__count);					\
+		while (count--) {					\
+			if (bits & (1U << count)) {			\
+				advance_space(NS_TO_US(rc5_unit));	\
+				advance_pulse(NS_TO_US(rc5_unit));	\
+			} else {					\
+				advance_pulse(NS_TO_US(rc5_unit));	\
+				advance_space(NS_TO_US(rc5_unit));	\
+			}						\
+		}							\
+	} while (0)
 
 	buf[n] = NS_TO_US(rc5_unit);
 
@@ -269,7 +280,9 @@ static int rc5_encode(enum rc_proto proto, unsigned sc
 		add_bits(scancode, 6);
 		break;
 	}
-
+#undef advance_space
+#undef advance_pulse
+#undef add_bits
 	/* drop any trailing pulse */
 	return (n % 2) ? n : n + 1;
 }
@@ -279,34 +292,38 @@ static int rc6_encode(enum rc_proto proto, unsigned sc
 	const unsigned int rc6_unit = 444444;
 	unsigned n = 0;
 
-	void advance_space(unsigned length)
-	{
-		if (n % 2)
-			buf[n] += length;
-		else
-			buf[++n] = length;
-	}
+#define	advance_space(__length)				\
+	do {						\
+		const unsigned length = (__length);	\
+		if (n % 2)				\
+			buf[n] += length;		\
+		else					\
+			buf[++n] = length;		\
+	} while (0)
 
-	void advance_pulse(unsigned length)
-	{
-		if (n % 2)
-			buf[++n] = length;
-		else
-			buf[n] += length;
-	}
+#define	advance_pulse(__length)				\
+	do {						\
+		const unsigned length = (__length);	\
+		if (n % 2)				\
+			buf[++n] = length;		\
+		else					\
+			buf[n] += length;		\
+	} while (0)
 
-	void add_bits(unsigned bits, unsigned count, unsigned length)
-	{
-		while (count--) {
-			if (bits & (1 << count)) {
-				advance_pulse(length);
-				advance_space(length);
-			} else {
-				advance_space(length);
-				advance_pulse(length);
-			}
-		}
-	}
+#define	add_bits(__bits, __count, length)		\
+	do {						\
+		const unsigned bits = (__bits);		\
+		int count = (__count);			\
+		while (count--) {			\
+			if (bits & (1U << count)) {	\
+				advance_pulse(length);	\
+				advance_space(length);	\
+			} else {			\
+				advance_space(length);	\
+				advance_pulse(length);	\
+			}				\
+		}					\
+	} while (0)
 
 	buf[n++] = NS_TO_US(rc6_unit * 6);
 	buf[n++] = NS_TO_US(rc6_unit * 2);
@@ -337,7 +354,9 @@ static int rc6_encode(enum rc_proto proto, unsigned sc
 		add_bits(scancode, 32, NS_TO_US(rc6_unit));
 		break;
 	}
-
+#undef advance_space
+#undef advance_pulse
+#undef add_bits
 	/* drop any trailing pulse */
 	return (n % 2) ? n : n + 1;
 }
