# New ports collection makefile for:	aegisub
# Date created:				2nd March 2010
# Whom:					Leinier Cruz Salfran <salfrancl@yahoo.es>
#
# $FreeBSD$
#    $MCom: ports-stable/multimedia/aegisub/Makefile,v 0.14 2010/03/10 17:02:00 salfrancl Exp $
#      $Id: Makefile,v 0.14 2010/03/10 17:02:00 salfrancl Exp $
#

PORTNAME=	aegisub
PORTVERSION=	2.1.9
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.aegisub.org/pub/releases/ \
		http://ftp2.aegisub.org/pub/releases/ \
		ftp://ftp.aegisub.org/pub/releases/ \
		ftp://ftp2.aegisub.org/pub/releases/ \
		GOOGLE_CODE:ffms
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FFMS_DISTFILE}:ffms
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross-platform subtitle editor

LICENSE=	BSD

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS_DEFINE=	DEBUG PROFILE GCOV EFENCE ASS ALSA OPENAL PORTAUDIO PULSEAUDIO \
		FFMPEG HUNSPELL LUA DOCS
OPTIONS_DEFAULT=	ASS PULSEAUDIO FFMPEG HUNSPELL LUA
GCOV_DESC=	GCOV (require profiling)
EFENCE_DESC=	Electric Fence (require profiling)
ASS_DESC=	libASS subtitle provider
HUNSPELL_DESC=	Hunspell support

USE_GNOME=	intltool
USE_WX=		2.8
WX_COMPS=	wx contrib
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
USE_GL=		glu
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-lua50
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	VERSION="${PORTVERSION:R}"

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PROJECTHOST=	ffmpegsource
FFMS_NAME=	ffms
FFMS_VERSION=	2.17
FFMS_DISTNAME=	${FFMS_NAME}-${FFMS_VERSION}-src
FFMS_DISTFILE=	${FFMS_DISTNAME}.tar.bz2
FFMS_WRKSRC=	${WRKDIR}/${FFMS_DISTNAME}
FFMS_CFLAGS=	-I${FFMS_WRKSRC}/include
FFMS_LIBS=	${FFMS_WRKSRC}/src/core/.libs/libffms2.a \
		`pkg-config --libs libavcodec libavformat libswscale libavutil`

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
LIB_DEPENDS+=	efence.0:${PORTSDIR}/devel/ElectricFence
CONFIGURE_ARGS+=	--enable-efence
WITH_PROFILE=	yes
.endif

.if ${PORT_OPTIONS:MPROFILE}
CONFIGURE_ARGS+=	--enable-profile
.endif

.if ${PORT_OPTIONS:MASS}
LIB_DEPENDS+=	ass.5:${PORTSDIR}/multimedia/libass
.else
CONFIGURE_ARGS+=	--without-libass
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if ${PORT_OPTIONS:MOPENAL}
USE_OPENAL=		yes
.else
CONFIGURE_ARGS+=	--without-openal
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
BROKEN=		portaudio2 support is broken
BUILD_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
CFLAGS+=	-isystem ${LOCALBASE}/include/portaudio2
LDFLAGS+=	-L${LOCALBASE}/lib/portaudio2
.else
CONFIGURE_ARGS+=	--without-portaudio
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ENV+=	FFMS_CFLAGS="${FFMS_CFLAGS}" FFMS_LIBS="${FFMS_LIBS}"
CONFIGURE_ARGS+=	--with-provider-video=ffmpegsource \
			--with-provider-audio=ffmpegsource
CPPFLAGS+=	${FFMS_CFLAGS}
.else
CONFIGURE_ARGS+=	--without-ffms
.endif

.if ${PORT_OPTIONS:MHUNSPELL}
LIB_DEPENDS+=	hunspell-1.3.0:${PORTSDIR}/textproc/hunspell
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
.if !defined(DISABLE_MAKE_JOBS)
_make_jobs=	-j${MAKE_JOBS_NUMBER}
.endif

post-extract:
.for i in ${FFMS_DISTFILE}
	@(cd ${WRKDIR} && ${BZIP2_CMD} ${EXTRACT_BEFORE_ARGS} \
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
