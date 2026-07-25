PORTNAME=	screensaver.matrixtrails
PORTVERSION=	22.0.3.20260525
DISTVERSIONSUFFIX=	-Piers
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Matrix trails screensaver for Kodi
WWW=		https://github.com/xbmc/screensaver.matrixtrails

LICENSE=	GPLv2+

USES=		cmake gl kodi

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	79a14cc1ab865f5f65b4076ba038e19da85bb979
USE_GL=		egl gl glu

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
