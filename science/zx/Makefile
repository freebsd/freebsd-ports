PORTNAME=	zx
PORTVERSION=	g20221101
CATEGORIES=	science # quantum-computing

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MQT ZX: A library for working with ZX-diagrams
WWW=		https://www.cda.cit.tum.de/research/quantum/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake:testing compiler:c++17-lang python:test

USE_GITHUB=	yes
GH_ACCOUNT=	cda-tum
GH_TAGNAME=	b01ba5e
GH_TUPLE=	boostorg:config:2543ff1:boostorg_config/extern/boost/config \
		boostorg:multiprecision:be4b8e8:boostorg_multiprecision/extern/boost/multiprecision \
		google:googletest:3026483:googletest/extern/googletest

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_ZX_TESTS
CMAKE_TESTING_ON=	BUILD_ZX_TESTS

do-install: # workaround for https://github.com/cda-tum/dd_package/issues/115
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${BUILD_WRKSRC}/src/libzx.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
