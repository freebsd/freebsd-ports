# Created by: Leinier Cruz Salfran <salfrancl@yahoo.es>
# $FreeBSD$

PORTNAME=	aegisub
PORTVERSION=	3.2.1
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.aegisub.org/pub/archives/releases/source/:aegisub \
		ftp://ftp.aegisub.org/pub/archives/releases/source/:aegisub \
		ftp://ftp2.aegisub.org/pub/archives/releases/source/:aegisub \
		GH
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:aegisub ${FFMS_DISTFILE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform subtitle editor

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libicui18n.so:${PORTSDIR}/devel/icu \
		libass.so:${PORTSDIR}/multimedia/libass \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USE_GITHUB=	yes
GH_ACCOUNT=	FFMS
GH_PROJECT=	ffms2
GH_TAGNAME=	${FFMS_VERSION}
GH_COMMIT=	f673b48

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		compiler:c++11-lib desktop-file-utils gettext gmake iconv \
		pkgconfig tar:xz
USE_GNOME=	intltool
USE_WX=		3.0
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
USE_GL=		glu
USE_CSTD=	c99
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ICONV_LIBS="${ICONV_LIB}" PTHREAD_LIBS="-pthread" \
		agi_cv_with_iconv=yes
CONFIGURE_ARGS=	--disable-compiler-flags \
		--disable-gcc-prec \
		--disable-sanity-checks \
		--disable-update-checker \
		--without-libc++ \
		${ICONV_CONFIGURE_ARG}
INSTALLS_ICONS=	yes

PLIST_SUB=	VERSION="${PORTVERSION:R}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		ALSA DOCS FFMPEG FFTW HUNSPELL OPENAL PORTAUDIO \
			PULSEAUDIO
OPTIONS_DEFAULT=	FFMPEG FFTW HUNSPELL PULSEAUDIO

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_OFF=	--without-alsa
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CONFIGURE_ENV=	FFMS2_CFLAGS="${FFMS_CFLAGS}" \
			FFMS2_LIBS="${FFMS_LIBS}"
FFMPEG_CONFIGURE_OFF=	--without-ffms
FFMPEG_CPPFLAGS=	${FFMS_CFLAGS}
FFTW_LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3
FFTW_CONFIGURE_OFF=	--without-fftw3
HUNSPELL_LIB_DEPENDS=	libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell
HUNSPELL_CONFIGURE_OFF=	--without-hunspell
OPENAL_USES=		openal
OPENAL_CONFIGURE_OFF=	--without-openal
PORTAUDIO_BUILD_DEPENDS=\
			portaudio2>0:${PORTSDIR}/audio/portaudio2
PORTAUDIO_RUN_DEPENDS=	portaudio2>0:${PORTSDIR}/audio/portaudio2
PORTAUDIO_CFLAGS=	-isystem ${LOCALBASE}/include/portaudio2
PORTAUDIO_LDFLAGS=	-L${LOCALBASE}/lib/portaudio2
PORTAUDIO_CONFIGURE_OFF=\
			--without-portaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=\
			--without-libpulse

FFMS_NAME=	ffms2
FFMS_VERSION=	2.20
FFMS_DISTNAME=	${FFMS_NAME}-${FFMS_VERSION}
FFMS_DISTFILE=	${FFMS_DISTNAME}.tar.gz
FFMS_WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}
FFMS_CFLAGS=	-I${FFMS_WRKSRC}/include
FFMS_LIBS=	${FFMS_WRKSRC}/src/core/.libs/libffms2.a \
		$$(pkg-config --libs libavcodec libavformat libswscale libavutil libavresample)

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "gcc"
USE_CXXSTD=	gnu++11
.if empty(CFLAGS:M-march=*)
CFLAGS_i386=	-march=pentium
.endif
.else
USE_CXXSTD=	c++11
CXXFLAGS+=	-Wno-c++11-narrowing
.if ${COMPILER_VERSION} < 34
BUILD_DEPENDS+=	${LOCALBASE}/lib/c++/libstdc++.so:${PORTSDIR}/devel/libc++ \
		${LOCALBASE}/bin/clang34:${PORTSDIR}/lang/clang34
CPP=		clang-cpp34
CC=		clang34
CXX=		clang++34
CXXFLAGS+=	-nostdinc++ -isystem ${LOCALBASE}/include/c++/v1
LDFLAGS+=	-L${LOCALBASE}lib/c++
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's| -O3||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|".*build/|"./build/|' ${WRKSRC}/build/version.sh
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 /^CCOPT_/s|=.*|=| ; \
		 /^CCDEBUG/s|=.*|=|' ${WRKSRC}/vendor/luajit/src/Makefile
.if ${COMPILER_TYPE} == "gcc"
	@${FIND} ${WRKSRC} -name "*.h" | ${XARGS} ${REINPLACE_CMD} -e \
		'/virtual /s|= default;$$|{ }|'
.endif

pre-configure:
.if ${PORT_OPTIONS:MFFMPEG}
	@(cd ${FFMS_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--disable-shared CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}")
.endif

pre-build:
.if ${PORT_OPTIONS:MFFMPEG}
	@(cd ${FFMS_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} -j${MAKE_JOBS_NUMBER} ${MAKE_ARGS} \
		${ALL_TARGET})
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/automation/v4-docs
	(cd ${WRKSRC}/automation/v4-docs && ${INSTALL_DATA} * \
		${STAGEDIR}${DOCSDIR}/automation/v4-docs)
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aegisub-*

.include <bsd.port.post.mk>
