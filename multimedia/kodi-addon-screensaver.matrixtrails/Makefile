# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	screensaver.matrixtrails
PORTVERSION=	2.6.0
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Matrix trails screensaver for Kodi

LICENSE=	GPLv2+

USES=		cmake gl kodi

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
USE_GL=		egl gl glu

CMAKE_ARGS=	-DADDONS_TO_BUILD=${PORTNAME}

.include <bsd.port.mk>
