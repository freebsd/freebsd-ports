# $FreeBSD$

PORTNAME=	geogram
DISTVERSION=	1.6.9
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/file/37779/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Programming library of geometric algorithms

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/devkit/license.dox

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		cmake:outsource gl localbase:ldflags
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm
USE_GL=		gl glu

CMAKE_ON=	GEOGRAM_USE_SYSTEM_GLFW3
CMAKE_ARGS=	-DVORPALINE_PLATFORM:STRING=FreeBSD
LDFLAGS+=	-pthread

post-stage:
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/geogram1/geogram_gfx/glup_viewer/colormaps

# geogram installs static libraries. I couldn't make it build with shared libraries due to link errors. I asked Bruno.Levy@inria.fr to fix this (via e-mail).

.include <bsd.port.mk>
