PORTNAME=	screensaver.matrixtrails
PORTVERSION=	21.0.0.20240219
DISTVERSIONSUFFIX=	-Omega
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Matrix trails screensaver for Kodi
WWW=		https://github.com/xbmc/screensaver.matrixtrails

LICENSE=	GPLv2+

USES=		cmake gl kodi

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	364b7275fb02edf9a5c03bd56c8010431711b249
USE_GL=		egl gl glu

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
