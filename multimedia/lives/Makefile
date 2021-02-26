# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lives
DISTVERSION=	3.2.0
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://lives-video.com/releases/
DISTNAME=	LiVES-${PORTVERSION}

MAINTAINER=	vvd@unislabs.com
COMMENT=	Video editing system

LICENSE=		GPLv3+ LGPL3+
LICENSE_COMB=		multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		analyseplugin:audio/ladspa
LIB_DEPENDS=	liboil-0.3.so:devel/liboil \
		libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg \
		libmjpegutils.so:multimedia/mjpegtools
RUN_DEPENDS=	analyseplugin:audio/ladspa \
		ffprobe:multimedia/ffmpeg \
		sox:audio/sox

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		autoreconf compiler:c++11-lib gettext-runtime gettext-tools \
		gl gnome libtool localbase pathfix perl5 pkgconfig python \
		sdl shebangfix xorg
SHEBANG_FILES=	build-lives-rfx-plugin build-lives-rfx-plugin-multi smogrify \
		tools/autolives.pl lives-plugins/plugins/encoders/*_encoder \
		lives-plugins/marcos-encoders/*encoder* \
		lives-plugins/plugins/encoders/multi_encoder3 \
		lives-plugins/plugins/playback/audiostream/audiostreamer.pl
GNU_CONFIGURE=	yes
USE_XORG=	x11 xrender
USE_GL=		gl glu
USE_SDL=	sdl sdl2
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-ldvgrab --disable-prctl --disable-system-weed
INSTALL_TARGET=	install-strip

DOC_FILES=	AUTHORS COPYING COPYING.LGPL ChangeLog FEATURES GETTING.STARTED NEWS README \
		OMC/lives-OMC.txt RFX/LiVES-Perl.odt RFX/rfxbuilder.odt \
		RFX/RFX.spec docs/c++-bindings.odt docs/clip_format.txt \
		lives-plugins/marcos-encoders/README.multi_encoder \
		weed-docs/weedspec.txt weed-docs/weedevents.txt

OPTIONS_DEFINE=			ALSA DOCS DOXYGEN DV FFTW FREI0R JACK IMAGEMAGICK LIBEXPLAIN \
				LIBVISUAL OGG OPENCV OPTIMIZED_CFLAGS NLS PROJECTM PULSEAUDIO \
				SCHROEDINGER THEORA V4L WAYLAND
OPTIONS_GROUP=			RUNTIME EXT_WIN_CAPTURE MPLAYERS MP3 YOUTUBE_DLX
OPTIONS_GROUP_RUNTIME=		CDDA2WAV GHOSTSCRIPT LAME MATROSKA MENCODER OGG123 OGM \
				SSWF X264 XDG_SCREENSAVER XWININFO
OPTIONS_GROUP_EXT_WIN_CAPTURE=	WMCTRL XDOTOOL
OPTIONS_GROUP_MP3=		MPG123 MPG321
OPTIONS_GROUP_MPLAYERS=		MPLAYER MPV
OPTIONS_GROUP_YOUTUBE_DLX=	YOUTUBE_DL YOUTUBE_DLC
OPTIONS_DEFAULT=		CDDA2WAV DOCS DV FFTW GHOSTSCRIPT IMAGEMAGICK JACK LAME \
				MPG123 MPLAYER NLS OGG OGG123 OGM OPENCV SCHROEDINGER \
				THEORA X264 XDG_SCREENSAVER XDOTOOL XWININFO YOUTUBE_DL
OPTIONS_SUB=			yes

ALSA_CONFIGURE_OFF=		--disable-alsa
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
CDDA2WAV_RUN_DEPENDS=		cdda2wav:sysutils/cdrtools
DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_CONFIGURE_OFF=		--disable-doxygen
DV_CONFIGURE_OFF=		--disable-libdv
DV_LIB_DEPENDS=			libdv.so:multimedia/libdv
DV_RUN_DEPENDS=			encodedv:multimedia/libdv
EXT_WIN_CAPTURE_DESC=		Allows external window capture via xdotool or wmctrl
FFTW_CONFIGURE_OFF=		--disable-fftw3f
FFTW_LIB_DEPENDS=		libfftw3.so:math/fftw3 \
				libfftw3f.so:math/fftw3-float
FREI0R_BUILD_DEPENDS=		frei0r>0:graphics/frei0r
FREI0R_CONFIGURE_OFF=		--disable-frei0r
FREI0R_RUN_DEPENDS=		frei0r>0:graphics/frei0r
GHOSTSCRIPT_USES=		ghostscript:run
IMAGEMAGICK_RUN_DEPENDS=	convert:graphics/ImageMagick${IMAGEMAGICK_DEFAULT} \
				composite:graphics/ImageMagick${IMAGEMAGICK_DEFAULT}
JACK_CONFIGURE_OFF=		--disable-jack
JACK_LIB_DEPENDS=		libjack.so:audio/jack \
				libjackserver.so:audio/jack
LAME_RUN_DEPENDS=		lame:audio/lame
LIBEXPLAIN_CONFIGURE_OFF=	--disable-libexplain
LIBEXPLAIN_DESC=		Used to explain Unix and Linux system call errors
LIBEXPLAIN_LIB_DEPENDS=		libexplain.so:devel/libexplain
LIBVISUAL_CONFIGURE_OFF=	--disable-libvisual
LIBVISUAL_LIB_DEPENDS=		libvisual-0.4.so:graphics/libvisual04
MATROSKA_RUN_DEPENDS=		mkvmerge:multimedia/mkvtoolnix
MENCODER_RUN_DEPENDS=		mencoder:multimedia/mencoder
MENCODER_DESC=			Use mencoder as video file and movie encoder
MP3_DESC=			Runtime check order is: mpg321, mpg123, mplayer, mplayer2, mpv
MPG123_RUN_DEPENDS=		mpg123:audio/mpg123
MPG321_DESC=			MP3 decoding support via mpg321
MPG321_RUN_DEPENDS=		mpg321:audio/mpg321
MPLAYER_RUN_DEPENDS=		mplayer:multimedia/mplayer
MPLAYERS_DESC=			Install mplayer/mpv (runtime check)
MPV_DESC=			MPV media player support
MPV_RUN_DEPENDS=		mpv:multimedia/mpv
NLS_USES=			gettext-tools
OGG_CONFIGURE_OFF=		--disable-ogg
OGG_LIB_DEPENDS=		libogg.so:audio/libogg
OGG123_DESC=			Use ogg123 from vorbis-tools
OGG123_RUN_DEPENDS=		ogg123:audio/vorbis-tools
OGM_DESC=			Use ogmtools for manipulating with OGM files
OGM_RUN_DEPENDS=		ogmmerge:multimedia/ogmtools
OPENCV_CONFIGURE_OFF=		--disable-opencv
OPENCV_LIB_DEPENDS=		libopencv_calib3d.so:graphics/opencv \
				libopencv_core.so:graphics/opencv
SCHROEDINGER_CONFIGURE_OFF=	--disable-dirac
SCHROEDINGER_LIB_DEPENDS=	libschroedinger-1.0.so:multimedia/schroedinger
SSWF_DESC=			Use sswf for manipulating with Flash movies
SSWF_RUN_DEPENDS=		sswf:graphics/sswf
THEORA_CONFIGURE_OFF=		--disable-theora
THEORA_LIB_DEPENDS=		libtheora.so:multimedia/libtheora
OPTIMIZED_CFLAGS_CONFIGURE_ON=	--enable-turbo
PROJECTM_CONFIGURE_OFF=		--disable-projectM
PROJECTM_DESC=			projectM support
PROJECTM_LIB_DEPENDS=		libprojectM.so:graphics/libprojectm
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
RUNTIME_DESC=			Runtime detected utilities
V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_CONFIGURE_OFF=		--disable-v4l
V4L_LIB_DEPENDS=		libv4l2.so:multimedia/libv4l
WAYLAND_CONFIGURE_OFF=		--disable-wayland
WAYLAND_LIB_DEPENDS=		libwayland-client.so:graphics/wayland \
				libwayland-egl.so:graphics/wayland \
				libwayland-cursor.so:graphics/wayland
WMCTRL_DESC=			Install wmctrl
WMCTRL_RUN_DEPENDS=		wmctrl:x11/wmctrl
YOUTUBE_DL_DESC=		Install youtube-dl
YOUTUBE_DL_RUN_DEPENDS=		youtube-dl:www/youtube_dl
YOUTUBE_DLC_DESC=		Install youtube-dlc
YOUTUBE_DLC_RUN_DEPENDS=	youtube-dlc:www/youtube_dlc
YOUTUBE_DLX_DESC=		Install youtube-dl (runtime check)
X264_RUN_DEPENDS=		x264:multimedia/x264
XDG_SCREENSAVER_DESC=		Used to disable screensaver during playback
XDG_SCREENSAVER_RUN_DEPENDS=	xdg-screensaver:devel/xdg-utils
XDOTOOL_DESC=			Install xdotool
XDOTOOL_RUN_DEPENDS=		xdotool:x11/xdotool
XWININFO_DESC=			Used for external window capture
XWININFO_RUN_DEPENDS=		xwininfo:x11/xwininfo

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		's/^LIBS = $$/&@LIBS@/'
	@${REINPLACE_CMD} -e 's|/usr/local/lib/|${LOCALBASE}/lib/|g' \
		${WRKSRC}/lives-plugins/weed-plugins/frei0r.c
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
