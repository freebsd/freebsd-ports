# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lives
PORTVERSION=	2.10.2
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	http://lives-video.com/releases/
DISTNAME=	LiVES-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video editing system

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		${LOCALBASE}/bin/analyseplugin:audio/ladspa
LIB_DEPENDS=	libogg.so:audio/libogg \
		liboil-0.3.so:devel/liboil \
		libvisual-0.4.so:graphics/libvisual04 \
		libopencv_calib3d.so:graphics/opencv \
		libopencv_core.so:graphics/opencv-core \
		libpng.so:graphics/png \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libavcodec.so:multimedia/ffmpeg \
		libdv.so:multimedia/libdv \
		libtheora.so:multimedia/libtheora \
		libmjpegutils.so:multimedia/mjpegtools \
		libschroedinger-1.0.so:multimedia/schroedinger
RUN_DEPENDS=	${LOCALBASE}/bin/analyseplugin:audio/ladspa \
		mpg123:audio/mpg123 \
		sox:audio/sox \
		ogg123:audio/vorbis-tools \
		convert:graphics/ImageMagick6 \
		sswf:graphics/sswf \
		mencoder:multimedia/mencoder \
		mplayer:multimedia/mplayer \
		ogmmerge:multimedia/ogmtools \
		transcode:multimedia/transcode \
		x264:multimedia/x264 \
		cdrecord:sysutils/cdrtools

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		autoreconf compiler:c++11-lib gettext-runtime gettext-tools \
		ghostscript:run gl gnome \
		libtool localbase pathfix perl5 pkgconfig python sdl \
		shebangfix tar:bzip2 xorg
SHEBANG_FILES=	build-lives-rfx-plugin build-lives-rfx-plugin-multi \
		smogrify tools/autolives.pl lives-plugins/plugins/encoders/*_encoder \
		lives-plugins/marcos-encoders/*encoder* \
		lives-plugins/plugins/encoders/multi_encoder3 \
		lives-plugins/plugins/playback/audiostream/audiostreamer.pl
GNU_CONFIGURE=	yes
USE_XORG=	x11 xrender
USE_GL=		gl glu
USE_SDL=	sdl
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-ldvgrab
INSTALL_TARGET=	install-strip

DOC_FILES=	AUTHORS BUGS ChangeLog FEATURES GETTING.STARTED README \
		OMC/lives-OMC.txt RFX/LiVES-Perl.odt RFX/rfxbuilder.odt \
		RFX/RFX.spec docs/clip_format.txt \
		lives-plugins/marcos-encoders/README.multi_encoder \
		weed-docs/weedspec.txt weed-docs/weedevents.txt

OPTIONS_DEFINE=	ALSA DOCS DOXYGEN FREI0R JACK MATROSKA V4L NLS PROJECTM PULSEAUDIO
OPTIONS_SUB=	yes

ALSA_CONFIGURE_OFF=	--disable-alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_OFF=	--disable-doxygen
FREI0R_BUILD_DEPENDS=	frei0r>0:graphics/frei0r
FREI0R_RUN_DEPENDS=	frei0r>0:graphics/frei0r
FREI0R_CONFIGURE_ENV_OFF=ac_cv_header_frei0r_h=no
JACK_CONFIGURE_OFF=	--disable-jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack
MATROSKA_RUN_DEPENDS=	mkvmerge:multimedia/mkvtoolnix
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
NLS_USES=		gettext-tools
NLS_CONFIGURE_OFF=	--disable-nls
PROJECTM_DESC=		projectM support
PROJECTM_CONFIGURE_OFF=	--disable-projectM
PROJECTM_LIB_DEPENDS=	libprojectM.so:graphics/libprojectm
PULSEAUDIO_CONFIGURE_OFF=--disable-pulse
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		's/^LIBS = $$/&@LIBS@/'
	@${REINPLACE_CMD} -e 's| install-docDATA||g; s|-$$(VERSION)||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|: install-data-local |: |g; s|-ldl||' \
		${WRKSRC}/lives-plugins/weed-plugins/gdk/Makefile.in \
		${WRKSRC}/lives-plugins/weed-plugins/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/local/lib/|${LOCALBASE}/lib/|g' \
		${WRKSRC}/lives-plugins/weed-plugins/frei0r.c
	@${REINPLACE_CMD} '/cp -rf/ s|data/|data|g; /cp -rf/ s|icons/|icons|g' \
		${WRKSRC}/lives-plugins/weed-plugins/cairo/Makefile.in \
		${WRKSRC}/lives-plugins/weed-plugins/Makefile.in
	@${REINPLACE_CMD} '/selectRandom/d' \
		${WRKSRC}/lives-plugins/weed-plugins/projectM.cpp
	@${REINPLACE_CMD} 's|/usr/bin/perl|${perl_CMD}|' \
		${WRKSRC}/build-lives-rfx-plugin

pre-build-NLS-on:
	@(cd ${WRKSRC}/po && ${DO_MAKE_BUILD} update-po)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} ${DOCSDIR_REL}/html \
		-not -type d >> ${TMPPLIST})

.include <bsd.port.mk>
