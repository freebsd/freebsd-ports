# Created by: Thomas E. Zander with help from Vladimir Kushnir
# $FreeBSD$

PORTNAME=	mplayer
PORTVERSION=	${MPLAYER_PORT_VERSION}.${MPLAYER_SNAPSHOT_DATE:S/-//g}
CATEGORIES=	multimedia audio

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	High performance media player supporting many formats

.include "${.CURDIR}/../../multimedia/mplayer/Makefile.common"

OPTIONS_DEFINE=	AALIB AMR_NB AMR_WB ASS BLURAY CACA CDIO DV DVDNAV \
		ENCA FONTCONFIG FRIBIDI GIF GNUTLS GSM GUI IPV6 JACK \
		LADSPA LIBMNG LIRC LZO NAS NLS OPENAL OPENGL \
		OPENJPEG OPUS PULSEAUDIO RTMP \
		SDL SKINS SNDIO SMB SPEEX SVGALIB V4L VDPAU VPX \
		X11 X11DGA X11VM XINERAMA XVIDEO XVMC

OPTIONS_DEFAULT=ASS DVDNAV FONTCONFIG FRIBIDI GNUTLS OPENGL \
		SKINS X11 X11DGA X11VM XINERAMA XVIDEO

OPTIONS_DEFINE_i386=	RTCPU
OPTIONS_DEFINE_amd64=	RTCPU
OPTIONS_DEFINE_powerpc=	RTCPU

OPTIONS_DEFAULT_i386=	RTCPU VDPAU
OPTIONS_DEFAULT_amd64=	RTCPU VDPAU
OPTIONS_DEFAULT_powerpc=RTCPU

ASS_DESC?=	Subtitles rendering via libass
BLURAY_DESC?=	BluRay support
DVDNAV_DESC?=	DVD navigation features support
ENCA_DESC?=	Charset conversion via enca
LZO_DESC?=	External liblzo support
RTCPU_DESC?=	Use runtime CPU detection
SKINS_DESC?=	Install skins for GUI
X11DGA_DESC?=	X11 DGA video driver support
X11VM_DESC?=	X11 VidMode support

SUB_FILES=	pkg-message

CONFLICTS=	mplayer2-2.*

CONFFILES=	example.conf input.conf menu.conf dvb-menu.conf
USES+=		iconv pkgconfig

OPTIONS_SUB=	yes

.include "${.CURDIR}/../../multimedia/mplayer/Makefile.optvars"
.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--disable-arts \
			--disable-directfb \
			--disable-faac \
			--disable-libdca \
			--disable-toolame \
			--disable-twolame \
			--disable-x264 \
			--disable-xvid \
			--disable-mencoder \
			--disable-mpg123 \
			--disable-musepack \
			--disable-theora

.include "${.CURDIR}/../../multimedia/mplayer/Makefile.options"

pre-everything::
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "There are some knobs which *can* *not* be selected via the"
	@${ECHO_MSG} "OPTIONS framework. At the moment, these settings are:"
	@${ECHO_MSG} "WITH_KERN_HZ=${DEFAULT_KERN_HZ}"
	@${ECHO_MSG} "DEFAULT_DVD_DEVICE=${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "DEFAULT_CDROM_DEVICE=${DEFAULT_CDROM_DEVICE}"

.if ${PORT_OPTIONS:MGUI} && ${PORT_OPTIONS:MX11}
	@${ECHO_MSG} "If you want to use the GUI, you can use the skins from"
	@${ECHO_MSG} "${PORTSDIR}/multimedia/mplayer-skins"
	@${ECHO_MSG} "or download them from"
	@${ECHO_MSG} "http://www.mplayerhq.hu/"
.endif

post-patch: common-post-patch

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${CHMOD} 755 ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/examples/etc
	@${CHMOD} 755 ${STAGEDIR}${DATADIR}/examples/etc
.for conf in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${conf} ${STAGEDIR}${DATADIR}/examples/etc
.endfor
.if ${PORT_OPTIONS:MGUI} && ${PORT_OPTIONS:MX11}
	@${LN} -sf mplayer ${STAGEDIR}${PREFIX}/bin/gmplayer
	@(cd ${STAGEDIR}${MAN1PREFIX}/man/man1 && ${LN} -sf mplayer.1.gz gmplayer.1.gz)
	${CP} -f ${WRKSRC}/etc/mplayer256x256.png ${STAGEDIR}${PREFIX}/share/pixmaps/mplayer.png
.endif

.include <bsd.port.post.mk>
