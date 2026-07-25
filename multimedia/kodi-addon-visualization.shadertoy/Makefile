PORTNAME=	visualization.shadertoy
PORTVERSION=	22.1.0.20260525
DISTVERSIONSUFFIX=	-Piers
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Shadertoy visualizer for Kodi
WWW=		https://github.com/xbmc/visualization.shadertoy

LICENSE=	GPLv2+

BUILD_DEPENDS=	glm>0:math/glm

USES=		cmake compiler:c++14-lang gl kodi localbase
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	1c7d847725a3da8b926eff4987dee7fde05e3317
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|delete buffer;|delete[] buffer;|g' \
		${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
