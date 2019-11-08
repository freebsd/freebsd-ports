# $FreeBSD$

PORTNAME=	mlt
DISTVERSIONPREFIX=	v
DISTVERSION=	6.16.0
PORTREVISION?=	2
CATEGORIES?=	multimedia

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	Multimedia framework for TV broadcasting

LICENSE?=	GPLv2 GPLv3 LGPL21
LICENSE_COMB?=	multi

USES+=		alias compiler:c++11-lang eigen:3 gmake gnome localbase \
		pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-gpl --enable-gpl3 --target-os=FreeBSD
USE_GITHUB=	yes
GH_ACCOUNT=	mltframework

.ifndef(WITH_DEBUG)
CONFIGURE_ARGS+=--disable-debug
.else
CONFIGURE_ARGS+=--enable-debug
.endif

.ifndef(SLAVEPORT) # Master port.

# They both install bin/melt.
CONFLICTS_INSTALL=	freeze-[0-9]*

LIB_DEPENDS=	libfftw3.so:math/fftw3

BROKEN_sparc64=		does not compile on sparc64 (invokes i386 asm)

USE_GL=		gl
USE_GNOME=	libxml2
USE_SDL=	image2
USE_XORG=	x11
USES+=		gl iconv pathfix sdl xorg
PATHFIX_MAKEFILEIN=	Makefile
CONFIGURE_ARGS+=--disable-qt --swig-languages=none
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

PORTDOCS=	AUTHORS ChangeLog NEWS README docs
PORTEXAMPLES=	demo

OPTIONS_DEFINE=	DOCS EXAMPLES FFMPEG FREI0R GTK2 JACK OPENGL \
		SAMPLERATE SOX SWFDEC VIDSTAB # OPENCV VDPAU
OPTIONS_DEFAULT=FFMPEG FREI0R GTK2 OPENGL SAMPLERATE SOX SWFDEC VIDSTAB
OPTIONS_SUB=	yes

GTK2_DESC=	Images and text rendering via GTK+ 2
SOX_DESC=	SoX audio effects support
VIDSTAB_DESC=	Video stabilization support via Vid.Stab

FFMPEG_SUFX=		# Currently empty.
FFMPEG_LIB_DEPENDS=	libavformat${FFMPEG_SUFX}.so:multimedia/ffmpeg${FFMPEG_SUFX}
FFMPEG_CONFIGURE_ENABLE=avformat
FFMPEG_CONFIGURE_ON=	--avformat-suffix="${FFMPEG_SUFX}"

FREI0R_BUILD_DEPENDS=	${LOCALBASE}/include/frei0r.h:graphics/frei0r
FREI0R_CONFIGURE_ENABLE=frei0r

GTK2_LIB_DEPENDS=	libexif.so:graphics/libexif \
			libfontconfig.so:x11-fonts/fontconfig
GTK2_USE=		GNOME=gdkpixbuf2,gtk20,pango
GTK2_CONFIGURE_ENABLE=	gtk2

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
JACK_CONFIGURE_ENABLE=	jackrack
JACK_USE=		GNOME=glib20

# Prepare for OpenCV 3 port.
CONFIGURE_ARGS+=	--disable-opencv
OPENCV_CONFIGURE_ENABLE=opencv

OPENGL_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
			libmovit.so:graphics/movit
OPENGL_USE=		GL=gl
OPENGL_CONFIGURE_ENABLE=opengl

SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=resample

SOX_LIB_DEPENDS=	libsox.so:audio/sox
SOX_CONFIGURE_ENABLE=	sox

SWFDEC_LIB_DEPENDS=	libswfdec-0.8.so:graphics/swfdec
SWFDEC_CONFIGURE_ENABLE=swfdec
SWFDEC_USE=		GNOME=glib20,cairo

# https://sourceforge.net/p/mlt/bugs/240/
CONFIGURE_ARGS+=	${VDPAU_CONFIGURE_OFF}
VDPAU_CONFIGURE_ON=	--avformat-vdpau
VDPAU_CONFIGURE_OFF=	--avformat-no-vdpau

VIDSTAB_LIB_DEPENDS=	libvidstab.so:multimedia/vid.stab
VIDSTAB_CONFIGURE_ENABLE=vid.stab

pre-configure:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' \
		${WRKSRC}/src/modules/avformat/vdpau.c \
		${WRKSRC}/src/modules/frei0r/factory.c \
		${WRKSRC}/src/modules/jackrack/plugin_mgr.c
	@${REINPLACE_CMD} -e 's,-lpthread,-pthread,' \
			-e 's,-liconv,${ICONV_LIB},' \
		${WRKSRC}/src/framework/Makefile \
		${WRKSRC}/src/melt/Makefile \
		${WRKSRC}/src/modules/*/Makefile

common-post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/melt.1 ${STAGEDIR}${MANPREFIX}/man/man1/melt.1
	@${RM} ${WRKSRC}/docs/melt.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/melt
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmlt.so.${PORTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmlt++.so.${PORTVERSION}

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

LIB_DEPENDS+=	libmlt.so:${MASTER_PORT}

PLIST?=		${.CURDIR}/pkg-plist

. if ${SLAVEPORT:Mqt*} # Qt slave port.
PKGNAMESUFFIX=	-${SLAVEPORT}

COMMENT=	Qt ${SLAVEPORT:C/[^0-9]//g} plugin for the MLT multimedia framework

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi

LIB_DEPENDS+=	libexif.so:graphics/libexif

CONFIGURE_ARGS+=--enable-qt \
		--qt-libdir="${QT_LIBDIR}" \
		--qt-includedir="${QT_INCDIR}"
BUILD_WRKSRC=	${WRKSRC}/src/modules/qt
. elif ${SLAVEPORT:Mswig} # SWIG slave port.
LANGUAGE=	${SLAVEPORT:Nswig}

COMMENT=	${LANGUAGE} bindings for the MLT multimedia framework

LICENSE=	LGPL21
LICENSE_COMB=	single

BUILD_DEPENDS+=	swig3.0:devel/swig30
BINARY_ALIAS=	swig=swig3.0

_CFLAGS=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
CFLAGS+=	${_CFLAGS}
CXXFLAGS+=	${_CFLAGS}
CONFIGURE_ARGS+=--swig-languages=${LANGUAGE:tl}
BUILD_WRKSRC=	${WRKSRC}/src/swig
INSTALL_WRKSRC=	${BUILD_WRKSRC}/${LANGUAGE:tl}

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}/${LANGUAGE:tl}
. endif

INSTALL_WRKSRC?=${BUILD_WRKSRC}

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}

# Dummy placeholder target.
common-post-install:
	@${TRUE}

.endif

post-install: common-post-install
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/* 2>/dev/null || ${TRUE}
	@${RMDIR} -p ${STAGEDIR}${PREFIX}/lib/${PORTNAME} 2>/dev/null || ${TRUE}

.include <bsd.port.mk>
