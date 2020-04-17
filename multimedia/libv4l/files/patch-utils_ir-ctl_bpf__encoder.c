--- utils/ir-ctl/bpf_encoder.c.orig	2020-04-09 16:29:54 UTC
+++ utils/ir-ctl/bpf_encoder.c
@@ -84,21 +84,23 @@ static void encode_manchester(struct keymap *map, uint
 {
 	int len = 0, bits, i;
 
-	void advance_space(unsigned length)
-	{
-		if (len % 2)
-			buf[len] += length;
-		else
-			buf[++len] = length;
-	}
+#define	advance_space(__length)				\
+	do {						\
+		const unsigned length = (__length);	\
+		if (len % 2)				\
+			buf[len] += length;		\
+		else					\
+			buf[++len] = length;		\
+	} while (0)
 
-	void advance_pulse(unsigned length)
-	{
-		if (len % 2)
-			buf[++len] = length;
-		else
-			buf[len] += length;
-	}
+#define	advance_pulse(__length)				\
+	do {						\
+		const unsigned length = (__length);	\
+		if (len % 2)				\
+			buf[++len] = length;		\
+		else					\
+			buf[len] += length;		\
+	} while (0)
 
 	bits = keymap_param(map, "bits", 14);
 
@@ -111,7 +113,8 @@ static void encode_manchester(struct keymap *map, uint
 			advance_pulse(keymap_param(map, "zero_pulse", 888));
 		}
 	}
-
+#undef advance_space
+#undef advance_pulse
 	/* drop any trailing pulse */
         *length = (len % 2) ? len : len + 1;
 }
