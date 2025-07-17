PORTNAME=	telegram-desktop
DISTVERSION=	5.16.4
PORTREVISION=	1
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
#BROKEN_SSL=	openssl openssl31
#BROKEN_SSL_REASON=	undefined symbol: ERR_load_BIO_strings
NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	Only little endian is supported

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		microsoft-gsl>0:devel/microsoft-gsl \
		range-v3>0:devel/range-v3 \
		tl-expected>0:devel/tl-expected \
		v4l_compat>0:multimedia/v4l_compat \
		yasm:devel/yasm \
		${LOCALBASE}/lib/libtde2e.a:net-im/tde2e \
		${LOCALBASE}/lib/libtg_owt.a:net-im/tg_owt
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libada.so:devel/libada \
		libavformat.so:multimedia/ffmpeg \
		libcrc32c.so:devel/crc32c \
		libdbus-1.so:devel/dbus \
		libdispatch.so:devel/libdispatch \
		libfmt.so:devel/libfmt \
		libgeoclue-2.so:net/geoclue \
		libgeocode-glib-2.so:net/geocode-glib2 \
		libheif.so:graphics/libheif \
		libhunspell-1.7.so:textproc/hunspell \
		libjxl.so:graphics/libjxl \
		liblz4.so:archivers/liblz4 \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpipewire-0.3.so:multimedia/pipewire \
		libprotobuf-lite.so:devel/protobuf \
		libqrcodegencpp.so:graphics/qr-code-generator \
		librnnoise.so:audio/rnnoise \
		libsrtp2.so:net/libsrtp2 \
		libxxhash.so:devel/xxhash \
		libvpx.so:multimedia/libvpx

USES=		cmake compiler:c++20-lang desktop-file-utils gl gnome jpeg kde:6 localbase \
		minizip openal pkgconfig python:build qt:6 ssl

USE_GITHUB=	nodefault
GH_ACCOUNT=	telegramdesktop
GH_PROJECT=	tdesktop

USE_QT=		5compat base declarative imageformats lottie shadertools svg tools:build
USE_KDE=	coreaddons kimageformats

USE_GL=		gl
USE_GNOME=	glib20 glibmm26 introspection

CMAKE_ARGS=	-DTDESKTOP_API_ID=${TELEGRAM_API_ID} -DTDESKTOP_API_HASH=${TELEGRAM_API_HASH} \
		-DQT_VERSION_MAJOR=6
# The order of the variables is important here due to complex combination validation 
CMAKE_ON=	DESKTOP_APP_USE_PACKAGED \
		DESKTOP_APP_DISABLE_CRASH_REPORTS \
		DESKTOP_APP_DISABLE_QT_PLUGINS

# Since cmake 3.25.0, BSDs are no longer recognised as Linux (in this port).
CMAKE_ARGS+=	-DLINUX=true

# libdispatch components
LDFLAGS+=	-lBlocksRuntime

# Telegram uses OpenAL for its audio, but libtgvoip (for voice calls) can use PulseAudio or ALSA.
# It dynamically loads PulseAudio, and if this fails, it loads ALSA.
# If both of them are not installed, then voice calls do not work, but other functionalities still work.
OPTIONS_DEFINE=		SYSTEM_FONTS
OPTIONS_DEFAULT=	ALSA X11 WAYLAND
OPTIONS_GROUP=	AUDIO
OPTIONS_MULTI=	DESKTOP
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO
OPTIONS_MULTI_DESKTOP=	X11 WAYLAND

AUDIO_DESC=		Audio backend for voice calls
DESKTOP_DESC=		Desktop integration
SYSTEM_FONTS_DESC=	Use system fonts instead of bundled patched ones

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
SYSTEM_FONTS_CMAKE_BOOL_OFF=	DESKTOP_APP_USE_PACKAGED_FONTS
WAYLAND_USE=		qt=wayland
X11_CMAKE_BOOL_OFF=	DESKTOP_APP_DISABLE_X11_INTEGRATION
X11_USES=		xorg
X11_USE=		xorg=x11,xcb,xcomposite,xdamage,xext,xfixes,xrandr,xtst
X11_LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms \
			libxkbcommon.so:x11/libxkbcommon

# Telegram asks each custom build to have its own API ID and hash.
TELEGRAM_API_HASH=	20a3432aab43f24bb4460fceac5ba38d
TELEGRAM_API_ID=	601761

post-extract:
	# Some of the third-party components already built, and
	# can be safely removed
	${RM} -rf \
		${WRKSRC}/Telegram/ThirdParty/GSL \
		${WRKSRC}/Telegram/ThirdParty/QR \
		${WRKSRC}/Telegram/ThirdParty/dispatch \
		${WRKSRC}/Telegram/ThirdParty/expected \
		${WRKSRC}/Telegram/ThirdParty/fcitx5-qt \
		${WRKSRC}/Telegram/ThirdParty/hime \
		${WRKSRC}/Telegram/ThirdParty/hunspell \
		${WRKSRC}/Telegram/ThirdParty/jemalloc \
		${WRKSRC}/Telegram/ThirdParty/jimf \
		${WRKSRC}/Telegram/ThirdParty/kcoreaddons \
		${WRKSRC}/Telegram/ThirdParty/kimageformats \
		${WRKSRC}/Telegram/ThirdParty/lz4 \
		${WRKSRC}/Telegram/ThirdParty/minizip \
		${WRKSRC}/Telegram/ThirdParty/plasma-wayland-protocols \
		${WRKSRC}/Telegram/ThirdParty/range-v3 \
		${WRKSRC}/Telegram/ThirdParty/wayland \
		${WRKSRC}/Telegram/ThirdParty/wayland-protocols \
		${WRKSRC}/Telegram/ThirdParty/xxHash

post-patch:
	# XXX fix the following on every source file
	# warning: unknown warning option '-Wno-maybe-uninitialized'
	# warning: argument unused during compilation: '-fstack-clash-protection'
	${REINPLACE_CMD} -e /-Wno-maybe-uninitialized/d -e /-fstack-clash-protection/d \
	    ${WRKSRC}/cmake/options_linux.cmake

.include <bsd.port.mk>
