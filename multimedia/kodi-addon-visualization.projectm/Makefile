PORTNAME=	visualization.projectm
PORTVERSION=	22.0.3.20260314
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
GH_TAGNAME=	cd73c9f645d63a46009f15c668904efe499365d6
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
