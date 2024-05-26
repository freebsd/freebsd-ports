PORTNAME=	screensaver.stars
PORTVERSION=	21.0.0.20240219
DISTVERSIONSUFFIX=	-Omega
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Starfield screensaver for Kodi
WWW=		https://github.com/xbmc/screensaver.stars

LICENSE=	GPLv2+

USES=		cmake compiler:c++14-lang gl kodi
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_TAGNAME=	e31111555b41692fd373719a9ba74aba3e7f4790
USE_CXXSTD=	c++14
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
