# New ports collection makefile for:   kino
# Date created:        10 April 2004
# Whom:                pb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kino
PORTVERSION=	1.0.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pb@FreeBSD.org
COMMENT=	A DV non-linear video editor

LIB_DEPENDS=	dv.4:${PORTSDIR}/multimedia/libdv	\
		Magick.10:${PORTSDIR}/graphics/ImageMagick	\
		samplerate.1:${PORTSDIR}/audio/libsamplerate
RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mplayer	\
		mplex:${PORTSDIR}/multimedia/mjpegtools

OPTIONS=	QUICKTIME "With Quicktime support" off	\
		FFMPEG_KINO "With ffmpeg-kino" on

USE_AUTOTOOLS=	autoconf:259
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libglade2 libxml2
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/lqt		\
			-I${LOCALBASE}/include -I${X11BASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib/libquicktime	\
			-L${LOCALBASE}/lib -L${X11BASE}/lib"	\
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-dv1394
MAN1=	ffmpeg-kino.1 kino.1 kino2raw.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	Does not compile on FreeBSD 4.x
.endif

.if defined(WITH_QUICKTIME)
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=	--with-quicktime
.endif

.if defined(WITH_FFMPEG_KINO)
PLIST_SUB+=	FFMPEG_KINO=""
.else
CONFIGURE_ARGS+= --disable-local-ffmpeg
PLIST_SUB+=	FFMPEG_KINO="@comment "
LIB_DEPENDS+=	avcodec.1:$(PORTSDIR)/multimedia/ffmpeg-devel
.endif

.include <bsd.port.post.mk>
