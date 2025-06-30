PORTNAME=	${_MLT_PORTNAME}
DISTVERSION=	${_MLT_VERSION}
PORTREVISION?=	1
CATEGORIES?=	multimedia
MASTER_SITES=	https://github.com/mltframework/mlt/releases/download/v${DISTVERSION}/
DISTFILES=	mlt-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	Multimedia framework for TV broadcasting
WWW=		https://www.mltframework.org/

LICENSE?=	GPLv2 GPLv3 LGPL21
LICENSE_COMB?=	multi

USES+=		alias cmake compiler:c++11-lang eigen:3 localbase \
		pathfix pkgconfig
USE_LDCONFIG=	yes

# Suppress errors with lld >= 17 due to undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

DATADIR=	${PREFIX}/share/mlt-7

WRKSRC=		${WRKDIR}/mlt-${DISTVERSION}

.ifndef(SLAVEPORT) # Master port.
USES+=		gnome mlt:7,nodepend
USE_GNOME=	libxml2

CMAKE_ON=	MOD_XML

# Explicitly disabled modules that are ouddated, unnecessary, or have
# their own port.
CMAKE_OFF=	MOD_GLAXNIMATE MOD_GLAXNIMATE_QT6 MOD_SDL1 MOD_QT \
		MOD_QT6 MOD_NDI \
		SWIG_CSHARP SWIG_JAVA SWIG_LUA SWIG_NODEJS SWIG_PERL \
		SWIG_PHP SWIG_PYTHON SWIG_RUBY SWIG_TCL

PORTDOCS=	AUTHORS NEWS
PORTEXAMPLES=	demo

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	AVFORMAT FREI0R GDK MOVIT KDENLIVE NORMALIZE PLUS PLUSGPL RESAMPLE SDL2 SOX \
			VIDSTAB VORBIS

OPTIONS_GROUP=		MODULES
OPTIONS_GROUP_MODULES=	AVFORMAT DECKLINK FREI0R GDK JACKRACK KDENLIVE MOVIT NORMALIZE \
			OLDFILM OPENCV PLUS PLUSGPL RESAMPLE RTAUDIO RUBBERBAND SDL2 \
			SOX VIDSTAB VORBIS XINE
OPTIONS_SUB=		yes

AVFORMAT_DESC=		Enable avformat module
AVFORMAT_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
AVFORMAT_CMAKE_BOOL=	MOD_AVFORMAT

DECKLINK_DESC=		Enable decklink module
DECKLINK_CMAKE_BOOL=	MOD_DECKLINK

FREI0R_DESC=		Enable frei0r module
FREI0R_BUILD_DEPENDS=	${LOCALBASE}/include/frei0r.h:graphics/frei0r
FREI0R_CMAKE_BOOL=	MOD_FREI0R

GDK_DESC=		Enable gdk module
GDK_LIB_DEPENDS=	libexif.so:graphics/libexif \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz
GDK_USE=		gnome=gdkpixbuf,pango
GDK_CMAKE_BOOL=		MOD_GDK

JACKRACK_DESC=		Enable jackrack module
JACKRACK_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
JACKRACK_LIB_DEPENDS=	libjack.so:audio/jack \
			liblilv-0.so:audio/lilv
JACKRACK_USE=		gnome=glib20
JACKRACK_CMAKE_BOOL=	MOD_JACKRACK

KDENLIVE_DESC=		Enable kdenlive module
KDENLIVE_CMAKE_BOOL=	MOD_KDENLIVE

MOVIT_DESC=		Enable Movit module
MOVIT_USES=		gl xorg
MOVIT_USE=		gl=opengl xorg=x11
MOVIT_LIB_DEPENDS=	libmovit.so:graphics/movit \
			libepoxy.so:graphics/libepoxy
MOVIT_CMAKE_BOOL=	MOD_MOVIT

NORMALIZE_DESC=		Enable normalize module
NORMALIZE_CMAKE_BOOL=	MOD_NORMALIZE

OLDFILM_DESC=		Enable oldfilm module
OLDFILM_CMAKE_BOOL=	MOD_OLDFILM

OPENCV_DESC=		Enable OpenCV module
OPENCV_LIB_DEPENDS=	libopencv_core.so:graphics/opencv
OPENCV_CMAKE_BOOL=	MOD_OPENCV

PLUSGPL_DESC=		Enable plus GPL module
PLUSGPL_CMAKE_BOOL=	MOD_PLUSGPL

PLUS_DESC=		Enable plus module
PLUS_USES=		ebur128
PLUS_LIB_DEPENDS=	libfftw3.so:math/fftw3
PLUS_CMAKE_BOOL=	MOD_PLUS

RESAMPLE_DESC=		Enable resample module
RESAMPLE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
RESAMPLE_CMAKE_BOOL=	MOD_RESAMPLE

RTAUDIO_DESC=		Enable RtAudio module
RTAUDIO_LIB_DEPENDS=	librtaudio.so:audio/rtaudio
RTAUDIO_CMAKE_BOOL=	MOD_RTAUDIO

RUBBERBAND_DESC=	Enable rubberband module
RUBBERBAND_LIB_DEPENDS=	librubberband.so:audio/rubberband
RUBBERBAND_CMAKE_BOOL=	MOD_RUBBERBAND

SDL2_DESC=		Enable SDL2 module
SDL2_USES=		sdl
SDL2_USE=		sdl=sdl2
SDL2_CMAKE_BOOL=	MOD_SDL2

SOX_DESC=		Enable SoX module
SOX_LIB_DEPENDS=	libsox.so:audio/sox
SOX_CMAKE_BOOL=		MOD_SOX

VIDSTAB_DESC=		Enable vid.stab module
VIDSTAB_LIB_DEPENDS=	libvidstab.so:multimedia/vid.stab
VIDSTAB_CMAKE_BOOL=	MOD_VIDSTAB

VORBIS_DESC=		Enable Vorbis module
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CMAKE_BOOL=	MOD_VORBIS

XINE_DESC=		Enable xine module
XINE_CMAKE_BOOL=	MOD_XINE

pre-configure:
	${RM} ${STAGEDIR}${PREFIX}/man/man1/melt.1

common-post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/melt-7
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmlt-7.so.${PORTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmlt++-7.so.${PORTVERSION}

post-install-DOCS-on:
.for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
.for f in ${PORTEXAMPLES}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.else # Slave port.
PORTSCOUT=	ignore:1

# Depend on multimedia/mlt7 for child ports
USES+=		mlt:7
PLIST?=		${.CURDIR}/pkg-plist

INSTALL_WRKSRC?=	${BUILD_WRKSRC}
.endif

post-install: common-post-install
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/* 2>/dev/null || ${TRUE}
	@${RMDIR} -p ${STAGEDIR}${PREFIX}/lib/${PORTNAME} 2>/dev/null || ${TRUE}

.include <bsd.port.mk>
