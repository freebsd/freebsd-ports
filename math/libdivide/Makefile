PORTNAME=	libdivide
DISTVERSION=	5.0
PORTREVISION=	1
CATEGORIES=	math

PATCH_SITES=	https://github.com/ridiculousfish/${PORTNAME}/commit/
PATCHFILES+=	fa020f3b3e7ab3e80a2b23ab70bad0f46dbab795.patch:-p1 # https://github.com/ridiculousfish/libdivide/pull/113

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
	${CONFIGURE_WRKSRC}/tester

.include <bsd.port.mk>
