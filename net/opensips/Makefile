# Created by: Euan Thoms <euan@potensol.com>
# $FreeBSD$

PORTNAME=		opensips
DISTVERSION=		3.0.2
PORTREVISION=		0
CATEGORIES=		net
MASTER_SITES=		http://opensips.org/pub/opensips/${PORTVERSION}/

MAINTAINER=		euan@potensol.com
COMMENT=		Open SIP Server

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

LIB_DEPENDS=		libxml2.so:textproc/libxml2 \
			libxmlrpc.so:net/xmlrpc-c \
			libpcre.so:devel/pcre \
			librabbitmq.so:net/rabbitmq-c \
			libhiredis.so:databases/hiredis \
			libexpat.so:textproc/expat2 \
			libcurl.so:ftp/curl \
			libjson-c.so:devel/json-c
BUILD_DEPENDS=		ginstall:sysutils/coreutils \
			gtar:archivers/gtar \
			gm4:devel/m4 \
			redis-server:databases/redis \
			flex:textproc/flex
RUN_DEPENDS=		${LOCALBASE}/bin/bash:shells/bash \
			${LOCALBASE}/bin/grep:textproc/gnugrep

USES=			gmake bison ncurses perl5 pkgconfig python \
			shebangfix ssl
USE_RC_SUBR=		opensips
USE_GCC=		yes

GINSTALL=		ginstall

WRKSRC=			${WRKDIR}/opensips-${PORTVERSION}
DOCSDIR=		share/doc/opensips

USERS=			opensips
GROUPS=			opensips

LDFLAGS+=		-pthread

NOPRECIOUSMAKEVARS=	yes

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES HTTP LDAP MEMCACHED MYSQL \
			PGSQL RADIUS SCTP TESTS TLS UNIXODBC SQLITE
OPTIONS_DEFAULT=	HTTP LDAP MEMCACHED PGSQL RADIUS TLS
OPTIONS_SUB=		yes

HTTP_DESC=		Enable HTTP transport via libmicrohttpd
MEMCACHED_DESC=		Build with memcached support
SCTP_DESC=		SCTP support
TESTS_DESC=		Install smoke tests

LDAP_USE=		OPENLDAP=client
MYSQL_USES=		mysql:client
PGSQL_USES=		pgsql

PGSQL_BUILD_DEPENDS=	p5-DBD-Pg>=3.4:databases/p5-DBD-Pg
RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient
HTTP_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
MEMCACHED_LIB_DEPENDS=	libmemcached.so:databases/libmemcached
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
SQLITE_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

SHEBANG_GLOB=	*.sh *.pl *.py *.php

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTTP}
EXTRA_MODULES+=		httpd
.endif

.if ${PORT_OPTIONS:MLDAP}
EXTRA_MODULES+=		ldap h350
.endif

.if ${PORT_OPTIONS:MMEMCACHED}
EXTRA_MODULES+=		cachedb_memcached
.endif

.if ${PORT_OPTIONS:MMYSQL}
EXTRA_MODULES+=		db_mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
EXTRA_MODULES+=		db_postgres
.endif

.if ${PORT_OPTIONS:MRADIUS}
EXTRA_MODULES+=		aaa_radius
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
EXTRA_MODULES+=		db_unixodbc
.endif

.if ${PORT_OPTIONS:MSCTP}
EXTRA_MODULES+=		sctp
.endif

.if ${PORT_OPTIONS:MTLS}
EXTRA_MODULES+=		proto_tls proto_wss tls_mgm
.endif

.if ${PORT_OPTIONS:MSQLITE}
EXTRA_MODULES+=		db_sqlite
.endif

OPENSIPS_MAKE_ENV=	CC="${CC}" CXX="${CXX}" CPP="${CPP}" _GCC_RUNTIME="${_GCC_RUNTIME}" CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" PYTHON="${PYTHON_CMD}"

do-configure:
	@(cp files/Makefile.conf ${WRKSRC})

	@${REINPLACE_CMD} -e "s|_PREFIX_|${PREFIX}|" ${WRKSRC}/Makefile.conf
	@${REINPLACE_CMD} -e "s|_STAGE_DIR_|${STAGEDIR}|" ${WRKSRC}/Makefile.conf

.for i in ${EXTRA_MODULES}
	@${REINPLACE_CMD} -e "s/\(^include_modules=.*\)/\1 ${i}/" ${WRKSRC}/Makefile.conf
