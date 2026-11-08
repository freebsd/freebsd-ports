PORTNAME=	adiak
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Standard interface for collecting HPC run metadata
WWW=		https://software.llnl.gov/Adiak/ \
		https://github.com/LLNL/Adiak

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	Adiak
GH_TUPLE=	LLNL:blt:e783e30f2823ee1a208f7f90741b41c1f5a08063:blt/blt

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_TESTS
CMAKE_TESTING_ON=	ENABLE_TESTS

# tests as of 0.5.0: 100% tests passed, 0 tests failed out of 2

.include <bsd.port.mk>
