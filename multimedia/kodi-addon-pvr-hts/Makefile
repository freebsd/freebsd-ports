# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kodi-addon-pvr-hts
PORTVERSION=	3.4.27
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Tvheadend PVR addon for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/lib/kodi/KodiConfig.cmake:multimedia/kodi
LIB_DEPENDS=	libp8-platform.so:devel/p8-platform \
		libkodiplatform.so:devel/kodi-platform
RUN_DEPENDS=	kodi:multimedia/kodi

USES=		cmake:noninja

USE_GITHUB=	yes
GH_ACCOUNT=	kodi-pvr
GH_PROJECT=	pvr.hts

.include <bsd.port.mk>
