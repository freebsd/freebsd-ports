PORTNAME=	audi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2-1
DISTVERSIONSUFFIX=	-g899eb78
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header only C++ library implementing the algebra of Taylor polynomials
WWW=		http://darioizzo.github.io/audi/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

HPP_DEPENDS=	boost-libs>0:devel/boost-libs \
		obake>0:math/obake
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS}

USES=		cmake:testing compiler:c++20-lang eigen:3,build,run

USE_GITHUB=	yes
GH_ACCOUNT=	darioizzo

CMAKE_OFF=	AUDI_BUILD_TESTS
CMAKE_TESTING_ON=	AUDI_BUILD_TESTS
NO_ARCH=	yes

.include <bsd.port.mk>
