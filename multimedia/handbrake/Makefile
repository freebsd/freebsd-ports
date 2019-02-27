# Created by: Andrew Thompson <andy@fud.org.nz>
# $FreeBSD$

PORTNAME=	handbrake
DISTVERSION=	1.2.2
CATEGORIES=	multimedia
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Versatile DVD ripper and video transcoder

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	invokes x86 assembler

BUILD_DEPENDS=	bash:shells/bash \
		nasm:devel/nasm \
		cmake:devel/cmake
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libxml2.so:textproc/libxml2 \
		libass.so:multimedia/libass \
		libspeex.so:audio/speex \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libvorbisenc.so:audio/libvorbis \
		libtheoradec.so:multimedia/libtheora \
		libtheoraenc.so:multimedia/libtheora \
		libsamplerate.so:audio/libsamplerate \
		libx264.so:multimedia/libx264 \
		libmp3lame.so:audio/lame \
		libopus.so:audio/opus \
		libjansson.so:devel/jansson

CONTRIB_FILES=	fdk-aac-0.1.5.tar.gz \
		ffmpeg-4.1.tar.bz2 \
		libbluray-1.0.2.tar.bz2 \
		libdvdnav-6.0.0.tar.bz2 \
		libdvdread-6.0.0.tar.bz2 \
		libvpx-1.7.0.tar.gz \
		x265_2.9.tar.gz
MASTER_SITES+=	https://download.handbrake.fr/contrib/:contrib
DISTFILES+=	${CONTRIB_FILES:S/$/:contrib/}

.if !defined(PACKAGE_BUILDING)
# DVDCSS version hardcoded in contrib/libdvdread/libdvdread-5.0.0-6-gcb1ae87/src/dvd_input.c (dlopen'ed)
LIB_DEPENDS+=	libdvdcss.so:multimedia/libdvdcss
.endif

GNU_CONFIGURE=	yes
USES=		autoreconf:build compiler:features gmake iconv \
		libtool:build localbase:ldflags pkgconfig python:2.7,build
MAKE_ENV=	V=1 ACLOCAL=${LOCALBASE}/bin/aclocal

USE_GITHUB=	yes
GH_ACCOUNT=	HandBrake
GH_PROJECT=	HandBrake

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

OPTIONS_DEFINE=		FDK_AAC X11
OPTIONS_DEFAULT=	X11

OPTIONS_SUB=	yes

FDK_AAC_DESC=	Enable non-free Fraunhofer FDK AAC codec
X11_DESC=	Build GTK+3 based GUI program

FDK_AAC_CONFIGURE_ENABLE=	fdk-aac
FDK_AAC_VARS=			LICENSE+=FDK_AAC LICENSE_COMB=multi
LICENSE_NAME_FDK_AAC=		Software License for The Fraunhofer FDK AAC Codec Library for Android
LICENSE_FILE_FDK_AAC=		${WRKDIR}/${DISTFILES:Mfdk*:R:R}/NOTICE
LICENSE_PERMS_FDK_AAC=		dist-mirror pkg-mirror auto-accept

X11_CONFIGURE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
X11_MAKE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
X11_CONFIGURE_ON=	--disable-gtk-update-checks
X11_CONFIGURE_OFF=	--disable-gtk
X11_LIB_DEPENDS=	libvpx.so:multimedia/libvpx \
			libnotify.so:devel/libnotify
X11_USES=	gettext desktop-file-utils gnome
X11_USE=	gstreamer1=gdkpixbuf,libav \
		gnome=gtk30,intltool,cairo,gdkpixbuf2

# HandBrake tries to fetch its dependencies during build phase, which is not
# considered good in FreeBSD.  Instead, we will provided the downloaded files.
post-extract: .SILENT
	${MKDIR} ${WRKSRC}/download
.for f in ${CONTRIB_FILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${WRKSRC}/download
.endfor
# Install version information.
	${CP} ${FILESDIR}/version.txt ${WRKSRC}
# Following patches reduces warnings with clang.
	${CP} ${FILESDIR}/P00-freebsd-libavutil-x86-asm-h.patch ${WRKSRC}/contrib/ffmpeg
	${CP} ${FILESDIR}/P01-freebsd-ifo_types.h.patch ${WRKSRC}/contrib/libdvdread

post-install-X11-on:
	${LN} -sf ghb ${STAGEDIR}${PREFIX}/bin/HandBrake

.include <bsd.port.mk>
