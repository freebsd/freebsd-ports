PORTNAME=	obs-studio
DISTVERSION=	31.1.2
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/obsproject/obs-studio/releases/download/${DISTVERSION}/
DISTFILES=	OBS-Studio-${DISTVERSION}-Sources${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source streaming/recording software
WWW=		https://obsproject.com/ \
		https://github.com/obsproject/obs-studio

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv7=	compilation fails: format specifies type 'unsigned long' but the argument has type 'size_t' (aka 'unsigned int') [-Werror,-Wformat] (32-builds aren't supported, see issue 10481)
BROKEN_i386=	link fails: relocation R_386_PC32 cannot be used against symbol 'strlist_split'; recompile with -fPIC, see https://github.com/obsproject/obs-studio/issues/10481

BUILD_DEPENDS=	asio>0:net/asio \
		${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json \
		v4l_compat>=0:multimedia/v4l_compat \
		swig:devel/swig \
		uthash>0:devel/uthash \
		websocketpp>0:devel/websocketpp
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libdatachannel.so:www/libdatachannel \
		libdbus-1.so:devel/dbus \
		libdrm.so:graphics/libdrm \
		libfdk-aac.so:audio/fdk-aac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjansson.so:devel/jansson \
		libmbedtls.so:security/mbedtls3 \
		libpci.so:devel/libpci \
		libqrcodegencpp.so:graphics/qr-code-generator \
		librist.so:multimedia/librist \
		librnnoise.so:audio/rnnoise \
		libspeexdsp.so:audio/speexdsp \
		libsrt.so:www/srt \
		libsysinfo.so:devel/libsysinfo \
		libudev.so:devel/libudev-devd \
		libv4l2.so:multimedia/libv4l \
		libx264.so:multimedia/libx264 \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-util.so:x11/xcb-util \
		libxkbcommon.so:x11/libxkbcommon \
		libuuid.so:misc/libuuid \
		libva.so:multimedia/libva

USES=		cmake compiler:c++17-lang desktop-file-utils gl gnome kde:6 lua luajit \
		pkgconfig python qt:6 xorg
USE_QT=		base svg tools:build
USE_KDE=	ecm:build
USE_GNOME=	glib20
USE_GL=		gl
USE_XORG=	ice sm x11 xcb xcomposite xext xfixes xinerama xrandr
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DOBS_VERSION_OVERRIDE:STRING="${PORTVERSION}" \
		-DQT_VERSION=6 \
		-DPython_EXECUTABLE="${PYTHON_CMD}"

CFLAGS_powerpc64=	-Wno-error=deprecated-altivec-src-compat -Wno-error=pass-failed
CFLAGS_powerpc64le=	-Wno-error=deprecated-altivec-src-compat
LDFLAGS+=	-fPIC # pending https://github.com/obsproject/obs-studio/issues/3436

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-sources

OPTIONS_DEFINE=		BROWSER PIPEWIRE VLC VST WAYLAND
OPTIONS_DEFAULT=	PIPEWIRE VLC VST WAYLAND
OPTIONS_MULTI=		AUDIO
OPTIONS_MULTI_AUDIO=	JACK PULSEAUDIO SNDIO
OPTIONS_DEFAULT+=	${OPTIONS_MULTI_AUDIO}
OPTIONS_SUB=		yes
AUDIO_DESC=		Audio backends

BROWSER_DESC=		Build OSB browser
BROWSER_CMAKE_BOOL=	BUILD_BROWSER # this also requires an additional git submodule
BROWSER_BROKEN=		Needs CEF (Chromium Embedded Framework) which isn't yet ported

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_ON=		-DENABLE_JACK=TRUE
JACK_CMAKE_OFF=		-DDISABLE_JACK=TRUE

PIPEWIRE_DESC=		Screen capture via PipeWire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	ENABLE_PIPEWIRE

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ENABLE_PULSEAUDIO

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_ON=		-DENABLE_SNDIO=TRUE
SNDIO_CMAKE_OFF=	-DDISABLE_SNDIO=TRUE

VLC_DESC=		Enable VLC plugin
VLC_CMAKE_BOOL=		ENABLE_VLC
VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc

VST_DESC=		Build VST submodule
VST_CMAKE_BOOL=		ENABLE_VST

WAYLAND_CATEGORIES=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != powerpc && ${ARCH} != powerpc64 && ${ARCH} != powerpc64le
PLIST_SUB+=	LUAJIT="@comment "
.else
PLIST_SUB+=	LUAJIT=""
.endif

.include <bsd.port.post.mk>
