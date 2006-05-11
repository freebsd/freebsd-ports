# New ports collection makefile for:   nrg
# Date created:        18 January 2004
# Whom:                Michael Ranner
#
# $FreeBSD$
#

PORTNAME=	nrg
PORTVERSION=	0.99.25
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	ftp://nrg.hep.wisc.edu/pub/src/nrg/ \
		http://www.ranner.jawa.at/stuff/

MAINTAINER=	mranner@inode.at
COMMENT=	Tool for visualizing network and resource utilization data

BUILD_DEPENDS=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/net/rrdtool \
		${LOCALBASE}/bin/snmpget:${PORTSDIR}/net-mgmt/net-snmp4
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${SITE_PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

NRG_WEB_PREFIX?=	${PREFIX}/www/data
NRG_WEB_DIR?=		nrg
NRG_WEB_TITLE?=		FreeBSD NRG Homepage

NRG_DIR?=		nrg
NRGDIR=			${NRG_DIR}
DOCSDIR=		${NRGDIR}/html
EXAMPLESDIR=	${NRGDIR}/examples

SITE_PERL_ARCH=	${SITE_PERL}/${PERL_ARCH}

PKGMESSAGE=		${WRKDIR}/pkg-message
USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/${NRGDIR}
ALL_TARGET=		pingd
PLIST_SUB=		NRGDIR=${NRG_DIR}

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    -DWITH_APCNISCLIENT to build collector for nrg-apcupsdstat"
	@${ECHO} ""

.if defined(WITH_APCNISCLIENT)
EXTRA_PATCHES+=	${PATCHDIR}/nrg-apcupsdstat.patch
PLIST_FILES+=	nrg/bin/nrg-apcupsdstat
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,= @WEB_PREFIX@,= ${NRG_WEB_PREFIX},g" \
		-e "s,= @NRG_WEB_DIR@,= ${NRG_WEB_DIR},g" \
		-e "s,= @NRG_WEB_TITLE@,= \"${NRG_WEB_TITLE}\",g" \
		${WRKSRC}/examples/Makefile.ops.in
	@${REINPLACE_CMD} -e "s,<malloc.h>,<stdlib.h>,g" \
		${WRKSRC}/roverpingd/send.c ${WRKSRC}/roverpingd/pingd.c \
		${WRKSRC}/roverpingd/read_list.c
	@${REINPLACE_CMD} -e "s,<values.h>,<limits.h>,g" \
		-e "s, MAXINT, INT_MAX,g" \
		${WRKSRC}/roverpingd/write_stats.c
	@${REINPLACE_CMD} -e "s,-D__FreeBSD__,,g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s,@bindir@/rrdtool,${PREFIX}/bin/rrdtool,g" \
		${WRKSRC}/etc/run-star-head.pl.in
	@${REINPLACE_CMD} -e "s,@prefix@,${PREFIX},g" \
		-e "s,NOW \"%a %b %d %H:%M %Z %Y\",NOW '%a %b %d %H:%M %Z %Y',g" \
		${WRKSRC}/templates/*.in
	@${CP} ${TEMPLATES}/config.guess ${WRKSRC}/config/
	@${CP} ${TEMPLATES}/config.sub ${WRKSRC}/config/

pre-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' <${.CURDIR}/pkg-message >${PKGMESSAGE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile.ops ${PREFIX}/nrg/Makefile-dist
	${INSTALL_DATA} ${WRKSRC}/examples/Default.conf ${PREFIX}/nrg/Default.conf-dist
	${INSTALL_DATA} ${WRKSRC}/examples/NRG.mconf ${PREFIX}/nrg/NRG.mconf-dist
	${INSTALL_DATA} ${WRKSRC}/examples/Site.mconf ${PREFIX}/nrg/Site.mconf-dist
	@${INSTALL_SCRIPT} ${FILESDIR}/run-nrg.sh ${PREFIX}/nrg/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
