PORTNAME=	xymon
PORTVERSION=	4.3.31
PORTREVISION=	2
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	-server${PKGNAMESUFFIX2}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	System for monitoring servers and networks
WWW=		https://github.com/xymon-monitoring/xymon

LICENSE=	GPLv2

BUILD_DEPENDS=	rrdtool:databases/rrdtool
LIB_DEPENDS=	libpng16.so:graphics/png \
		libpcre2-8.so:devel/pcre2 \
		libcares.so:dns/c-ares
RUN_DEPENDS=	rrdtool:databases/rrdtool \
		fping:net/fping \
		mtr:net/mtr@nox11

USES=		compiler:c11 cpe gmake shebangfix ssl

USERS=		xymon
GROUPS=		xymon

# Options
XYMONUSER?=	xymon
XYMONHOSTNAME?=	xymon.example.com
XYMONHOSTIP?=	127.0.0.1

SHEBANG_FILES=	${WRKSRC}/xymond/xymonreports.sh.DIST ${WRKSRC}/build/upgrade430.sh
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ENV=	MAKE=${MAKE_CMD} XYMONTOPDIR=${WWWDIR} MANROOT=${PREFIX}/share/man
MAKE_ENV+=	XYMONUSER="${XYMONUSER}"
MAKE_ENV+=	XYMONHOSTNAME="${XYMONHOSTNAME}"
MAKE_ENV+=	XYMONHOSTIP="${XYMONHOSTIP}"
MAKE_ENV+=	INSTALLROOT="${STAGEDIR}"
MAKE_ENV+=	MANPREFIX="${STAGEDIR}${PREFIX}/share"
MAKE_ARGS+=	PKGBUILD="true"
USE_RC_SUBR=	xymon-server
SUB_LIST+=	XYMONUSER="${XYMONUSER}"
PLIST_SUB+=	XYMONUSER="${XYMONUSER}" \
		WWWGRP="${WWWGRP}"

CONFIG_FILES=	critical.cfg cgioptions.cfg client-local.cfg \
		columndoc.csv graphs.cfg protocols.cfg \
		tasks.cfg xymonserver.cfg xymon-apache.conf
FIXME1=		alerts.cfg hosts.cfg xymon-apache-open xymon-apache-secure
FIXME2=		analysis.cfg combo.cfg holidays.cfg rrddefinitions.cfg \
		snmpmibs.cfg xymonmenu.cfg xymonserver-migration.cfg

USE_GITHUB=	yes
GH_ACCOUNT=	xymon-monitoring
GH_PROJECT=	xymon
GH_TAGNAME=	rel-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--server --fping=${PREFIX}/bin/fping

OPTIONS_DEFINE=DEBUG NETSNMP
OPTIONS_DEFAULT=	LDAP NETSNMP
OPTIONS_SUB=	yes
NETSNMP_DESC=Enable Net-SNMP support

LDAP_USES=	ldap
LDAP_MAKE_ENV=	WITH_LDAP=1
NETSNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp \
			libpkg.so:${PKG_ORIGIN}
NETSNMP_MAKE_ENV=	WITH_NETSNMP=1
NETSNMP_CONFIGURE_ENV=	SNMP=1

post-patch:
	${REINPLACE_CMD} -e 's|web-build client|web-build|' ${WRKSRC}/build/Makefile.rules
	${REINPLACE_CMD} -e 's|install-docs install-client|install-docs|' ${WRKSRC}/build/Makefile.rules
	${REINPLACE_CMD} -e 's|TRACEROUTE="traceroute"|TRACEROUTE="mtr"|' ${WRKSRC}/xymond/etcfiles/xymonserver.cfg.DIST
	${REINPLACE_CMD} -e 's|TRACEROUTEOPTS="-n -q 2 -w 2 -m 15"|TRACEROUTEOPTS="-n -c 2 -w 2 -m 15 --report"|' ${WRKSRC}/xymond/etcfiles/xymonserver.cfg.DIST
	${REINPLACE_CMD} -e 's|@CGIDIR@|${WWWDIR}/server/cgi-bin|g' \
	-e 's|@SECURECGIDIR@|${WWWDIR}/server/cgi-secure|g' \
	-e 's|@INSTALLETCDIR@|${WWWDIR}/server/etc|g' \
	-e 's|@INSTALLWWWDIR@|${WWWDIR}/server/www|g' \
	-e 's|@SECUREXYMONCGIURL@|/cgi-secure|g' \
	-e 's|@XYMONCGIURL@|/cgi-bin|g' \
	-e 's|@XYMONHOSTURL@|/xymon|g' ${WRKSRC}/xymond/etcfiles/xymon-apache-*.DIST

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL} ${FILESDIR}/xymon-server.newsyslog.conf.sample ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/xymon-server.conf.sample
	${MKDIR} ${STAGEDIR}${WWWDIR}/data
	${MKDIR} ${STAGEDIR}${WWWDIR}/data/acks
	${MKDIR} ${STAGEDIR}${WWWDIR}/data/data
	${MKDIR} ${STAGEDIR}${WWWDIR}/data/disabled
	${MKDIR} ${STAGEDIR}${WWWDIR}/data/hist
	${MKDIR} ${STAGEDIR}${WWWDIR}/data/histlogs
	${MKDIR} ${STAGEDIR}${WWWDIR}/data/hostdata
	${MKDIR} ${STAGEDIR}${WWWDIR}/data/logs
	${MKDIR} ${STAGEDIR}${WWWDIR}/data/rrd
	${MKDIR} ${STAGEDIR}${WWWDIR}/server/download
	${MKDIR} ${STAGEDIR}${WWWDIR}/server/tmp
	${MKDIR} ${STAGEDIR}${WWWDIR}/server/www/html
	${MKDIR} ${STAGEDIR}${WWWDIR}/server/www/notes
	${MKDIR} ${STAGEDIR}${WWWDIR}/server/www/rep
	${MKDIR} ${STAGEDIR}${WWWDIR}/server/www/snap
	${MKDIR} ${STAGEDIR}${WWWDIR}/server/www/wml
	${INSTALL_SCRIPT} ${WRKSRC}/build/upgrade430.sh ${STAGEDIR}${WWWDIR}/server/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/renamevars ${STAGEDIR}${WWWDIR}/server/bin/
.for i in ${FIXME1}
	${INSTALL_DATA} ${WRKSRC}/xymond/etcfiles/${i}.DIST ${STAGEDIR}${WWWDIR}/server/etc/${i}.sample
.endfor
.for i in ${FIXME2}
	${INSTALL_DATA} ${WRKSRC}/xymond/etcfiles/${i} ${STAGEDIR}${WWWDIR}/server/etc/${i}.sample
.endfor
.for i in ${CONFIG_FILES}
	${MV} ${STAGEDIR}${WWWDIR}/server/etc/${i} ${STAGEDIR}${WWWDIR}/server/etc/${i}.sample
.endfor

.include <bsd.port.mk>
