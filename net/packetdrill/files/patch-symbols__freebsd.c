--- symbols_freebsd.c.orig	2023-10-07 04:37:59 UTC
+++ symbols_freebsd.c
@@ -406,7 +406,9 @@ struct int_symbol platform_symbols_table[] = {
 	{ TCP_NOOPT,                        "TCP_NOOPT"                       },
 	{ TCP_MD5SIG,                       "TCP_MD5SIG"                      },
 	{ TCP_INFO,                         "TCP_INFO"                        },
+#if defined(TCP_STATS)
 	{ TCP_STATS,                        "TCP_STATS"                       },
+#endif
 #if defined(TCP_LOG)
 	{ TCP_LOG,                          "TCP_LOG"                         },
 #endif
