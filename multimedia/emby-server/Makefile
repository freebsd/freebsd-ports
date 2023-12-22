PORTNAME=	emby-server
DISTVERSION?=	4.7.14.0
PORTREVISION?=	7
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/MediaBrowser/Emby.Releases/releases/download/${DISTVERSION}/ \
		https://mediabrowser.github.io/embytools/
DISTNAME=	emby-server-freebsd13_${DISTVERSION}_amd64
DISTFILES=	${DISTNAME}.tar.xz \
		ffdetect-${FFVERSION}-x64_freebsd13.tar.xz \
		ffmpeg-${FFVERSION}.tar.gz \
		license.docx
DIST_SUBDIR?=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.xz \
		ffdetect-${FFVERSION}-x64_freebsd13.tar.xz \
		ffmpeg-${FFVERSION}.tar.gz

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Media server to organize, play & stream audio/video to various devices
WWW=		https://emby.media/

LICENSE=	UNKNOWN
LICENSE_NAME=	custom
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/license.docx
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	nasm:devel/nasm \
		${LOCALBASE}/include/CL/opencl.h:devel/opencl
LIB_DEPENDS=	libaribb24.so:multimedia/aribb24 \
		libass.so:multimedia/libass \
		libchromaprint.so:audio/chromaprint \
		libdav1d.so:multimedia/dav1d \
		libdrm.so:graphics/libdrm \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libmbedtls.so:security/mbedtls \
		libmfx.so:multimedia/intel-media-sdk \
		libOpenCL.so:devel/ocl-icd \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libpng.so:graphics/png \
		libraw.so:graphics/libraw \
		libtesseract.so:graphics/tesseract \
		libtheora.so:multimedia/libtheora \
		libva.so:multimedia/libva \
		libvorbis.so:audio/libvorbis \
		libvpx.so:multimedia/libvpx \
		libwebp.so:graphics/webp \
		libx264.so:multimedia/libx264 \
		libx265.so:multimedia/x265 \
		libzvbi.so:devel/libzvbi

RUN_DEPENDS=	icu>0:devel/icu \
		libexif>0:graphics/libexif \
		libheif>0:graphics/libheif \
		libimagequant>0:graphics/libimagequant \
		libinotify>0:devel/libinotify \
		libjxl>0:graphics/libjxl \
		libunwind>0:devel/libunwind \
		openjpeg>0:graphics/openjpeg \
		orc>0:devel/orc

USES=		compiler:c11 gmake iconv localbase:ldflags pkgconfig sqlite ssl:run
USE_RC_SUBR=	${PORTNAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc="${CC}" \
		--disable-alsa \
		--disable-doc \
		--disable-ffplay \
		--disable-libxcb \
		--disable-outdev=xv \
		--disable-sdl2 \
		--disable-shared \
		--disable-sndio \
		--disable-v4l2-m2m \
		--disable-vdpau \
		--disable-xlib \
		--enable-chromaprint \
		--enable-fontconfig \
		--enable-gpl \
		--enable-iconv \
		--enable-libaribb24 \
		--enable-libass \
		--enable-libdav1d \
		--enable-libdrm \
		--enable-libfreetype \
		--enable-libfribidi \
		--enable-libmfx \
		--enable-libopus \
		--enable-libtesseract \
		--enable-libtheora \
		--enable-libvorbis \
		--enable-libvpx \
		--enable-libwebp \
		--enable-libx264 \
		--enable-libx265 \
		--enable-libzvbi \
		--enable-mbedtls \
		--enable-opencl \
		--enable-optimizations \
		--enable-static \
		--enable-vaapi \
		--enable-version3

MAKE_ENV=	V=1

CONFLICTS_INSTALL?=	emby-server-devel

NOPRECIOUSMAKEVARS=	yes
SUB_FILES=	SQLitePCLRaw.provider.sqlite3.dll.config
SUB_LIST=	GROUP=${GROUPS} \
		PORTNAME=${PORTNAME} \
		RC_NAME=emby_server \
		USER=${USERS}

WRKSRC=		${WRKDIR}/ffmpeg-${FFVERSION}_public

USERS=		emby
GROUPS=		emby

OPTIONS_DEFINE=		LAME
OPTIONS_DEFAULT=	LAME

LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_ENABLE=	libmp3lame

FFVERSION=	2022_05_07

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/emby-server/bin
	(${INSTALL_PROGRAM} ${WRKDIR}/bin/ffdetect ${STAGEDIR}${PREFIX}/lib/emby-server/bin)
	(${INSTALL_PROGRAM} ${WRKSRC}/ffmpeg ${STAGEDIR}${PREFIX}/lib/emby-server/bin)
	(${INSTALL_PROGRAM} ${WRKSRC}/ffprobe ${STAGEDIR}${PREFIX}/lib/emby-server/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/emby-server/lib
	(cd ${WRKDIR}/lib && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/lib/emby-server/lib)
	${RLN} ${LOCALBASE}/lib/libimagequant.so.0.0.4 ${STAGEDIR}${PREFIX}/lib/emby-server/lib/libimagequant.so.0
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/emby-server/system
	(${INSTALL_DATA} ${WRKDIR}/SQLitePCLRaw.provider.sqlite3.dll.config ${STAGEDIR}${PREFIX}/lib/emby-server/system)
	(cd ${WRKDIR}/system && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/emby-server/system "! -name EmbyServer")
	(${INSTALL_PROGRAM} ${WRKDIR}/system/EmbyServer ${STAGEDIR}${PREFIX}/lib/emby-server/system)

post-install:
	@${FIND} -s ${STAGEDIR}${PREFIX}/lib -not -type d | ${SORT} | ${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>
