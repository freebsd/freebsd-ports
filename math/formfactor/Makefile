PORTNAME=	formfactor
DISTVERSION=	0.5.1
CATEGORIES=	math
MASTER_SITES=	https://jugit.fz-juelich.de/mlz/lib/${PORTNAME}/-/archive/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for computation of scattering form factors of polyhedra
WWW=		https://jugit.fz-juelich.de/mlz/lib/formfactor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	heinz>0:devel/heinz

USES=		compiler:c++20-lang cmake:testing
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

# tests as of 0.5.1: 100% tests passed, 0 tests failed out of 19

.include <bsd.port.mk>
