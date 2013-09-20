# Created by: Andrew Thompson <andy@fud.org.nz>
# $FreeBSD$

PORTNAME=	handbrake
PORTVERSION=	0.9.8
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION} \
		http://download.handbrake.fr/handbrake/contrib/:contrib
DISTFILES=	HandBrake-${PORTVERSION}.tar.bz2 \
		a52dec-0.7.4.tar.gz:contrib \
		faac-1.28.tar.gz:contrib \
		faad2-2.7.tar.gz:contrib \
		ffmpeg-v0.7-1696-gcae4f4b.tar.bz2:contrib \
		fontconfig-2.8.0.tar.gz:contrib \
		freetype-2.4.7.tar.bz2:contrib \
		lame-3.98.tar.gz:contrib \
		libass-0.10.0-1.tar.gz:contrib \
		libbluray-0.0.1-pre-213-ga869da8.tar.gz:contrib \
		libdca-r81-strapped.tar.gz:contrib \
		libdvdnav-svn1168.tar.gz:contrib \
		libdvdread-svn1168.tar.gz:contrib \
		libmkv-0.6.5-0-g82075ae.tar.gz:contrib \
		libogg-1.3.0.tar.gz:contrib \
		libsamplerate-0.1.4.tar.gz:contrib \
		libtheora-1.1.0.tar.bz2:contrib \
		libvorbis-aotuv_b6.03.tar.bz2:contrib \
		libxml2-2.7.7.tar.gz:contrib \
		mp4v2-trunk-r355.tar.bz2:contrib \
		mpeg2dec-0.5.1.tar.gz:contrib \
		x264-r2146-bcd41db.tar.gz:contrib
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	dmarion@FreeBSD.org
COMMENT=	Versatile DVD ripper and video transcoder

LICENSE=	GPLv2

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm
LIB_DEPENDS=	libfribidi.so:${PORTSDIR}/converters/fribidi
RUN_DEPENDS=	${LOCALBASE}/lib/libdvdcss.so:${PORTSDIR}/multimedia/libdvdcss

USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtool aclocal
LIBTOOLFILES=	configure
USE_PYTHON_BUILD=	yes
WANT_GNOME=	yes

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# Recent GNU binutils are required to handle inline SSSE3 asm (in x264), and
# to support --exclude-libs option for ld(1) when building GUI program
.if ${PORT_OPTIONS:MX11} || ${OSVERSION} < 802509 || \
	${OSVERSION} >= 900000 && ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/ld:${PORTSDIR}/devel/binutils
CONFIGURE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--disable-gtk-update-checks --disable-gst
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libnotify.so:${PORTSDIR}/devel/libnotify
USE_GNOME=	gtk20
PLIST_FILES+=	bin/HandBrake
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

run-autotools-aclocal:
	@${DO_NADA}

# HandBrake tries to fetch its dependencies during build phase, which is not
# considered good in FreeBSD.  Instead, we will prepare everything manually.
post-extract: .SILENT
# Unversioned directories can be copied in a loop
.for d in a52dec lame libdca libdvdnav libdvdread libsamplerate mpeg2dec x264
	${MKDIR} ${BUILD_WRKSRC}/contrib/${d}
	${MV} ${WRKDIR}/${d} ${BUILD_WRKSRC}/contrib/${d}
.endfor
# Others had to be processed one by one due to irregular (versioned) names
	cd ${BUILD_WRKSRC}/contrib && ${MKDIR} faac faad2 ffmpeg fontconfig \
		freetype libass libbluray libmkv libogg libtheora libvorbis \
		libxml2 mp4v2
	${MV} ${WRKDIR}/faac-1.28 ${BUILD_WRKSRC}/contrib/faac
	${MV} ${WRKDIR}/faad2-2.7 ${BUILD_WRKSRC}/contrib/faad2
	${MV} ${WRKDIR}/ffmpeg-v0.7-1696-gcae4f4b \
		${BUILD_WRKSRC}/contrib/ffmpeg
	${MV} ${WRKDIR}/fontconfig-2.8.0 ${BUILD_WRKSRC}/contrib/fontconfig
	${MV} ${WRKDIR}/freetype-2.4.7 ${BUILD_WRKSRC}/contrib/freetype
	${MV} ${WRKDIR}/libass-0.10.0-1 ${BUILD_WRKSRC}/contrib/libass
	${MV} ${WRKDIR}/libbluray-0.0.1-pre-213-ga869da8 \
		${BUILD_WRKSRC}/contrib/libbluray
	${MV} ${WRKDIR}/libmkv-0.6.5-0-g82075ae ${BUILD_WRKSRC}/contrib/libmkv
	${MV} ${WRKDIR}/libogg-1.3.0 ${BUILD_WRKSRC}/contrib/libogg
	${MV} ${WRKDIR}/libtheora-1.1.0 ${BUILD_WRKSRC}/contrib/libtheora
	${MV} ${WRKDIR}/aotuv-b6.03_20110424 ${BUILD_WRKSRC}/contrib/libvorbis
	${MV} ${WRKDIR}/libxml2-2.7.7 ${BUILD_WRKSRC}/contrib/libxml2
	${MV} ${WRKDIR}/mp4v2-trunk-r355 ${BUILD_WRKSRC}/contrib/mp4v2
# Remove one patch file that does not apply cleanly
	${RM} ${WRKSRC}/contrib/fontconfig/A00-config.patch
# Avoid conflict with `print/harfbuzz' (also installs "hb.h")
	${MV} ${WRKSRC}/libhb/hb.h ${WRKSRC}/libhb/hb-of-handbrake.h

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|' \
		${BUILD_WRKSRC}/contrib/a52dec/a52dec/libao/audio_out_oss.c
	@${REINPLACE_CMD} -e 's|-ldl|-lc| ; s|\[dl\]|[c]|' \
		${BUILD_WRKSRC}/contrib/libbluray/libbluray-0.0.1-pre-213-ga869da8/configure.ac
	@${REINPLACE_CMD} -e 's|<malloc|<stdlib|' ${WRKSRC}/libhb/fifo.c
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/contrib/libass/module.defs \
		${WRKSRC}/libhb/module.defs ${WRKSRC}/test/module.defs
	@${REINPLACE_CMD} -e 's|libdvdcss\.so\.2|libdvdcss.so|' \
		${BUILD_WRKSRC}/contrib/libdvdread/libdvdread/src/dvd_input.c
	@${FIND} ${WRKSRC} -type f -name '*.[ch]' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e '/#include/s|hb\.h|hb-of-handbrake.h|'

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/HandBrakeCLI ${PREFIX}/bin
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gtk/src/ghb ${PREFIX}/bin/HandBrake
.endif

.include <bsd.port.post.mk>
