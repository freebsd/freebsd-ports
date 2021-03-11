# $FreeBSD$

PORTNAME=	tinyobjloader
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0rc8-3
DISTVERSIONSUFFIX=	-g7ba4b65
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ single file wavefront obj loader

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

post-install:
	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE

.include <bsd.port.mk>
