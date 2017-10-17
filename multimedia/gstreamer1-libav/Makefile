# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer1-libav
PORTVERSION=	1.12.3
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-libav/
DISTNAME=	gst-libav-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plug-in with many audio/video decoders/encoders

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	orc>=0.4.16:devel/orc
LIB_DEPENDS=	liborc-0.4.so:devel/orc \
		libavcodec.so:multimedia/ffmpeg

PORTSCOUT=	limitw:1,even

USES=		compiler:features gettext-runtime gmake libtool localbase \
		pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GSTREAMER1=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libav

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
