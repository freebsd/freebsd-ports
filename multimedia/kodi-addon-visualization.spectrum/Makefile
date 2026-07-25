PORTNAME=	visualization.spectrum
PORTVERSION=	22.1.0.20260528
DISTVERSIONSUFFIX=	-Piers
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Spectrum visualizer for Kodi
WWW=		https://github.com/xbmc/visualization.spectrum

LICENSE=	GPLv2+

BUILD_DEPENDS=	glm>0:math/glm

USES=		cmake compiler:c++14-lang gl kodi localbase
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	35402d2e5809a448e2b640b5967e1bb1c369639d
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
