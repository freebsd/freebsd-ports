# Created by: Euan Thoms <euan@potensol.com>
# $FreeBSD$

PORTNAME=		opensips
PORTVERSION=		2.1.2
PORTREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://opensips.org/pub/opensips/${PORTVERSION}/

MAINTAINER=		euan@potensol.com
COMMENT=		Open SIP Server

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=		libxml2.so:textproc/libxml2 \
			libxmlrpc.so:net/xmlrpc-c \
			libpcre.so:devel/pcre \
			libconfuse.so:devel/libconfuse \
			librabbitmq.so:net/rabbitmq-c-devel \
			libhiredis.so:databases/hiredis \
			libexpat.so:textproc/expat2 \
			libjson-c.so:devel/json-c
BUILD_DEPENDS=		ginstall:sysutils/coreutils \
			gtar:archivers/gtar \
			gm4:devel/m4 \
			redis-server:databases/redis-devel \
			python2:lang/python2 \
			python:lang/python
RUN_DEPENDS=		${LOCALBASE}/bin/bash:shells/bash \
			${LOCALBASE}/bin/python2:lang/python2 \
			${LOCALBASE}/bin/grep:textproc/gnugrep

GINSTALL=		ginstall

WRKSRC=			${WRKDIR}/opensips-${PORTVERSION}
DOCSDIR=		share/doc/opensips

USE_RC_SUBR=		opensips

USES=			gmake perl5 pkgconfig shebangfix
USE_GCC=		yes

NOPRECIOUSMAKEVARS=	yes

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES GEOIP HTTP LDAP MEMCACHED MYSQL PGSQL RADIUS TESTS TLS UNIXODBC
OPTIONS_DEFAULT=	GEOIP HTTP LDAP MEMCACHED PGSQL RADIUS TLS
OPTIONS_SUB=		yes

GEOIP_DESC=		Build with GeoIP support
HTTP_DESC=		Enable HTTP transport via libmicrohttpd
MEMCACHED_DESC=		Build with memcached support
TESTS_DESC=		Install smoke tests

LDAP_USE=		OPENLDAP=client
MYSQL_USE=		MYSQL=client
PGSQL_USES+=		pgsql

PGSQL_BUILD_DEPENDS+=	p5-DBD-Pg>=3.4:databases/p5-DBD-Pg
RADIUS_BUILD_DEPENDS+=	radiusclient:net/radiusclient
HTTP_LIB_DEPENDS+=	libmicrohttpd.so:www/libmicrohttpd
GEOIP_LIB_DEPENDS+=	libGeoIP.so:net/GeoIP
MEMCACHED_LIB_DEPENDS+=	libmemcached.so:databases/libmemcached
UNIXODBC_LIB_DEPENDS+=	libodbc.so:databases/unixODBC

SHEBANG_FILES=		scripts/osipsconsole \
			modules/jabber/doc/jabberreg.pl \
			modules/sipcapture/examples/partrotate_unixtimestamp.pl \
			scripts/dbtextdb/__init__.py \
			scripts/dbtextdb/dbtextdb.py \
			scripts/dbtextdb/dbtextdb_test.py \
			packaging/fedora/opensips.m4cfg \
			packaging/fedora/opensips.init \
			packaging/rpm/opensips.init \
			modules/seas/doc/xml2sgml.sh \
			utils/fifo_relay/fifo_server.php \
			test/1.sh \
			test/2.sh \
			test/3.sh \
			test/4.sh \
			test/5.sh \
			test/6.sh \
			test/7.sh \
			test/8.sh \
			test/9.sh \
			test/10.sh \
			test/11.sh \
			test/12.sh \
			test/13.sh \
			test/14.sh \
			test/15.sh \
			test/16.sh \
			test/17.sh \
			test/18.sh \
			test/19.sh \
			test/20.sh \
			test/21.sh \
			test/22.sh \
			test/23.sh \
			test/24.sh \
			test/25.sh \
			test/26.sh \
			test/27.sh \
			test/28.sh \
			test/29.sh \
			test/30.sh \
			test/31.sh \
			test/32.sh \
			test/33.sh \
			test/34.sh \
			test/35.sh

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEOIP}
EXTRA_MODULES+=		mmgeoip
.endif

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

.if ${PORT_OPTIONS:MTLS}
EXTRA_MODULES+=		proto_tls
.endif

OPENSIPS_MAKE_ENV=	CC="${CC}" CXX="${CXX}" CPP="${CPP}" _GCC_RUNTIME="${_GCC_RUNTIME}" CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"

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

do-install-TESTS-on:
	(cp -r ${WRKSRC}/test ${STAGEDIR}${PREFIX}/tests/opensips)

do-install-EXAMPLES-on:
	(cp -r ${WRKSRC}/examples ${STAGEDIR}${PREFIX}/share/examples/opensips)

post-stage:
	@${REINPLACE_CMD} -e "s|^# MD5=.*|MD5=\"md5\"|" ${STAGEDIR}${PREFIX}/etc/opensips/opensipsctlrc.sample
	@${REINPLACE_CMD} -e "s|^# GREP=.*|GREP=\"${LOCALBASE}/bin/grep\"|" ${STAGEDIR}${PREFIX}/etc/opensips/opensipsctlrc.sample
	@${REINPLACE_CMD} -e "s|^# MD5=.*|MD5=\"md5\"|" ${STAGEDIR}${PREFIX}/etc/opensips/osipsconsolerc.sample
	@${REINPLACE_CMD} -e "s|^# GREP=.*|GREP=\"${LOCALBASE}/bin/egrep\"|" ${STAGEDIR}${PREFIX}/etc/opensips/osipsconsolerc.sample
	(cp ${FILESDIR}/opensips.cfg.sample ${STAGEDIR}${ETCDIR}/opensips.cfg.sample)

post-stage-RADIUS-on:
	(mv ${STAGEDIR}${ETCDIR}/dictionary.opensips ${STAGEDIR}${ETCDIR}/dictionary.opensips.sample)

# Strip binaries in sbin
	@${ECHO_CMD} "Stripping binaries in ${STAGEDIR}${PREFIX}/sbin/"

.for i in opensipsunix opensips osipsconfig
	@if [ -e ${STAGEDIR}${PREFIX}/sbin/${i} ]; then \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${i}; \
	fi
.endfor

# Strip binaries in lib/opensips/modules
	@${ECHO_CMD} "Stripping binaries in ${STAGEDIR}${PREFIX}/lib/opensips/modules/"

.for i in	aaa_radius.so acc.so alias_db.so auth.so auth_aaa.so auth_db.so auth_diameter.so \
		avpops.so b2b_entities.so b2b_logic.so b2b_sca.so benchmark.so cachedb_local.so \
		cachedb_memcached.so cachedb_sql.so call_center.so call_control.so carrierroute.so \
		cfgutils.so closeddial.so cpl-c.so db_cachedb.so db_flatstore.so db_mysql.so \
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
		proto_ws.so proto_tls.so cachedb_redis.so
		@if [ -e ${STAGEDIR}${PREFIX}/lib/opensips/modules/${i} ]; then \
			${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/opensips/modules/${i}; \
		fi
.endfor

.include <bsd.port.mk>
