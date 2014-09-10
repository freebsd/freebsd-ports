# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer1-vaapi
PORTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.freedesktop.org/software/vaapi/releases/gstreamer-vaapi/
DISTNAME=	gstreamer-vaapi-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer hardware video decoding via VA-API plug-in

LICENSE=	LGPL21

LIB_DEPENDS=	libva.so:${PORTSDIR}/multimedia/libva

USE_LDCONFIG=	yes
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
USE_GL=		gl
USE_XORG=	x11 xrandr xrender xproto:build
USES=		gmake pkgconfig tar:bzip2
CONFIGURE_ARGS=	--disable-wayland --with-gstreamer-api=1.2
PATHFIX_MAKEFILEIN=	configure

PLIST_SUB=	VERSION=1.2

# manual since pathfix doesn't work.
post-patch:
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/pkgconfig|{prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgst*-1.2.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0/libgstvaapi.so

.include <bsd.port.mk>
