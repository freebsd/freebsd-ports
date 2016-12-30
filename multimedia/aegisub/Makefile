# Created by: Leinier Cruz Salfran <salfrancl@yahoo.es>
# $FreeBSD$

PORTNAME=	aegisub
PORTVERSION=	3.2.2
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.aegisub.org/pub/archives/releases/source/ \
		ftp://ftp.aegisub.org/pub/archives/releases/source/ \
		ftp://ftp2.aegisub.org/pub/archives/releases/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform subtitle editor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libicui18n.so:devel/icu \
		libass.so:multimedia/libass \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c++11-lib desktop-file-utils gettext gmake iconv \
		localbase pkgconfig tar:xz
USE_GNOME=	intltool
USE_WX=		3.0
WX_CONF_ARGS=	absolute
USE_GL=		gl
USE_CSTD=	c99
USE_CXXSTD=	c++11
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528
LDFLAGS+=	-Wl,--as-needed # freetype
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

OPTIONS_DEFINE=		ALSA DOCS FFMPEG FFTW HUNSPELL OPENAL PORTAUDIO \
			PULSEAUDIO
OPTIONS_DEFAULT=	FFMPEG FFTW HUNSPELL PULSEAUDIO

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=	--without-alsa
FFMPEG_LIB_DEPENDS=	libffms2.so:multimedia/ffms2
FFMPEG_CONFIGURE_OFF=	--without-ffms
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW_CONFIGURE_OFF=	--without-fftw3
HUNSPELL_LIB_DEPENDS=	libhunspell-1.5.so:textproc/hunspell
HUNSPELL_CONFIGURE_OFF=	--without-hunspell
OPENAL_USES=		openal
OPENAL_CONFIGURE_OFF=	--without-openal
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_OFF=\
			--without-portaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=\
			--without-libpulse

# src/audio_display.o: undefined reference to symbol '__atomic_load_8@@LIBATOMIC_1.0'
.if empty(CFLAGS:M-march=*)
CFLAGS+=		${CFLAGS_${ARCH}_${CHOSEN_COMPILER_TYPE}}
CFLAGS_i386_gcc=	-march=pentium
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

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		automation/v4-docs ${STAGEDIR}${DOCSDIR})
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aegisub-*

.include <bsd.port.mk>
