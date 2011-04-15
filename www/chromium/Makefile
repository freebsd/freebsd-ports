# New ports collection makefile for:	chromium
# Date created:				September 30 2009
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chromium
DISTVERSIONPREFIX=	courgette-redacted-
DISTVERSION=	10.0.648.205
CATEGORIES=	www
MASTER_SITES=	http://download.goodking.org/downloads/ \
		ftp://rene-ladan.nl/pub/distfiles/ \
		http://files.etoilebsd.net/goodking/
DISTNAME=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	chromium@FreeBSD.org
COMMENT=	A mostly BSD-licensed web browser based on WebKit and Gtk+

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		bash:${PORTSDIR}/shells/bash \
		yasm:${PORTSDIR}/devel/yasm \
		nss>=3.12:${PORTSDIR}/security/nss
# minimal version of nss, LIB_DEPENDS does not enforce this

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		cairo.2:${PORTSDIR}/graphics/cairo \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		asound.2:${PORTSDIR}/audio/alsa-lib \
		freetype.9:${PORTSDIR}/print/freetype2 \
		nss3.1:${PORTSDIR}/security/nss \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring

RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins \
		${LOCALBASE}/lib/X11/fonts/Droid/fonts.dir:${PORTSDIR}/x11-fonts/droid-fonts-ttf

ONLY_FOR_ARCHS=	i386 amd64
USE_XZ=		yes
USE_BISON=	build
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_PYTHON_BUILD=	2.6+
USE_XORG=	scrnsaverproto x11 xproto xscrnsaver xtst
USE_GNOME=	glib20 gtk20 dconf libxslt pkgconfig
MAN1=		chrome.1
LICENSE_COMB=	multi
LICENSE=	BSD LGPL21 MPL

DESKTOP_ENTRIES="Chromium" "${COMMENT}" "${DATADIR}/product_logo_48.png" \
		"chrome" "Application;Network;WebBrowser;" true

ALL_TARGET=	chrome

#user tunables showing defaults, some won't compile if changed
#GYP_DEFINES+=	target_arch=ia32     #or x64, should be detected automatically
#GYP_DEFINES+=	use_system_bzip2=1
#GYP_DEFINES+=	use_system_libevent=0
#GYP_DEFINES+=	use_system_libjpeg=1
#GYP_DEFINES+=	use_system_libpng=1
GYP_DEFINES+=	use_system_libxml=1
GYP_DEFINES+=	use_system_ffmpeg=0
#GYP_DEFINES+=	use_system_sqlite=0
GYP_DEFINES+=	use_system_yasm=1
#GYP_DEFINES+=	use_system_zlib=1
GYP_DEFINES+=	python_ver=${PYTHON_VER}

OPTIONS=	CODECS	"Compile and enable patented codecs like H.264"	off \
		GCONF	"Use GConf2 for preferences"			on \
		VPX	"Use system libvpx for VP8 codec"		on

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
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

.if defined(WITH_VPX)
LIB_DEPENDS+=	vpx:${PORTSDIR}/multimedia/libvpx
GYP_DEFINES+=	use_system_vpx=1
.endif

.if !defined(WITH_DEBUG)
BUILDTYPE=	Release
.else
BUILDTYPE=	Debug
STRIP=
.endif

MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}
MAKE_JOBS_SAFE=	yes

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
	@${REINPLACE_CMD} -e "s|/usr/include/vpx|${LOCALBASE}/include|" \
		${WRKSRC}/third_party/ffmpeg/ffmpeg.gyp
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
# kludges just to make it progress for now
	@${REINPLACE_CMD} -e "s|/usr/lib|${LOCALBASE}/lib|" \
			-e "s|'python_ver%': '2.5'|'python_ver%': '2.6'|" \
			-e "s|.so.1.0|.so.1|" \
				${WRKSRC}/build/common.gypi
	@${REINPLACE_CMD} -e "s|'-ldl',|'-lc',|" \
		${WRKSRC}/app/app_base.gypi \
		${WRKSRC}/build/linux/system.gyp \
		${WRKSRC}/chrome/chrome_browser.gypi \
		${WRKSRC}/media/media.gyp

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

post-install:
.if ${OSVERSION} < 900000
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
