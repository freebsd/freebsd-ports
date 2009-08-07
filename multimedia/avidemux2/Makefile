# New ports collection makefile for:    avidemux2
# Date created:         16 April 2003
# Whom:                 Anish Mistry
#                       with help from mean
# $FreeBSD$
#

PORTNAME=	avidemux2
PORTVERSION=	2.4.4
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_BERLIOS} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	avidemux
DISTNAME=	avidemux_${PORTVERSION}

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Simple GUI based video editor

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		mad.2:${PORTSDIR}/audio/libmad \
		a52.0:${PORTSDIR}/audio/liba52 \
		png.5:${PORTSDIR}/graphics/png \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

CONFLICTS=	avidemux2-2.[0-35-9].*
# Necessary for CMake to find libs
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

BROKEN=		need a update for Qt 4.5

USE_GNOME=	libxml2
USE_QT_VER=	4
QT_COMPONENTS=

USE_ICONV=	yes
WANT_SDL=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=yes
CMAKE_ARGS+=	-DTHREADS_HAVE_PTHREAD_ARG:STRING="${PTHREAD_LIBS}"

OPTIONS=	GTK "GTK+ GUI" on \
		QT4 "QT4 GUI (Experimental)" off \
		FREETYPE "TrueType font rendering engine" on \
		FONTCONFIG "Font configuration API for X" on \
		OSS "OSS audio device" on \
		ESD "ESOUND audio device" off \
		JACK "JACK audio device" off \
		PULSE "PULSE audio device" off \
		XVIDEO "X Video Extension library" on \
		FAAC "FAAC (mpeg4/aac encoder)" on \
		FAAD "FAAD (mpeg4/aac decoder)" on \
		X264 "H.264 encoding" on \
		XVID "Xvid video" on \
		SDL "SDL audio/video framework" on \
		DCA "DTS Coherent Acoustics decoder" on \
		AMRNB "3GPP AMR Speech Codec" on \
		VORBIS "OGG/Vorbis audio support" on \
		SAMPLERATE "Sample Rate Converter for audio" on \
		NLS "Native languages support" on \
		OPTIMIZED_CFLAGS "build with -O3 for lavcodec" off

.include <bsd.port.pre.mk>

# Package server cannot distribute these
.if defined(PACKAGE_BUILDING)
WITHOUT_LAME=	yes
WITHOUT_FAAC=	yes
WITHOUT_AMRNB=	yes
.endif

# We haven't ALSA(Never) & Aften(Yet) on FreeBSD
CMAKE_ARGS+=	-DNO_ARTS=1 -DNO_ALSA=1 -DNO_Aften=1

.if !defined(WITH_GTK) && !defined(WITH_QT4)
CMAKE_ARGS+=	-DNO_X11=1 -DNO_GTK=1 -DNO_QT4=1
.endif

.if defined(WITHOUT_GTK)
CMAKE_ARGS+=	-DNO_GTK=1
PLIST_SUB+=	GTK="@comment "
.else
USE_GNOME+=	gnomeprefix gnomehack gtk20
PLIST_SUB+=	GTK=""
.endif

.if defined(WITHOUT_QT4)
CMAKE_ARGS+=	-DNO_QT4=1
PLIST_SUB+=	QT4="@comment "
.else
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build linguist_build gui
PLIST_SUB+=	QT4=""
.endif

.if defined(WITH_GTK) || defined(WITH_QT4)
USE_GNOME+=	libxslt desktopfileutils
.endif

.if defined(WITHOUT_OSS)
CMAKE_ARGS+=	-DNO_OSS=1
.endif

.if defined(WITHOUT_ESD)
CMAKE_ARGS+=	-DNO_Esd=1
.else
USE_GNOME+=	esound
.endif

.if defined(WITHOUT_JACK)
CMAKE_ARGS+=	-DNO_Jack=1
.else
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.endif

.if defined(WITHOUT_PULSE)
CMAKE_ARGS+=	-DNO_PULSE_SIMPLE=1
.else
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.endif

.if defined(WITHOUT_FREETYPE)
CMAKE_ARGS+=	-DNO_FREETYPE=1
.else
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.endif

.if defined(WITHOUT_FONTCONFIG)
CMAKE_ARGS+=	-DNO_FontConfig=1
.else
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
.endif

.if defined(WITHOUT_SAMPLERATE)
CMAKE_ARGS+=	-DNO_libsamplerate=1
.else
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
.endif

