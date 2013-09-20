# Created by: Danton Dorati <urisso@bsd.com.br>
# $FreeBSD$

PORTNAME=	snortsam
PORTVERSION=	2.70
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.snortsam.net/files/snortsam/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	urisso@bsd.com.br
COMMENT=	SnortSam is a output plugin for Snort

OPTIONS_DEFINE=	IPFW SAMTOOL DEBUG DOCS
OPTIONS_DEFAULT=	IPFW SAMTOOL
IPFW_DESC=	checks if configured tables are available
SAMTOOL_DESC=	install samtool

NO_STAGE=	yes
.include <bsd.port.pre.mk>

USE_RC_SUBR=	snortsam
SUB_FILES=	pkg-message \
		pkg-install

HAS_CONFIGURE=	yes
NO_BUILD=	yes
CONFIGURE_SCRIPT=	src/Makefile

CONFIG_DIR?=	${PREFIX}/etc/snortsam

PLIST_DIRS=	etc/snortsam
PLIST_FILES=	sbin/snortsam \
		etc/snortsam/snortsam.conf.sample \
		etc/snortsam/country-rootservers.conf.sample \
		etc/snortsam/rootservers.cfg.sample

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

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

pre-configure:
	@${REINPLACE_CMD} -e "s|/etc/snortsam.conf|${CONFIG_DIR}/snortsam.conf|g" ${WRKSRC}/conf/snortsam.conf.sample
	@${REINPLACE_CMD} -e "s|/etc/snortsam.conf|${CONFIG_DIR}/snortsam.conf|g" ${WRKSRC}/docs/README.conf
	@${REINPLACE_CMD} -e "s|/etc/snortsam.conf|${CONFIG_DIR}/snortsam.conf|g" ${WRKSRC}/src/snortsam.h
	@${REINPLACE_CMD} -e "s|/etc/snortsam.conf|${CONFIG_DIR}/snortsam.conf|g" ${WRKSRC}/contrib/snortsam-state.c
	@${CHMOD} +x ${WRKSRC}/makesnortsam.sh

do-configure:
	@cd ${WRKSRC}/src && ${MAKE} ${DEBUG}
	@cd ${WRKSRC}/src && ${MAKE} samtool ${DEBUG}

# no access to snortsam.conf and samtool for non root users!
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/snortsam ${PREFIX}/sbin
.if ${PORT_OPTIONS:MSAMTOOL}
	@${INSTALL} -o root -g wheel -m 500 ${WRKSRC}/samtool ${PREFIX}/sbin
.endif
	@${MKDIR} -m 700 ${CONFIG_DIR}
	@${INSTALL_DATA} -m 600 ${WRKSRC}/conf/snortsam.conf.sample ${CONFIG_DIR}/snortsam.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/conf/rootservers.cfg ${CONFIG_DIR}/rootservers.cfg.sample
	@${INSTALL_DATA} ${WRKSRC}/conf/country-rootservers.conf ${CONFIG_DIR}/country-rootservers.conf.sample

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
