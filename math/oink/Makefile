PORTNAME=	oink
DISTVERSION=	g20210710
PORTREVISION=	6
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern parity game solvers written in C++
WWW=		https://github.com/trolando/oink

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

USES=		cmake:testing
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	trolando
GH_TAGNAME=	3327c54
USE_LDCONFIG=	yes


CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
