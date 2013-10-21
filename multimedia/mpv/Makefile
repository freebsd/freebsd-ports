# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpv
PORTVERSION=	20130711
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Free and open-source general-purpose video player

LICENSE=	GPLv3

LIB_DEPENDS=	ass:${PORTSDIR}/multimedia/libass \
		dvdread:${PORTSDIR}/multimedia/libdvdread
BUILD_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		rst2man:${PORTSDIR}/textproc/py-docutils
RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg

USE_XZ=		yes
USES=		gmake iconv pkgconfig
USE_XORG=	x11 xv xxf86vm
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${PREFIX}/man \
		--cc=${CC} \
		--extra-cflags=' \
		-I${LOCALBASE}/include' \
		--extra-ldflags=' \
		-L${LOCALBASE}/lib' \
		--disable-mng \
		--disable-mpg123 \
		--disable-alsa \
		--disable-portaudio

OPTIONS_DEFINE=		BS2B DEBUG LADSPA LIRC
OPTIONS_GROUP=		IN VO AO
OPTIONS_GROUP_IN=	CDIO LIBBLURAY V4L QUVI SMB
OPTIONS_GROUP_VO=	OPENGL VDPAU XINERAMA
OPTIONS_GROUP_AO=	JACK PULSEAUDIO

BS2B_DESC=	Enable Bauer Stereophonic-to-Binaural DSP support
QUVI_DESC=	Enable flash media stream support
IN_DESC=	Input
VO_DESC=	Video Output
AO_DESC=	Audio Output


MAN1=		mpv.1
MANCOMPRESSED=	no

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBBLURAY}
LIB_DEPENDS+=		bs2b:${PORTSDIR}/audio/libbs2b
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
RUN_DEPENDS+=		${LOCALBASE}/lib/ladspa/amp.so:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ARGS+=	--disable-ladspa
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=		lirc_client:${PORTSDIR}/comms/lirc
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
LIB_DEPENDS+=		cdio:${PORTSDIR}/sysutils/libcdio
.else
CONFIGURE_ARGS+=	--disable-libcdio
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
LIB_DEPENDS+=		bluray:${PORTSDIR}/multimedia/libbluray
.else
CONFIGURE_ARGS+=	--disable-bluray
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS+=		v4l2:${PORTSDIR}/multimedia/libv4l
CONFIGURE_ARGS+=	--enable-tv-v4l2
EXTRA_LIBS+=		-lv4l2
.else
CONFIGURE_ARGS+=	--disable-tv-v4l2
.endif

.if ${PORT_OPTIONS:MQUVI}
LIB_DEPENDS+=		quvi:${PORTSDIR}/multimedia/libquvi
.else
CONFIGURE_ARGS+=	--disable-libquvi4 --disable-libquvi9
.endif

.if ${PORT_OPTIONS:MSMB}
LIB_DEPENDS+=		smbclient:${PORTSDIR}/net/samba-libsmbclient
.else
CONFIGURE_ARGS+=	--disable-smb
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_XORG+=		glproto
LIB_DEPENDS+=		GL:${PORTSDIR}/graphics/libGL
.else
CONFIGURE_ARGS+=	--disable-gl
.endif

.if ${PORT_OPTIONS:MVDPAU}
LIB_DEPENDS+=		vdpau:${PORTSDIR}/multimedia/libvdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=		xinerama xineramaproto
.else
CONFIGURE_ARGS+=	--disable-xinerama
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=		jack:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=		pulse:${PORTSDIR}/audio/pulseaudio
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
	@${REINPLACE_CMD} \
		-e 's|/dev/acd0|/dev/cd0|' \
		-e 's|-lncurses|/usr/lib/libncurses.so|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${WRKSRC}/DOCS/man -name '*.rst' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g' \
		-e 's|/dev/cdrom|/dev/cd0|g' \
		-e 's|/dev/dvd|/dev/cd0|g'

post-install:
	${MKDIR} ${PREFIX}/etc/mpv
	${INSTALL_DATA} ${WRKSRC}/etc/example.conf ${PREFIX}/etc/mpv/mpv.conf.sample
.for conf in encoding-example-profiles input
	${INSTALL_DATA} ${WRKSRC}/etc/${conf}.conf ${PREFIX}/etc/mpv/${conf}.conf.sample
.endfor

.include <bsd.port.mk>
