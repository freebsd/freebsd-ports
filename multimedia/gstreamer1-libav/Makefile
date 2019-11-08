# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer1-libav
PORTVERSION=	1.14.4
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-libav/
DISTNAME=	gst-libav-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plug-in with many audio/video decoders/encoders

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	orc>=0.4.16:devel/orc
LIB_DEPENDS=	liborc-0.4.so:devel/orc

PORTSCOUT=	limitw:1,even

USES=		compiler:features gettext-runtime gmake gnome libtool localbase \
		pkgconfig python:build tar:xz
USE_LDCONFIG=	yes
USE_GSTREAMER1=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CFLAGS_powerpc64=	-mminimal-toc

OPTIONS_DEFINE=	FFMPEG
OPTIONS_DEFAULT=FFMPEG

FFMPEG_DESC?=	Use system ffmpeg instead of internal libav
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	system-libav
FFMPEG_BUILD_DEPENDS_OFF=	nasm:devel/nasm
FFMPEG_MAKE_ENV_OFF=	V=1
FFMPEG_VARS_OFF+=	NOPRECIOUSMAKEVARS=yes # ARCH

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
