# Created by: Andrew Thompson <andy@fud.org.nz>
# $FreeBSD$

PORTNAME=	handbrake
PORTVERSION=	0.9.9
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION} \
		http://download.handbrake.fr/handbrake/contrib/:contrib
DISTFILES=	HandBrake-${PORTVERSION}.tar.bz2 \
		a52dec-0.7.4.tar.gz:contrib \
		faac-1.28.tar.gz:contrib \
		faad2-2.7.tar.gz:contrib \
		libav-v9.6.tar.bz2:contrib \
		lame-3.98.tar.gz:contrib \
		libbluray-0.2.3.tar.bz2:contrib \
		libdca-r81-strapped.tar.gz:contrib \
		libdvdnav-svn1168.tar.gz:contrib \
		libdvdread-svn1168.tar.gz:contrib \
		libmkv-0.6.5-0-g82075ae.tar.gz:contrib \
		mp4v2-trunk-r355.tar.bz2:contrib \
		mpeg2dec-0.5.1.tar.gz:contrib \
		x264-r2273-b3065e6.tar.gz:contrib
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Versatile DVD ripper and video transcoder

LICENSE=	GPLv2

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm
LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libass.so:${PORTSDIR}/multimedia/libass \
		libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libvorbisenc.so:${PORTSDIR}/audio/libvorbis \
		libtheoradec.so:${PORTSDIR}/multimedia/libtheora \
		libtheoraenc.so:${PORTSDIR}/multimedia/libtheora \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate
.if !defined(PACKAGE_BUILDING)
# DVDCSS version hardcoded in contrib/libdvdread/libdvdread/src/dvd_input.c (dlopen'ed)
LIB_DEPENDS+=	libdvdcss.so.2:${PORTSDIR}/multimedia/libdvdcss
.endif

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool:build pkgconfig python:build
USE_AUTOTOOLS=	autoconf:env automake:env

WRKSRC=		${WRKDIR}/HandBrake-${PORTVERSION}
PLIST_FILES=	bin/HandBrakeCLI

CONFIGURE_ARGS=	--force
CONFIGURE_TARGET=	build

BUILD_WRKSRC=	${WRKSRC}/build
MAKEFILE=	GNUmakefile
ALL_TARGET=	#
MAKE_JOBS_UNSAFE=	yes

NOPRECIOUSMAKEVARS=	yes			# for ffmpeg and x264

OPTIONS_DEFINE=	X11
X11_DESC=	Build GTK+2 based GUI program
OPTIONS_DEFAULT=	X11

.include <bsd.port.options.mk>

# Recent GNU binutils are required to handle inline SSSE3 asm (in x264), and
# to support --exclude-libs option for ld(1) when building GUI program
.if ${PORT_OPTIONS:MX11} || ${OSVERSION} < 802509 || \
	${OSVERSION} >= 900000 && ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/ld:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--disable-gtk-update-checks --disable-gst
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libnotify.so:${PORTSDIR}/devel/libnotify
USE_GNOME+=	gtk20
PLIST_FILES+=	bin/HandBrake
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

# Enforce linking to the system c++ standard lib
.if ${OSVERSION} >= 1000054
LDFLAGS+=	-lc++
.else
LDFLAGS+=	-lstdc++
.endif

# HandBrake tries to fetch its dependencies during build phase, which is not
# considered good in FreeBSD.  Instead, we will prepare everything manually.
post-extract: .SILENT
# Unversioned directories can be copied in a loop
.for d in a52dec lame libdca libdvdnav libdvdread mpeg2dec x264
	${MKDIR} ${BUILD_WRKSRC}/contrib/${d}
	${MV} ${WRKDIR}/${d} ${BUILD_WRKSRC}/contrib/${d}
.endfor
# Others had to be processed one by one due to irregular (versioned) names
	cd ${BUILD_WRKSRC}/contrib && ${MKDIR} faac faad2 ffmpeg libbluray libmkv mp4v2
	${MV} ${WRKDIR}/faac-1.28 ${BUILD_WRKSRC}/contrib/faac
	${MV} ${WRKDIR}/faad2-2.7 ${BUILD_WRKSRC}/contrib/faad2
	${MV} ${WRKDIR}/libav-v9.6 ${BUILD_WRKSRC}/contrib/ffmpeg/libav-v9.6
	${MV} ${WRKDIR}/libbluray-0.2.3 ${BUILD_WRKSRC}/contrib/libbluray
	${MV} ${WRKDIR}/libmkv-0.6.5-0-g82075ae ${BUILD_WRKSRC}/contrib/libmkv
	${MV} ${WRKDIR}/mp4v2-trunk-r355 ${BUILD_WRKSRC}/contrib/mp4v2
# Avoid conflict with `print/harfbuzz' (also installs "hb.h")
	${MV} ${WRKSRC}/libhb/hb.h ${WRKSRC}/libhb/hb-of-handbrake.h
# Mark all bundled dependencies as extracted
	${TOUCH} ${BUILD_WRKSRC}/contrib/a52dec/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/faac/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/faad2/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/ffmpeg/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/lame/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/libbluray/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/libdca/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/libdvdnav/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/libdvdread/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/libmkv/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/mp4v2/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/mpeg2dec/.stamp.extract
	${TOUCH} ${BUILD_WRKSRC}/contrib/x264/.stamp.extract

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|' \
		${BUILD_WRKSRC}/contrib/a52dec/a52dec/libao/audio_out_oss.c
	@${REINPLACE_CMD} -e 's|-ldl|-lc| ; s|\[dl\]|[c]|' \
		${BUILD_WRKSRC}/contrib/libbluray/libbluray-0.2.3/configure.ac
	@${REINPLACE_CMD} \
		-e '/GHB_PACKAGES=/s/gthread-2.0/& gmodule-2.0/' \
		-e 's/-lhb/& ${ICONV_LIB}/' \
		${WRKSRC}/gtk/configure.ac
	@${REINPLACE_CMD} -e 's|<malloc|<stdlib|' ${WRKSRC}/libhb/fifo.c
	@${FIND} ${WRKSRC} -type f -name '*.[ch]' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e '/#include/s|hb\.h|hb-of-handbrake.h|'
	@${REINPLACE_CMD} -e "s|ToolProbe( 'GCC.gcc',   'gcc',|ToolProbe( 'GCC.gcc',   '${CC}',|" \
		${WRKSRC}/make/configure.py
	@${REINPLACE_CMD} -e 's|avcodec avformat avutil avresample|avformat avcodec avresample avutil|' \
		${WRKSRC}/libhb/module.defs ${WRKSRC}/test/module.defs
	${TR} -d '\r' < ${WRKSRC}/contrib/mpeg2dec/A02-gwluserdata.patch > ${WRKDIR}/A02-gwluserdata.patch
	${MV} ${WRKDIR}/A02-gwluserdata.patch ${WRKSRC}/contrib/mpeg2dec/
	@${REINPLACE_CMD} -E \
		-e 's|%%REP_CC%%|${CC}|g' \
		-e 's|%%REP_CXX%%|${CXX}|g' \
		-e 's|%%REP_I%%|-I./contrib/include -I${LOCALBASE}/include|g' \
		-e 's|%%REP_L%%|-L${LOCALBASE}/lib|g' \
		-e 's|%%REP_ARCHS%%|${CPUTYPE}|g' \
		-e 's|%%REP_ICONV%%|${ICONV_LIB:S/-l//}|g' \
		${WRKSRC}/custom.defs

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/HandBrakeCLI ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gtk/src/ghb ${STAGEDIR}${PREFIX}/bin/HandBrake
.endif

.include <bsd.port.mk>
