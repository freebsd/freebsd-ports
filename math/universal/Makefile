PORTNAME=	universal
DISTVERSIONPREFIX=	v
DISTVERSION=	4.7.2
CATEGORIES=	math
PKGNAMESUFFIX=	-fp-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ template library for universal number arithmetic
WWW=		https://github.com/stillwater-sc/universal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++23-lang

USE_GITHUB=	yes
GH_ACCOUNT=	stillwater-sc

CMAKE_OFF=	UNIVERSAL_ENABLE_TESTS BUILD_DEMONSTRATION BUILD_PLAYGROUND BUILD_EDUCATION BUILD_APPLICATIONS
CMAKE_TESTING_ON=	UNIVERSAL_ENABLE_TESTS UNIVERSAL_BUILD_NUMBER_INTEGERS

OPTIONS_DEFINE=		TOOLS
OPTIONS_SUB=		yes

TOOLS_DESC=		Build command line tools
TOOLS_CMAKE_BOOL=	UNIVERSAL_BUILD_TOOLS_CMD_LINE
TOOLS_VARS_OFF=		NO_ARCH=yes # header-only library w/out executables

# tests as of 4.7.2: 100% tests passed, 0 tests failed out of 38

.include <bsd.port.mk>
