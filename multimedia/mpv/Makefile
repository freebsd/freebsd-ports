# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpv
PORTVERSION=	0.17.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia audio

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Free and open-source general-purpose video player

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
BUILD_DEPENDS=	rst2man:textproc/py-docutils

USE_GITHUB=	yes
GH_ACCOUNT=	mpv-player waf-project:waf
GH_PROJECT=	waf:waf
GH_TAGNAME=	waf-1.9.0pre1:waf

WAF_CMD=	${WRKSRC_waf}/waf-light

USES=		compiler:c11 desktop-file-utils iconv pkgconfig python:build waf
USE_LDCONFIG=	yes

CPPFLAGS+=	-I.. -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--docdir=${EXAMPLESDIR} \
		--mandir=${MANPREFIX}/man \
		--prefix=${PREFIX} \
		--disable-debug-build \
		--disable-d3d11va-hwaccel \
		--disable-dxva2-hwaccel \
		--disable-gpl3 \
		--disable-optimize \
		--disable-pdf \
		--disable-rubberband \
		--disable-vaapi-wayland \
		--disable-vapoursynth \
		--disable-vapoursynth-lazy \
		--disable-videotoolbox-hwaccel \
		--disable-videotoolbox-gl \
		--disable-wayland \
		--enable-libmpv-shared

OPTIONS_DEFINE=		ASS DOCS ENCA LCMS2 \
			LIBGUESS LUAJIT UCHARDET ZSH
OPTIONS_DEFAULT=	ASS DVDREAD DVDNAV ENCA OPENGL \
			V4L VAAPI VDPAU X11 XINERAMA YTDL ZSH
OPTIONS_GROUP=		IN VO AO
OPTIONS_GROUP_IN=	CDIO DVDREAD DVDNAV LIBBLURAY V4L YTDL SMB
OPTIONS_GROUP_VO=	CACA OPENGL VAAPI VDPAU X11 XINERAMA
OPTIONS_GROUP_AO=	ALSA JACK PULSEAUDIO SDL
OPTIONS_SUB=		yes

ASS_DESC=	ASS/SSA subtitle and OSD rendering
DVDREAD_DESC=	DVD Playback support
DVDNAV_DESC=	DVD menu navigation
ENCA_DESC=	Enable encoding detection support
LIBGUESS_DESC=	Enable high-speed character set detection support
LUAJIT_DESC=	Use LuaJIT instead of Lua scripting language support
YTDL_DESC=	Install youtube-dl
UCHARDET_DESC=	Use UCHARDET instead ENCA support
IN_DESC=	Input
VO_DESC=	Video Output
AO_DESC=	Audio Output

ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=		--disable-alsa

ASS_LIB_DEPENDS=		libass.so:multimedia/libass
ASS_CONFIGURE_OFF=		--disable-libass

CACA_LIB_DEPENDS=		libcaca.so:graphics/libcaca
CACA_CONFIGURE_OFF=		--disable-caca

CDIO_LIB_DEPENDS=		libcdio_paranoia.so:sysutils/libcdio-paranoia
CDIO_CONFIGURE_OFF=		--disable-cdda

DVDNAV_LIB_DEPENDS=		libdvdnav.so:multimedia/libdvdnav
DVDNAV_CONFIGURE_OFF=		--disable-dvdnav

DVDREAD_LIB_DEPENDS=		libdvdread.so:multimedia/libdvdread
DVDREAD_CONFIGURE_OFF=		--disable-dvdread

ENCA_LIB_DEPENDS=		libenca.so:converters/enca
ENCA_CONFIGURE_OFF=		--disable-enca

JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CONFIGURE_OFF=		--disable-jack

LCMS2_LIB_DEPENDS=		liblcms2.so:graphics/lcms2
LCMS2_CONFIGURE_OFF=		--disable-lcms2

LIBBLURAY_LIB_DEPENDS=		libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_OFF=	--disable-libbluray

LIBGUESS_LIB_DEPENDS=		libguess.so:textproc/libguess
LIBGUESS_CONFIGURE_OFF=		--disable-libguess

LUAJIT_LIB_DEPENDS=		libluajit-5.1.so:lang/luajit
LUAJIT_USES_OFF=		lua
LUAJIT_CONFIGURE_ON=		--lua=luajit
LUAJIT_CONFIGURE_OFF=		--lua=${LUA_VER_STR}fbsd

OPENGL_USE=			GL=gl
OPENGL_CONFIGURE_OFF=		--disable-gl
OPENGL_IMPLIES=			X11

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse

SDL_USE=			SDL=sdl2
SDL_CONFIGURE_ON=		--enable-sdl2
SDL_CONFIGURE_OFF=		--disable-sdl2

SMB_LIB_DEPENDS=		libsmbclient.so:net/samba-libsmbclient
SMB_CONFIGURE_OFF=		--disable-libsmbclient

UCHARDET_LIB_DEPENDS=		libuchardet.so:textproc/uchardet
UCHARDET_CONFIGURE_OFF=		--disable-uchardet

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=		libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_OFF=		--disable-tv-v4l2

VAAPI_LIB_DEPENDS=		libva.so:multimedia/libva
VAAPI_CONFIGURE_OFF=		--disable-vaapi

VDPAU_LIB_DEPENDS=		libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_OFF=		--disable-vdpau

X11_USE=			XORG=x11,xv,xxf86vm
X11_VARS=			INSTALLS_ICONS=yes
X11_CONFIGURE_OFF=		--disable-x11

XINERAMA_USE=			XORG=xinerama,xineramaproto
XINERAMA_CONFIGURE_OFF=		--disable-xinerama
XINERAMA_IMPLIES=		X11

YTDL_RUN_DEPENDS=		youtube-dl:www/youtube_dl

ZSH_USES=			perl5
ZSH_USE=			PERL5=build
ZSH_CONFIGURE_ENABLE=		zsh-comp

post-patch:
	@${REINPLACE_CMD} -e 's|/pkgconfig/mpv.pc|data/pkgconfig/mpv.pc|g' \
		${WRKSRC}/wscript_build.py
	@${FIND} ${WRKSRC}/DOCS/man -name '*.rst' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g'

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mpv
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpv.so

.include <bsd.port.mk>
