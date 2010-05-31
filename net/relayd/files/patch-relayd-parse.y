--- relayd/parse.y.orig	2010-05-31 09:00:51.007686324 +0200
+++ relayd/parse.y	2010-05-31 09:00:42.736791085 +0200
@@ -2003,6 +2006,11 @@
 	bzero(&conf->sc_proto_default, sizeof(conf->sc_proto_default));
 	conf->sc_proto_default.flags = F_USED;
 	conf->sc_proto_default.cache = RELAY_CACHESIZE;
+	conf->sc_proto_default.tcpflags = TCPFLAG_DEFAULT;
+	conf->sc_proto_default.tcpbacklog = RELAY_BACKLOG;
+	conf->sc_proto_default.sslflags = SSLFLAG_DEFAULT;
+	(void)strlcpy(conf->sc_proto_default.sslciphers, SSLCIPHERS_DEFAULT,
+	    sizeof(conf->sc_proto_default.sslciphers));
 	conf->sc_proto_default.type = RELAY_PROTO_TCP;
 	(void)strlcpy(conf->sc_proto_default.name, "default",
 	    sizeof(conf->sc_proto_default.name));
