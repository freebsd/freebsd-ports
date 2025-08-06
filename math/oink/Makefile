PORTNAME=	oink
DISTVERSION=	g20250105
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern parity game solvers written in C++
WWW=		https://github.com/trolando/oink

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		liblace.so:devel/lace14

USES=		cmake:testing
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	trolando
GH_TAGNAME=	32950f2

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	OINK_BUILD_NATIVE

# tests as of g20250105: 59% tests passed, 14 tests failed out of 34 # failures are likely from some test running too high in memory, because individual tests all pass when standalone

.include <bsd.port.mk>
