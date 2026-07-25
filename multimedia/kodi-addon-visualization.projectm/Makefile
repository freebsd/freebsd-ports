PORTNAME=	visualization.projectm
PORTVERSION=	22.2.0.20260531
DISTVERSIONSUFFIX=	-Piers
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	ProjectM visualizer for Kodi
WWW=		https://github.com/xbmc/visualization.projectm

LICENSE=	GPLv2+

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libprojectM.so:graphics/libprojectm

USES=		cmake compiler:c++14-lang gl kodi localbase
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	047d05e4f711895f7ec95e9121c07d41843b7cb3
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
