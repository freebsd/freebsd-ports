PORTNAME=	cpp-peglib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	textproc devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only PEG (Parsing Expression Grammars) library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	yhirose

CMAKE_TESTING_ON=	FREEBSD_BUILD_TESTS

NO_ARCH=	yes

PLIST_FILES=	include/peglib.h

.include <bsd.port.mk>
