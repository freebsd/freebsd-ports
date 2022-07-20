PORTNAME=	handbrake
DISTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/HandBrake/HandBrake/releases/download/${DISTVERSION}/
MASTER_SITES+=	https://github.com/HandBrake/HandBrake-contribs/releases/download/contribs/:contrib
DISTNAME=	HandBrake-${DISTVERSION}
DISTFILES=	${DISTNAME}-source.tar.bz2 ${CONTRIB_FILES:S/$/:contrib/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Versatile DVD ripper and video transcoder

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64le

BUILD_DEPENDS=	bash:shells/bash \
		nasm:devel/nasm \
		cmake:devel/cmake \
		meson:devel/meson
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgudev-1.0.so:devel/libgudev \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libturbojpeg.so:graphics/libjpeg-turbo \
		libxml2.so:textproc/libxml2 \
		libass.so:multimedia/libass \
		libspeex.so:audio/speex \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libvorbisenc.so:audio/libvorbis \
		libtheoradec.so:multimedia/libtheora \
		libtheoraenc.so:multimedia/libtheora \
		libx264.so:multimedia/libx264 \
		libvpx.so:multimedia/libvpx \
		libmp3lame.so:audio/lame \
		libopus.so:audio/opus \
		libjansson.so:devel/jansson

USES=		autoreconf:build compiler:c11 gmake iconv libtool:build \
		localbase:ldflags ninja:build pkgconfig python:3.6+,build

CONTRIB_FILES=	fdk-aac-2.0.1.tar.gz \
		ffmpeg-4.4.1.tar.bz2 \
		libbluray-1.3.0.tar.bz2 \
		libdvdnav-6.1.1.tar.bz2 \
		libdvdread-6.1.1.tar.bz2 \
		dav1d-0.9.2.tar.bz2 \
		x265_3.5.tar.gz \
		zimg-3.0.3.tar.gz

.if !defined(PACKAGE_BUILDING)
# DVDCSS version hardcoded in contrib/libdvdread/libdvdread-5.0.0-6-gcb1ae87/src/dvd_input.c (dlopen'ed)
LIB_DEPENDS+=	libdvdcss.so:multimedia/libdvdcss
.endif

GNU_CONFIGURE=	yes
MAKE_ENV=	V=1 ACLOCAL=${LOCALBASE}/bin/aclocal

BINARY_ALIAS=	python3=${PYTHON_VERSION}

CONFIGURE_ARGS=	--force --enable-x265
CONFIGURE_TARGET=	build

BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${WRKSRC}/build
MAKEFILE=	GNUmakefile
ALL_TARGET=	#
INSTALL_TARGET=	install-strip

NOPRECIOUSMAKEVARS=	yes			# for ffmpeg and x264

# Enforce linking to bundled libraries instead of system libraries
LDFLAGS+=	-L${BUILD_WRKSRC}/contrib/lib

OPTIONS_DEFINE=		FDK_AAC VPL X11
OPTIONS_DEFAULT=	VPL X11
OPTIONS_EXCLUDE_i386=	VPL
OPTIONS_EXCLUDE_powerpc=	VPL
OPTIONS_EXCLUDE_powerpc64=	VPL
OPTIONS_EXCLUDE_powerpc64le=	VPL

OPTIONS_SUB=	yes

FDK_AAC_DESC=	Enable non-free Fraunhofer FDK AAC codec
VPL_DESC=	Intel oneVPL (aka Quick Sync Video)
X11_DESC=	Build GTK+3 based GUI program

FDK_AAC_CONFIGURE_ENABLE=	fdk-aac
FDK_AAC_VARS=			LICENSE+=FDK_AAC LICENSE_COMB=multi
LICENSE_NAME_FDK_AAC=		Software License for The Fraunhofer FDK AAC Codec Library for Android
LICENSE_FILE_FDK_AAC=		${WRKDIR}/${DISTFILES:Mfdk*:R:R}/NOTICE
LICENSE_PERMS_FDK_AAC=		dist-mirror pkg-mirror auto-accept

VPL_LIB_DEPENDS=	libvpl.so:multimedia/onevpl \
			libmfx.so:multimedia/intel-media-sdk \
			libva-drm.so:multimedia/libva
VPL_CONFIGURE_ON=	--enable-qsv

X11_CONFIGURE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
X11_MAKE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
X11_CONFIGURE_ON=	--disable-gtk-update-checks
X11_CONFIGURE_OFF=	--disable-gtk
X11_LIB_DEPENDS=	libvpx.so:multimedia/libvpx \
			libnotify.so:devel/libnotify
X11_USES=	gettext desktop-file-utils gnome gstreamer
X11_USE=	gstreamer=gdkpixbuf,libav \
		gnome=gtk30,intltool,cairo,gdkpixbuf2

# HandBrake tries to fetch its dependencies during build phase, which is not
# considered good in FreeBSD.  Instead, we will provide the downloaded files.
post-extract: .SILENT
	${MKDIR} ${WRKSRC}/download

pre-configure:
	cd ${DISTDIR}/${DIST_SUBDIR} && \
	    ${INSTALL_DATA} ${CONTRIB_FILES} \
	    ${WRKSRC}/download
# Following patches reduces warnings with clang.
	${CP} ${FILESDIR}/P00-freebsd-libavutil-x86-asm-h.patch ${WRKSRC}/contrib/ffmpeg
	${CP} ${FILESDIR}/P01-freebsd-ifo_types.h.patch ${WRKSRC}/contrib/libdvdread
# for powerpc64
# picked from multimedia/ffmpeg/files/patch-libswscale_ppc_yuv2rgb__altivec.c
	${CP} ${FILESDIR}/P02-freebsd-ppc-libswscale.patch ${WRKSRC}/contrib/ffmpeg

post-install-X11-on:
	${LN} -sf ghb ${STAGEDIR}${PREFIX}/bin/HandBrake

.include <bsd.port.mk>
