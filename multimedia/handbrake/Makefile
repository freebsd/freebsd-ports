# Created by: Andrew Thompson <andy@fud.org.nz>
# $FreeBSD$

PORTNAME=	handbrake
PORTVERSION=	0.10.5
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://download.handbrake.fr/releases/${PORTVERSION}/ \
		http://download.handbrake.fr/handbrake/contrib/:contrib \
		http://download.handbrake.fr/contrib/:contrib
DISTFILES=	HandBrake-${PORTVERSION}.tar.bz2 \
		a52dec-0.7.4.tar.gz:contrib \
		faac-1.28.tar.gz:contrib \
		faad2-2.7.tar.gz:contrib \
		fdk-aac-v0.1.1-6-gbae4553.tar.bz2:contrib \
		libav-v10.1.tar.bz2:contrib \
		libbluray-0.5.0.tar.bz2:contrib \
		libdca-r81-strapped.tar.gz:contrib \
		libdvdnav-5.0.1-0-gaa3659d.tar.gz:contrib \
		libdvdread-5.0.0-6-gcb1ae87.tar.gz:contrib \
		libvpx-v1.3.0.tar.bz2:contrib \
		x264-r2479-dd79a61.tar.gz:contrib \
		x265_1.9.tar.gz:contrib
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Versatile DVD ripper and video transcoder

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm:devel/yasm \
		cmake:devel/cmake
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libxml2.so:textproc/libxml2 \
		libass.so:multimedia/libass \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libvorbisenc.so:audio/libvorbis \
		libtheoradec.so:multimedia/libtheora \
		libtheoraenc.so:multimedia/libtheora \
		libsamplerate.so:audio/libsamplerate \
		libx264.so:multimedia/libx264 \
		libmp3lame.so:audio/lame

BROKEN_aarch64=	Fails to build: invokes x86 asm

.if !defined(PACKAGE_BUILDING)
# DVDCSS version hardcoded in contrib/libdvdread/libdvdread-5.0.0-6-gcb1ae87/src/dvd_input.c (dlopen'ed)
LIB_DEPENDS+=	libdvdcss.so.2:multimedia/libdvdcss
.endif

GNU_CONFIGURE=	yes
USES=		autoreconf:build compiler:features gmake iconv \
		libtool:build localbase:ldflags pkgconfig python:build
MAKE_ENV=	V=1

WRKSRC=		${WRKDIR}/HandBrake-${PORTVERSION}
PLIST_FILES=	bin/HandBrakeCLI

CONFIGURE_ARGS=	--force
CONFIGURE_TARGET=	build

BUILD_WRKSRC=	${WRKSRC}/build
MAKEFILE=	GNUmakefile
ALL_TARGET=	#
MAKE_JOBS_UNSAFE=	yes

NOPRECIOUSMAKEVARS=	yes			# for ffmpeg and x264

# Enforce linking to bundled libraries instead of system libraries
LDFLAGS+=	-L${BUILD_WRKSRC}/contrib/lib

