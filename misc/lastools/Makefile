PORTNAME=	LAStools
DISTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient tools for LiDAR processing

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake:insource zip

CMAKE_ON=	BUILD_SHARED_LIBS

CONFLICTS_INSTALL=	liblas

EXECUTABLES=	lasindex las2txt las2las txt2las lasdiff lasinfo laszip lasmerge lasprecision

pre-install:
	${MV} ${WRKSRC}/LASlib/src/LASlib-config.cmake ${WRKSRC}/LASlib/src/laslib-config.cmake

post-install: # strip the "64" suffix from executables
.for e in ${EXECUTABLES}
	${MV} ${STAGEDIR}${PREFIX}/bin/${e}64 ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
