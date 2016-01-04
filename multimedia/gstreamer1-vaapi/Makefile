# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer1-vaapi
PORTVERSION=	0.7.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.freedesktop.org/software/vaapi/releases/gstreamer-vaapi/
DISTNAME=	gstreamer-vaapi-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer hardware video decoding via VA-API plug-in

LICENSE=	LGPL21

LIB_DEPENDS=	libva.so:${PORTSDIR}/multimedia/libva

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-wayland \
		--disable-builtin-libvpx --disable-silent-rules
INSTALL_TARGET=	install-strip
USES=		compiler:c11 gmake libtool pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GSTREAMER1=	yes
USE_GL=		gl
USE_XORG=	x11 xrandr xrender xproto:build

PLIST_SUB=	VERSION=1.0 LIBVER=1.6

# manual since pathfix doesn't work.
post-patch:
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/pkgconfig|{prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
