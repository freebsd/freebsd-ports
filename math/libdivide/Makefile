PORTNAME=	libdivide
DISTVERSIONPREFIX=v
DISTVERSION=	5.3.0
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Fast prime counting function implementations
WWW=		https://libdivide.com/

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

OPTIONS_DEFINE=		NATIVE

NATIVE_CMAKE_BOOL=	FREEBSD_NATIVE

do-test:
	${CONFIGURE_WRKSRC}/OFFtester

.include <bsd.port.mk>
