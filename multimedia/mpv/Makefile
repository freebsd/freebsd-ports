# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpv
PORTVERSION=	0.3.2
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	GH:0 GHC:0 https://waf.googlecode.com/files/:1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:0 waf-${WAF_VERSION}:1
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Free and open-source general-purpose video player

LICENSE=	GPLv2

LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libass.so:${PORTSDIR}/multimedia/libass \
		libdvdread.so:${PORTSDIR}/multimedia/libdvdread
BUILD_DEPENDS=	rst2man:${PORTSDIR}/textproc/py-docutils

USE_GITHUB=	yes
GH_ACCOUNT=	mpv-player
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	6b20c24

WAF_VERSION=	1.7.14

USES=		compiler:c11 desktop-file-utils gmake iconv pkgconfig
USE_PYTHON_BUILD=	yes
USE_LUA=	5.1-5.2
USE_XORG=	x11 xv xxf86vm
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${MANPREFIX}/man \
		--disable-debug-build \
		--disable-mpg123 \
		--disable-alsa \
		--disable-portaudio \
		--disable-libguess \
		--disable-pdf

OPTIONS_DEFINE=		BS2B ENCA LADSPA LCMS2 LIRC
OPTIONS_GROUP=		IN VO AO
OPTIONS_GROUP_IN=	CDIO DVDNAV LIBBLURAY V4L QUVI
OPTIONS_GROUP_VO=	CACA OPENGL VAAPI VDPAU XINERAMA
OPTIONS_GROUP_AO=	JACK PULSEAUDIO

BS2B_DESC=	Enable Bauer Stereophonic-to-Binaural DSP support
DVDNAV_DESC=	Enable DVD navigation menus support
ENCA_DESC=	Enable encoding detection support
QUVI_DESC=	Enable flash media stream support
IN_DESC=	Input
VO_DESC=	Video Output
AO_DESC=	Audio Output

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBS2B}
LIB_DEPENDS+=		libbs2b.so:${PORTSDIR}/audio/libbs2b
.else
CONFIGURE_ARGS+=	--disable-libbs2b
.endif

.if ${PORT_OPTIONS:MENCA}
LIB_DEPENDS+=		libenca.so:${PORTSDIR}/converters/enca
.else
CONFIGURE_ARGS+=	--disable-enca
.endif

.if ${PORT_OPTIONS:MLADSPA}
LIB_DEPENDS+=		ladspa/amp.so:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ARGS+=	--disable-ladspa
.endif

.if ${PORT_OPTIONS:MLCMS2}
LIB_DEPENDS+=		liblcms2.so:${PORTSDIR}/graphics/lcms2
.else
CONFIGURE_ARGS+=	--disable-lcms2
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=		liblirc_client.so:${PORTSDIR}/comms/lirc
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif

.if ${PORT_OPTIONS:MCDIO}
LIB_DEPENDS+=		libcdio.so:${PORTSDIR}/sysutils/libcdio
.else
CONFIGURE_ARGS+=	--disable-cdda
.endif

.if ${PORT_OPTIONS:MDVDNAV}
LIB_DEPENDS+=		libdvdnav.so:${PORTSDIR}/multimedia/libdvdnav
.else
CONFIGURE_ARGS+=	--disable-dvdnav
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
LIB_DEPENDS+=		libbluray.so:${PORTSDIR}/multimedia/libbluray
.else
CONFIGURE_ARGS+=	--disable-libbluray
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS+=		libv4l2.so:${PORTSDIR}/multimedia/libv4l
CONFIGURE_ARGS+=	--enable-tv-v4l2
.else
CONFIGURE_ARGS+=	--disable-tv-v4l2
.endif

.if ${PORT_OPTIONS:MQUVI}
LIB_DEPENDS+=		libquvi.so:${PORTSDIR}/multimedia/libquvi
.else
CONFIGURE_ARGS+=	--disable-libquvi
.endif

#.if ${PORT_OPTIONS:MSMB}
#LIB_DEPENDS+=		libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
#.else
CONFIGURE_ARGS+=	--disable-libsmbclient
#.endif

.if ${PORT_OPTIONS:MCACA}
LIB_DEPENDS+=		libcaca.so:${PORTSDIR}/graphics/libcaca
.else
CONFIGURE_ARGS+=	--disable-caca
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_XORG+=		glproto
LIB_DEPENDS+=		libGL.so:${PORTSDIR}/graphics/libGL
.else
CONFIGURE_ARGS+=	--disable-gl
.endif

.if ${PORT_OPTIONS:MVAAPI}
LIB_DEPENDS+=		libva.so:${PORTSDIR}/multimedia/libva
.else
CONFIGURE_ARGS+=	--disable-vaapi
.endif

.if ${PORT_OPTIONS:MVDPAU}
LIB_DEPENDS+=		libvdpau.so:${PORTSDIR}/multimedia/libvdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=		xinerama xineramaproto
.else
CONFIGURE_ARGS+=	--disable-xinerama
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=		libjack.so:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=		libpulse.so:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

post-extract:
	${CP} ${DISTDIR}/waf-${WAF_VERSION} ${WRKSRC}/waf
	@${CHMOD} +x ${WRKSRC}/waf

post-patch:
	@${FIND} ${WRKSRC}/DOCS/man -name '*.rst' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g'

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		waf configure ${_MAKE_JOBS} ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		waf build ${_MAKE_JOBS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		waf install --destdir=${STAGEDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mpv
	${INSTALL_DATA} ${WRKSRC}/etc/example.conf ${STAGEDIR}${PREFIX}/etc/mpv/mpv.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/input.conf ${STAGEDIR}${PREFIX}/etc/mpv/input.conf.sample

.include <bsd.port.mk>
