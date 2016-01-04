# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer1-libav
PORTVERSION=	1.6.2
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-libav/
DISTNAME=	gst-libav-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plug-in with many audio/video decoders/encoders

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	orc>=0.4.16:${PORTSDIR}/devel/orc
LIB_DEPENDS=	liborc-0.4.so:${PORTSDIR}/devel/orc \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg

PORTSCOUT=	limitw:1,even

USES=		compiler:features gmake libtool pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libav

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
