# $FreeBSD$

PORTNAME=	libhdhomerun
PORTVERSION=	20150826
CATEGORIES=	multimedia
MASTER_SITES=	http://download.silicondust.com/hdhomerun/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sam@middling.me.uk
COMMENT=	Library and command line utility for interfacing with HDHomeRun device

LICENSE=	LGPL21

USES=		gmake tar:tgz
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/libhdhomerun

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libhdhomerun
	${INSTALL_PROGRAM} ${WRKSRC}/hdhomerun_config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libhdhomerun.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/libhdhomerun

.include <bsd.port.mk>
