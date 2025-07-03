PORTNAME=	obs-studio
DISTVERSION=	31.0.3
PORTREVISION=	2
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	ff4522e2edf0f3bb40753f412944344050139794.patch:-p1 # v4l2loopback/virtual camera: Add support for non-Linux environments (updated PR)

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

USES=		cmake compiler:c++17-lang desktop-file-utils gl gnome lua luajit \
		pkgconfig python qt:6 xorg
USE_QT=		base svg tools:build
USE_GNOME=	glib20
USE_GL=		gl
USE_XORG=	ice sm x11 xcb xcomposite xext xfixes xinerama xrandr
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	obsproject
GH_TUPLE=	obsproject:libdshowcapture:ef8c1d2e19c93e664100dd41e1a0df4f8ad45430:obsproject_libdshowcapture/plugins/win-dshow/libdshowcapture \
		obsproject:obs-browser:e4e523df775bd6fa216d40a7488b76f3b21c1733:obsproject_obs_browser/plugins/obs-browser \
		Mixer:ftl-sdk:d0c8469f66806b5ea738d607f7d2b000af8b1129:Mixer_ftl_sdk/plugins/obs-outputs/ftl-sdk \
		obsproject:obs-websocket:a73c92788d70f08f91b8c0477b74f99c999beb09:obsproject_obs_websocket/plugins/obs-websocket \
		elgatosf:capture-device-support:81c94fb13dfddb412fcb17f1ba031917ec24be64:elgatosf_capture_device_support/deps/libdshowcapture/src/external/capture-device-support

CMAKE_ON=	UNIX_STRUCTURE
CMAKE_ARGS=	-DOBS_VERSION_OVERRIDE:STRING="${PORTVERSION}" \
		-DQT_VERSION=6 \
		-DPython_EXECUTABLE="${PYTHON_CMD}"

CFLAGS_powerpc64=	-Wno-error=deprecated-altivec-src-compat -Wno-error=pass-failed
CFLAGS_powerpc64le=	-Wno-error=deprecated-altivec-src-compat
LDFLAGS+=	-fPIC # pending https://github.com/obsproject/obs-studio/issues/3436

OPTIONS_DEFINE=		BROWSER PIPEWIRE VLC VST WAYLAND
OPTIONS_DEFAULT=	PIPEWIRE VLC VST WAYLAND
OPTIONS_MULTI=		AUDIO
OPTIONS_MULTI_AUDIO=	JACK PULSEAUDIO SNDIO
OPTIONS_DEFAULT+=	${OPTIONS_MULTI_AUDIO}
OPTIONS_SUB=		yes
AUDIO_DESC=		Audio backends

BROWSER_DESC=		Build OSB browser
BROWSER_CMAKE_BOOL=	BUILD_BROWSER
BROWSER_BROKEN=		Needs CEF (Chromium Embedded Framework) which isn't yet ported

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_ON=		-DENABLE_JACK=TRUE
JACK_CMAKE_OFF=		-DDISABLE_JACK=TRUE

PIPEWIRE_DESC=		Screen capture via PipeWire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	ENABLE_PIPEWIRE

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DENABLE_PULSEAUDIO=TRUE
PULSEAUDIO_CMAKE_OFF=	-DDISABLE_PULSEAUDIO=TRUE
PULSEAUDIO_BROKEN_OFF=	https://github.com/obsproject/obs-studio/issues/4025

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_ON=		-DENABLE_SNDIO=TRUE
SNDIO_CMAKE_OFF=	-DDISABLE_SNDIO=TRUE

VLC_DESC=		Enable VLC plugin
VLC_CMAKE_BOOL=		ENABLE_VLC
VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc

VST_DESC=		Build VST submodule
VST_CMAKE_BOOL=		BUILD_VST

WAYLAND_CATEGORIES=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != powerpc && ${ARCH} != powerpc64 && ${ARCH} != powerpc64le
PLIST_SUB+=	LUAJIT="@comment "
.else
PLIST_SUB+=	LUAJIT=""
.endif

xpost-install:
	# https://github.com/obsproject/obs-studio/issues/2625
	${INSTALL_DATA} ${WRKSRC}/UI/obs-frontend-api/obs-frontend-api.h ${STAGEDIR}${PREFIX}/include/obs
	# https://github.com/obsproject/obs-studio/issues/2647 (only for multimedia/obs-audio-spectralizer, should be removed later)
	${INSTALL_DATA} ${WRKSRC}/cmake/Modules/ObsHelpers.cmake ${STAGEDIR}${PREFIX}/lib/cmake
	${INSTALL_DATA} ${WRKSRC}/cmake/external/ObsPluginHelpers.cmake ${STAGEDIR}${PREFIX}/lib/cmake

.include <bsd.port.post.mk>
