# $FreeBSD$

PORTNAME=	libhdhomerun
PORTVERSION=	20190621
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://download.silicondust.com/hdhomerun/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Library and command line utility for interfacing with HDHomeRun device

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake tar:tgz
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/libhdhomerun

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libhdhomerun
	${INSTALL_PROGRAM} ${WRKSRC}/hdhomerun_config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libhdhomerun.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/libhdhomerun

.include <bsd.port.mk>
