PORTNAME=	obs-studio
DISTVERSION=	27.2.3
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ecd7a59aed665eca0a50b99939ef28e04e144876.patch:-p1 \
		445f39764b8f11f951d41d14ee57ae13f57b13d4.patch:-p1 # backport the PR "Fix building OBS Studio on FreeBSD", https://github.com/obsproject/obs-studio/pull/6026

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source streaming/recording software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	https://github.com/obsproject/obs-browser/issues/241

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat \
		swig:devel/swig
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libfdk-aac.so:audio/fdk-aac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjansson.so:devel/jansson \
		libmbedtls.so:security/mbedtls \
		libpci.so:devel/libpci \
		libspeexdsp.so:audio/speexdsp \
		libsysinfo.so:devel/libsysinfo \
		libudev.so:devel/libudev-devd \
		libv4l2.so:multimedia/libv4l \
		libvlc.so:multimedia/vlc \
		libwayland-client.so:graphics/wayland \
		libx264.so:multimedia/libx264 \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-util.so:x11/xcb-util \
		libxkbcommon.so:x11/libxkbcommon \
		${LIB_DEPENDS_${ARCH}}
LIB_DEPENDS_amd64=	libluajit-5.1.so:lang/luajit
LIB_DEPENDS_armv7=	libluajit-5.1.so:lang/luajit
LIB_DEPENDS_i386=	libluajit-5.1.so:lang/luajit
LIB_DEPENDS_powerpc=	libluajit-5.1.so:lang/luajit
LIB_DEPENDS_powerpc64=	libluajit-5.1.so:lang/luajit-openresty
LIB_DEPENDS_powerpc64le=	libluajit-5.1.so:lang/luajit-openresty

USES=		cmake compiler:c++17-lang gl gnome lua pkgconfig python:3.4+ \
		qt:5 xorg
USE_QT=		core gui network svg widgets x11extras xml buildtools_build imageformats_run qmake_build
USE_GNOME=	glib20
USE_GL=		gl
USE_XORG=	ice sm x11 xcb xcomposite xext xfixes xinerama xrandr
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	obsproject
GH_TUPLE=	obsproject:obs-browser:f1a61c5:obs_browser/plugins/obs-browser \
		obsproject:obs-vst:aaa7b7f:obs_vst/plugins/obs-vst

CMAKE_ON=	UNIX_STRUCTURE
CMAKE_OFF=	ENABLE_PIPEWIRE # beginning with 27.0.1 (PR#4287) the linux-capture plugin optionally requires the piperware library and in this case expects the linux/dma-buf.h header
CMAKE_ARGS=	-DOBS_VERSION_OVERRIDE:STRING="${PORTVERSION}"

LDFLAGS+=	-fPIC # pending https://github.com/obsproject/obs-studio/issues/3436

OPTIONS_DEFINE=		BROWSER VST
OPTIONS_DEFAULT=	VST
OPTIONS_MULTI=		AUDIO
OPTIONS_MULTI_AUDIO=	JACK PULSEAUDIO SNDIO
OPTIONS_DEFAULT+=	JACK PULSEAUDIO SNDIO
OPTIONS_SUB=		yes
AUDIO_DESC=		Audio backends

BROWSER_DESC=		Build OSB browser
BROWSER_CMAKE_BOOL=	BUILD_BROWSER
BROWSER_BROKEN=		Needs CEF (Chromium Embedded Framework) which isn't yet ported

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_ON=		-DENABLE_JACK=TRUE
JACK_CMAKE_OFF=		-DDISABLE_JACK=TRUE

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DENABLE_PULSEAUDIO=TRUE
PULSEAUDIO_CMAKE_OFF=	-DDISABLE_PULSEAUDIO=TRUE
PULSEAUDIO_BROKEN_OFF=	https://github.com/obsproject/obs-studio/issues/4025

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_ON=		-DENABLE_SNDIO=TRUE
SNDIO_CMAKE_OFF=	-DDISABLE_SNDIO=TRUE

VST_DESC=		Build VST submodule
VST_CMAKE_BOOL=		BUILD_VST

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != powerpc && ${ARCH} != powerpc64 && ${ARCH} != powerpc64le
PLIST_SUB+=	LUAJIT="@comment "
.else
PLIST_SUB+=	LUAJIT=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| 3.4)| ${PYTHON_VER})|' \
		${WRKSRC}/cmake/Modules/FindPythonDeps.cmake
	# patch out linixism
	#@${REINPLACE_CMD} -e 's|versionsort|alphasort|' \
	#	${WRKSRC}/plugins/linux-v4l2/v4l2-output.c

post-install:
	# https://github.com/obsproject/obs-studio/issues/2625
	${INSTALL_DATA} ${WRKSRC}/UI/obs-frontend-api/obs-frontend-api.h ${STAGEDIR}${PREFIX}/include/obs
	# https://github.com/obsproject/obs-studio/issues/2647 (only for multimedia/obs-audio-spectralizer, should be removed later)
	${INSTALL_DATA} ${WRKSRC}/cmake/Modules/ObsHelpers.cmake ${STAGEDIR}${PREFIX}/lib/cmake
	${INSTALL_DATA} ${WRKSRC}/cmake/external/ObsPluginHelpers.cmake ${STAGEDIR}${PREFIX}/lib/cmake

.include <bsd.port.post.mk>
