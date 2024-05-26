PORTNAME=	screensaver.biogenesis
PORTVERSION=	21.0.0.20240219
DISTVERSIONSUFFIX=	-Omega
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	BioGenesis screensaver for Kodi
WWW=		https://github.com/xbmc/screensaver.biogenesis

LICENSE=	GPLv2+

USES=		cmake gl kodi
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	953947d07fdf69967e2dc64b289631c57c79e800
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
