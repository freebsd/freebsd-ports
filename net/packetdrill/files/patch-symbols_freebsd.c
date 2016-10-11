--- symbols_freebsd.c.orig	2016-10-01 08:55:57 UTC
+++ symbols_freebsd.c
@@ -76,7 +76,9 @@ struct int_symbol platform_symbols_table
 	{ SO_LISTENQLEN,                    "SO_LISTENQLEN"                   },
 	{ SO_LISTENINCQLEN,                 "SO_LISTENINCQLEN"                },
 	{ SO_SETFIB,                        "SO_SETFIB"                       },
+#ifdef SO_USER_COOKIE
 	{ SO_USER_COOKIE,                   "SO_USER_COOKIE"                  },
+#endif
 
 	/* /usr/include/netinet/sctp.h and /usr/include/netinet/sctp_uio.h */
 	{ SCTP_RTOINFO,                     "SCTP_RTOINFO"                    },
@@ -525,7 +527,9 @@ struct int_symbol platform_symbols_table
 	{ ENOLINK,                          "ENOLINK"                         },
 	{ EPROTO,                           "EPROTO"                          },
 	{ ENOTCAPABLE,                      "ENOTCAPABLE"                     },
+#ifdef ECAPMODE
 	{ ECAPMODE,                         "ECAPMODE"                        },
+#endif
 
 	/* Sentinel marking the end of the table. */
 	{ 0, NULL },
