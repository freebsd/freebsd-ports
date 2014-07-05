# Created by: Leinier Cruz Salfran <salfrancl@yahoo.es>
# $FreeBSD$

PORTNAME=	aegisub
PORTVERSION=	3.1.3
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
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libass.so:${PORTSDIR}/multimedia/libass

USE_GITHUB=	yes
GH_ACCOUNT=	FFMS
GH_PROJECT=	ffms2
GH_TAGNAME=	${FFMS_VERSION}
GH_COMMIT=	6b0e4a2

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		compiler:c++11-lib desktop-file-utils gmake gettext iconv \
		pkgconfig tar:xz
USE_GNOME=	intltool
USE_WX=		3.0
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
USE_GL=		glu
USE_CSTD=	c99
USE_LUA=	5.1+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-compiler-flags \
		--disable-update-checker \
		--without-libc++ \
		--disable-gcc-prec
INSTALLS_ICONS=	yes

PLIST_SUB=	VERSION="${PORTVERSION:R}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

OPTIONS_DEFINE=		ALSA DOCS FFMPEG FFTW HUNSPELL OPENAL \
			PORTAUDIO PULSEAUDIO
OPTIONS_DEFAULT=	FFMPEG FFTW HUNSPELL PULSEAUDIO

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_OFF=	--without-alsa
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CONFIGURE_ENV=	FFMS2_CFLAGS="${FFMS_CFLAGS}" \
			FFMS2_LIBS="${FFMS_LIBS}"
FFMPEG_CONFIGURE_OFF=	--without-ffms2
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
FFMS_VERSION=	2.19.1
FFMS_DISTNAME=	${FFMS_NAME}-${FFMS_VERSION}
FFMS_DISTFILE=	${FFMS_DISTNAME}.tar.gz
FFMS_WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}
FFMS_CFLAGS=	-I${FFMS_WRKSRC}/include
FFMS_LIBS=	${FFMS_WRKSRC}/src/core/.libs/libffms2.a \
		$$(pkg-config --libs libavcodec libavformat libswscale libavutil libavresample)

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "gcc"
USE_CXXSTD=	gnu++11
.else
USE_CXXSTD=	c++11
CXXFLAGS+=	-Wno-c++11-narrowing
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's| -O3||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|".*build/|"./build/|' ${WRKSRC}/build/version.sh
	@${REINPLACE_CMD} -e \
		'/iconv_t/s|^|//|' \
		${WRKSRC}/libaegisub/include/libaegisub/charset_conv.h

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
