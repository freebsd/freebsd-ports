PORTNAME=	ncrystal
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.6
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for thermal neutron transport in crystals and other materials
WWW=		https://github.com/mctools/ncrystal

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# ncrystal-4.4.4/ncrystal_core/src/core/NCDefs.cc:25:18: error:
# static assertion failed due to requirement 'std::numeric_limits<unsigned int>::max() >=
# std::numeric_limits<unsigned long long>::max()': NCrystal is no longer supported on 32bit systems
NOT_FOR_ARCHS=	armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	NCrystal is no longer supported on 32bit systems

USES=		cmake:testing python:build,test
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mctools

CMAKE_TESTING_ON=	NCRYSTAL_ENABLE_TESTING \
			NCRYSTAL_ENABLE_CORE_TEST

# tests as of 4.4.6: 100% tests passed, 0 tests failed out of 127

.include <bsd.port.mk>
