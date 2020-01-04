# $FreeBSD$

PORTNAME=	geogram
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Programming library of geometric algorithms

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/devkit/license.dox

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		cmake gl localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	alicevision
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm
USE_GL=		gl glu
USE_LDCONFIG=	yes

CMAKE_ON=	GEOGRAM_USE_SYSTEM_GLFW3 VORPALINE_BUILD_DYNAMIC
CMAKE_ARGS=	-DVORPALINE_PLATFORM:STRING=FreeBSD
LDFLAGS+=	-pthread

.include <bsd.port.mk>
