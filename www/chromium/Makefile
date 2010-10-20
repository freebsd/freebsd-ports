# New ports collection makefile for:	chromium
# Date created:				September 30 2009
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chromium
DISTVERSIONPREFIX=	courgette-redacted-
DISTVERSION=	5.0.375.127
CATEGORIES=	www
MASTER_SITES=	http://chromium.hybridsource.org/old/ports/ \
		CRITICAL

MAINTAINER=	chromium@hybridsource.org
COMMENT=	A mostly BSD-licensed web browser based on WebKit and Gtk+

BUILD_DEPENDS=	flex:${PORTSDIR}/textproc/flex		\
		gperf:${PORTSDIR}/devel/gperf		\
		bash:${PORTSDIR}/shells/bash		\
		pkg-config:${PORTSDIR}/devel/pkg-config	\
		nss>=3.12:${PORTSDIR}/security/nss	\
		yasm:${PORTSDIR}/devel/yasm

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo	\
		cairo.2:${PORTSDIR}/graphics/cairo		\
		dbus-1.3:${PORTSDIR}/devel/dbus			\
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib	\
		Xss.1:${PORTSDIR}/x11/libXScrnSaver		\
		asound.2:${PORTSDIR}/audio/alsa-lib		\
		freetype.9:${PORTSDIR}/print/freetype2

RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_BISON=	build
USE_PYTHON=	2.6			# only needed at build time
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_GCC=	4.2+
MAN1=		chrome.1
USE_XORG=	scrnsaverproto
USE_GNOME=	glib20 gtk20 gconf2
LICENSE_COMB=	multi
LICENSE=	BSD LGPL21 MPL

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

OPTIONS=	CODECS		"Compile and enable patented codecs like H.264" off

DESKTOP_ENTRIES=	"Chromium" \
			"${COMMENT}" \
			"${DATADIR}/product_logo_48.png" \
			"chrome" \
			"Application;Network;WebBrowser;" \
			"true"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build on 6.X
.endif

.if defined(WITH_CODECS)
GYP_DEFINES+=	ffmpeg_branding=Chrome
.else
GYP_DEFINES+=	ffmpeg_branding=Chromium
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
		${WRKSRC}/third_party/icu/public/common/unicode/pfreebsd.h   \
		${WRKSRC}/third_party/tcmalloc/chromium/src/config_freebsd.h \
		${WRKSRC}/third_party/WebKit/WebCore/plugins/PluginDatabase.cpp \
		${WRKSRC}/v8/tools/gyp/v8.gyp

do-configure:
	cd ${WRKSRC} && \
		${SETENV} GYP_GENERATORS="make" GYP_DEFINES="${GYP_DEFINES}" ${PYTHON_CMD} ./build/gyp_chromium chrome/chrome.gyp --depth ./

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/out/${BUILDTYPE}/chrome.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/chrome.pak ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/product_logo_48.png ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/out/${BUILDTYPE}/chrome-wrapper ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/out/${BUILDTYPE}/xdg-settings ${DATADIR}
.for f in chrome ffmpegsumo_nolink libffmpegsumo.so mksnapshot protoc
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/${f} ${DATADIR}
.endfor
	cd ${WRKSRC}/out/${BUILDTYPE} && ${COPYTREE_SHARE} "locales resources" ${DATADIR}
	${LN} -sf ${DATADIR}/chrome ${PREFIX}/bin/

.include <bsd.port.post.mk>
