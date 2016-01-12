# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpv
PORTVERSION=	0.14.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	multimedia audio

MAINTAINER=	cpm@fbsd.es
COMMENT=	Free and open-source general-purpose video player

LICENSE=	GPLv2

LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
BUILD_DEPENDS=	rst2man:${PORTSDIR}/textproc/py-docutils

USE_GITHUB=	yes
GH_ACCOUNT=	mpv-player waf-project:waf
GH_PROJECT=	waf:waf
GH_TAGNAME=	waf-1.8.18:waf

WAF_CMD=	${WRKSRC_waf}/waf-light

USES=		compiler:c11 desktop-file-utils iconv pkgconfig python:build waf
USE_LDCONFIG=	yes

CPPFLAGS+=	-I.. -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--docdir=${EXAMPLESDIR} \
		--mandir=${MANPREFIX}/man \
		--prefix=${PREFIX} \
		--disable-debug-build \
		--disable-optimize \
		--disable-pdf \
		--enable-libmpv-shared

OPTIONS_DEFINE=		ASS DOCS ENCA LCMS2 \
			LIBGUESS LUAJIT UCHARDET ZSH
OPTIONS_DEFAULT=	ASS DVDREAD DVDNAV ENCA OPENGL \
			V4L VAAPI VDPAU X11 XINERAMA YTDL ZSH
OPTIONS_GROUP=		IN VO AO
OPTIONS_GROUP_IN=	CDIO DVDREAD DVDNAV LIBBLURAY V4L YTDL SMB
OPTIONS_GROUP_VO=	CACA OPENGL VAAPI VDPAU X11 XINERAMA
OPTIONS_GROUP_AO=	ALSA JACK PULSEAUDIO
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

ALSA_LIB_DEPENDS=		libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_OFF=		--disable-alsa

ASS_LIB_DEPENDS=		libass.so:${PORTSDIR}/multimedia/libass
ASS_CONFIGURE_OFF=		--disable-libass

CACA_LIB_DEPENDS=		libcaca.so:${PORTSDIR}/graphics/libcaca
CACA_CONFIGURE_OFF=		--disable-caca

CDIO_LIB_DEPENDS=		libcdio_paranoia.so:${PORTSDIR}/sysutils/libcdio-paranoia
CDIO_CONFIGURE_OFF=		--disable-cdda

DVDNAV_LIB_DEPENDS=		libdvdnav.so:${PORTSDIR}/multimedia/libdvdnav
DVDNAV_CONFIGURE_OFF=		--disable-dvdnav

DVDREAD_LIB_DEPENDS=		libdvdread.so:${PORTSDIR}/multimedia/libdvdread
DVDREAD_CONFIGURE_OFF=		--disable-dvdread

ENCA_LIB_DEPENDS=		libenca.so:${PORTSDIR}/converters/enca
ENCA_CONFIGURE_OFF=		--disable-enca

JACK_LIB_DEPENDS=		libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_OFF=		--disable-jack

LCMS2_LIB_DEPENDS=		liblcms2.so:${PORTSDIR}/graphics/lcms2
LCMS2_CONFIGURE_OFF=		--disable-lcms2

LIBBLURAY_LIB_DEPENDS=		libbluray.so:${PORTSDIR}/multimedia/libbluray
LIBBLURAY_CONFIGURE_OFF=	--disable-libbluray

LIBGUESS_LIB_DEPENDS=		libguess.so:${PORTSDIR}/textproc/libguess
LIBGUESS_CONFIGURE_OFF=		--disable-libguess

LUAJIT_LIB_DEPENDS=		libluajit-5.1.so:${PORTSDIR}/lang/luajit
LUAJIT_USES_OFF=		lua
LUAJIT_CONFIGURE_ON=		--lua=luajit
LUAJIT_CONFIGURE_OFF=		--lua=${LUA_VER_STR}fbsd

OPENGL_USE=			GL=gl
OPENGL_CONFIGURE_OFF=		--disable-gl
OPENGL_IMPLIES=			X11

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse

SMB_LIB_DEPENDS=		libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
SMB_CONFIGURE_OFF=		--disable-libsmbclient

UCHARDET_LIB_DEPENDS=		libuchardet.so:${PORTSDIR}/textproc/uchardet
UCHARDET_CONFIGURE_OFF=		--disable-uchardet

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
V4L_LIB_DEPENDS=		libv4l2.so:${PORTSDIR}/multimedia/libv4l
V4L_CONFIGURE_OFF=		--disable-tv-v4l2

VAAPI_LIB_DEPENDS=		libva.so:${PORTSDIR}/multimedia/libva
VAAPI_CONFIGURE_OFF=		--disable-vaapi

VDPAU_LIB_DEPENDS=		libvdpau.so:${PORTSDIR}/multimedia/libvdpau
VDPAU_CONFIGURE_OFF=		--disable-vdpau

X11_USE=			XORG=x11,xv,xxf86vm
X11_CONFIGURE_OFF=		--disable-x11

XINERAMA_USE=			XORG=xinerama,xineramaproto
XINERAMA_CONFIGURE_OFF=		--disable-xinerama
XINERAMA_IMPLIES=		X11

YTDL_RUN_DEPENDS=		youtube-dl:${PORTSDIR}/www/youtube_dl

ZSH_USES=			perl5
ZSH_USE=			PERL5=build
ZSH_CONFIGURE_ENABLE=		zsh-comp

.include <bsd.port.options.mk>

# Fix crash on i386
.if ${ARCH} == "i386"
CFLAGS:=	${CFLAGS:N-O*} -O0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/pkgconfig/mpv.pc|data/pkgconfig/mpv.pc|g' \
		${WRKSRC}/wscript_build.py
	@${FIND} ${WRKSRC}/DOCS/man -name '*.rst' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g'

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mpv
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpv.so

.include <bsd.port.mk>
