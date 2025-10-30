PORTNAME=	adiak
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
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
GH_TUPLE=	LLNL:blt:655aa8c:blt/blt

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_TESTS
CMAKE_TESTING_ON=	ENABLE_TESTS

# tests as of 0.4.1: 100% tests passed, 0 tests failed out of 2

.include <bsd.port.mk>
