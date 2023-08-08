PORTNAME=	screensaver.matrixtrails
PORTVERSION=	20.1.0
DISTVERSIONSUFFIX=	-Nexus
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Matrix trails screensaver for Kodi
WWW=		https://github.com/xbmc/screensaver.matrixtrails

LICENSE=	GPLv2+

USES=		cmake gl kodi

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
USE_GL=		egl gl glu

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
