--- lib/asn1.h.orig     Tue Dec  2 18:52:37 2003
+++ lib/asn1.h  Wed Sep 21 09:53:04 2005
@@ -183,4 +183,10 @@
        ASN_EXCEPT_ENDOFMIBVIEW = 0x02,
 };

+#if !defined(__STDC_LIMIT_MACROS)
+#define INT32_MIN       (-0x7fffffff-1)
+#define INT32_MAX       0x7fffffff
+#define UINT32_MAX      0xffffffffU
+#endif
+
 #endif
