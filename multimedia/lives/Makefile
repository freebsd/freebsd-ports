# New ports collection makefile for:	lives
# Date created:		3 November 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lives
DISTVERSION=	0.9.8.10
CATEGORIES=	multimedia
MASTER_SITES=	http://www.xs4all.nl/%7Esalsaman/lives/current/ CENKES
DISTNAME=	LiVES-${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Video editing system

LIB_DEPENDS=	Magick.10:${PORTSDIR}/graphics/ImageMagick \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		jack.0:${PORTSDIR}/audio/jack \
		visual-0.4.0:${PORTSDIR}/graphics/libvisual04 \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		dv.4:${PORTSDIR}/multimedia/libdv \
		matroska.0:${PORTSDIR}/multimedia/libmatroska \
		oil-0.3.0:${PORTSDIR}/devel/liboil \
		mjpegutils-1.9.1:${PORTSDIR}/multimedia/mjpegtools \
		x264.50:${PORTSDIR}/multimedia/x264
BUILD_DEPENDS=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		sox:${PORTSDIR}/audio/sox \
		transcode:${PORTSDIR}/multimedia/transcode \
		xmms:${PORTSDIR}/multimedia/xmms \
		mpg123:${PORTSDIR}/audio/mpg123 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		sswf:${PORTSDIR}/graphics/sswf \
		${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r

WRKSRC=		${WRKDIR}/${DISTNAME:L}
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PERL5=	yes
USE_CDRTOOLS=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_GHOSTSCRIPT_RUN=	yes
USE_SDL=	yes
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -fPIC
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
LC_MESSAGES_NAMES=	lives
PORT_VERBS=	lives LiVES _encoder.py midistart midistop smogrify sendOSC

post-patch:
	@${REINPLACE_CMD} -e 's|i<FX_KEYS_MAX_VIRTUAL|i<prefs->rte_keys_virtual|' ${WRKSRC}/src/rte_window.c
	@${REINPLACE_CMD} -e '/LIBS/s|-ldl ||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/LDFLAGS/s|-ldl||'\
		${WRKSRC}/lives-plugins/weed-plugins/Makefile.in
	@${REINPLACE_CMD} -e 's|-d alsa|-d oss|' ${WRKSRC}/src/main.c
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|weed-plugins||' ${WRKSRC}/lives-plugins/Makefile.in
	@${REINPLACE_CMD} -e '/^docdir/s|=.*|=${DOCSDIR}|;\
		/update_with_plugins.*install/d' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC}/ -name Makefile.in |\
		${XARGS} ${EGREP} -lm1 '(-O3|-fexpensive-optimizations)' |\
		${XARGS} ${REINPLACE_CMD} -e 's|-O3||;s|-fexpensive-optimizations||'
	@${REINPLACE_CMD} -e 's|\*\.py|*_encoder.py|' ${WRKSRC}/lives-plugins/marcos-encoders/Makefile.in

.include <bsd.port.mk>
