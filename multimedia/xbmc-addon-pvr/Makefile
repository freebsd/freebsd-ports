# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xbmc-pvr-addons
PORTVERSION=	14.0.20150301
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	XBMC PVR addons for various backends

RUN_DEPENDS+=	kodi:${PORTSDIR}/multimedia/kodi

USE_GITHUB=	yes
GH_ACCOUNT=	opdenkamp
GH_TAGNAME=	4854fbe

USES=		autoreconf libtool pkgconfig
USE_GL=		gl
GNU_CONFIGURE=	yes
REINPLACE_ARGS=	-i ''

CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

post-patch:
	# addons for FreeBSD look for linux platform
	@${REINPLACE_CMD} 's|@OS@|freebsd linux|' \
		${WRKSRC}/addons/*/addon/addon.xml.in
	@${REINPLACE_CMD} 's|-ldl||' \
		${WRKSRC}/addons/pvr.hts/Makefile.am

.include <bsd.port.mk>
