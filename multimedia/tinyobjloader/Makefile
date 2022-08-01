PORTNAME=	tinyobjloader
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0rc9-5
DISTVERSIONSUFFIX=	-ga1e8bad
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ single file wavefront obj loader

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake cpe
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

post-install:
	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE

.include <bsd.port.mk>