.endfor

do-configure-DEBUG-off:
	@${REINPLACE_CMD} -e "s/^#DEFS+= -DNO_DEBUG/DEFS+= -DNO_DEBUG/" ${WRKSRC}/Makefile.conf

do-build:
	cd ${WRKSRC} && ${OPENSIPS_MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} ${ALL_TARGET}

do-install:
	cd ${WRKSRC} && ${OPENSIPS_MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}

	(cp ${FILESDIR}/opensips.cfg.sample ${STAGEDIR}${ETCDIR}/opensips.cfg.sample)

do-install-TESTS-on:
	(cp -r ${WRKSRC}/test ${STAGEDIR}${PREFIX}/tests/opensips)

do-install-EXAMPLES-on:
	(cp -r ${WRKSRC}/examples ${STAGEDIR}${PREFIX}/share/examples/opensips)

post-install:
	@cd ${STAGEDIR}${PREFIX}/sbin && ${STRIP_CMD} opensips osipsconfig
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/opensips/modules/*.so

post-install-RADIUS-on:
	(mv ${WRKSRC}/etc/dictionary.opensips ${STAGEDIR}${ETCDIR}/dictionary.opensips.sample)

# Strip binaries in sbin
	@${ECHO_CMD} "Stripping binaries in ${STAGEDIR}${PREFIX}/sbin/"

.for i in opensips osipsconfig
	@if [ -e ${STAGEDIR}${PREFIX}/sbin/${i} ]; then \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${i}; \
	fi
.endfor

# Strip binaries in lib/opensips/modules
	@${ECHO_CMD} "Stripping binaries in ${STAGEDIR}${PREFIX}/lib/opensips/modules/"

.for i in	aaa_radius.so acc.so alias_db.so auth.so auth_aaa.so auth_db.so auth_diameter.so \
		avpops.so b2b_entities.so b2b_logic.so b2b_sca.so benchmark.so cachedb_local.so \
		cachedb_memcached.so cachedb_sql.so call_center.so call_control.so carrierroute.so \
		cfgutils.so closeddial.so cpl_c.so db_cachedb.so db_flatstore.so db_mysql.so \
		db_postgres.so db_text.so db_unixodbc.so db_virtual.so dialog.so dialplan.so \
		dispatcher.so diversion.so dns_cache.so domain.so domainpolicy.so drouting.so \
		enum.so event_datagram.so event_rabbitmq.so event_route.so event_xmlrpc.so exec.so \
		gflags.so group.so h350.so httpd.so identity.so imc.so jabber.so json.so ldap.so \
		load_balancer.so mangler.so mathops.so maxfwd.so mediaproxy.so mi_datagram.so \
		mi_fifo.so mi_http.so mi_json.so mi_xmlrpc.so mi_xmlrpc_ng.so mmgeoip.so msilo.so \
		nat_traversal.so nathelper.so options.so path.so pdt.so peering.so perl.so \
		permissions.so pi_http.so pike.so presence.so presence_callinfo.so \
		presence_dialoginfo.so presence_mwi.so presence_xcapdiff.so presence_xml.so pua.so \
		pua_bla.so pua_dialoginfo.so pua_mi.so pua_usrloc.so pua_xmpp.so python.so qos.so \
		ratelimit.so regex.so registrar.so rest_client.so rls.so rr.so rtpproxy.so \
		script_helper.so seas.so signaling.so sipcapture.so sipmsgops.so siptrace.so sl.so \
		sms.so speeddial.so sst.so statistics.so stun.so textops.so tlsops.so tm.so uac.so \
		uac_auth.so uac_redirect.so uac_registrant.so uri.so userblacklist.so usrloc.so \
		xcap.so xcap_client.so xmpp.so topology_hiding.so fraud_detection.so rtpengine.so \
		proto_ws.so proto_tls.so cachedb_redis.so db_sqlite.so proto_bin.so tls_mgm.so \
		tls_mgm.so event_flatstore.so event_virtual.so proto_hep.so proto_wss.so \
		clusterer.so sql_cacher.so
		@if [ -e ${STAGEDIR}${PREFIX}/lib/opensips/modules/${i} ]; then \
			${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/opensips/modules/${i}; \
		fi
.endfor

.include <bsd.port.mk>
