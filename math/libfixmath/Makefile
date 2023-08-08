PORTNAME=	libfixmath
PORTVERSION=	g20220915
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform fixed point math library
WWW=		https://github.com/PetteriAimonen/libfixmath

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	PetteriAimonen
GH_TAGNAME=	1416c99

CMAKE_ON=	BUILD_SHARED_LIBS

do-install:
	# headers
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/libfixmath/*.h* ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	# library
	${INSTALL_LIB} ${BUILD_WRKSRC}/libfixmath.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
