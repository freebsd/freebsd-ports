# Created by: Thomas E. Zander
# $FreeBSD$

PORTNAME=	mencoder
PORTVERSION=	${MPLAYER_PORT_VERSION}.${MPLAYER_SNAPSHOT_DATE:S/-//g}
CATEGORIES=	multimedia audio

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Convenient video file and movie encoder

.include "${.CURDIR}/../mplayer/Makefile.common"

OPTIONS_DEFINE=	AMR_NB AMR_WB BLURAY CDIO DEBUG DV DVDNAV FAAC FONTCONFIG \
		FRIBIDI GIF GNUTLS GSM IPV6 JACK LADSPA LIBMNG LZO \
		MAD NAS OPENAL OPENJPEG OPUS PULSEAUDIO \
		RTMP SCHROEDINGER SMB SPEEX THEORA TWOLAME V4L VPX \
		X264 XVID

OPTIONS_DEFAULT=DVDNAV FONTCONFIG GIF GNUTLS X264 XVID

OPTIONS_DEFINE_i386=	RTCPU
OPTIONS_DEFINE_amd64=	RTCPU
OPTIONS_DEFINE_powerpc=	RTCPU

OPTIONS_DEFAULT_i386=	RTCPU
OPTIONS_DEFAULT_amd64=	RTCPU
OPTIONS_DEFAULT_powerpc=RTCPU

BLURAY_DESC?=	BluRay support
DVDNAV_DESC?=	DVD navigation features support
LZO_DESC?=	Enable external liblzo library
RTCPU_DESC?=	Use runtime CPU detection

RESTRICTED=	Port has restricted dependencies

PATCHDIR=	${.CURDIR}/../mplayer/files
FILESDIR=	${PATCHDIR}
DATADIR=	${PREFIX}/share/mplayer

TOOLFILES=	aconvert.sh binary_codecs.sh calcbpp.pl \
		checktree.sh countquant.pl divx2svcd.sh \
		dvd2divxscript.pl edgedetect.fp edgeenh.fp \
		emboss.fp mencvcd.sh midentify.sh \
		mpconsole.sh mphelp_check.py mplmult.sh \
		plotpsnr.pl psnr-video.sh qepdvcd.sh \
		subedit.pl subsearch.sh vobshift.py \
		w32codec_dl.pl wma2ogg.pl

USES+=		alias iconv pkgconfig shebangfix
SHEBANG_FILES=	TOOLS/calcbpp.pl TOOLS/checktree.sh TOOLS/countquant.pl	\
		TOOLS/divx2svcd.sh TOOLS/dvd2divxscript.pl TOOLS/mencvcd.sh \
		TOOLS/mphelp_check.py TOOLS/plotpsnr.pl TOOLS/psnr-video.sh \
		TOOLS/qepdvcd.sh TOOLS/subedit.pl TOOLS/w32codec_dl.pl \
		TOOLS/wma2ogg.pl

.include "${.CURDIR}/../mplayer/Makefile.optvars"
.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--disable-mplayer \
			--disable-libdca \
			--disable-x11 \
			--disable-vdpau \
			--disable-rtc \
			--disable-arts \
			--disable-caca \
			--disable-lirc \
			--disable-sdl \
			--disable-svga \
			--disable-aa \
			--disable-joystick \
			--disable-directfb \
			--disable-mpg123 \
			--disable-enca \
			--disable-musepack

LIB_DEPENDS+=	libmp3lame.so:audio/lame

ALL_TARGET=	mencoder

.include "${.CURDIR}/../mplayer/Makefile.options"

BROKEN_aarch64=		Fails to compile: error: invalid operand for instruction

pre-everything::
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "There are some knobs which *can* *not* be selected via the"
	@${ECHO_MSG} "OPTIONS framework. At the moment, these settings are:"
	@${ECHO_MSG} "DEFAULT_DVD_DEVICE=${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "DEFAULT_CDROM_DEVICE=${DEFAULT_CDROM_DEVICE}"

post-patch: common-post-patch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mencoder ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/DOCS/man/en/mplayer.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/mencoder.1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${CHMOD} 755 ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/tools
	@${CHMOD} 755 ${STAGEDIR}${DATADIR}/tools
.for tool in ${TOOLFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/TOOLS/${tool} ${STAGEDIR}${DATADIR}/tools
.endfor

.include <bsd.port.post.mk>
