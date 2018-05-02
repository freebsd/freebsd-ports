# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpv
PORTVERSION=	0.27.2
DISTVERSIONPREFIX=	v
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	multimedia audio

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Free and open-source general-purpose video player

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	ffmpeg>=3.3,1:multimedia/ffmpeg
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		compiler:c11 desktop-file-utils iconv jpeg localbase:ldflags \
		pkgconfig python:build waf
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mpv-player
# Keep in sync with bootstrap.py to avoid regressions
GH_TUPLE=	waf-project:waf:waf-1.9.8:waf

WAF_CMD=	${WRKSRC_waf}/waf-light

CONFIGURE_ENV=	BIN_PYTHON="${PYTHON_CMD}"
CONFIGURE_ARGS=	--docdir="${EXAMPLESDIR}" \
		--htmldir="${DOCSDIR}/html" \
		--mandir="${MANPREFIX}/man" \
		--disable-debug-build \
		--disable-optimize \
		--disable-pdf \
		--disable-rubberband \
		--disable-vapoursynth \
		--disable-vapoursynth-lazy \
		--enable-libmpv-shared

OPTIONS_DEFINE=		ARCHIVE ASS DOCS LCMS2 LUAJIT MANPAGES TEST UCHARDET ZSH
OPTIONS_DEFAULT=	ARCHIVE ASS DVDREAD DVDNAV MANPAGES OPENGL UCHARDET \
			V4L VAAPI VDPAU X11 YTDL
OPTIONS_GROUP=		IN VO AO
OPTIONS_GROUP_IN=	CDIO DVDREAD DVDNAV LIBBLURAY V4L YTDL SMB
OPTIONS_GROUP_VO=	CACA OPENGL VAAPI VDPAU WAYLAND X11
OPTIONS_GROUP_AO=	ALSA JACK PULSEAUDIO SDL SNDIO
OPTIONS_SUB=		yes

ASS_DESC=		ASS/SSA subtitle and OSD rendering
DVDREAD_DESC=		DVD Playback support
DVDNAV_DESC=		DVD menu navigation
LUAJIT_DESC=		Use LuaJIT instead of Lua scripting language support
UCHARDET_DESC=		Guess subtitle encoding via uchardet
WAYLAND_DESC=		Wayland (graphics) support
YTDL_DESC=		Install youtube-dl
IN_DESC=		Input
VO_DESC=		Video Output
AO_DESC=		Audio Output

ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=		--disable-alsa

ARCHIVE_USES=			libarchive
ARCHIVE_CONFIGURE_ON=		--enable-libarchive

ASS_LIB_DEPENDS=		libass.so:multimedia/libass
ASS_CONFIGURE_OFF=		--disable-libass

CACA_LIB_DEPENDS=		libcaca.so:graphics/libcaca
CACA_CONFIGURE_OFF=		--disable-caca

CDIO_LIB_DEPENDS=		libcdio_paranoia.so:sysutils/libcdio-paranoia
CDIO_CONFIGURE_ON=		--enable-cdda

DOCS_BUILD_DEPENDS=		rst2html:textproc/py-docutils
DOCS_CONFIGURE_ON=		--enable-html

DVDNAV_LIB_DEPENDS=		libdvdnav.so:multimedia/libdvdnav
DVDNAV_CONFIGURE_ON=		--enable-dvdnav

DVDREAD_LIB_DEPENDS=		libdvdread.so:multimedia/libdvdread
DVDREAD_CONFIGURE_ON=		--enable-dvdread

JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CONFIGURE_OFF=		--disable-jack

LCMS2_LIB_DEPENDS=		liblcms2.so:graphics/lcms2
LCMS2_CONFIGURE_OFF=		--disable-lcms2

LIBBLURAY_LIB_DEPENDS=		libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ON=		--enable-libbluray
LIBBLURAY_CONFIGURE_OFF=	--disable-libbluray

LUAJIT_LIB_DEPENDS=		libluajit-5.1.so:lang/luajit
LUAJIT_USES_OFF=		lua
LUAJIT_CONFIGURE_ON=		--lua=luajit
LUAJIT_CONFIGURE_OFF=		--lua=${LUA_VER_STR}fbsd

MANPAGES_BUILD_DEPENDS=		rst2man:textproc/py-docutils
MANPAGES_CONFIGURE_OFF=		--disable-manpage

OPENGL_USE=			GL=egl,gbm,gl
OPENGL_CONFIGURE_OFF=		--disable-gl
OPENGL_IMPLIES=			X11

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse

SDL_USE=			SDL=sdl2
SDL_CONFIGURE_ON=		--enable-sdl2

SNDIO_LIB_DEPENDS=		libsndio.so:audio/sndio
SNDIO_CONFIGURE_ON=		--enable-sndio
SNDIO_CONFIGURE_OFF=		--disable-sndio

SMB_USES=			samba:lib
SMB_CONFIGURE_ON=		--enable-libsmbclient

TEST_BUILD_DEPENDS=		cmocka>=1.1.0:sysutils/cmocka
TEST_CONFIGURE_ON=		--enable-test
TEST_UNITTESTFILES=		chmap chmap_sel gl_video

UCHARDET_LIB_DEPENDS=		libuchardet.so:textproc/uchardet
UCHARDET_CONFIGURE_OFF=		--disable-uchardet

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=		libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_ON=		--enable-tv --enable-dvbin

VAAPI_LIB_DEPENDS=		libva.so:multimedia/libva
VAAPI_CONFIGURE_OFF=		--disable-vaapi

VDPAU_LIB_DEPENDS=		libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_OFF=		--disable-vdpau

WAYLAND_LIB_DEPENDS=		libwayland-client.so:graphics/wayland \
				libwayland-cursor.so:graphics/wayland \
				libxkbcommon.so:x11/libxkbcommon
WAYLAND_CONFIGURE_OFF=		--disable-wayland

X11_USE=			XORG=x11,xext,xinerama,xineramaproto,xrandr,xscrnsaver,xv,xxf86vm
X11_VARS=			INSTALLS_ICONS=yes
X11_CONFIGURE_OFF=		--disable-x11

YTDL_RUN_DEPENDS=		youtube-dl:www/youtube_dl

ZSH_USES=			perl5
ZSH_USE=			PERL5=build
ZSH_CONFIGURE_ENV=		BIN_PERL="${PERL}"
ZSH_CONFIGURE_ENABLE=		zsh-comp

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
	@${REINPLACE_CMD} -e 's|DBL_EPSILON|FLT_EPSILON|'g \
		${WRKSRC}/test/test_helpers.h

post-patch-MANPAGES-on:
	@${FIND} ${WRKSRC}/DOCS/man -name '*.rst' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g'

pre-install-TEST-on:
.for test in ${TEST_UNITTESTFILES}
	cd ${WRKSRC}/build/test && ./${test}
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mpv
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpv.so

.include <bsd.port.mk>
