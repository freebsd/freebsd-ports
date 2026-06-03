PORTNAME=	screensaver.matrixtrails
PORTVERSION=	22.0.1.20260227
DISTVERSIONSUFFIX=	-Piers
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Matrix trails screensaver for Kodi
WWW=		https://github.com/xbmc/screensaver.matrixtrails

LICENSE=	GPLv2+

USES=		cmake gl kodi

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	a2b9066437ccaeabcccaa6594f5d40606be5b3c6
USE_GL=		egl gl glu

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
