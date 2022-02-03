# Created by: Grzegorz Blach <gblach@FreeBSD.org>

PORTNAME=	mpv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.34.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	https://waf.io/:waf
DISTFILES=	${WAF_RELEASE}${EXTRACT_SUFX}:waf

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	b030cfe05f58.patch:-p1 # https://github.com/mpv-player/mpv/pull/9440
PATCHFILES+=	edf0039d7621.patch:-p1 # https://github.com/mpv-player/mpv/pull/9298
PATCHFILES+=	5319731526fb.patch:-p1 # https://github.com/mpv-player/mpv/pull/9298
PATCHFILES+=	82390d212123.patch:-p1 # https://github.com/mpv-player/mpv/pull/9587
PATCHFILES+=	22b0bac28e6c.patch:-p1 # https://github.com/mpv-player/mpv/pull/9587
PATCHFILES+=	b7a71ea70671.patch:-p1 # https://github.com/mpv-player/mpv/pull/9734
PATCHFILES+=	09343bc86e8b.patch:-p1 # https://github.com/mpv-player/mpv/pull/9734
PATCHFILES+=	bc9805c71a67.patch:-p1 # https://github.com/mpv-player/mpv/pull/9830

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Free and open-source general-purpose video player

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	ffmpeg>=4.0.2,1:multimedia/ffmpeg
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libass.so:multimedia/libass

USES=		compiler:c11 cpe desktop-file-utils iconv jpeg localbase:ldflags \
		pkgconfig python:build tar:bz2 waf
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mpv-player

# Keep in sync with bootstrap.py to avoid regressions
WAF_CMD=	${WRKDIR}/${WAF_RELEASE}/waf-light
WAF_RELEASE=	waf-2.0.20

CONFIGURE_ENV=	BIN_PYTHON="${PYTHON_CMD}"
CONFIGURE_ARGS=	--docdir="${EXAMPLESDIR}" \
		--htmldir="${DOCSDIR}/html" \
		--mandir="${MANPREFIX}/man" \
		--disable-debug-build \
		--disable-optimize \
		--disable-pdf \
		--disable-rubberband \
		--disable-shaderc \
		--disable-vapoursynth \
		--enable-libmpv-shared

OPTIONS_DEFINE=		ARCHIVE DOCS LCMS2 MANPAGES MUJS TEST UCHARDET EXAMPLES ZIMG
OPTIONS_DEFAULT=	ARCHIVE DVDNAV LUA MANPAGES OPENGL UCHARDET \
			V4L VAAPI VDPAU VULKAN WAYLAND X11 YTDLP
OPTIONS_GROUP=		IN VO AO
OPTIONS_GROUP_IN=	CDIO DVDNAV LIBBLURAY V4L
OPTIONS_GROUP_VO=	CACA OPENGL SIXEL VAAPI VDPAU VULKAN WAYLAND X11
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
PIPEWIRE_DESC=		Pipewire sound server support
SIXEL_DESC=		Sixel graphics support
UCHARDET_DESC=		Guess subtitle encoding via uchardet
VULKAN_DESC=		Vulkan output support
YTDLP_DESC=		Install yt-dlp (youtube-dl fork)
YTDL_DESC=		Install youtube-dl
ZIMG_DESC=		High quality software scaling via "z" library
IN_DESC=		Input
VO_DESC=		Video Output
AO_DESC=		Audio Output

ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=		--disable-alsa

ARCHIVE_USES=			libarchive
ARCHIVE_CONFIGURE_ON=		--enable-libarchive

CACA_LIB_DEPENDS=		libcaca.so:graphics/libcaca
CACA_CONFIGURE_OFF=		--disable-caca

CDIO_LIB_DEPENDS=		libcdio_paranoia.so:sysutils/libcdio-paranoia
CDIO_CONFIGURE_ON=		--enable-cdda

DOCS_BUILD_DEPENDS=		rst2html:textproc/py-docutils
DOCS_CONFIGURE_ON=		--enable-html

DVDNAV_LIB_DEPENDS=		libdvdnav.so:multimedia/libdvdnav \
				libdvdread.so:multimedia/libdvdread
DVDNAV_CONFIGURE_ON=		--enable-dvdnav

JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CONFIGURE_OFF=		--disable-jack

LCMS2_LIB_DEPENDS=		liblcms2.so:graphics/lcms2
LCMS2_CONFIGURE_OFF=		--disable-lcms2

LIBBLURAY_LIB_DEPENDS=		libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ON=		--enable-libbluray
LIBBLURAY_CONFIGURE_OFF=	--disable-libbluray

