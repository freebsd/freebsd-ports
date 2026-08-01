PORTNAME=	audi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header only C++ library implementing the algebra of Taylor polynomials
WWW=		http://darioizzo.github.io/audi/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.gpl3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.lgpl3

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
