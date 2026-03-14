PORTNAME=	cpp-peglib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
CATEGORIES=	textproc devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only PEG (Parsing Expression Grammars) library
WWW=		https://github.com/yhirose/cpp-peglib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	yhirose

CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS

NO_ARCH=	yes

PLIST_FILES=	include/peglib.h

# tests as of 1.10.1: 100% tests passed, 0 tests failed out of 382

.include <bsd.port.mk>
