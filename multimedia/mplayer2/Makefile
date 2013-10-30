# $FreeBSD$

PORTNAME=	mplayer2
PORTVERSION=	${MPLAYER2_PORT_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Advanced general-purpose video player

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libdvdread.so:${PORTSDIR}/multimedia/libdvdread
BUILD_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		python3:${PORTSDIR}/lang/python3 \
		rst2man:${PORTSDIR}/textproc/py-docutils
RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg

USE_XZ=		yes
USES=		gmake iconv ncurses pkgconfig
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		TMPDIR="${WRKSRC}"
CONFIGURE_ARGS=	--cc=${CC} \
		--extra-cflags='-I${LOCALBASE}/include/portaudio2' \
		--extra-libs='-lavresample' \
		--extra-ldflags='-L${LOCALBASE}/lib/portaudio2' \
		--mandir=${PREFIX}/man \
		--enable-libavresample \
		--disable-alsa \
		--disable-liba52 \
		--disable-directfb \
		--disable-faad \
		--disable-mng \
		--disable-libdca \
		--disable-xvid \
		--disable-mpg123 \
		--disable-musepack
MAKE_ARGS+=	BINDIR=${STAGEDIR}${PREFIX}/bin \
		CONFDIR=${STAGEDIR}${PREFIX}/etc/mplayer

MPLAYER2_SNAPSHOT_DATE=	2013-04-28
MPLAYER2_PORT_VERSION=	2.0.${MPLAYER2_SNAPSHOT_DATE:S/-//g}


OPTIONS_DEFINE=	DEBUG RTC IPV6 SMB LIBBLURAY V4L DV THEORA \
		X11 XINERAMA OPENGL SDL VDPAU GIF CACA \
		MAD SPEEX LIBCDIO LADSPA REALPLAYER \
		JACK PULSE PORTAUDIO ASS LIRC
OPTIONS_DEFAULT=X11 ASS

.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFINE+=	WIN32
OPTIONS_DEFAULT+=	WIN32
.endif

RTC_DESC=	Enable kernel realtime clock timing
PULSE_DESC=	Enable PulseAudio support
THEORA_DESC=	Enable ogg theora video support
ASS_DESC=	Enable ASS/SSA subtitle rendering
WIN32_DESC=	Enable win32 codec set on the IA32 arch
REALPLAYER_DESC=Enable realplayer plugin
LIRC_DESC=	Enable lirc support
LIBCDIO_DESC=	Enable libcdio support
V4L_DESC=	Enable Video4Linux TV support

SUB_FILES=	pkg-message

CONFLICTS=	mplayer-1.*

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${OSVERSION} < 803000
CONFIGURE_ARGS+=	--disable-ssse3
.endif

WITH_CDROM_DEVICE?=	/dev/cd0

#On i386, gcc runs out of general purpose registers when
#trying to compile a debug version with the default flags.
.if ${PORT_OPTIONS:MDEBUG}
.if ${ARCH} == "i386"
DEBUG_FLAGS=		-g -O -fomit-frame-pointer
.endif
.else
.if defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-runtime-cpudetection
CFLAGS+=		-O2 -fomit-frame-pointer
.else
CONFIGURE_ENV+=		CPPFLAGS= CFLAGS= LDFLAGS=
.endif
.endif

.if ${PORT_OPTIONS:MIPV6}
CATEGORIES+=		ipv6
.else
CONFIGURE_ARGS+=	--disable-inet6
.endif

.if ${PORT_OPTIONS:MGIF}
LIB_DEPENDS+=		libgif.so:${PORTSDIR}/graphics/giflib
.else
CONFIGURE_ARGS+=	--disable-gif
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=		libmad.so:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=	--disable-mad
.endif

.if ${PORT_OPTIONS:MDV}
LIB_DEPENDS+=		libdv.so:${PORTSDIR}/multimedia/libdv
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif

.if ${PORT_OPTIONS:MTHEORA}
LIB_DEPENDS+=		libtheora.so:${PORTSDIR}/multimedia/libtheora
.else
CONFIGURE_ARGS+=	--disable-theora
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=		libspeex.so:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=	--disable-speex
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=		libjack.so:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if ${PORT_OPTIONS:MPULSE}
LIB_DEPENDS+=		libpulse.so:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=		libportaudio.so.2:${PORTSDIR}/audio/portaudio2
.else
CONFIGURE_ARGS+=	--disable-portaudio
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
LIB_DEPENDS+=		libbluray.so:${PORTSDIR}/multimedia/libbluray
.else
CONFIGURE_ARGS+=	--disable-bluray
.endif

.if ${PORT_OPTIONS:MSMB}
LIB_DEPENDS+=		libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
.else
CONFIGURE_ARGS+=	--disable-smb
.endif

.if ${PORT_OPTIONS:MLIBCDIO}
LIB_DEPENDS+=		libcdio.so:${PORTSDIR}/sysutils/libcdio
.else
CONFIGURE_ARGS+=	--disable-libcdio
.endif

.if ${PORT_OPTIONS:MLADSPA}
RUN_DEPENDS+=		${LOCALBASE}/lib/ladspa/amp.so:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ARGS+=	--disable-ladspa
.endif

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
.if ${PORT_OPTIONS:MWIN32} && !defined(PACKAGE_BUILDING) && ${ARCH} == "i386"
CODEC_PORT=		${PORTSDIR}/multimedia/win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
RUN_DEPENDS+=		${CODEC_DETECTION_FILE}:${CODEC_PORT}
CONFIGURE_ARGS+=	--codecsdir=${LOCALBASE}/lib/win32
.else
CONFIGURE_ARGS+=	--disable-win32dll --disable-qtx
.endif
.endif # ARCH == i386/amd64

.if ${PORT_OPTIONS:MREALPLAYER}
RUN_DEPENDS+=		realplay:${PORTSDIR}/multimedia/linux-realplayer
BUILD_DEPENDS+=		realplay:${PORTSDIR}/multimedia/linux-realplayer
.else
CONFIGURE_ARGS+=	--disable-real
.endif

.if ${PORT_OPTIONS:MV4L}
BUILD_DEPENDS+=		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS+=		libv4l2.so:${PORTSDIR}/multimedia/libv4l
CONFIGURE_ARGS+=	--enable-tv-v4l2
EXTRA_LIBS+=		-lv4l2
.else
CONFIGURE_ARGS+=	--disable-tv-v4l2
.endif

.if defined(EXTRA_LIBS)
CONFIGURE_ARGS+=	--extra-libs="${EXTRA_LIBS}"
.endif

.if ${PORT_OPTIONS:MASS}
LIB_DEPENDS+=		libass.so:${PORTSDIR}/multimedia/libass
.else
CONFIGURE_ARGS+=	--disable-libass --disable-enca
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=		x11 xv xxf86vm
.if ${PORT_OPTIONS:MOPENGL}
USE_XORG+=		glproto
LIB_DEPENDS+=		libGL.so:${PORTSDIR}/graphics/libGL
.else
CONFIGURE_ARGS+=	--disable-gl
.endif
.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=		xinerama xineramaproto
.else
CONFIGURE_ARGS+=	--disable-xinerama
.endif
.else			#WITHOUT_X11
CONFIGURE_ARGS+=	--disable-x11
.endif

.if ${PORT_OPTIONS:MVDPAU}
LIB_DEPENDS+=		libvdpau.so:${PORTSDIR}/multimedia/libvdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

.if ${PORT_OPTIONS:MRTC}
BUILD_DEPENDS+=	${LOCALBASE}/modules/rtc.ko:${PORTSDIR}/emulators/rtc
RUN_DEPENDS+=	${LOCALBASE}/modules/rtc.ko:${PORTSDIR}/emulators/rtc
CONFIGURE_ARGS+=	--enable-rtc
.else
CONFIGURE_ARGS+=	--disable-rtc
.endif

.if ${PORT_OPTIONS:MLIBCACA}
LIB_DEPENDS+=		libcaca.so:${PORTSDIR}/graphics/libcaca
.else
CONFIGURE_ARGS+=	--disable-caca
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=		liblirc_client.so:${PORTSDIR}/comms/lirc
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=		sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if defined(WITH_KERN_HZ)
DEFAULT_KERN_HZ=${WITH_KERN_HZ}
.else
DEFAULT_KERN_HZ=1024
.endif

pre-everything::
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "There are some knobs which *can* *not* be selected via the"
	@${ECHO_MSG} "OPTIONS framework. You might want to check the Makefile in"
	@${ECHO_MSG} "order to learn more about them."

post-patch:
.if ${OSVERSION} >= 900010
	@${REINPLACE_CMD} -e \
		'/CFLAGS.*-D_LARGEFILE64_SOURCE/ s/-D_LARGEFILE64_SOURCE/-D_FILE_OFFSET_BITS=64/' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
	@${REINPLACE_CMD} \
		-e 's|/dev/acd0|${WITH_CDROM_DEVICE}|' \
		-e 's|/usr/local|${LOCALBASE}|' \
		-e 's|-lbz2|/usr/lib/libbz2.so|' \
		-e 's|-lncurses|/usr/lib/libncurses.so|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} -E ${WRKSRC} -type f \
		-iregex ".*(configure|.sh|Makefile)" -print0 | \
		${XARGS} -x -0 -n 10 \
		${REINPLACE_CMD} -E \
			-e 's|[[:space:]]gcc[-[:digit:]\.]+| ${CC}|' \
			-e 's|[[:space:]]gcc| ${CC}|' \
			-e 's|\$$\(CC\)|${CC}|' \
			-e 's|/usr/X11R6|${LOCALBASE}|'
	@${FIND} ${WRKSRC}/DOCS/man -name "mplayer.1" | ${XARGS} ${REINPLACE_CMD} -E -e \
		's|/usr/\\:local/\\:etc/\\:mplayer|${DATADIR:S/\//\/\\\:/g}|g ; \
		 s|/dev/\\:(dvd[[:alnum:]]*[[:>:]])|${WITH_CDROM_DEVICE:S/dev\//dev\/\\\:/}|g ; \
		 s|/dev/\\:(cdrom[[:alnum:]]*[[:>:]])|${WITH_CDROM_DEVICE:S/dev\//dev\/\\\:/}|g'
.if ${PORT_OPTIONS:MRTC}
	@${REINPLACE_CMD} -e \
		's|irqp = 1024|irqp = ${DEFAULT_KERN_HZ}|' \
		${WRKSRC}/mplayer.c
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/etc/example.conf \
		${STAGEDIR}${PREFIX}/etc/mplayer/mplayer.conf.sample
.for conf in codecs input
	@${INSTALL_DATA} ${WRKSRC}/etc/${conf}.conf \
		${STAGEDIR}${PREFIX}/etc/mplayer/${conf}.conf.sample
.endfor

.include <bsd.port.mk>
