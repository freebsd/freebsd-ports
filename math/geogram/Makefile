# $FreeBSD$

PORTNAME=	geogram
DISTVERSION=	1.6.9
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/file/37779/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Programming library of geometric algorithms

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/devkit/license.dox

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		cmake gl localbase:ldflags
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm
USE_GL=		gl glu
USE_LDCONFIG=	yes

CMAKE_ON=	GEOGRAM_USE_SYSTEM_GLFW3 VORPALINE_BUILD_DYNAMIC
CMAKE_ARGS=	-DVORPALINE_PLATFORM:STRING=FreeBSD
LDFLAGS+=	-pthread

post-stage:
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/geogram1/geogram_gfx/glup_viewer/colormaps

.include <bsd.port.mk>
