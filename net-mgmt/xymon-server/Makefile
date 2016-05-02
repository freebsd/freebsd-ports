# $FreeBSD$

PORTNAME=	xymon
PORTVERSION=	4.3.27
PORTREVISION=	1
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/xymon/Xymon/${PORTVERSION}
PKGNAMESUFFIX=	-server${PKGNAMESUFFIX2}
DIST_SUBDIR=	repacked

MAINTAINER=	feld@FreeBSD.org
COMMENT=	System for monitoring servers and networks

LICENSE=	GPLv2

BUILD_DEPENDS=	rrdtool:databases/rrdtool
LIB_DEPENDS=	libpng.so:graphics/png \
		libpcre.so:devel/pcre \
		libcares.so:dns/c-ares
RUN_DEPENDS=	rrdtool:databases/rrdtool \
		fping:net/fping \
		mtr:net/mtr-nox11

USERS=		xymon
GROUPS=		xymon

# Options
XYMONUSER?=	xymon
XYMONHOSTNAME?=	xymon.example.com
XYMONHOSTIP?=	127.0.0.1

USES=		cpe gmake shebangfix
SHEBANG_FILES=	${WRKSRC}/xymond/xymonreports.sh.DIST ${WRKSRC}/build/upgrade430.sh
USE_OPENSSL=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ENV=	MAKE=gmake
MAKE_ENV+=	XYMONUSER="${XYMONUSER}"
MAKE_ENV+=	XYMONHOSTNAME="${XYMONHOSTNAME}"
MAKE_ENV+=	XYMONHOSTIP="${XYMONHOSTIP}"
MAKE_ENV+=	INSTALLROOT="${STAGEDIR}"
MANPREFIX=	${STAGEDIR}${PREFIX}
MAKE_ARGS+=	PKGBUILD="true"
USE_RC_SUBR=	xymon-server
SUB_LIST+=	XYMONUSER="${XYMONUSER}"
PLIST_SUB+=	XYMONUSER="${XYMONUSER}"

CONFIG_FILES=	cgioptions.cfg client-local.cfg \
		columndoc.csv graphs.cfg protocols.cfg \
		tasks.cfg xymonserver.cfg xymon-apache.conf
FIXME1=		alerts.cfg hosts.cfg xymon-apache-open xymon-apache-secure
FIXME2=		analysis.cfg combo.cfg holidays.cfg rrddefinitions.cfg \
		snmpmibs.cfg xymonmenu.cfg xymonserver-migration.cfg

OPTIONS_DEFINE=DEBUG LDAP NETSNMP
NETSNMP_DESC=Enable Net-SNMP support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
MAKE_ENV+=	WITH_LDAP=1
USE_OPENLDAP=	yes
.endif

.if ${PORT_OPTIONS:MNETSNMP}
MAKE_ENV+=	WITH_NETSNMP=1
LIB_DEPENDS+=	libnetsnmp.so:net-mgmt/net-snmp
.endif

post-patch:
	${REINPLACE_CMD} -e 's|web-build client|web-build|' ${WRKSRC}/build/Makefile.rules
	${REINPLACE_CMD} -e 's|install-docs install-client|install-docs|' ${WRKSRC}/build/Makefile.rules
	${REINPLACE_CMD} -e 's|$(INSTALLETCDIR)/protocols.cfg|$(INSTALLETCDIR)/protocols.cfg.DIST|' ${WRKSRC}/xymonnet/Makefile
	${REINPLACE_CMD} -e 's|TRACEROUTE="traceroute"|TRACEROUTE="mtr -c 2 -n --report"|' ${WRKSRC}/xymond/etcfiles/xymonserver.cfg.DIST
	${RM} ${WRKSRC}/docs/manpages/man1/xymonping.1.html
	${RM} ${WRKSRC}/xymonnet/xymonping.1

# Configure script is interactive
do-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/server/etc
	${LN} -s ${LOCALBASE}/sbin/fping ${STAGEDIR}${WWWDIR}/server/bin/xymonping
	${INSTALL_SCRIPT} ${WRKSRC}/build/upgrade430.sh ${STAGEDIR}${WWWDIR}/server/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/renamevars ${STAGEDIR}${WWWDIR}/server/bin/
.for i in ${FIXME1}
	${INSTALL_DATA} ${WRKSRC}/xymond/etcfiles/${i}.DIST ${STAGEDIR}${WWWDIR}/server/etc/${i}.sample
.endfor
.for i in ${FIXME2}
	${INSTALL_DATA} ${WRKSRC}/xymond/etcfiles/${i} ${STAGEDIR}${WWWDIR}/server/etc/${i}.sample
.endfor
.for i in ${CONFIG_FILES}
	${MV} ${STAGEDIR}${WWWDIR}/server/etc/${i}.DIST ${STAGEDIR}${WWWDIR}/server/etc/${i}.sample
.endfor

.include <bsd.port.mk>
