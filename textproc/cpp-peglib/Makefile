PORTNAME=	cpp-peglib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
CATEGORIES=	textproc devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only PEG (Parsing Expression Grammars) library
WWW=		https://github.com/yhirose/cpp-peglib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	yhirose

CMAKE_OFF=	PEGLIB_BUILD_TESTS
CMAKE_TESTING_ON=	PEGLIB_BUILD_TESTS

NO_ARCH=	yes

PLIST_FILES=	include/peglib.h

.include <bsd.port.mk>
