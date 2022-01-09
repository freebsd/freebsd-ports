PORTNAME=	LAStools
DISTVERSION=	2.0.0
CATEGORIES=	misc
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient tools for LiDAR processing

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake zip

CMAKE_ON=	BUILD_SHARED_LIBS

EXECUTABLES=	lasindex las2txt las2las txt2las lasdiff lasinfo laszip lasmerge lasprecision

post-configure: # workaround for https://github.com/LAStools/LAStools/issues/108
	@${REINPLACE_CMD} -e '/laslib-config.cmake/,1d' ${BUILD_WRKSRC}/LASlib/src/cmake_install.cmake

post-install: # install executables, workaround for https://github.com/LAStools/LAStools/issues/120
.for e in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/${e}64 ${STAGEDIR}${PREFIX}/bin
	${MV} ${STAGEDIR}${PREFIX}/bin/${e}64 ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
