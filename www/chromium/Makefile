# New ports collection makefile for:	chromium
# Date created:				September 30 2009
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chromium
DISTVERSIONPREFIX=	courgette-redacted-
DISTVERSION=	14.0.835.202
CATEGORIES=	www
MASTER_SITES=	http://download.goodking.org/downloads/ \
		ftp://rene-ladan.nl/pub/distfiles/ \
		http://files.etoilebsd.net/goodking/ \
		http://distfiles.cybertron.gr/

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	A mostly BSD-licensed web browser based on WebKit and Gtk+

LICENSE=	BSD LGPL21 MPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		bash:${PORTSDIR}/shells/bash \
		yasm:${PORTSDIR}/devel/yasm \
		flock:${PORTSDIR}/sysutils/flock \
		v4l_compat>=1.0.20110603:${PORTSDIR}/multimedia/v4l_compat \
		nss>=3.12:${PORTSDIR}/security/nss
# minimal version of nss, LIB_DEPENDS does not enforce this

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		cairo.2:${PORTSDIR}/graphics/cairo \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		asound.2:${PORTSDIR}/audio/alsa-lib \
		freetype.9:${PORTSDIR}/print/freetype2 \
		nss3.1:${PORTSDIR}/security/nss \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring \
		cups.2:${PORTSDIR}/print/cups-client \
		icuuc.48:${PORTSDIR}/devel/icu \
		icui18n.48:${PORTSDIR}/devel/icu \
		icudata.48:${PORTSDIR}/devel/icu \
		event-1.4:${PORTSDIR}/devel/libevent \
		vpx:${PORTSDIR}/multimedia/libvpx \
		tcmalloc.2:${PORTSDIR}/devel/google-perftools

RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins \
		${LOCALBASE}/lib/X11/fonts/Droid/fonts.dir:${PORTSDIR}/x11-fonts/droid-fonts-ttf \
		${LOCALBASE}/lib/libgcrypt.so:${PORTSDIR}/security/libgcrypt

ONLY_FOR_ARCHS=	i386 amd64
USE_XZ=		yes
USE_BISON=	build
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_PYTHON_BUILD=	2.6+
USE_XORG=	scrnsaverproto x11 xproto xscrnsaver xtst
USE_GNOME=	glib20 gtk20 dconf libxslt pkgconfig
MAN1=		chrome.1

DESKTOP_ENTRIES="Chromium" "${COMMENT}" "${DATADIR}/product_logo_48.png" \
		"chrome" "Application;Network;WebBrowser;" true

ALL_TARGET=	chrome

# See build/common.gypi for all the available variables.
GYP_DEFINES+=	use_cups=1 \
		use_system_icu=1 \
		use_system_vpx=1 \
		use_system_yasm=1 \
		use_system_libxml=1 \
		use_system_ffmpeg=0 \
		use_system_libevent=1 \
		use_system_tcmalloc=1 \
		linux_use_heapchecker=0 \
		disable_nacl=1 \
		enable_webrtc=0 \
		enable_openmax=1 \
		os_ver=${OSVERSION} \
		prefix_dir=${LOCALBASE} \
		python_ver=${PYTHON_VER}

OPTIONS=	CODECS	"Compile and enable patented codecs like H.264"	on \
		GCONF	"Use GConf2 for preferences"			on \
		CLANG	"Compile Chromium with clang"			off \
		GCC45	"Compile Chromium with gcc 4.5+"		off \
		DEBUG	"Compile with debug symbols and verbose output"	off

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900033 || defined(WITH_GCC45)
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${OSVERSION} < 801000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-base__base.gypi-stub
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-base__base.gypi-freebsd
.endif

.if defined(WITH_CODECS)
GYP_DEFINES+=	ffmpeg_branding=Chrome
GYP_DEFINES+=	use_proprietary_codecs=1
.else
GYP_DEFINES+=	ffmpeg_branding=Chromium
GYP_DEFINES+=	use_proprietary_codecs=0
.endif

.if defined(WITH_GCONF)
USE_GNOME+=	gconf2
.else
GYP_DEFINES+=	use_gconf=0
.endif

.if ! ${MACHINE_CPU:Msse2}
GYP_DEFINES+=	disable_sse2=1
.endif

.if defined(GCC45) && defined(CLANG)
IGNORE=	conflicting options (CLANG or GCC45)
.endif

.if defined(WITH_GCC45)
USE_GCC?=	4.5+
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-gcc
.endif

.if defined(WITH_CLANG)
.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	clang:${PORTSDIR}/lang/clang
.endif
CC=		clang
CXX=		clang++
GYP_DEFINES+=	clang=1
.endif

.if !defined(WITH_DEBUG)
BUILDTYPE=	Release
.else
MAKE_ENV+=	V=1
BUILDTYPE=	Debug
.endif

MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
BUILD_DEPENDS+=	p5-Switch>=0:${PORTSDIR}/lang/p5-Switch
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build Chromium, you should have around 1 GB of memory"
.if defined(WITH_DEBUG)
	@${ECHO_MSG} "and lots of free diskspace (~ 7GB)."
.else
	@${ECHO_MSG} "and a fair amount of free diskspace (~ 1.5GB)."
.endif
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|" \
		${WRKSRC}/base/base.gypi \
		${WRKSRC}/build/common.gypi \
		${WRKSRC}/third_party/libvpx/libvpx.gyp \
		${WRKSRC}/third_party/WebKit/Source/WebCore/plugins/PluginDatabase.cpp \
		${WRKSRC}/v8/tools/gyp/v8.gyp
	@${REINPLACE_CMD} -e "s|linux|freebsd|" \
		${WRKSRC}/tools/gyp/pylib/gyp/generator/make.py
	@${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|' \
		${WRKSRC}/third_party/WebKit/Source/WebCore/bindings/scripts/IDLParser.pm \
		${WRKSRC}/third_party/WebKit/Source/WebCore/dom/make_names.pl
	@${REINPLACE_CMD} -e "s|'flex'|'${LOCALBASE}/bin/flex'|" \
		${WRKSRC}/third_party/angle/src/build_angle.gyp \
		${WRKSRC}/third_party/WebKit/Source/WebCore/WebCore.gyp/scripts/action_maketokenizer.py
	@${REINPLACE_CMD} -e 's|gperf --key-positions|${LOCALBASE}/bin/gperf --key-positions|' \
		${WRKSRC}/third_party/WebKit/Source/WebCore/css/makeprop.pl \
		${WRKSRC}/third_party/WebKit/Source/WebCore/css/makevalues.pl \
		${WRKSRC}/third_party/WebKit/Source/WebCore/make-hash-tools.pl

do-configure:
	cd ${WRKSRC} && \
		GYP_DEFINES="${GYP_DEFINES}" ${PYTHON_CMD} \
			./build/gyp_chromium chrome/chrome.gyp --depth .

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/out/${BUILDTYPE}/chrome.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/chrome.pak \
		${WRKSRC}/out/${BUILDTYPE}/product_logo_48.png \
		${WRKSRC}/out/${BUILDTYPE}/resources.pak ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/out/${BUILDTYPE}/chrome-wrapper \
		${WRKSRC}/out/${BUILDTYPE}/xdg-settings ${DATADIR}
.for f in chrome ffmpegsumo_nolink libffmpegsumo.so mksnapshot protoc
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/${f} ${DATADIR}
.endfor
	cd ${WRKSRC}/out/${BUILDTYPE} && \
		${COPYTREE_SHARE} "locales resources" ${DATADIR}
	${LN} -sf ${DATADIR}/chrome ${PREFIX}/bin

.include <bsd.port.post.mk>