.if defined(WITHOUT_XVIDEO)
CMAKE_ARGS+=	-DNO_XV=1
.else
LIB_DEPENDS+=	Xv.1:${PORTSDIR}/x11/libXv
.endif

.if defined(WITHOUT_FAAC)
CMAKE_ARGS+=	-DNO_FAAC=1
.else
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
.endif

.if defined(WITHOUT_FAAD)
CMAKE_ARGS+=	-DNO_FAAD=1 -DNO_NeAAC=1
.else
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
.endif

.if defined(WITHOUT_X264)
CMAKE_ARGS+=	-DNO_x264=1
.else
LIB_DEPENDS+=	x264.65:${PORTSDIR}/multimedia/x264
.endif

.if defined(WITHOUT_XVID)
CMAKE_ARGS+=	-DNO_Xvid=1
.else
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
.endif

.if defined(WITHOUT_SDL)
CMAKE_ARGS+=	-DNO_SDL=1
.else
USE_SDL=	sdl
.endif

.if defined(WITHOUT_VORBIS)
CMAKE_ARGS+=	-DNO_Vorbis=1
.else
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITHOUT_DCA)
CMAKE_ARGS+=	-DNO_libdca=1
.else
LIB_DEPENDS+=	dca.0:${PORTSDIR}/multimedia/libdca
.endif

.if defined(WITHOUT_AMRNB)
CMAKE_ARGS+=	-DNO_AMRNB=1
.else
LIB_DEPENDS+=	amrnb.3:${PORTSDIR}/audio/libamrnb
.endif

.if defined(WITHOUT_NLS)
CMAKE_ARGS+=	-DNO_NLS=1
PLIST_SUB+=	NLS="@comment " QT_NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
. 	if !defined(WITH_QT4)
PLIST_SUB+=	QT_NLS="@comment "
.	else
PLIST_SUB+=	QT_NLS=""
.	endif
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-extract:
	@${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' \
		${WRKSRC}/avidemux/ADM_libraries/ADM_mplex/ADM_mplexout.cpp

post-patch:
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/*/*/Makefile
	@${CP} ${FILESDIR}/execinfo.cpp ${WRKSRC}/cmake_compile_check/
	@${REINPLACE_CMD} "s|%%DATADIR%%|${DATADIR}|g" \
	    ${WRKSRC}/avidemux/ADM_userInterfaces/ADM_QT4/ui_support.cpp \
	    ${WRKSRC}/cmake/Ts.cmake
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} "s|-O3|${CFLAGS}|g" ${WRKSRC}/avidemux/ADM_libraries/ADM_lavcodec/Makefile.am
.endif

post-install:
.if defined(WITH_GTK) || defined(WITH_QT4)
	@${MKDIR} "${DATADIR}"
	${INSTALL_DATA} "${WRKSRC}/avidemux_icon.png" "${DATADIR}/${PORTNAME}.png"
	@${ECHO_CMD} "${DATADIR_REL}/${PORTNAME}.png" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/${DATADIR_REL} 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${MKDIR} "${DESKTOPDIR}"
	@${ECHO_CMD} "@cwd ${DESKTOPDIR}" >> ${TMPPLIST}
.if defined(WITH_GTK)
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%DATADIR%%|${DATADIR}|g" \
	    -e "s|%%NAME%%|${PORTNAME}|g" -e "s|%%API%%|gtk|g" \
	    < ${FILESDIR}/avidemux2.desktop.in > ${WRKDIR}/${PORTNAME}.desktop
	${INSTALL_DATA} "${WRKDIR}/${PORTNAME}.desktop" "${DESKTOPDIR}"
	@${ECHO_CMD} "${PORTNAME}.desktop" >> ${TMPPLIST}
.endif
.if defined(WITH_QT4)
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%DATADIR%%|${DATADIR}|g" \
	    -e "s|%%NAME%%|${PORTNAME}|g" -e "s|%%API%%|qt4|g" \
	    < ${FILESDIR}/avidemux2.desktop.in > ${WRKDIR}/${PORTNAME}_qt4.desktop
	${INSTALL_DATA} "${WRKDIR}/${PORTNAME}_qt4.desktop" "${DESKTOPDIR}"
	@${ECHO_CMD} "${PORTNAME}_qt4.desktop" >> ${TMPPLIST}
.endif
	@${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} ${DESKTOPDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec %D/bin/update-desktop-database 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec %D/bin/update-desktop-database 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	-update-desktop-database
.endif

.include <bsd.port.post.mk>
