PORTNAME=	emby-server
DISTVERSION=	4.9.3.0
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/MediaBrowser/Emby.Releases/releases/download/${DISTVERSION}/ \
		https://mediabrowser.github.io/embytools/
DISTNAME=	embyserver-netcore_${DISTVERSION}
DISTFILES=	${DISTNAME}.zip \
		ffdetect-${FFDETECT_VERSION}.tar.xz \
		ffmpeg-${FFMPEG_VERSION}.tar.gz \
		libskiasharp-${SKIASHARP_VERSION}.tar.xz \
		libvips-${VIPS_VERSION}.tar.xz \
		license.docx
DIST_SUBDIR?=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.zip \
		ffdetect-${FFDETECT_VERSION}.tar.xz \
		ffmpeg-${FFMPEG_VERSION}.tar.gz \
		libskiasharp-${SKIASHARP_VERSION}.tar.xz \
		libvips-${VIPS_VERSION}.tar.xz

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
		libexpat.so:textproc/expat2 \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgnutls.so:security/gnutls \
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
RUN_DEPENDS=	dotnet8>0:lang/dotnet8 \
		icu>0:devel/icu \
		krb5>0:security/krb5 \
		libexif>0:graphics/libexif \
		libheif>0:graphics/libheif \
		libimagequant>0:graphics/libimagequant \
		libinotify>0:devel/libinotify \
		libjxl>0:graphics/libjxl \
		libunwind>0:devel/libunwind \
		openexr>0:graphics/openexr \
		openjpeg>0:graphics/openjpeg \
		orc>0:devel/orc \
		pango>0:x11-toolkits/pango \
		tiff>0:graphics/tiff

USES=		compiler:c11 gmake iconv libarchive:run localbase:ldflags pkgconfig sqlite ssl:run
USE_GNOME=	cairo glib20 librsvg2
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
		--disable-vulkan \
		--disable-xlib \
		--enable-chromaprint \
		--enable-fontconfig \
		--enable-gnutls \
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
		--enable-opencl \
		--enable-optimizations \
		--enable-static \
		--enable-vaapi \
		--enable-version3

MAKE_ENV=	V=1

NOPRECIOUSMAKEVARS=	yes
SUB_FILES=	SQLitePCLRaw.provider.sqlite3.dll.config
SUB_LIST=	GROUP=${GROUPS} \
		PORTNAME=${PORTNAME} \
		RC_NAME=emby_server \
		USER=${USERS}

WRKSRC=		${WRKDIR}/ffmpeg-${FFMPEG_VERSION:C/-.*$//}_public

USERS=		emby
GROUPS=		emby

OPTIONS_DEFINE=		LAME
OPTIONS_DEFAULT=	LAME

LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_ENABLE=	libmp3lame

OSVERSION_MAJOR=	${OSVERSION:C/^([0-9][0-9]).*/\1/}
FFMPEG_VERSION=		2023_06_25-u1
FFDETECT_VERSION=	2023.06.25p4-x64_freebsd${OSVERSION_MAJOR}
SKIASHARP_VERSION=	2.88.7-x64_freebsd${OSVERSION_MAJOR}
VIPS_VERSION=		8.16.0-x64_freebsd${OSVERSION_MAJOR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/emby-server
	(cd ${WRKDIR}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/lib/emby-server/bin)
	(cd ${WRKDIR}/lib && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/lib/emby-server/lib)
	(cd ${WRKDIR}/system && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/emby-server/system)
	(${INSTALL_PROGRAM} ${WRKSRC}/ffmpeg ${STAGEDIR}${PREFIX}/lib/emby-server/bin)
	(${INSTALL_PROGRAM} ${WRKSRC}/ffprobe ${STAGEDIR}${PREFIX}/lib/emby-server/bin)
	(${INSTALL_DATA} ${WRKDIR}/SQLitePCLRaw.provider.sqlite3.dll.config ${STAGEDIR}${PREFIX}/lib/emby-server/system)
	${RLN} ${LOCALBASE}/lib/libimagequant.so.0.4 ${STAGEDIR}${PREFIX}/lib/emby-server/lib/libimagequant.so.0

post-install:
	@${FIND} -s ${STAGEDIR}${PREFIX}/lib -not -type d | ${SORT} | ${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>
