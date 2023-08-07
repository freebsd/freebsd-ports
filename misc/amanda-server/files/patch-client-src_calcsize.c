--- client-src/calcsize.c.orig	2017-12-01 13:26:32 UTC
+++ client-src/calcsize.c
@@ -166,7 +166,11 @@ main(
 	dump_total += (ST_BLOCKS(finfo) + (off_t)1) / (off_t)2 + (off_t)1;
 	gtar_total += ROUND(4,(ST_BLOCKS(finfo) + (off_t)1));
     }
+#ifdef GNUTAR
+    g_printf("           GNUTAR           dump\n");
+#else
     g_printf("           gtar           dump\n");
+#endif
     g_printf("total      %-9lu         %-9lu\n",gtar_total,dump_total);
     return 0;
 #else
