PORTNAME=	screensaver.biogenesis
PORTVERSION=	22.0.3.20260227
DISTVERSIONSUFFIX=	-Piers
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	BioGenesis screensaver for Kodi
WWW=		https://github.com/xbmc/screensaver.biogenesis

LICENSE=	GPLv2+

USES=		cmake gl kodi
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	11fcf624ef3d94b77e3ee86883bed0823dbf9f39
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
