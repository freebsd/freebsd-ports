--- symbols_freebsd.c.orig	2025-04-23 21:59:38 UTC
+++ symbols_freebsd.c
@@ -412,7 +412,9 @@ struct int_symbol platform_symbols_table[] = {
 	{ TCP_NOOPT,                        "TCP_NOOPT"                       },
 	{ TCP_MD5SIG,                       "TCP_MD5SIG"                      },
 	{ TCP_INFO,                         "TCP_INFO"                        },
+#if defined(TCP_STATS)
 	{ TCP_STATS,                        "TCP_STATS"                       },
+#endif
 #if defined(TCP_LOG)
 	{ TCP_LOG,                          "TCP_LOG"                         },
 #endif
@@ -931,7 +933,9 @@ struct int_symbol platform_symbols_table[] = {
 #ifdef SF_NOCACHE
 	{ SF_NOCACHE,                       "SF_NOCACHE"                      },
 #endif
+#ifdef SF_SYNC
 	{ SF_SYNC,                          "SF_SYNC"                         },
+#endif
 
 	/* /usr/include/sys/unistd.h */
 	{ SEEK_SET,                         "SEEK_SET"                        },
