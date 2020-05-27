# Created by: Danton Dorati <urisso@bsd.com.br>
# $FreeBSD$

PORTNAME=	snortsam
PORTVERSION=	2.70
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.snortsam.net/files/snortsam/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	urisso@bsd.com.br
COMMENT=	Output plugin for Snort

OPTIONS_DEFINE=	IPFW SAMTOOL DEBUG DOCS
OPTIONS_DEFAULT=	IPFW SAMTOOL
IPFW_DESC=	checks if configured tables are available
SAMTOOL_DESC=	install samtool

.include <bsd.port.pre.mk>

USE_RC_SUBR=	snortsam
SUB_FILES=	pkg-message \
		pkg-install

PLIST_FILES=	sbin/snortsam \
		%%ETCDIR%%/snortsam.conf.sample \
		%%ETCDIR%%/country-rootservers.conf.sample \
		%%ETCDIR%%/rootservers.cfg.sample

.if ${PORT_OPTIONS:MSAMTOOL}
PLIST_FILES+=	sbin/samtool
.endif

PORTDOCS=	AUTHORS BUGS CREDITS FAQ INSTALL LICENSE README README.ciscoacl \
		README.conf README.iptables README.netscreen README.pf README.pf2 \
		README.rules README.slackware README.snmp_interface_down README.wgrd \
		README_8signs.rtf TODO

.if ! ${PORT_OPTIONS:MIPFW}
EXTRA_PATCHES+=	${FILESDIR}/ssp_ipfw2_no_table_check.patch
.endif

.if ${PORT_OPTIONS:MDEBUG}
DEBUG=-DDEBUG
.endif

# This seems silly, but the RC file gets into ${WRKDIR}/${PORTNAME} which
# without this, would exist and be a directory.
post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e "s|/etc/snortsam.conf|${ETCDIR}/snortsam.conf|g" ${WRKSRC}/conf/snortsam.conf.sample
	@${REINPLACE_CMD} -e "s|/etc/snortsam.conf|${ETCDIR}/snortsam.conf|g" ${WRKSRC}/docs/README.conf
	@${REINPLACE_CMD} -e "s|/etc/snortsam.conf|${ETCDIR}/snortsam.conf|g" ${WRKSRC}/src/snortsam.h
	@${REINPLACE_CMD} -e "s|/etc/snortsam.conf|${ETCDIR}/snortsam.conf|g" ${WRKSRC}/contrib/snortsam-state.c
	@${CHMOD} +x ${WRKSRC}/makesnortsam.sh

do-build:
	@cd ${WRKSRC}/src && ${MAKE} ${DEBUG}
	@cd ${WRKSRC}/src && ${MAKE} samtool ${DEBUG}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snortsam ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/samtool ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/snortsam.conf.sample ${STAGEDIR}${ETCDIR}/snortsam.conf.sample
	${INSTALL_DATA} ${WRKSRC}/conf/rootservers.cfg ${STAGEDIR}${ETCDIR}/rootservers.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/conf/country-rootservers.conf ${STAGEDIR}${ETCDIR}/country-rootservers.conf.sample

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
