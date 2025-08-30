PORTNAME=	handbrake
DISTVERSION=	1.10.1
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/HandBrake/HandBrake/releases/download/${DISTVERSION}/
MASTER_SITES+=	https://github.com/HandBrake/HandBrake-contribs/releases/download/contribs/:contrib
MASTER_SITES+=	https://github.com/HandBrake/HandBrake-contribs/releases/download/contribs2/:contrib
DISTNAME=	HandBrake-${DISTVERSION}
DISTFILES=	${DISTNAME}-source.tar.bz2 ${CONTRIB_FILES:S/$/:contrib/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Versatile DVD ripper and video transcoder
WWW=		https://handbrake.fr/

LICENSE=		GPLv2 FDK_AAC
LICENSE_COMB=		multi
LICENSE_NAME_FDK_AAC=	Software License for The Fraunhofer FDK AAC Codec Library for Android
LICENSE_FILE_FDK_AAC=	${WRKDIR}/${DISTFILES:Mfdk*:R:R}/NOTICE
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_PERMS_FDK_AAC=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64 powerpc powerpc64 powerpc64le

BUILD_DEPENDS=	bash:shells/bash \
		nasm:devel/nasm \
		cmake:devel/cmake-core \
		meson:devel/meson \
		git:devel/git@lite
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdrm.so:graphics/libdrm \
		libturbojpeg.so:graphics/libjpeg-turbo \
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
		localbase:ldflags ninja:build pkgconfig python:build

CONTRIB_FILES=	SVT-AV1-v3.1.0.tar.gz \
		fdk-aac-2.0.3.tar.gz \
		ffmpeg-7.1.1.tar.bz2 \
		libbluray-1.3.4.tar.bz2 \
		libdvdnav-6.1.1.tar.bz2 \
		libdvdread-6.1.3.tar.bz2 \
		dav1d-1.5.1.tar.bz2 \
		dovi_tool-libdovi-3.3.2.tar.gz \
		x265-snapshot-20250729-13276.tar.gz \
		zimg-snapshot-20250624.tar.gz

.if !defined(PACKAGE_BUILDING)
# DVDCSS version hardcoded in contrib/libdvdread/libdvdread-5.0.0-6-gcb1ae87/src/dvd_input.c (dlopen'ed)
LIB_DEPENDS+=	libdvdcss.so:multimedia/libdvdcss
.endif

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--force --enable-x265
CONFIGURE_TARGET=	build

MAKEFILE=	GNUmakefile
MAKE_ENV=	V=1 ACLOCAL=${LOCALBASE}/bin/aclocal
ALL_TARGET=	#
INSTALL_TARGET=	install-strip

# Enforce linking to bundled libraries instead of system libraries
LDFLAGS+=	-L${BUILD_WRKSRC}/contrib/lib

BINARY_ALIAS=	python3=${PYTHON_VERSION}
NOPRECIOUSMAKEVARS=	yes			# for ffmpeg and x264

BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${WRKSRC}/build

OPTIONS_DEFINE=		FDK_AAC VPL X11
OPTIONS_DEFAULT=	VPL X11
OPTIONS_EXCLUDE_powerpc=	VPL
OPTIONS_EXCLUDE_powerpc64=	VPL
OPTIONS_EXCLUDE_powerpc64le=	VPL

OPTIONS_SUB=	yes

FDK_AAC_DESC=	Enable non-free Fraunhofer FDK AAC codec
VPL_DESC=	Intel oneVPL (aka Quick Sync Video)
X11_DESC=	Build GTK 3 based GUI program

FDK_AAC_CONFIGURE_ENABLE=	fdk-aac
FDK_AAC_VARS=			LICENSE+=FDK_AAC LICENSE_COMB=multi

VPL_LIB_DEPENDS=	libvpl.so:multimedia/onevpl \
			libmfx.so:multimedia/intel-media-sdk \
			libva-drm.so:multimedia/libva
VPL_CONFIGURE_ON=	--enable-qsv

X11_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
X11_USES=		gettext desktop-file-utils gnome gstreamer
X11_USE=		gstreamer=gdkpixbuf,libav \
			gnome=gtk40,intltool,cairo,gdkpixbuf,libxml2
X11_CONFIGURE_OFF=	--disable-gtk
X11_CONFIGURE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
X11_MAKE_ENV=		COMPILER_PATH=${LOCALBASE}/bin

# HandBrake tries to fetch its dependencies during build phase, which is not
# considered good in FreeBSD.  Instead, we will provide the downloaded files.
post-extract: .SILENT
	${MKDIR} ${WRKSRC}/download

pre-configure:
	cd ${DISTDIR}/${DIST_SUBDIR} && \
	    ${INSTALL_DATA} ${CONTRIB_FILES} \
	    ${WRKSRC}/download

# for powerpc64
# picked from multimedia/ffmpeg/files/patch-libswscale_ppc_yuv2rgb__altivec.c
	${CP} ${FILESDIR}/P02-freebsd-ppc-libswscale.patch ${WRKSRC}/contrib/ffmpeg

post-install-X11-on:
	${LN} -sf ghb ${STAGEDIR}${PREFIX}/bin/HandBrake

.include <bsd.port.mk>
