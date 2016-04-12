# Created by: vfom@narod.ru
# $FreeBSD$

PORTNAME=	netmond
PORTVERSION=	2.2b6
PORTREVISION=	7
CATEGORIES=	net-mgmt
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/:daemon \
		ftp://ftp.risp.ru/pub/RinetSoftware/:daemon \
		http://vfom.narod.ru/download/:docs
DISTFILES=	${PORTNAME}-2.2-b6${EXTRACT_SUFX}:daemon
EXTRACT_ONLY=	${PORTNAME}-2.2-b6${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netmond - IP network monitoring daemon

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}-2.2-b6

USERS=	netmon
GROUPS=	${USERS}

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USES=		bison tar:tgz
CFLAGS+=	-Wno-return-type

USE_RC_SUBR=	netmond
SUB_FILES+=	pkg-message netmond_watchdog netmondctl
PORTDOCS=	README README.ru CHANGES README.port.eng README.port.ru index.html netmond.css en/* ru/*

OPTIONS_DEFINE=	DOCS GD
OPTIONS_SUB=	yes

GD_LIB_DEPENDS=	libgd.so:graphics/gd
GD_CONFIGURE_OFF=	--without-ifgraph

DOCS_DISTFILES= ${PORTNAME}-2.2-b6.docs${EXTRACT_SUFX}:docs

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netmond ${STAGEDIR}${PREFIX}/sbin/netmond
.if ${PORT_OPTIONS:MGD}
	${INSTALL_PROGRAM} ${WRKSRC}/ifgraph ${STAGEDIR}${PREFIX}/sbin/ifgraph
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/netmond_watchdog ${STAGEDIR}${PREFIX}/sbin/netmond_watchdog
	${INSTALL_SCRIPT} ${WRKDIR}/netmondctl ${STAGEDIR}${PREFIX}/sbin/netmondctl
	${INSTALL_DATA} ${WRKSRC}/netmon.conf.sample ${STAGEDIR}${PREFIX}/etc/netmond.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -zxf ${DISTDIR}/${PORTNAME}-2.2-b6.docs${EXTRACT_SUFX} -C ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
