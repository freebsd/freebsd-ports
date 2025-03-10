PORTNAME=	libfixmath
PORTVERSION=	2023.08.08 # release unlikely, project is semi-deprecated, see https://github.com/PetteriAimonen/libfixmath/issues/51#issuecomment-2614311140
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform fixed point math library
WWW=		https://github.com/PetteriAimonen/libfixmath

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	PetteriAimonen
GH_TAGNAME=	d308e46

CMAKE_ON=	BUILD_SHARED_LIBS

do-install:
	# headers
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/libfixmath/*.h* ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	# library
	${INSTALL_LIB} ${BUILD_WRKSRC}/libfixmath.so ${STAGEDIR}${PREFIX}/lib

# tests are broken due to cmake issues

.include <bsd.port.mk>
