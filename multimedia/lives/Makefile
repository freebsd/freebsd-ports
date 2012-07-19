# New ports collection makefile for:	lives
# Date created:		3 November 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lives
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://salsaman.home.xs4all.nl/lives/current/
DISTNAME=	LiVES-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Video editing system

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		oil-0.3.0:${PORTSDIR}/devel/liboil \
		visual-0.4.0:${PORTSDIR}/graphics/libvisual04 \
		dv.4:${PORTSDIR}/multimedia/libdv \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		mjpegutils-2.0.0:${PORTSDIR}/multimedia/mjpegtools \
		pulse:${PORTSDIR}/audio/pulseaudio \
		schroedinger-1.0:${PORTSDIR}/multimedia/schroedinger \
		asound:${PORTSDIR}/audio/alsa-lib \
		avcodec:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		sox:${PORTSDIR}/audio/sox \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		convert:${PORTSDIR}/graphics/ImageMagick \
		sswf:${PORTSDIR}/graphics/sswf \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		transcode:${PORTSDIR}/multimedia/transcode \
		x264:${PORTSDIR}/multimedia/x264 \
		xmms:${PORTSDIR}/multimedia/xmms

WRKSRC=		${WRKDIR}/${DISTNAME:L}

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gtk20 gnomehack
USE_SDL=	sdl
USE_PYTHON=	yes
USE_PERL5=	yes
USE_CDRTOOLS=	yes
USE_GHOSTSCRIPT_RUN=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--disable-ldvgrab

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

DOC_FILES=	AUTHORS BUGS ChangeLog FEATURES GETTING.STARTED README \
		OMC/lives-OMC.txt \
		RFX/LiVES-Perl.odt RFX/rfxbuilder.odt RFX/RFX.spec \
		docs/clip_format.txt \
		lives-plugins/marcos-encoders/README.multi_encoder \
		weed-docs/weedspec.txt weed-docs/weedevents.txt

PORT_VERBS=	lives LiVES _encoder.py midistart midistop smogrify sendOSC

OPTIONS_DEFINE=	DOXYGEN FREI0R
FREI0R_DESC=	Enable frei0r support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
PORTDOCS=	html
.else
CONFIGURE_ARGS+=--disable-doxygen
.endif

.if ${PORT_OPTIONS:MFREI0R}
BUILD_DEPENDS+=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
RUN_DEPENDS+=	${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r
PLIST_SUB+=	FREI0R=""
.else
CONFIGURE_ENV+=	ac_cv_header_frei0r_h=no
PLIST_SUB+=	FREI0R="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/s|-ldl ||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| install-docDATA||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|: install-data-local |: |g' \
		${WRKSRC}/lives-plugins/weed-plugins/gdk/Makefile.in \
		${WRKSRC}/lives-plugins/weed-plugins/Makefile.in
	@${REINPLACE_CMD} -e 's|off64_t|off_t|g ; s|lseek64|lseek|g' \
		${WRKSRC}/src/audio.c \
		${WRKSRC}/lives-plugins/plugins/decoders/dv_decoder.c \
		${WRKSRC}/lives-plugins/plugins/decoders/ogg_decoder.h
	@${REINPLACE_CMD} -e 's|/usr/local/lib/|${LOCALBASE}/lib/|g' \
		${WRKSRC}/lives-plugins/weed-plugins/frei0r.c
	@${FIND} ${WRKSRC} -name "Makefile.in" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		'/FLAGS/s|-O3||g ; \
		 /FLAGS/s|-ldl||g ; \
		 /flags/s|-L/usr/lib64||g ; \
		 /flags/s|-Wl,-Bsymbolic||g ; \
		 /flags/s|--tag=disable-static||g'
	@${REINPLACE_CMD} -e 's|-$$(VERSION)||g' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} 's|/bin/touch|/usr/bin/touch|g' \
		${WRKSRC}/smogrify \
		${WRKSRC}/src/callbacks.c \
		${WRKSRC}/src/saveplay.c \
		${WRKSRC}/src/utils.c

pre-build:
	@cd ${WRKSRC}/po; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} update-po

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
