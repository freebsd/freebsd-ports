PORTNAME=	mpv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.35.1
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	multimedia audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	b95111dda879.patch:-p1 # https://github.com/mpv-player/mpv/pull/10871
PATCHFILES+=	94c189dae76b.patch:-p1 # https://github.com/mpv-player/mpv/pull/11398
PATCHFILES+=	362256edbc4f.patch:-p1 # https://github.com/mpv-player/mpv/pull/11398
PATCHFILES+=	3a2f8d42ab20.patch:-p1 # https://github.com/mpv-player/mpv/pull/11447

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Free and open-source general-purpose video player
WWW=		https://mpv.io

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENSE.LGPL

BUILD_DEPENDS=	ffmpeg>=4.0.2,1:multimedia/ffmpeg
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libass.so:multimedia/libass

USES=		compiler:c11 cpe desktop-file-utils iconv jpeg \
		meson pkgconfig python:build shebangfix tar:bz2
USE_LDCONFIG=	yes
SHEBANG_FILES=	*.py TOOLS/*.py

USE_GITHUB=	yes
GH_ACCOUNT=	mpv-player
MESON_ARGS=	--auto-features=auto \
		-Dshaderc=disabled \
		-Dlibmpv=true

OPTIONS_DEFINE=		ARCHIVE DOCS LCMS2 MANPAGES MUJS RUBBERBAND TEST UCHARDET EXAMPLES ZIMG
OPTIONS_DEFAULT=	ARCHIVE DVDNAV LCMS2 LUAJIT MANPAGES NVDEC OPENGL UCHARDET \
			V4L VAAPI VDPAU VULKAN WAYLAND X11 YTDLP
OPTIONS_GROUP=		IN VO AO
OPTIONS_GROUP_IN=	CDIO DVDNAV LIBBLURAY V4L VAPOURSYNTH
OPTIONS_GROUP_VO=	CACA NVDEC OPENGL SIXEL VAAPI VDPAU VULKAN WAYLAND X11
OPTIONS_GROUP_AO=	ALSA JACK OPENAL PIPEWIRE PULSEAUDIO SDL SNDIO
OPTIONS_RADIO=		YOUTUBE
OPTIONS_RADIO_YOUTUBE=	YTDL YTDLP
OPTIONS_SINGLE=		LUA
OPTIONS_SINGLE_LUA=	LUA LUAJIT LUA_NONE
OPTIONS_SUB=		yes

DVDNAV_DESC=		DVD menu navigation
LUA_NONE_DESC=		Disable Lua scripting language support
LUAJIT_DESC=		Use LuaJIT instead of Lua scripting language support
MUJS_DESC=		Use MuJS for Javascript language support
NVDEC_DESC=		NVIDIA decoder with CUDA support
PIPEWIRE_DESC=		Pipewire sound server support
RUBBERBAND_DESC=	High quality pitch correction with librubberband
SIXEL_DESC=		Sixel graphics support
UCHARDET_DESC=		Guess subtitle encoding via uchardet
VAPOURSYNTH_DESC=	VapourSynth filter bridge
VULKAN_DESC=		Vulkan output support
YTDLP_DESC=		Install yt-dlp (youtube-dl fork)
YTDL_DESC=		Install youtube-dl
ZIMG_DESC=		High quality software scaling via "z" library
IN_DESC=		Input
VO_DESC=		Video Output
AO_DESC=		Audio Output

ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_MESON_ENABLED=		alsa

ARCHIVE_USES=			libarchive
ARCHIVE_MESON_ENABLED=		libarchive

CACA_LIB_DEPENDS=		libcaca.so:graphics/libcaca
CACA_MESON_ENABLED=		caca

CDIO_LIB_DEPENDS=		libcdio_paranoia.so:sysutils/libcdio-paranoia
CDIO_MESON_ENABLED=		cdda

DOCS_BUILD_DEPENDS=		rst2html:textproc/py-docutils
DOCS_MESON_ENABLED=		html-build

DVDNAV_LIB_DEPENDS=		libdvdnav.so:multimedia/libdvdnav
DVDNAV_MESON_ENABLED=		dvdnav

JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_MESON_ENABLED=		jack

LCMS2_LIB_DEPENDS=		liblcms2.so:graphics/lcms2
LCMS2_MESON_ENABLED=		lcms2

LIBBLURAY_LIB_DEPENDS=		libbluray.so:multimedia/libbluray
LIBBLURAY_MESON_ENABLED=	libbluray

LUA_USES=			lua:51-52
LUA_MESON_ON=			-Dlua=lua-${LUA_VER}

LUAJIT_USES=			luajit
LUAJIT_MESON_ON=		-Dlua=luajit

LUA_NONE_MESON_ON=		-Dlua=disabled

MANPAGES_BUILD_DEPENDS=		rst2man:textproc/py-docutils
MANPAGES_MESON_ENABLED=		manpage-build

MUJS_LIB_DEPENDS=		libmujs.so:lang/mujs
MUJS_MESON_ENABLED=		javascript

NVDEC_BUILD_DEPENDS=		${LOCALBASE}/include/ffnvcodec/dynlink_loader.h:multimedia/ffnvcodec-headers
NVDEC_RUN_DEPENDS=		${LOCALBASE}/include/ffnvcodec/dynlink_loader.h:multimedia/ffnvcodec-headers
NVDEC_MESON_ENABLED=		cuda-hwaccel

OPENAL_USES=			openal
OPENAL_MESON_ENABLED=		openal
OPENAL_LDFLAGS=			${_OPENAL_LDFLAGS_${ARCH}}
_OPENAL_LDFLAGS_i386=		-Wl,-znotext

OPENGL_USES=			gl
OPENGL_USE=			GL=egl,gbm
OPENGL_MESON_ENABLED=		gl

PIPEWIRE_LIB_DEPENDS=		libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_MESON_ENABLED=		pipewire

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	pulse

RUBBERBAND_LIB_DEPENDS=		librubberband.so:audio/rubberband
RUBBERBAND_MESON_ENABLED=	rubberband

SDL_USES=			sdl
SDL_USE=			SDL=sdl2
SDL_MESON_ENABLED=		sdl2

SIXEL_LIB_DEPENDS=		libsixel.so:graphics/libsixel
SIXEL_MESON_ENABLED=		sixel

SNDIO_LIB_DEPENDS=		libsndio.so:audio/sndio
SNDIO_MESON_ENABLED=		sndio

TEST_MESON_TRUE=		tests

UCHARDET_LIB_DEPENDS=		libuchardet.so:textproc/uchardet
UCHARDET_MESON_ENABLED=		uchardet

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/dvb/dmx.h:multimedia/v4l_compat
V4L_MESON_ENABLED=		dvbin

VAAPI_LIB_DEPENDS=		libva.so:multimedia/libva
VAAPI_MESON_ENABLED=		vaapi

VAPOURSYNTH_LIB_DEPENDS=	libvapoursynth-script.so:multimedia/vapoursynth
VAPOURSYNTH_MESON_ENABLED=	vapoursynth

VDPAU_LIB_DEPENDS=		libvdpau.so:multimedia/libvdpau
VDPAU_MESON_ENABLED=		vdpau
VDPAU_IMPLIES=			X11

VULKAN_BUILD_DEPENDS=		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=		libplacebo.so:graphics/libplacebo \
				libvulkan.so:graphics/vulkan-loader
VULKAN_MESON_ENABLED=		vulkan libplacebo

WAYLAND_CATEGORIES=		wayland
WAYLAND_BUILD_DEPENDS=		wayland-protocols>=1.15:graphics/wayland-protocols \
				${LOCALBASE}/include/linux/input-event-codes.h:devel/evdev-proto
WAYLAND_LIB_DEPENDS=		libwayland-client.so:graphics/wayland \
				libwayland-cursor.so:graphics/wayland \
				libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=		wayland-protocols>=1.15:graphics/wayland-protocols # pkg-config
WAYLAND_MESON_ENABLED=		wayland
WAYLAND_IMPLIES=		OPENGL

X11_USES=			gnome xorg
X11_USE=			XORG=x11,xext,xinerama,xorgproto,xpresent,xrandr,xscrnsaver,xv,xxf86vm
X11_MESON_ENABLED=		x11

YTDLP_RUN_DEPENDS=		yt-dlp:www/yt-dlp

YTDL_RUN_DEPENDS=		youtube-dl:www/youtube_dl

ZIMG_LIB_DEPENDS=		libzimg.so:graphics/sekrit-twc-zimg
ZIMG_MESON_ENABLED=		zimg

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVAAPI} && ${PORT_OPTIONS:MWAYLAND}
MESON_ARGS+=		-Dvaapi-wayland=enabled
LIB_DEPENDS+=		libva-wayland.so:multimedia/libva
.else
MESON_ARGS+=		-Dvaapi-wayland=disabled
.endif

post-patch-MANPAGES-on:
	@${FIND} ${WRKSRC}/DOCS/man -name '*.rst' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g'

pre-install-TEST-on:
	@(cd ${WRKSRC} && ${SETENV} ${TEST_ENV} \
		${MESON_BUILD_DIR}/${PORTNAME} --unittest=all-simple)

.include <bsd.port.mk>
