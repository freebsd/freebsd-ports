# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$

#TODO eadler: s/python/python2/g on a number of files, chromium does not build with python3

PORTNAME=	chromium
DISTVERSIONPREFIX=	courgette-redacted-
DISTVERSION=	28.0.1500.71
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.goodking.org/downloads/ \
		ftp://rene-ladan.nl/pub/distfiles/ \
		http://files.etoilebsd.net/goodking/

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	Mostly BSD-licensed web browser based on WebKit and Gtk+

LICENSE=	BSD LGPL21 MPL
LICENSE_COMB=	multi

CFLAGS+=	-Wno-error -fno-stack-protector

BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		bash:${PORTSDIR}/shells/bash \
		yasm:${PORTSDIR}/devel/yasm \
		flock:${PORTSDIR}/sysutils/flock \
		v4l_compat>=1.0.20110603:${PORTSDIR}/multimedia/v4l_compat

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		cairo:${PORTSDIR}/graphics/cairo \
		dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		asound:${PORTSDIR}/audio/alsa-lib \
		freetype:${PORTSDIR}/print/freetype2 \
		nss3:${PORTSDIR}/security/nss \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		cups:${PORTSDIR}/print/cups-client \
		event-1:${PORTSDIR}/devel/libevent \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		pci:${PORTSDIR}/devel/libpci

RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins \
		${LOCALBASE}/lib/X11/fonts/Droid/fonts.dir:${PORTSDIR}/x11-fonts/droid-fonts-ttf

ONLY_FOR_ARCHS=	i386 amd64
USE_XZ=		yes
USES=		bison gmake desktop-file-utils pkgconfig
USE_PERL5_BUILD=	yes
USE_PYTHON_BUILD=	2.6-2.7
USE_XORG=	scrnsaverproto x11 xproto xscrnsaver xtst
USE_GNOME=	glib20 gtk20 dconf libxslt
MAN1=		chrome.1

ALL_TARGET=	chrome

# See build/common.gypi for all the available variables.
GYP_DEFINES+=	use_cups=1 \
		use_system_yasm=1 \
		use_system_libxml=1 \
		use_system_ffmpeg=0 \
		use_system_libusb=1 \
		use_system_libevent=1 \
		use_system_libvpx=0 \
		linux_breakpad=0 \
		linux_strip_binary=1 \
		linux_use_tcmalloc=0 \
		linux_use_heapchecker=0 \
		test_isolation_mode=noop \
		clang_use_chrome_plugins=0 \
		disable_nacl=1 \
		enable_webrtc=1 \
		enable_openmax=1 \
		enable_one_click_signin=1 \
		no_gc_sections=1 \
		os_ver=${OSVERSION} \
		prefix_dir=${LOCALBASE} \
		python_ver=${PYTHON_VER}

# FreeBSD Chromium Api Key
# Set up Google API keys, see http://www.chromium.org/developers/how-tos/api-keys .
# Note: these are for FreeBSD use ONLY. For your own distribution,
# please get your own set of keys.
GYP_DEFINES+=	google_api_key=AIzaSyBsp9n41JLW8jCokwn7vhoaMejDFRd1mp8 \
		google_default_client_id=996322985003.apps.googleusercontent.com \
		google_default_client_secret=IR1za9-1VK0zZ0f_O8MVFicn

SUB_FILES=	chromium-browser.desktop
SUB_LIST=	COMMENT="${COMMENT}" \
		DATADIR=${DATADIR}

OPTIONS_DEFINE=	CODECS GCONF PULSEAUDIO CLANG DEBUG

CODECS_DESC=	Compile and enable patented codecs like H.264
CLANG_DESC=	Build Chromium with Clang instead of GCC 4.6+

OPTIONS_DEFAULT=	CODECS GCONF CLANG

.include <bsd.port.options.mk>

