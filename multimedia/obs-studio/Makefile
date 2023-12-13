PORTNAME=	obs-studio
DISTVERSION=	30.0.2
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source streaming/recording software
WWW=		https://obsproject.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_12=	fatal error: 'sys/eventfd.h' file not found

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat \
		swig:devel/swig
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libdatachannel.so:www/libdatachannel \
		libdbus-1.so:devel/dbus \
		libfdk-aac.so:audio/fdk-aac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjansson.so:devel/jansson \
		libmbedtls.so:security/mbedtls \
		libpci.so:devel/libpci \
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
		libuuid.so:misc/e2fsprogs-libuuid \
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
GH_TUPLE=	obsproject:obs-amd-encoder:d5a136c6834c39293ad749cf8f07bdaa772fe44b:obsproject_obs_amd_encoder/plugins/enc-amf \
		obsproject:obs-browser:e2310b02df3e6c184fe6eb6608244a82e37f582e:obsproject_obs_browser/plugins/obs-browser \
		obsproject:obs-websocket:5716577019b1ccda01a12db2cba35a023082b7ad:obsproject_obs_websocket/plugins/obs-websocket \
			chriskohlhoff:asio:b73dc1d:chriskohlhoff_asio/plugins/obs-websocket/deps/asio \
			nayuki:QR-Code-generator:8518684:nayuki_QR_Code_generator/plugins/obs-websocket/deps/qr \
			nlohmann:json:a34e011:nlohmann_json/plugins/obs-websocket/deps/json \
			zaphoyd:websocketpp:56123c8:zaphoyd_websocketpp/plugins/obs-websocket/deps/websocketpp \
		obsproject:libdshowcapture:a93f1a34c14e91b5c540f264fb965f32caf77336:obsproject_libdshowcapture/plugins/win-dshow/libdshowcapture \
			elgatosf:capture-device-support:bedcf28ed7a74eb7bf96a383fd18d2f5a1849b10:elgatosf_capture_device_support/plugins/win-dshow/libdshowcapture/external/capture-device-support \
		palana:Syphon-Framework:01b144811f6f7080b70b2d7cc729da071f86f9d7:palana_Syphon_Framework/plugins/mac-syphon/syphon-framework \
		Mixer:ftl-sdk:d0c8469f66806b5ea738d607f7d2b000af8b1129:Mixer_ftl_sdk/plugins/obs-outputs/ftl-sdk \
			curl:curl:44b9b4d4f56d6f6de92c89636994c03984e9cd01:curl_curl/plugins/obs-outputs/ftl-sdk/libcurl \
			akheron:jansson:bc5741fb1ac730ead24e9bd08977fc6c248e04b0:akheron_jansson/plugins/obs-outputs/ftl-sdk/libjansson

CMAKE_ON=	UNIX_STRUCTURE
CMAKE_ARGS=	-DOBS_VERSION_OVERRIDE:STRING="${PORTVERSION}" \
		-DQT_VERSION=6 \
		-DPython_EXECUTABLE="${PYTHON_CMD}"

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
