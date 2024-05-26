PORTNAME=	visualization.projectm
PORTVERSION=	21.0.1.20240504
DISTVERSIONSUFFIX=	-Omega
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
GH_TAGNAME=	d39cad13e6e3c2c11f4ba4768d0b27dd890a706f
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
