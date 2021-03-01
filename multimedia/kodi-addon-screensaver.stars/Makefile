# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	screensaver.stars
PORTVERSION=	2.4.0
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Starfield screensaver for Kodi

LICENSE=	GPLv2+

USES=		cmake compiler:c++14-lang gl kodi
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
USE_CXXSTD=	c++14
USE_GL=		egl gl glu

PLIST_SUB=	SOVERSION=${PORTVERSION}

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
