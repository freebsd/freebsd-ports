# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$

#TODO eadler: s/python/python2/g on a number of files, chromium does not build with python3

PORTNAME=	chromium
PORTVERSION=	33.0.1750.152
CATEGORIES=	www
MASTER_SITES=	http://commondatastorage.googleapis.com/chromium-browser-official/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	Mostly BSD-licensed web browser based on WebKit and Gtk+

LICENSE=	BSD3CLAUSE LGPL21 MPL
LICENSE_COMB=	multi

CFLAGS+=	-fno-stack-protector

BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		bash:${PORTSDIR}/shells/bash \
		yasm:${PORTSDIR}/devel/yasm \
		flock:${PORTSDIR}/sysutils/flock \
		v4l_compat>=1.0.20110603:${PORTSDIR}/multimedia/v4l_compat

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libasound.so:${PORTSDIR}/audio/alsa-lib \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libnss3.so:${PORTSDIR}/security/nss \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libcups.so:${PORTSDIR}/print/cups-client \
		libevent-1.4.so:${PORTSDIR}/devel/libevent \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libpci.so:${PORTSDIR}/devel/libpci

RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins \
		${LOCALBASE}/lib/X11/fonts/Droid/fonts.dir:${PORTSDIR}/x11-fonts/droid-fonts-ttf

ONLY_FOR_ARCHS=	i386 amd64
USES=		bison compiler:c++11-lib desktop-file-utils pkgconfig \
		perl5 shebangfix ninja tar:xz
USE_PERL5=	build
USE_PYTHON_BUILD=	2.6-2.7
USE_XORG=	scrnsaverproto x11 xproto xscrnsaver xtst
USE_GNOME=	glib20 gtk20 dconf libxslt

SHEBANG_FILES=	chrome/tools/build/linux/chrome-wrapper
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
		werror= \
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

SUB_FILES=	chromium-browser.desktop chrome
SUB_LIST+=	COMMENT="${COMMENT}"

OPTIONS_DEFINE=	CODECS GCONF PULSEAUDIO TEST DEBUG
CODECS_DESC=	Compile and enable patented codecs like H.264

OPTIONS_DEFAULT=	CODECS GCONF

GCONF_USE=	GNOME=gconf2
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio

TEST_DISTFILES=	${PORTNAME}-${DISTVERSION}-testdata${EXTRACT_SUFX}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCODECS}
GYP_DEFINES+=	ffmpeg_branding=Chrome
GYP_DEFINES+=	proprietary_codecs=1
.else
GYP_DEFINES+=	ffmpeg_branding=Chromium
GYP_DEFINES+=	proprietary_codecs=0
.endif

.if ! ${PORT_OPTIONS:MGCONF}
GYP_DEFINES+=	use_gconf=0
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
GYP_DEFINES+=	use_pulseaudio=1
.else
GYP_DEFINES+=	use_pulseaudio=0
.endif

.if ! ${MACHINE_CPU:Msse2}
GYP_DEFINES+=	disable_sse2=1
.endif

.if ${OSVERSION} >= 1000052 && !exists(${LOCALBASE}/include/execinfo.h)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-fixup-execinfo
.endif
.if ${OSVERSION} < 1000052
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif

.if ${PORT_OPTIONS:MTEST}
.include "Makefile.tests"
ALL_TARGET+=	${TEST_TARGETS}
.endif

DEBUG_MAKE_ENV=	V=1
.if ${PORT_OPTIONS:MDEBUG}
BUILDTYPE=	Debug
GYP_DEFINES+=	remove_webcore_debug_symbols=1
.else
BUILDTYPE=	Release
GYP_DEFINES+=	buildtype=Official
.endif

CONFIGURE_ENV+=	CC=${CC} \
		CXX=${CXX} \
		GYP_GENERATORS=ninja \
		GYP_DEFINES="${GYP_DEFINES}"
MAKE_ENV+=	BUILDTYPE=${BUILDTYPE} \
		GPERF=${LOCALBASE}/bin/gperf
MAKE_ARGS+=	-C out/${BUILDTYPE}

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
GYP_DEFINES+=	gcc_version=${CXX:S/g++//}
CFLAGS+=	-Wno-unknown-warning
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-gcc
.else
GYP_DEFINES+=	clang=1
CFLAGS+=	-Wno-unknown-warning-option
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-clang
CONFIGURE_ENV+=	AR=/usr/bin/ar
.endif

# according to portlint the below is passed via bsd.port.mk,
# but 'make -V CONFIGURE_ENV' does not show it:
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}"

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
		${WRKSRC}/crypto/crypto.gyp \
		${WRKSRC}/third_party/libvpx/libvpx.gyp \
		${WRKSRC}/third_party/WebKit/Source/testing/testing.gyp \
		${WRKSRC}/v8/tools/gyp/v8.gyp \
		${WRKSRC}/v8/build/toolchain.gypi
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" \
		${WRKSRC}/chrome/common/chrome_paths.cc
	@${REINPLACE_CMD} -e "s|/usr/bin/gcc|${CC}|" \
		${WRKSRC}/third_party/WebKit/Source/build/scripts/preprocessor.pm \
		${WRKSRC}/third_party/WebKit/Source/build/scripts/scripts.gypi
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
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./build/gyp_chromium chrome/chrome.gyp --depth .

test regression-test: build
.for t in ${TEST_TARGETS}
	cd ${WRKSRC}/out/${BUILDTYPE} && ${SETENV} LC_ALL=en_US.UTF-8 \
		./${t} --gtest_filter=-${EXCLUDE_${t}:ts:} || ${TRUE}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/out/${BUILDTYPE}/chrome.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/product_logo_48.png ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/out/${BUILDTYPE}/chrome-wrapper \
		${WRKSRC}/out/${BUILDTYPE}/xdg-settings ${STAGEDIR}${DATADIR}
.for p in chrome chrome_100_percent content_resources resources
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${p}.pak ${STAGEDIR}${DATADIR}
.endfor
.for f in chrome libffmpegsumo.so protoc
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/${f} ${STAGEDIR}${DATADIR}
.endfor
	cd ${WRKSRC}/out/${BUILDTYPE} && \
		${COPYTREE_SHARE} "locales resources" ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/chromium-browser.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/chrome ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
