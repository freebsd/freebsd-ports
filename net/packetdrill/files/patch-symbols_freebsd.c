--- symbols_freebsd.c.orig	2013-09-04 15:08:25.000000000 +0900
+++ symbols_freebsd.c	2013-09-04 15:08:28.000000000 +0900
@@ -76,7 +76,9 @@
 	{ SO_LISTENQLEN,                    "SO_LISTENQLEN"                   },
 	{ SO_LISTENINCQLEN,                 "SO_LISTENINCQLEN"                },
 	{ SO_SETFIB,                        "SO_SETFIB"                       },
+#ifdef SO_USER_COOKIE
 	{ SO_USER_COOKIE,                   "SO_USER_COOKIE"                  },
+#endif
 
 	/* /usr/include/netinet/tcp.h */
 	{ TCP_NODELAY,                      "TCP_NODELAY"                     },
@@ -296,7 +298,9 @@
 	{ ENOLINK,                          "ENOLINK"                         },
 	{ EPROTO,                           "EPROTO"                          },
 	{ ENOTCAPABLE,                      "ENOTCAPABLE"                     },
+#ifdef ECAPMODE
 	{ ECAPMODE,                         "ECAPMODE"                        },
+#endif
 
 };
 
