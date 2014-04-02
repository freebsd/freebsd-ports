# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpv
PORTVERSION=	0.3.7
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	GH:0 GHC:0 http://waf.googlecode.com/files/:1
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
GH_COMMIT=	2758bc4

WAF_VERSION=	1.7.15

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
OPTIONS_GROUP_IN=	CDIO DVDNAV LIBBLURAY V4L QUVI SMB
OPTIONS_GROUP_VO=	CACA OPENGL VAAPI VDPAU XINERAMA
OPTIONS_GROUP_AO=	JACK PULSEAUDIO

BS2B_DESC=	Enable Bauer Stereophonic-to-Binaural DSP support
DVDNAV_DESC=	Enable DVD navigation menus support
ENCA_DESC=	Enable encoding detection support
QUVI_DESC=	Enable flash media stream support
IN_DESC=	Input
VO_DESC=	Video Output
AO_DESC=	Audio Output

BS2B_LIB_DEPENDS=		libbs2b.so:${PORTSDIR}/audio/libbs2b
BS2B_CONFIGURE_ENABLE=		libbs2b

ENCA_LIB_DEPENDS=		libenca.so:${PORTSDIR}/converters/enca
ENCA_CONFIGURE_ENABLE=		enca

LADSPA_LIB_DEPENDS=		ladspa/amp.so:${PORTSDIR}/audio/ladspa
LADSPA_CONFIGURE_ENABLE=	ladspa

LCMS2_LIB_DEPENDS=		liblcms2.so:${PORTSDIR}/graphics/lcms2
LCMS2_CONFIGURE_ENABLE=		lcms2

LIRC_LIB_DEPENDS=		liblirc_client.so:${PORTSDIR}/comms/lirc
LIRC_CONFIGURE_ENABLE=		lirc

CDIO_LIB_DEPENDS=		libcdio.so:${PORTSDIR}/sysutils/libcdio
CDIO_CONFIGURE_ENABLE=		cdda

DVDNAV_LIB_DEPENDS=		libdvdnav.so:${PORTSDIR}/multimedia/libdvdnav
DVDNAV_CONFIGURE_ENABLE=	dvdnav

LIBBLURAY_LIB_DEPENDS=		libbluray.so:${PORTSDIR}/multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	libbluray

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
V4L_LIB_DEPENDS=		libv4l2.so:${PORTSDIR}/multimedia/libv4l
V4L_CONFIGURE_ENABLE=		tv-v4l2

QUVI_LIB_DEPENDS=		libquvi.so:${PORTSDIR}/multimedia/libquvi
QUVI_CONFIGURE_ENABLE=		libquvi

SMB_LIB_DEPENDS=		libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
SMB_CONFIGURE_ENABLE=		libsmbclient

CACA_LIB_DEPENDS=		libcaca.so:${PORTSDIR}/graphics/libcaca
CACA_CONFIGURE_ENABLE=		caca

OPENGL_USE=			XORG=glproto
OPENGL_LIB_DEPENDS=		libGL.so:${PORTSDIR}/graphics/libGL
OPENGL_CONFIGURE_ENABLE=	gl

VAAPI_LIB_DEPENDS=		libva.so:${PORTSDIR}/multimedia/libva
VAAPI_CONFIGURE_ENABLE=		vaapi

VDPAU_LIB_DEPENDS=		libvdpau.so:${PORTSDIR}/multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=		vdpau

XINERAMA_USE=			XORG=xinerama,xineramaproto
XINERAMA_CONFIGURE_ENABLE=	xinerama

JACK_LIB_DEPENDS=		libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ENABLE=		jack

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

.include <bsd.port.options.mk>

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
