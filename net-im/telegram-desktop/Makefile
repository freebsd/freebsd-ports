# $FreeBSD$

PORTNAME=	telegram-desktop
DISTVERSION=	2.1.0
CATEGORIES=	net-im
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTNAME=	tdesktop-${DISTVERSION}-full

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Telegram Desktop messaging app

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	Only little endian is supported

BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib \
		dee>0:devel/dee \
		pulseaudio>0:audio/pulseaudio \
		range-v3>0:devel/range-v3 \
		microsoft-gsl>0:devel/microsoft-gsl \
		tl-expected>0:devel/tl-expected
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libdbus-1.so:devel/dbus \
		libminizip.so:archivers/minizip \
		libopenal.so:audio/openal-soft \
		libopus.so:audio/opus \
		libdbusmenu-qt5.so:devel/libdbusmenu-qt \
		libhunspell-1.7.so:textproc/hunspell \
		libxxhash.so:devel/xxhash \
		libenchant-2.so:textproc/enchant2 \
		liblz4.so:archivers/liblz4

USES=		cmake compiler:c++17-lang desktop-file-utils \
		gnome pkgconfig python:3.7,build qt:5 ssl xorg

# see Bugzilla #245452 for details
NO_CCACHE=	yes

GH_ACCOUNT=	telegramdesktop
GH_PROJECT=	tdesktop
USE_GNOME=	glib20
USE_QT=		core dbus gui imageformats network widgets buildtools_build \
		qmake_build
USE_XORG=	x11 xcb

CMAKE_ON=	DESKTOP_APP_USE_PACKAGED DESKTOP_APP_DISABLE_CRASH_REPORTS \
		TDESKTOP_DISABLE_REGISTER_CUSTOM_SCHEME TDESKTOP_DISABLE_DESKTOP_FILE_GENERATION
CMAKE_OFF=	DESKTOP_APP_USE_PACKAGED_RLOTTIE DESKTOP_APP_USE_PACKAGED_VARIANT \
		DESKTOP_APP_USE_GLIBC_WRAPS TDESKTOP_USE_PACKAGED_TGVOIP
CMAKE_ARGS=	-DDESKTOP_APP_SPECIAL_TARGET="" -DTDESKTOP_LAUNCHER_BASENAME="telegramdesktop" \
		-DTDESKTOP_API_ID=${TELEGRAM_API_ID} -DTDESKTOP_API_HASH=${TELEGRAM_API_HASH} \
		-Ddisable_autoupdate=1

# Telegram asks each custom build to have its own API ID and hash.
TELEGRAM_API_ID=	601761
TELEGRAM_API_HASH=	20a3432aab43f24bb4460fceac5ba38d

# Telegram uses OpenAL for its audio, but libtgvoip (for voice calls) can use PulseAudio or ALSA.
# It dynamically loads PulseAudio, and if this fails, it loads ALSA.
# If both of them are not installed, then voice calls do not work, but other functionalities still work.
OPTIONS_MULTI=		AUDIO
OPTIONS_MULTI_AUDIO=	ALSA PULSEAUDIO
OPTIONS_DEFINE=		GTK
OPTIONS_DEFAULT=	ALSA

AUDIO_DESC=	Audio backend for voice calls
GTK_DESC=	Gtk integration (Use Gtk dialogs, etc.)

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

GTK_CMAKE_BOOL_OFF=	TDESKTOP_DISABLE_GTK_INTEGRATION

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK}
USE_GNOME+=	gtk30
.endif

.include <bsd.port.mk>
