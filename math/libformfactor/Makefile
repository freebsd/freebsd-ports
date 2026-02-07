PORTNAME=	libformfactor
DISTVERSION=	0.3.2
CATEGORIES=	math
MASTER_SITES=	https://jugit.fz-juelich.de/mlz/libformfactor/-/archive/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for computation of scattering form factors of polyhedra
WWW=		https://jugit.fz-juelich.de/mlz/libformfactor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libheinz>0:devel/libheinz

USES=		compiler:c++20-lang cmake:testing
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

# tests as of 0.3.2: 100% tests passed, 0 tests failed out of 18

.include <bsd.port.mk>
