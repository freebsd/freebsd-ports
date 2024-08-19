PORTNAME=	arborx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Performance-portable geometric search library
WWW=		https://github.com/arborx/ArborX

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CXX_DEPENDS=	onetbb>0:devel/onetbb \
		kokkos>0:devel/kokkos
BUILD_DEPENDS=	${CXX_DEPENDS}
RUN_DEPENDS=	${CXX_DEPENDS}

USES=		cmake:testing

USE_GITHUB=	yes
GH_PROJECT=	ArborX

CMAKE_TESTING_ON=	ARBORX_ENABLE_TESTS

NO_ARCH=	yes

.include <bsd.port.mk>