# Enforce linking to the system c++ standard lib
LDFLAGS+=	-l${COMPILER_FEATURES:Mlib*c++:S/lib//}

OPTIONS_DEFINE=	FDK_AAC X11
OPTIONS_DEFAULT=	X11

FDK_AAC_DESC=	Enable non-free Fraunhofer FDK AAC codec
X11_DESC=	Build GTK+3 based GUI program

FDK_AAC_CONFIGURE_ENABLE=	fdk-aac
FDK_AAC_VARS=			LICENSE+=FDK_AAC LICENSE_COMB=multi
LICENSE_NAME_FDK_AAC=		Software License for The Fraunhofer FDK AAC Codec Library for Android
LICENSE_FILE_FDK_AAC=		${BUILD_WRKSRC}/contrib/fdkaac/${DISTFILES:Mfdk*:R:R}/NOTICE
LICENSE_PERMS_FDK_AAC=		dist-mirror pkg-mirror auto-accept

.include <bsd.port.options.mk>

# Recent GNU binutils are required to handle inline SSSE3 asm (in x264), and
# to support --exclude-libs option for ld(1) when building GUI program
.if ${PORT_OPTIONS:MX11}
BUILD_DEPENDS+=	${LOCALBASE}/bin/ld:devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
LIB_DEPENDS+=	libvpx.so:multimedia/libvpx
.endif
CC!=/usr/bin/which ${CC}
MAKE_ENV+=ACLOCAL=${LOCALBASE}/bin/aclocal

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--disable-gtk-update-checks --disable-gst
LIB_DEPENDS+=	libdbus-glib-1.so:devel/dbus-glib \
		libnotify.so:devel/libnotify
USES+=		gettext
USE_GNOME+=	gtk30 intltool
PLIST_FILES+=	bin/HandBrake

DESKTOP_ENTRIES="HandBrake" \
		"${COMMENT}" \
		"" \
		"HandBrake" \
		"AudioVideo;" \
		false
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

# HandBrake tries to fetch its dependencies during build phase, which is not
# considered good in FreeBSD.  Instead, we will prepare everything manually.
post-extract: .SILENT
# Unversioned directories can be copied in a loop
.for d in a52dec libdca x264
	${MKDIR} ${BUILD_WRKSRC}/contrib/${d}
	${MV} ${WRKDIR}/${d} ${BUILD_WRKSRC}/contrib/${d}
.endfor
# Others had to be processed one by one due to irregular (versioned) names
	cd ${BUILD_WRKSRC}/contrib && ${MKDIR} faac faad2 ffmpeg libbluray libdvdnav \
	    libdvdread libvpx x265
	${MV} ${WRKDIR}/faac-1.28 ${BUILD_WRKSRC}/contrib/faac
	${MV} ${WRKDIR}/faad2-2.7 ${BUILD_WRKSRC}/contrib/faad2
	${MV} ${WRKDIR}/libav-v10.1 ${BUILD_WRKSRC}/contrib/ffmpeg/libav-v10.1
	${MV} ${WRKDIR}/libbluray-0.5.0 ${BUILD_WRKSRC}/contrib/libbluray
	${MV} ${WRKDIR}/libdvdnav-5.0.1-0-gaa3659d ${BUILD_WRKSRC}/contrib/libdvdnav
	${MV} ${WRKDIR}/libdvdread-5.0.0-6-gcb1ae87 ${BUILD_WRKSRC}/contrib/libdvdread
	${MV} ${WRKDIR}/libvpx-v1.3.0 ${BUILD_WRKSRC}/contrib/libvpx
	${MV} ${WRKDIR}/x265_1.9 ${BUILD_WRKSRC}/contrib/x265
# Avoid conflict with `print/harfbuzz' (also installs "hb.h")
	${MV} ${WRKSRC}/libhb/hb.h ${WRKSRC}/libhb/hb-of-handbrake.h
# Mark all bundled dependencies as extracted
	${TOUCH} ${BUILD_WRKSRC}/contrib/a52dec/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/faac/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/faad2/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/ffmpeg/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/libbluray/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/libdca/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/libdvdnav/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/libdvdread/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/libvpx/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/x264/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/x265/.stamp.extract

post-extract-FDK_AAC-on:
	${MKDIR} ${BUILD_WRKSRC}/contrib/fdkaac
	${MV} ${WRKDIR}/fdk-aac-v0.1.1-6-gbae4553 ${BUILD_WRKSRC}/contrib/fdkaac
	${TOUCH} ${BUILD_WRKSRC}/contrib/fdkaac/.stamp.extract

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|' \
		${BUILD_WRKSRC}/contrib/a52dec/a52dec/libao/audio_out_oss.c
	@${REINPLACE_CMD} -e 's|-ldl|-lc| ; s|\[dl\]|[c]| ; s|ACLOCAL=.*|ACLOCAL=aclocal|g' \
		${BUILD_WRKSRC}/contrib/libbluray/libbluray-0.5.0/configure
	@${REINPLACE_CMD} -e 's|ACLOCAL = @ACLOCAL@|ACLOCAL = ${LOCALBASE}/bin/aclocal|g' \
		-e 's|-D_ISOC99_SOURCE -D_POSIX_C_SOURCE=200112L -D_REENTRANT||g' \
		${BUILD_WRKSRC}/contrib/libbluray/libbluray-0.5.0/Makefile.in \
		${BUILD_WRKSRC}/contrib/libbluray/libbluray-0.5.0/src/Makefile.in
	@${REINPLACE_CMD} \
		-e '/GHB_PACKAGES=/s/gthread-2.0/& gmodule-2.0/' \
		-e 's/-lhb/& ${ICONV_LIB}/' \
		-e 's/-lhandbrake/& ${ICONV_LIB}/' \
		-e 's:-lxml2:& ../../contrib/lib/libx265.a:g' \
		${WRKSRC}/gtk/configure.ac
	@${REINPLACE_CMD} -e 's|<malloc|<stdlib|' ${WRKSRC}/libhb/fifo.c
	@${FIND} ${WRKSRC} -type f -name '*.[ch]' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e '/#include/s|hb\.h|hb-of-handbrake.h|'
	@${REINPLACE_CMD} -e "s|ToolProbe( 'GCC.gcc',   'gcc',|ToolProbe( 'GCC.gcc',   '${CC}',|" \
		${WRKSRC}/make/configure.py
	@${REINPLACE_CMD} -e 's|avcodec avformat avutil avresample|avformat avcodec avresample avutil|' \
		-e 's|TEST.libs = $$(LIBHB.a)|& ${ICONV_LIB}|' \
		${WRKSRC}/libhb/module.defs ${WRKSRC}/test/module.defs
	@${TR} -d '\r' < ${WRKSRC}/contrib/ffmpeg/A06-frame-threading-state.patch > ${WRKDIR}/A06-frame-threading-state.patch
	@${MV} ${WRKDIR}/A06-frame-threading-state.patch ${WRKSRC}/contrib/ffmpeg/
	@${REINPLACE_CMD} -E \
		-e 's|%%REP_CC%%|${CC}|g' \
		-e 's|%%REP_CXX%%|${CXX}|g' \
		-e 's|%%REP_I%%|-I./contrib/include -I${LOCALBASE}/include|g' \
		-e 's|%%REP_L%%|-L${LOCALBASE}/lib|g' \
		-e 's|%%REP_ARCHS%%|${CPUTYPE}|g' \
		-e 's|%%REP_ICONV%%|${ICONV_LIB:S/-l//}|g' \
		${WRKSRC}/custom.defs

post-patch-X11-off:
	@${REINPLACE_CMD} -e 's:--enable-libvpx:--disable-libvpx:' ${WRKSRC}/contrib/ffmpeg/module.defs
	@${REINPLACE_CMD} -e 's| vpx | |' \
		${WRKSRC}/libhb/module.defs ${WRKSRC}/test/module.defs

post-patch-FDK_AAC-on:
	@${REINPLACE_CMD} -e 's:/lib/cpp:${CPP}:g' ${BUILD_WRKSRC}/contrib/fdkaac/fdk-aac-v0.1.1-6-gbae4553/configure
	@${REINPLACE_CMD} -e 's:-lxml2:& ../../contrib/lib/libfdk-aac.a:g' \
		${WRKSRC}/gtk/configure.ac

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/HandBrakeCLI ${STAGEDIR}${PREFIX}/bin

do-install-X11-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gtk/src/ghb ${STAGEDIR}${PREFIX}/bin/HandBrake

.include <bsd.port.mk>
