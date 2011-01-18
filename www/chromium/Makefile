# New ports collection makefile for:	chromium
# Date created:				September 30 2009
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chromium
DISTVERSIONPREFIX=	courgette-redacted-
DISTVERSION=	6.0.472.63
CATEGORIES=	www
MASTER_SITES=	http://download.goodking.org/downloads/ \
		ftp://rene-ladan.nl/pub/distfiles/ \
		CRITICAL

MAINTAINER=	rene@FreeBSD.org
COMMENT=	A mostly BSD-licensed web browser based on WebKit and Gtk+

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex		\
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf		\
		bash:${PORTSDIR}/shells/bash		\
		pkg-config:${PORTSDIR}/devel/pkg-config	\
		yasm:${PORTSDIR}/devel/yasm		\
		nss>=3.12:${PORTSDIR}/security/nss
# minimal version of nss, LIB_DEPENDS does not enforce this

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo	\
		avformat:${PORTSDIR}/multimedia/ffmpeg		\
		cairo.2:${PORTSDIR}/graphics/cairo		\
		dbus-1.3:${PORTSDIR}/devel/dbus			\
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib	\
		Xss.1:${PORTSDIR}/x11/libXScrnSaver		\
		asound.2:${PORTSDIR}/audio/alsa-lib		\
		freetype.9:${PORTSDIR}/print/freetype2		\
		nss3.1:${PORTSDIR}/security/nss			\
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring

FORBIDDEN=		several security vulnerabilities

RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins \
		${LOCALBASE}/lib/X11/fonts/Droid/fonts.dir:${PORTSDIR}/x11-fonts/droid-fonts-ttf

ONLY_FOR_ARCHS=	i386 amd64
USE_XZ=		yes
USE_BISON=	build
USE_PYTHON=	2.6+			# only needed at build time
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
MAN1=		chrome.1
USE_XORG=	scrnsaverproto xtst
USE_GNOME=	glib20 gtk20 dconf libxslt
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
#GYP_DEFINES+=	use_system_sqlite=0
#GYP_DEFINES+=	use_system_zlib=1

.include <bsd.port.options.mk>

OPTIONS=	CODECS		"Compile and enable patented codecs like H.264" off \
		GCONF		"Use gconf2 for preferences"		on \
		SSE2		"Use SSE2, disable this for PIII or older" on \
		VPX		"Use system libvpx for VP8 codec"	on

.include <bsd.port.pre.mk>

.if defined(WITH_CODECS)
GYP_DEFINES+=	ffmpeg_branding=Chrome
.else
GYP_DEFINES+=	ffmpeg_branding=Chromium
.endif

.if defined(WITH_GCONF)
USE_GNOME+=	gconf2
.else
GYP_DEFINES+=	use_gconf=0
.endif

.if defined(WITHOUT_SSE2)
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
.endif

MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}
MAKE_JOBS_SAFE=	yes
STRIP=

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
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|"	\
		${WRKSRC}/base/base.gypi			\
		${WRKSRC}/build/common.gypi			\
		${WRKSRC}/third_party/ffmpeg/ffmpeg.gyp		\
		${WRKSRC}/third_party/icu/public/common/unicode/pfreebsd.h   \
		${WRKSRC}/third_party/tcmalloc/chromium/src/config_freebsd.h \
		${WRKSRC}/third_party/WebKit/WebCore/plugins/PluginDatabase.cpp \
		${WRKSRC}/v8/tools/gyp/v8.gyp
	@${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|' \
		${WRKSRC}/third_party/WebKit/WebCore/bindings/scripts/IDLParser.pm \
		${WRKSRC}/third_party/WebKit/WebCore/dom/make_names.pl
	@${REINPLACE_CMD} -e "s|'flex'|'${LOCALBASE}/bin/flex'|" \
		${WRKSRC}/third_party/angle/src/build_angle.gyp  \
		${WRKSRC}/third_party/WebKit/WebCore/WebCore.gyp/scripts/action_maketokenizer.py
	@${REINPLACE_CMD} -e 's|gperf --key-positions|${LOCALBASE}/bin/gperf --key-positions|' \
		${WRKSRC}/third_party/WebKit/WebCore/css/makeprop.pl	\
		${WRKSRC}/third_party/WebKit/WebCore/css/makevalues.pl	\
		${WRKSRC}/third_party/WebKit/WebCore/make-hash-tools.pl

do-configure:
	cd ${WRKSRC} && \
		GYP_DEFINES="${GYP_DEFINES}" ${PYTHON_CMD} ./build/gyp_chromium chrome/chrome.gyp --depth ./

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/out/${BUILDTYPE}/chrome.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/chrome.pak ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/product_logo_48.png ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/resources.pak ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/out/${BUILDTYPE}/chrome-wrapper ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/out/${BUILDTYPE}/xdg-settings ${DATADIR}
.for f in chrome ffmpegsumo_nolink libffmpegsumo.so mksnapshot protoc
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/${f} ${DATADIR}
.endfor
	cd ${WRKSRC}/out/${BUILDTYPE} && ${COPYTREE_SHARE} "locales resources" ${DATADIR}
	${LN} -sf ${DATADIR}/chrome ${PREFIX}/bin/

.include <bsd.port.post.mk>
