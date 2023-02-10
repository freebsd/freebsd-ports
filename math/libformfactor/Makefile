PORTNAME=	libformfactor
DISTVERSION=	0.1.3
CATEGORIES=	math
MASTER_SITES=	https://jugit.fz-juelich.de/mlz/libformfactor/-/archive/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for computation of scattering form factors of polyhedra
WWW=		https://jugit.fz-juelich.de/mlz/libformfactor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libheinz>0:devel/libheinz

USES=		cmake:testing
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

.include <bsd.port.mk>
