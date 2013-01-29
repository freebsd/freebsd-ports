# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lives
PORTVERSION=	1.8.2
CATEGORIES=	multimedia
MASTER_SITES=	http://salsaman.home.xs4all.nl/lives/current/
DISTNAME=	LiVES-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Video editing system

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:${PORTSDIR}/multimedia/v4l_compat \
		${LOCALBASE}/bin/analyseplugin:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	asound:${PORTSDIR}/audio/alsa-lib \
		FLAC:${PORTSDIR}/audio/flac \
		jack:${PORTSDIR}/audio/jack \
		ogg:${PORTSDIR}/audio/libogg \
		sndfile:${PORTSDIR}/audio/libsndfile \
		vorbis:${PORTSDIR}/audio/libvorbis \
		pulse:${PORTSDIR}/audio/pulseaudio \
		gdbm:${PORTSDIR}/databases/gdbm \
		dbus-1:${PORTSDIR}/devel/dbus \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		oil:${PORTSDIR}/devel/liboil \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		orc:${PORTSDIR}/devel/orc \
		pcre:${PORTSDIR}/devel/pcre \
		aa:${PORTSDIR}/graphics/aalib \
		cairo:${PORTSDIR}/graphics/cairo \
		visual-0.4:${PORTSDIR}/graphics/libvisual04 \
		opencv_calib3d:${PORTSDIR}/graphics/opencv \
		opencv_core:${PORTSDIR}/graphics/opencv-core \
		png15:${PORTSDIR}/graphics/png \
		fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		dv:${PORTSDIR}/multimedia/libdv \
		theora:${PORTSDIR}/multimedia/libtheora \
		vpx:${PORTSDIR}/multimedia/libvpx \
		mjpegutils:${PORTSDIR}/multimedia/mjpegtools \
		schroedinger:${PORTSDIR}/multimedia/schroedinger \
		xvidcore:${PORTSDIR}/multimedia/xvid \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		xcb:${PORTSDIR}/x11/libxcb \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/bin/analyseplugin:${PORTSDIR}/audio/ladspa \
		mpg123:${PORTSDIR}/audio/mpg123 \
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
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
USE_CSTD=	gnu89
USE_ICONV=	yes
USE_PYTHON=	yes
USE_PERL5=	yes
USE_CDRTOOLS=	yes
USE_GHOSTSCRIPT_RUN=	yes
USE_XORG=	ice pixman sm x11 xau xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender xtst
USE_SDL=	sdl
USE_GNOME=	gdkpixbuf2 gtk20
USE_LDCONFIG=	yes
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
	@${REINPLACE_CMD} -e 's| install-docDATA||g; s|-$$(VERSION)||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|: install-data-local |: |g; s|-ldl||' \
		${WRKSRC}/lives-plugins/weed-plugins/gdk/Makefile.in \
		${WRKSRC}/lives-plugins/weed-plugins/Makefile.in
	@${REINPLACE_CMD} -e 's|off64_t|off_t|g ; s|lseek64|lseek|g' \
		${WRKSRC}/src/audio.c \
		${WRKSRC}/lives-plugins/plugins/decoders/dv_decoder.c \
		${WRKSRC}/lives-plugins/plugins/decoders/ogg_decoder.h
	@${REINPLACE_CMD} -e 's|/usr/local/lib/|${LOCALBASE}/lib/|g' \
		${WRKSRC}/lives-plugins/weed-plugins/frei0r.c
	@${REINPLACE_CMD} 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/libweed/Makefile.in
	@${REINPLACE_CMD} 's|/bin/touch|/usr/bin/touch|g' \
		${WRKSRC}/src/callbacks.c \
		${WRKSRC}/src/saveplay.c \
		${WRKSRC}/src/utils.c
	@${REINPLACE_CMD} '/cp -rf/ s|data/|data|g; /cp -rf/ s|icons/|icons|g' \
		${WRKSRC}/lives-plugins/weed-plugins/cairo/Makefile.in \
		${WRKSRC}/lives-plugins/weed-plugins/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
