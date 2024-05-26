PORTNAME=	visualization.shadertoy
PORTVERSION=	21.0.0.20240219
DISTVERSIONSUFFIX=	-Omega
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
GH_TAGNAME=	364132b12b6da78e281b6a1d678155d43aace83f
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|delete buffer;|delete[] buffer;|g' \
		${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
