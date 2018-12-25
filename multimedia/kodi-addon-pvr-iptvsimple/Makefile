# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kodi-addon-pvr-iptvsimple
PORTVERSION=	2.4.14
DISTVERSIONSUFFIX=	-Krypton
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	IPTV Live TV and Radio PVR client for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/lib/kodi/KodiConfig.cmake:multimedia/kodi
LIB_DEPENDS=	libp8-platform.so:devel/p8-platform \
		libkodiplatform.so:devel/kodi-platform
RUN_DEPENDS=	kodi:multimedia/kodi

USES=		cmake:noninja

USE_GITHUB=	yes
GH_ACCOUNT=	kodi-pvr
GH_PROJECT=	pvr.iptvsimple

.include <bsd.port.mk>
