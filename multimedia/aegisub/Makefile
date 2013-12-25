# Created by: Leinier Cruz Salfran <salfrancl@yahoo.es>
# $FreeBSD$

PORTNAME=	aegisub
PORTVERSION=	2.1.9
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.aegisub.org/pub/archives/releases/source/ \
		ftp://ftp.aegisub.org/pub/archives/releases/source/ \
		ftp://ftp2.aegisub.org/pub/archives/releases/source/ \
		GOOGLE_CODE:ffms
PROJECTHOST=	ffmpegsource
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FFMS_DISTFILE}:ffms
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform subtitle editor

LICENSE=	BSD

LIB_DEPENDS=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS_DEFINE=	DEBUG PROFILE GCOV EFENCE ASS ALSA OPENAL PORTAUDIO PULSEAUDIO \
		FFMPEG HUNSPELL LUA DOCS
OPTIONS_DEFAULT=	ASS PULSEAUDIO FFMPEG HUNSPELL LUA
GCOV_DESC=	GCOV (require profiling)
EFENCE_DESC=	Electric Fence (require profiling)
ASS_DESC=	libASS subtitle provider
HUNSPELL_DESC=	Spell checking via Hunspell

USES=		pkgconfig gettext iconv
USE_GNOME=	intltool
USE_WX=		2.8
WX_COMPS=	wx contrib
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
USE_GL=		glu
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gcc-prec --without-lua50
INSTALLS_ICONS=	yes

PLIST_SUB=	VERSION="${PORTVERSION:R}"

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

FFMS_NAME=	ffms
FFMS_VERSION=	2.17
FFMS_DISTNAME=	${FFMS_NAME}-${FFMS_VERSION}-src
FFMS_DISTFILE=	${FFMS_DISTNAME}.tar.bz2
FFMS_WRKSRC=	${WRKDIR}/${FFMS_DISTNAME}
FFMS_CFLAGS=	-I${FFMS_WRKSRC}/include
FFMS_LIBS=	${FFMS_WRKSRC}/src/core/.libs/libffms2.a \
		`pkg-config --libs libavcodec libavformat libswscale libavutil`

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug --enable-debug-exceptions
.endif

.if ${PORT_OPTIONS:MGCOV}
CONFIGURE_ARGS+=	--enable-gcov
LDFLAGS+=	-fprofile-arcs
WITH_PROFILE=	yes
.endif

.if ${PORT_OPTIONS:MEFENCE}
LIB_DEPENDS+=	efence:${PORTSDIR}/devel/ElectricFence
CONFIGURE_ARGS+=	--enable-efence
WITH_PROFILE=	yes
.endif

.if ${PORT_OPTIONS:MPROFILE}
CONFIGURE_ARGS+=	--enable-profile
.endif

.if ${PORT_OPTIONS:MASS}
LIB_DEPENDS+=	ass:${PORTSDIR}/multimedia/libass
.else
CONFIGURE_ARGS+=	--without-libass
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if ${PORT_OPTIONS:MOPENAL}
USES+=			openal
.else
CONFIGURE_ARGS+=	--without-openal
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
BUILD_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
CONFIGURE_ENV+=	PORTAUDIO_LIBS="${LOCALBASE}/lib/portaudio2/libportaudio.so"
.else
CONFIGURE_ARGS+=	--without-portaudio
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ENV+=	FFMS_CFLAGS="${FFMS_CFLAGS}" FFMS_LIBS="${FFMS_LIBS}"
CONFIGURE_ARGS+=	--with-provider-video=ffmpegsource \
			--with-provider-audio=ffmpegsource
CPPFLAGS+=	${FFMS_CFLAGS}
.else
CONFIGURE_ARGS+=	--without-ffms
.endif

.if ${PORT_OPTIONS:MHUNSPELL}
LIB_DEPENDS+=	hunspell-1.3:${PORTSDIR}/textproc/hunspell
.else
CONFIGURE_ARGS+=	--without-hunspell
.endif

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.1+
CONFIGURE_ENV+=	LUA_CFLAGS="-I${LUA_INCDIR}" \
		LUA_LDFLAGS="-L${LUA_LIBDIR} -llua"
CPPFLAGS+=	-I${LUA_INCDIR}
.else
CONFIGURE_ARGS+=	--without-lua
.endif

# use multiple make jobs for FFMS_WRKSRC
_make_jobs=	-j${MAKE_JOBS_NUMBER}

post-extract:
.for i in ${FFMS_DISTFILE}
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${i} ${EXTRACT_AFTER_ARGS})
.endfor

post-patch:
.for i in configure
	@${REINPLACE_CMD} -e \
		'/opt_flag/s|-O2||' ${WRKSRC}/${i}
.endfor
.for i in automation/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@HAVE_AUTOMATION_TRUE@|| ; \
		 s|@HAVE_AUTOMATION_FALSE@|#| ; \
		 s|@HAVE_AUTO4_LUA_TRUE@|| ; \
		 s|@HAVE_AUTO4_LUA_FALSE@|#| ; \
		 s|@HAVE_AUTO3_LUA_TRUE@|#| ; \
		 s|@HAVE_AUTO3_LUA_FALSE|| ; \
		 /^install-data-am/s|: install|: # install|' ${WRKSRC}/${i}
.endfor
.for i in src/Makefile.in src/libauto3/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@HAVE_AUTO3_LUA_TRUE@|#| ; \
		 s|@HAVE_AUTO3_LUA_FALSE@||' ${WRKSRC}/${i}
.endfor
.for i in src/audio_player_portaudio.h
	@${REINPLACE_CMD} -e \
		's|<portaudio\.h>|<portaudio2/portaudio.h>|' ${WRKSRC}/${i}
.endfor

pre-configure:
.if ${PORT_OPTIONS:MFFMPEG}
	@(cd ${FFMS_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--disable-shared CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}")
.endif

pre-build:
.if ${PORT_OPTIONS:MFFMPEG}
	@(cd ${FFMS_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${_make_jobs} ${MAKE_ARGS} \
		${ALL_TARGET})
.endif

post-install:
	@(cd ${WRKSRC}/automation && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		install-nobase_automationDATA)
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/automation && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		install-nobase_share_docDATA)
.endif

.include <bsd.port.mk>
