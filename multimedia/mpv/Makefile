# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpv
PORTVERSION=	0.2.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia audio

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Free and open-source general-purpose video player

LICENSE=	GPLv2

LIB_DEPENDS=	libass.so:${PORTSDIR}/multimedia/libass \
		libdvdread.so:${PORTSDIR}/multimedia/libdvdread
BUILD_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		rst2man:${PORTSDIR}/textproc/py-docutils
RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	mpv-player
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	93ce083

USES=		desktop-file-utils gmake iconv pkgconfig
USE_LUA=	5.1
USE_XORG=	x11 xv xxf86vm
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${PREFIX}/man \
		--cc=${CC} \
		--disable-mng \
		--disable-mpg123 \
		--disable-alsa \
		--disable-portaudio \
		--disable-pdf

OPTIONS_DEFINE=		BS2B DEBUG LADSPA LCMS2 LIRC
OPTIONS_GROUP=		IN VO AO
OPTIONS_GROUP_IN=	CDIO LIBBLURAY V4L QUVI SMB
OPTIONS_GROUP_VO=	CACA OPENGL VAAPI VDPAU XINERAMA
OPTIONS_GROUP_AO=	JACK PULSEAUDIO

BS2B_DESC=	Enable Bauer Stereophonic-to-Binaural DSP support
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

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--disable-optimization
.else
CONFIGURE_ARGS+=	--enable-optimization="${CFLAGS}" \
			--disable-debug
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
CONFIGURE_ARGS+=	--disable-libcdio
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
LIB_DEPENDS+=		libbluray.so:${PORTSDIR}/multimedia/libbluray
.else
CONFIGURE_ARGS+=	--disable-bluray
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS+=		libv4l2.so:${PORTSDIR}/multimedia/libv4l
CONFIGURE_ARGS+=	--enable-tv-v4l2
EXTRA_LIBS+=		-lv4l2
.else
CONFIGURE_ARGS+=	--disable-tv-v4l2
.endif

.if ${PORT_OPTIONS:MQUVI}
LIB_DEPENDS+=		libquvi.so:${PORTSDIR}/multimedia/libquvi
.else
CONFIGURE_ARGS+=	--disable-libquvi4 --disable-libquvi9
.endif

.if ${PORT_OPTIONS:MSMB}
LIB_DEPENDS+=		libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
.else
CONFIGURE_ARGS+=	--disable-smb
.endif

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

.if defined(EXTRA_LIBS)
CONFIGURE_ARGS+=	--extra-libs="${EXTRA_LIBS}"
.endif

post-patch:
.if ${OSVERSION} >= 900010
	@${REINPLACE_CMD} -e \
		'/CFLAGS.*-D_LARGEFILE64_SOURCE/ s/-D_LARGEFILE64_SOURCE/-D_FILE_OFFSET_BITS=64/' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
	@${FIND} ${WRKSRC}/DOCS/man -name '*.rst' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g'

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mpv
	${INSTALL_DATA} ${WRKSRC}/etc/example.conf ${STAGEDIR}${PREFIX}/etc/mpv/mpv.conf.sample
.for conf in encoding-example-profiles input
	${INSTALL_DATA} ${WRKSRC}/etc/${conf}.conf ${STAGEDIR}${PREFIX}/etc/mpv/${conf}.conf.sample
.endfor

.include <bsd.port.mk>