LUA_USES=			lua:51-52
LUA_CONFIGURE_ON=		--lua=${LUA_VER_STR}fbsd

LUAJIT_LIB_DEPENDS=		libluajit-5.1.so:lang/luajit
LUAJIT_CONFIGURE_ON=		--lua=luajit

LUA_NONE_CONFIGURE_ON=		--disable-lua

MANPAGES_BUILD_DEPENDS=		rst2man:textproc/py-docutils
MANPAGES_CONFIGURE_OFF=		--disable-manpage

MUJS_LIB_DEPENDS=		libmujs.so:lang/mujs
MUJS_CONFIGURE_ON=		--enable-javascript
MUJS_CONFIGURE_OFF=		--disable-javascript

OPENAL_CONFIGURE_ENABLE=	openal
OPENAL_USES=			openal
OPENAL_LDFLAGS=			${_OPENAL_LDFLAGS_${ARCH}}
_OPENAL_LDFLAGS_i386=		-Wl,-znotext

OPENGL_USES=			gl
OPENGL_USE=			GL=egl,gbm
OPENGL_CONFIGURE_OFF=		--disable-gl

PIPEWIRE_LIB_DEPENDS=		libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CONFIGURE_OFF=		--disable-pipewire

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse

SDL_USES=			sdl
SDL_USE=			SDL=sdl2
SDL_CONFIGURE_ON=		--enable-sdl2

SIXEL_LIB_DEPENDS=		libsixel.so:graphics/libsixel
SIXEL_CONFIGURE_OFF=		--disable-sixel

SNDIO_LIB_DEPENDS=		libsndio.so:audio/sndio
SNDIO_CONFIGURE_ON=		--enable-sndio
SNDIO_CONFIGURE_OFF=		--disable-sndio

TEST_CONFIGURE_ON=		--enable-tests

UCHARDET_LIB_DEPENDS=		libuchardet.so:textproc/uchardet
UCHARDET_CONFIGURE_OFF=		--disable-uchardet

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/dvb/dmx.h:multimedia/v4l_compat
V4L_CONFIGURE_ON=		--enable-dvbin

VAAPI_LIB_DEPENDS=		libva.so:multimedia/libva
VAAPI_CONFIGURE_OFF=		--disable-vaapi

VDPAU_LIB_DEPENDS=		libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_OFF=		--disable-vdpau

VULKAN_BUILD_DEPENDS=		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=		libplacebo.so:graphics/libplacebo \
				libvulkan.so:graphics/vulkan-loader
VULKAN_CONFIGURE_OFF=		--disable-vulkan --disable-libplacebo

WAYLAND_BUILD_DEPENDS=		wayland-protocols>=1.14:graphics/wayland-protocols \
				${LOCALBASE}/include/linux/input-event-codes.h:devel/evdev-proto
WAYLAND_LIB_DEPENDS=		libwayland-client.so:graphics/wayland \
				libwayland-cursor.so:graphics/wayland \
				libxkbcommon.so:x11/libxkbcommon
WAYLAND_CONFIGURE_OFF=		--disable-wayland
WAYLAND_IMPLIES=		OPENGL

X11_USES=			gnome xorg
X11_USE=			XORG=x11,xext,xinerama,xorgproto,xrandr,xscrnsaver,xv,xxf86vm
X11_CONFIGURE_OFF=		--disable-x11

YTDLP_RUN_DEPENDS=		yt-dlp:www/yt-dlp

YTDL_RUN_DEPENDS=		youtube-dl:www/youtube_dl

ZIMG_LIB_DEPENDS=		libzimg.so:graphics/sekrit-twc-zimg
ZIMG_CONFIGURE_OFF=		--disable-zimg

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVAAPI} && ${PORT_OPTIONS:MWAYLAND}
CONFIGURE_ARGS+=	--enable-vaapi-wayland
LIB_DEPENDS+=		libva-wayland.so:multimedia/libva
.else
CONFIGURE_ARGS+=	--disable-vaapi-wayland
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/pkgconfig/mpv.pc|data/pkgconfig/mpv.pc|g' \
		${WRKSRC}/wscript_build.py

post-patch-MANPAGES-on:
	@${FIND} ${WRKSRC}/DOCS/man -name '*.rst' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g'

pre-install-TEST-on:
	@(cd ${WRKSRC} && ${SETENV} ${TEST_ENV} build/mpv --unittest=all-simple)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mpv
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpv.so

.include <bsd.port.mk>
