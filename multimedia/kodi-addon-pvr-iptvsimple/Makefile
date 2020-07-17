# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kodi-addon-pvr-iptvsimple
PORTVERSION=	3.9.8
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	IPTV Live TV and Radio PVR client for Kodi

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/kodi/libXBMC_addon.h:multimedia/kodi \
		${LOCALBASE}/include/rapidxml.hpp:textproc/rapidxml
LIB_DEPENDS=	libp8-platform.so:devel/p8-platform \
		libkodiplatform.so:devel/kodi-platform
RUN_DEPENDS=	kodi:multimedia/kodi

USES=		cmake:noninja

USE_GITHUB=	yes
GH_ACCOUNT=	kodi-pvr
GH_PROJECT=	pvr.iptvsimple
GH_TAGNAME=	${PORTVERSION}-Leia

post-patch:
	@${REINPLACE_CMD} 's|rapidxml/rapidxml.hpp|rapidxml.hpp|' \
		${WRKSRC}/FindRapidxml.cmake \
		${WRKSRC}/src/PVRIptvData.cpp

.include <bsd.port.mk>
