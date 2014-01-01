# Created by: pb@FreeBSD.org
# $FreeBSD$

PORTNAME=	kino
PORTVERSION=	1.3.4
PORTREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DV non-linear video editor

LIB_DEPENDS=	dv.4:${PORTSDIR}/multimedia/libdv	\
		MagickWand:${PORTSDIR}/graphics/ImageMagick	\
		samplerate.1:${PORTSDIR}/audio/libsamplerate
RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mencoder	\
		mplex:${PORTSDIR}/multimedia/mjpegtools

DEPRECATED=	Not developed since 2009, declared dead 05.08.2013 on there website.
EXPIRATION_DATE=	20140130

OPTIONS_DEFINE=	QUICKTIME FFMPEG_KINO
QUICKTIME_DESC=	With Quicktime support
FFMPEG_KINO_DESC=	With ffmpeg-kino

USE_XORG=	x11 xv ice
USE_AUTOTOOLS=	autoconf
USE_GMAKE=	yes
USES=		pathfix gettext iconv
USE_GNOME=	gnomeprefix libglade2 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include/lqt		\
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/libquicktime	\
		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-dv1394
MAN1=	kino.1 kino2raw.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFFMPEG_KINO}
MAN1+=	ffmpeg-kino.1
.endif

.if ${PORT_OPTIONS:MQUICKTIME}
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--enable-quicktime
.endif

.if ${PORT_OPTIONS:MFFMPEG_KINO}
PLIST_SUB+=	FFMPEG_KINO=""
.else
CONFIGURE_ARGS+=	--disable-local-ffmpeg
PLIST_SUB+=	FFMPEG_KINO="@comment "
LIB_DEPENDS+=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
.endif

.include <bsd.port.mk>
