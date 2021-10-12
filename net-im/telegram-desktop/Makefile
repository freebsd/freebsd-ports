PORTNAME=	telegram-desktop
DISTVERSION=	3.1.9
CATEGORIES=	net-im
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTNAME=	tdesktop-${DISTVERSION}-full
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Telegram Desktop messaging app

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
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libdbusmenu-qt5.so:devel/libdbusmenu-qt \
		libenchant-2.so:textproc/enchant2 \
		libevent.so:devel/libevent \
		libhunspell-1.7.so:textproc/hunspell \
		libjpeg.so:graphics/jpeg-turbo \
		liblz4.so:archivers/liblz4 \
		libminizip.so:archivers/minizip \
		librnnoise.so:audio/rnnoise \
		libopenal.so:audio/openal-soft \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpipewire-0.3.so:multimedia/pipewire \
		libqrcodegencpp.so:graphics/qr-code-generator \
		libusrsctp.so:net/libusrsctp \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxkbcommon.so:x11/libxkbcommon \
		libxxhash.so:devel/xxhash \
		libvpx.so:multimedia/libvpx

USES=		cmake compiler:c++17-lang desktop-file-utils gl \
		gnome pkgconfig python:3.7+,build qt:5 ssl xorg

USE_GITHUB=	nodefault
GH_ACCOUNT=	telegramdesktop
GH_PROJECT=	tdesktop
USE_GL=		gl
USE_GNOME=	glib20 glibmm
INSTALLS_ICONS=	yes
USE_QT=		core dbus gui imageformats network widgets buildtools_build \
		qmake_build wayland svg
USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xrender xrandr xtst

CMAKE_ARGS=	-DDESKTOP_APP_SPECIAL_TARGET="" -DTDESKTOP_LAUNCHER_BASENAME="telegramdesktop" \
		-DTDESKTOP_API_ID=${TELEGRAM_API_ID} -DTDESKTOP_API_HASH=${TELEGRAM_API_HASH} \
		-Ddisable_autoupdate=1
CMAKE_ON=	DESKTOP_APP_USE_PACKAGED DESKTOP_APP_DISABLE_CRASH_REPORTS \
		TDESKTOP_DISABLE_REGISTER_CUSTOM_SCHEME TDESKTOP_DISABLE_DESKTOP_FILE_GENERATION \
		DESKTOP_APP_DISABLE_WAYLAND_INTEGRATION
CMAKE_OFF=	DESKTOP_APP_USE_PACKAGED_RLOTTIE DESKTOP_APP_USE_PACKAGED_VARIANT \
		DESKTOP_APP_USE_GLIBC_WRAPS TDESKTOP_USE_PACKAGED_TGVOIP \
		DESKTOP_APP_USE_PACKAGED_FONTS

# Disable DCHECKs, otherwise video calls will crash.
CXXFLAGS+=	-DNDEBUG

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

.if ${CHOSEN_COMPILER_TYPE} == clang && ${COMPILER_VERSION} <= 100
post-patch:
	@${REINPLACE_CMD} -e '/-fstack-clash-protection/d' ${WRKSRC}/cmake/options_linux.cmake
.endif

.include <bsd.port.post.mk>
