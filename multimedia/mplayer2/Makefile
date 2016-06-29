# $FreeBSD$

PORTNAME=	mplayer2
PORTVERSION=	${MPLAYER2_PORT_VERSION}
PORTREVISION=	21
CATEGORIES=	multimedia audio
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Advanced general-purpose video player

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libavcodec.so:multimedia/ffmpeg
BUILD_DEPENDS=	rst2man:textproc/py-docutils

USES=		cpe gmake iconv ncurses pkgconfig python:3,build tar:xz
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	TMPDIR="${WRKSRC}"
CONFIGURE_ARGS=	--cc=${CC} \
		--extra-libs='${LIBS}' \
		--mandir=${PREFIX}/man \
		--disable-alsa \
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

OPTIONS_DEFINE=	A52 ASS CACA CDIO DEBUG DV DVDREAD DVDNAV GIF IPV6 JACK LADSPA \
		LIBBLURAY LIRC MAD OPENGL PORTAUDIO PULSEAUDIO REALPLAYER \
		RTC SDL SMB SPEEX THEORA V4L VDPAU X11 XINERAMA
OPTIONS_DEFAULT=A52 ASS ENCA DVDREAD DVDNAV VDPAU X11
OPTIONS_SUB=	yes

OPTIONS_DEFINE_i386+=		WIN32
.if !defined(PACKAGE_BUILDING)
# Depend on RESTRICTED package only when building manually
OPTIONS_DEFAULT_i386+=		WIN32
.endif

.for _arch in i386 amd64 powerpc powerpc64
OPTIONS_DEFAULT_${_arch}+=	RTCPU
OPTIONS_DEFINE_${_arch}+=	RTCPU
.endfor

ASS_DESC=	Enable ASS/SSA subtitle rendering
DVDREAD_DESC=	DVD Playback support
DVDNAV_DESC=	DVD menu navigation
REALPLAYER_DESC=Enable realplayer plugin
RTC_DESC=	Enable kernel realtime clock timing
RTCPU_DESC=	Allow runtime CPU detection
WIN32_DESC=	Enable win32 codec set on the IA32 arch

SUB_FILES=	pkg-message

CONFLICTS=	mplayer-1.*

BROKEN_sparc64=	Does not compile on sparc64

A52_LIB_DEPENDS=	liba52.so:audio/liba52
A52_CONFIGURE_OFF=	--disable-liba52

ASS_LIB_DEPENDS=	libass.so:multimedia/libass
ASS_CONFIGURE_OFF=	--disable-libass

CACA_LIB_DEPENDS=	libcaca.so:graphics/libcaca
CACA_CONFIGURE_OFF=	--disable-caca

CDIO_LIB_DEPENDS=	libcdio_paranoia.so:sysutils/libcdio-paranoia
CDIO_CONFIGURE_OFF=	--disable-libcdio

DEBUG_CONFIGURE_ON=	--enable-debug=3
DEBUG_CONFIGURE_OFF=	--disable-debug

DV_LIB_DEPENDS=		libdv.so:multimedia/libdv
DV_CONFIGURE_OFF=	--disable-libdv

DVDREAD_LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread
DVDREAD_CONFIGURE_OFF=	--disable-dvdread

DVDNAV_LIB_DEPENDS=	libdvdnav.so:multimedia/libdvdnav
DVDNAV_CONFIGURE_OFF=	--disable-dvdnav

ENCA_LIB_DEPENDS=	libenca.so:converters/enca
ENCA_CONFIGURE_OFF=	--disable-enca

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_ON=	--enable-gif
GIF_CONFIGURE_OFF=	--disable-gif

IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_OFF=	--disable-inet6

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--disable-jack

LADSPA_RUN_DEPENDS=	${LOCALBASE}/lib/ladspa/amp.so:audio/ladspa
LADSPA_CONFIGURE_OFF=	--disable-ladspa

LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_OFF=--disable-bluray

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_OFF=	--disable-lirc

MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CONFIGURE_OFF=	--disable-mad

OPENGL_USE=		GL=gl XORG=glproto
OPENGL_CONFIGURE_OFF=	--disable-gl
OPENGL_IMPLIES=		X11

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_OFF=--disable-portaudio

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=--disable-pulse

REALPLAYER_BUILD_DEPENDS=realplay:multimedia/linux-realplayer
REALPLAYER_RUN_DEPENDS=	realplay:multimedia/linux-realplayer
REALPLAYER_CONFIGURE_OFF=--disable-real

RTC_BUILD_DEPENDS=	${LOCALBASE}/modules/rtc.ko:emulators/rtc
RTC_RUN_DEPENDS=	${LOCALBASE}/modules/rtc.ko:emulators/rtc
RTC_CONFIGURE_OFF=	--disable-rtc

RTCPU_CONFIGURE_ON=	--enable-runtime-cpudetection
RTCPU_CONFIGURE_OFF=	--disable-runtime-cpudetection

SDL_USE=		SDL=sdl
SDL_CONFIGURE_OFF=	--disable-sdl

SMB_LIB_DEPENDS=	libsmbclient.so:net/samba-libsmbclient
SMB_CONFIGURE_OFF=	--disable-smb

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
SPEEX_CONFIGURE_OFF=	--disable-speex

THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CONFIGURE_OFF=	--disable-theora

V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_OFF=	--disable-tv-v4l2
V4L_LIBS=		-lv4l2

VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_OFF=	--disable-vdpau

WIN32_RUN_DEPENDS=	win32-codecs>0:multimedia/win32-codecs
WIN32_CONFIGURE_ON=	--codecsdir=${LOCALBASE}/lib/win32
WIN32_CONFIGURE_OFF=	--disable-win32dll --disable-qtx

X11_USE=		XORG=x11,xv,xxf86vm
X11_CONFIGURE_OFF=	--disable-x11

XINERAMA_USE=		XORG=xinerama,xineramaproto
XINERAMA_CONFIGURE_OFF=	--disable-xinerama
XINERAMA_IMPLIES=	X11

WITH_CDROM_DEVICE?=	/dev/cd0

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
	@${REINPLACE_CMD} -e \
		'/CFLAGS.*-D_LARGEFILE64_SOURCE/ s/-D_LARGEFILE64_SOURCE/-D_FILE_OFFSET_BITS=64/' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
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

post-patch-RTC-on:
	@${REINPLACE_CMD} -e \
		's|irqp = 1024|irqp = ${DEFAULT_KERN_HZ}|' \
		${WRKSRC}/mplayer.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/example.conf \
		${STAGEDIR}${PREFIX}/etc/mplayer/mplayer.conf.sample
.for conf in codecs input
	${INSTALL_DATA} ${WRKSRC}/etc/${conf}.conf \
		${STAGEDIR}${PREFIX}/etc/mplayer/${conf}.conf.sample
.endfor

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE= you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
