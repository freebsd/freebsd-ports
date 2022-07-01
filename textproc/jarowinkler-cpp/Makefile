PORTNAME=	jarowinkler-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast Jaro and Jaro Winkler distance C++ header-only library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	maxbachmann

CMAKE_TESTING_ON=	JARO_WINKLER_BUILD_TESTING

NO_ARCH=	yes

.include <bsd.port.mk>
