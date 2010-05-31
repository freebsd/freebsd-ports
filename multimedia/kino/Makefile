# New ports collection makefile for:   kino
# Date created:        10 April 2004
# Whom:                pb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kino
PORTVERSION=	1.3.4
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	pb@FreeBSD.org
COMMENT=	A DV non-linear video editor

LIB_DEPENDS=	dv.4:${PORTSDIR}/multimedia/libdv	\
		MagickWand.3:${PORTSDIR}/graphics/ImageMagick	\
		samplerate.1:${PORTSDIR}/audio/libsamplerate
RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mencoder	\
		mplex:${PORTSDIR}/multimedia/mjpegtools

OPTIONS=	QUICKTIME "With Quicktime support" off	\
		FFMPEG_KINO "With ffmpeg-kino" off

USE_XORG=	x11 xv ice
USE_AUTOTOOLS=	autoconf:262
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libglade2 libxml2
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/lqt		\
			-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib/libquicktime	\
			-L${LOCALBASE}/lib"	\
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-dv1394
MAN1=	kino.1 kino2raw.1

.include <bsd.port.pre.mk>

.if defined(WITH_FFMPEG_KINO)
MAN1+=	ffmpeg-kino.1
.endif

.if defined(WITH_QUICKTIME)
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--enable-quicktime
.endif

.if defined(WITH_FFMPEG_KINO)
PLIST_SUB+=	FFMPEG_KINO=""
.else
CONFIGURE_ARGS+=	--disable-local-ffmpeg
PLIST_SUB+=	FFMPEG_KINO="@comment "
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.endif

.include <bsd.port.post.mk>
