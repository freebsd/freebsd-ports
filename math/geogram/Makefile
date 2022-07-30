PORTNAME=	geogram
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.9
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Programming library of geometric algorithms

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/devkit/license.dox

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	use of inline assembly for these architectures only, at least in src/lib/geogram/basic/atomics.h

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		cmake gl localbase:ldflags xorg
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm
USE_GL=		gl glu
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	alicevision

CMAKE_ON=	GEOGRAM_USE_SYSTEM_GLFW3 VORPALINE_BUILD_DYNAMIC
CMAKE_ARGS=	-DVORPALINE_PLATFORM:STRING=FreeBSD

CFLAGS+=	-fcommon # https://github.com/alicevision/geogram/issues/16
CXXFLAGS+=	-fcommon # https://github.com/alicevision/geogram/issues/16
LDFLAGS+=	-pthread

.include <bsd.port.mk>
