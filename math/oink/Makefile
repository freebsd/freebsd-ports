PORTNAME=	oink
DISTVERSION=	g20260123
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern parity game solvers written in C++
WWW=		https://github.com/trolando/oink

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		liblace.so:devel/lace

USES=		cmake:testing compiler:c++17-lang
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	trolando
GH_TAGNAME=	ac3c12a

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	OINK_BUILD_NATIVE

# tests as of g20260123: 100% tests passed, 0 tests failed out of 36

.include <bsd.port.mk>
