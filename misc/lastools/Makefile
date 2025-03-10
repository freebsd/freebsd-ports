PORTNAME=	LAStools
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.3
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient tools for LiDAR processing
WWW=		https://rapidlasso.com/lastools/ \
		https://github.com/LAStools/LAStools

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake:insource
USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

CONFLICTS_INSTALL=	liblas

EXECUTABLES=	lasindex las2txt las2las txt2las lasdiff lasinfo laszip lasmerge lasprecision

xpre-install:
	${MV} ${WRKSRC}/LASlib/src/LASlib-config.cmake ${WRKSRC}/LASlib/src/laslib-config.cmake

post-install: # strip the "64" suffix from executables
.for e in ${EXECUTABLES}
	${MV} ${STAGEDIR}${PREFIX}/bin/${e}64 ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
