# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lives
PORTVERSION=	2.8.1
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video editing system

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:multimedia/v4l_compat \
		${LOCALBASE}/bin/analyseplugin:audio/ladspa
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libjack.so:audio/jack \
		libogg.so:audio/libogg \
		libpulse.so:audio/pulseaudio \
		liboil-0.3.so:devel/liboil \
		libprojectM.so:graphics/libprojectm \
		libvisual-0.4.so:graphics/libvisual04 \
		libopencv_calib3d.so:graphics/opencv2 \
		libopencv_core.so:graphics/opencv2-core \
		libpng16.so:graphics/png \
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
		convert:graphics/ImageMagick \
		sswf:graphics/sswf \
		mencoder:multimedia/mencoder \
		mplayer:multimedia/mplayer \
		ogmmerge:multimedia/ogmtools \
		transcode:multimedia/transcode \
		x264:multimedia/x264 \
		cdrecord:sysutils/cdrtools

USES=		compiler:c++11-lib gettext-runtime ghostscript:run libtool \
		localbase pathfix perl5 pkgconfig python shebangfix tar:bzip2
SHEBANG_FILES=	build-lives-rfx-plugin build-lives-rfx-plugin-multi \
		smogrify tools/autolives.pl lives-plugins/plugins/encoders/*_encoder \
		lives-plugins/plugins/playback/audiostream/audiostreamer.pl
GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_GL=		gl
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

OPTIONS_DEFINE=	DOCS DOXYGEN FREI0R MATROSKA NLS
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_OFF=	--disable-doxygen
FREI0R_BUILD_DEPENDS=	frei0r>0:graphics/frei0r
FREI0R_RUN_DEPENDS=	frei0r>0:graphics/frei0r
FREI0R_CONFIGURE_ENV_OFF=	ac_cv_header_frei0r_h=no
MATROSKA_RUN_DEPENDS=	mkvmerge:multimedia/mkvtoolnix
NLS_USES=		gettext-tools
NLS_CONFIGURE_OFF=	--disable-nls

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

pre-build-NLS-on:
	@(cd ${WRKSRC}/po && ${DO_MAKE_BUILD} update-po)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} ${DOCSDIR:S|${PREFIX}/||}/html \
		! -type d >> ${TMPPLIST})

.include <bsd.port.mk>