.if ${OSVERSION} < 902000 || ! ${PORT_OPTIONS:MCLANG}
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${PORT_OPTIONS:MCODECS}
GYP_DEFINES+=	ffmpeg_branding=Chrome
GYP_DEFINES+=	proprietary_codecs=1
.else
GYP_DEFINES+=	ffmpeg_branding=Chromium
GYP_DEFINES+=	proprietary_codecs=0
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
.else
GYP_DEFINES+=	use_gconf=0
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
GYP_DEFINES+=	use_pulseaudio=1
.else
GYP_DEFINES+=	use_pulseaudio=0
.endif

.if ! ${MACHINE_CPU:Msse2}
GYP_DEFINES+=	disable_sse2=1
.endif

.if ${PORT_OPTIONS:MCLANG}
.if ${OSVERSION} < 902000
BUILD_DEPENDS+=	clang:${PORTSDIR}/lang/clang
.endif
CC=		clang
CXX=		clang++
GYP_DEFINES+=	clang=1
.else
USE_GCC?=	4.6+
GYP_DEFINES+=	gcc_version=${CXX:S/g++//}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-gcc
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ENV+=	V=1
BUILDTYPE=	Debug
.else
BUILDTYPE=	Release
GYP_DEFINES+=	buildtype=Official
.endif

MAKE_ENV+=	BUILDTYPE=${BUILDTYPE} \
		GPERF=${LOCALBASE}/bin/gperf

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To build Chromium, you should have around 1 GB of memory"
.if ${PORT_OPTIONS:MDEBUG}
	@${ECHO_MSG} "and lots of free diskspace (~ 8.5GB)."
.else
	@${ECHO_MSG} "and a fair amount of free diskspace (~ 2.4GB)."
.endif
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|" \
		${WRKSRC}/base/base.gypi \
		${WRKSRC}/build/common.gypi \
		${WRKSRC}/third_party/libvpx/libvpx.gyp \
		${WRKSRC}/crypto/crypto.gyp \
		${WRKSRC}/v8/tools/gyp/v8.gyp \
		${WRKSRC}/v8/build/common.gypi
	@${REINPLACE_CMD} -e "s|linux|freebsd|" \
		${WRKSRC}/tools/gyp/pylib/gyp/generator/make.py
	@${REINPLACE_CMD} -e "s|is_linux|(is_linux or is_bsd)|" \
		${WRKSRC}/chrome/browser/browser_resources.grd \
		${WRKSRC}/chrome/app/theme/theme_resources.grd \
		${WRKSRC}/chrome/browser/resources/task_manager/defines.js \
		${WRKSRC}/tools/grit/grit/xtb_reader_unittest.py \
		${WRKSRC}/ui/base/strings/app_locale_settings.grd \
		${WRKSRC}/ui/base/strings/app_locale_settings_bn.xtb \
		${WRKSRC}/ui/base/strings/app_locale_settings_ja.xtb \
		${WRKSRC}/ui/base/strings/app_locale_settings_ko.xtb \
		${WRKSRC}/ui/base/strings/app_locale_settings_ml.xtb \
		${WRKSRC}/ui/base/strings/app_locale_settings_th.xtb

do-configure:
	cd ${WRKSRC} && \
		GYP_DEFINES="${GYP_DEFINES}" ${PYTHON_CMD} \
			./build/gyp_chromium chrome/chrome.gyp --depth .

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/out/${BUILDTYPE}/chrome.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/product_logo_48.png ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/out/${BUILDTYPE}/chrome-wrapper \
		${WRKSRC}/out/${BUILDTYPE}/xdg-settings ${DATADIR}
.for p in chrome chrome_100_percent content_resources resources
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${p}.pak ${DATADIR}
.endfor
.for f in chrome libffmpegsumo.so protoc
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/${f} ${DATADIR}
.endfor
	cd ${WRKSRC}/out/${BUILDTYPE} && \
		${COPYTREE_SHARE} "locales resources" ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/chromium-browser.desktop ${DESKTOPDIR}
	${LN} -sf ${DATADIR}/chrome ${PREFIX}/bin

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
