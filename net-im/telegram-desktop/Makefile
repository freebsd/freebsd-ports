PORTNAME=	telegram-desktop
DISTVERSION=	4.5.0
CATEGORIES=	net-im
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTNAME=	tdesktop-${DISTVERSION}-full
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Telegram Desktop messaging app
WWW=		https://desktop.telegram.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	does not build, webrtc related
NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	Only little endian is supported

BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib \
		microsoft-gsl>0:devel/microsoft-gsl \
		pulseaudio>0:audio/pulseaudio \
		range-v3>0:devel/range-v3 \
		tl-expected>0:devel/tl-expected \
		v4l_compat>0:multimedia/v4l_compat \
		yasm:devel/yasm \
		${LOCALBASE}/lib/libtg_owt.a:net-im/tg_owt
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libavformat.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libdispatch.so:devel/libdispatch \
		libhunspell-1.7.so:textproc/hunspell \
		libjpeg.so:graphics/jpeg-turbo \
		liblz4.so:archivers/liblz4 \
		libminizip.so:archivers/minizip \
		libopenal.so:audio/openal-soft \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpipewire-0.3.so:multimedia/pipewire \
		libprotobuf.so:devel/protobuf \
		libqrcodegencpp.so:graphics/qr-code-generator \
		librnnoise.so:audio/rnnoise \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxkbcommon.so:x11/libxkbcommon \
		libxxhash.so:devel/xxhash \
		libvpx.so:multimedia/libvpx

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}
qt5_PKGNAMESUFFIX=
qt6_PKGNAMESUFFIX=	-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}

USES=		cmake compiler:c++17-lang desktop-file-utils gl \
		gnome localbase pkgconfig python:3.7+,build ssl xorg

USE_GITHUB=	nodefault
GH_ACCOUNT=	telegramdesktop
GH_PROJECT=	tdesktop

.if ${FLAVOR} == qt5
USES+=		kde:5 qt:5
USE_QT=		buildtools:build core dbus gui imageformats network qmake:build \
		svg wayland widgets
USE_KDE=	coreaddons kimageformats
.else
USES+=		qt:6
USE_QT=		5compat base imageformats lottie shadertools svg tools:build wayland
.endif

USE_GL=		gl
USE_GNOME=	glib20 glibmm26
USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xrandr xrender xtst

CMAKE_ARGS=	-DTDESKTOP_API_ID=${TELEGRAM_API_ID} -DTDESKTOP_API_HASH=${TELEGRAM_API_HASH}
CMAKE_ON=	DESKTOP_APP_USE_PACKAGED DESKTOP_APP_DISABLE_CRASH_REPORTS \
		DESKTOP_APP_DISABLE_WAYLAND_INTEGRATION
CMAKE_OFF=	DESKTOP_APP_USE_PACKAGED_FONTS

# libdispatch components
LDFLAGS+=	-lBlocksRuntime

# see Bugzilla #245452 for details
NO_CCACHE=	yes

# Telegram uses OpenAL for its audio, but libtgvoip (for voice calls) can use PulseAudio or ALSA.
# It dynamically loads PulseAudio, and if this fails, it loads ALSA.
# If both of them are not installed, then voice calls do not work, but other functionalities still work.
OPTIONS_DEFAULT=	ALSA
OPTIONS_MULTI=		AUDIO
OPTIONS_MULTI_AUDIO=	ALSA PULSEAUDIO

AUDIO_DESC=	Audio backend for voice calls

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

# Telegram asks each custom build to have its own API ID and hash.
TELEGRAM_API_HASH=	20a3432aab43f24bb4460fceac5ba38d
TELEGRAM_API_ID=	601761

.include <bsd.port.pre.mk>

.if ${COMPILER_VERSION} < 130
LLVM_VER=	13
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CC=		${LOCALBASE}/bin/clang${LLVM_VER}
CXX=		${LOCALBASE}/bin/clang++${LLVM_VER}
.endif

.include <bsd.port.post.mk>
