# Created by: thierry@pompo.net

PORTNAME=	libdivide
DISTVERSION=	5.0
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Fast prime counting function implementations

LICENSE=	ZLIB BSL
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	ridiculousfish

USES=		cmake compiler:c++11-lang
NO_ARCH=	yes

# NEON support requires arm64
CMAKE_OFF_armv6=	LIBDIVIDE_NEON
CMAKE_OFF_armv7=	LIBDIVIDE_NEON
CMAKE_OFF=	${CMAKE_OFF_${ARCH}}

PLIST_FILES=	include/libdivide.h	\
		lib/cmake/libdivide/libdivideConfig.cmake	\
		lib/cmake/libdivide/libdivideConfigVersion.cmake

do-test:
	${CONFIGURE_WRKSRC}/tester

.include <bsd.port.mk>
