# Created by: Thomas E. Zander
# $FreeBSD$

PORTNAME=	mencoder
PORTVERSION=	${MPLAYER_PORT_VERSION}
PORTREVISION=	1

COMMENT=	Convenient video file and movie encoder

NO_STAGE=	yes
.include "${.CURDIR}/../mplayer/Makefile.shared"

OPTIONS_DEFINE= AMR_NB AMR_WB BLURAY CDIO CDPARANOIA DEBUG DIRAC \
		DV FAAC FONTCONFIG FRIBIDI GIF GSM IPV6 JACK LADSPA \
		LIBMNG LIVEMEDIA LZO MAD NAS OCFLAGS OPENAL OPENJPEG \
		OTCHAIN PULSEAUDIO REAL RTCPU RTMP SCHROEDINGER SMB \
		THEORA TWOLAME V4L VPX WIN32 X264 XVID

OPTIONS_DEFAULT=GIF IPV6 OCFLAGS RTCPU WIN32 X264 XVID

BLURAY_DESC?=	BluRay support
LZO_DESC?=	Enable external liblzo library
OCFLAGS_DESC?=	Use optimized compiler flags
OTCHAIN_DESC?=	Use gcc 4.6+ toolchain on legacy systems
REAL_DESC?=	Enable realplayer plugin
RTCPU_DESC?=	Use runtime CPU detection
WIN32_DESC?=	Install win32 binary codecs

MAN1=		mencoder.1

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

.include <bsd.port.pre.mk>

LIB_DEPENDS+=	mp3lame:${PORTSDIR}/audio/lame

CONFIGURE_ARGS+=	--disable-mplayer \
			--disable-libdca \
			--disable-x11 \
			--disable-vdpau \
			--disable-rtc \
			--disable-arts \
			--disable-esd \
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

ALL_TARGET=	mencoder

.include "${.CURDIR}/../mplayer/Makefile.options"

.if ${PORT_OPTIONS:MFONTCONFIG}
LIB_DEPENDS+=		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
.else
CONFIGURE_ARGS+=	--disable-fontconfig
.endif

.if ${PORT_OPTIONS:MTWOLAME}
LIB_DEPENDS+=		twolame:${PORTSDIR}/audio/twolame
.else
CONFIGURE_ARGS+=	--disable-twolame
.endif

.if ${PORT_OPTIONS:MFAAC}
LIB_DEPENDS+=		faac:${PORTSDIR}/audio/faac
.else
CONFIGURE_ARGS+=	--disable-faac
.endif

.if ${PORT_OPTIONS:MX264}
LIB_DEPENDS+=		x264:${PORTSDIR}/multimedia/x264
.else
CONFIGURE_ARGS+=	--disable-x264
.endif

.if ${PORT_OPTIONS:MXVID}
LIB_DEPENDS+=		xvidcore:${PORTSDIR}/multimedia/xvid
.else
CONFIGURE_ARGS+=	--disable-xvid
.endif

.if ${PORT_OPTIONS:MDIRAC}
LIB_DEPENDS+=		dirac_encoder:${PORTSDIR}/multimedia/dirac
.else
CONFIGURE_ARGS+=	--disable-libdirac-lavc
.endif

pre-everything::
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "There are some knobs which *can* *not* be selected via the"
	@${ECHO_MSG} "OPTIONS framework. At the moment, their defaults are:"
	@${ECHO_MSG} "WITH_LANG=<LanguageCode>"
	@${ECHO_MSG} "DEFAULT_DVD_DEVICE=/dev/cd0"
	@${ECHO_MSG} "DEFAULT_CDROM_DEVICE=/dev/cd0"

post-patch:
.if ${OSVERSION} >= 900010
	@${REINPLACE_CMD} -e \
		'/CFLAGS.*-D_LARGEFILE64_SOURCE/ s/-D_LARGEFILE64_SOURCE/-D_FILE_OFFSET_BITS=64/' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
	@${REINPLACE_CMD} \
		-e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|; \
		s|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
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
		 s|/dev/\\:(dvd[[:alnum:]]*[[:>:]])|${DEFAULT_DVD_DEVICE:S/dev\//dev\/\\\:/}|g ; \
		 s|/dev/\\:(cdrom[[:alnum:]]*[[:>:]])|${DEFAULT_CDROM_DEVICE:S/dev\//dev\/\\\:/}|g'

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mencoder ${PREFIX}/bin

post-install:
	@${INSTALL_MAN} ${WRKSRC}/DOCS/man/en/mplayer.1 ${MAN1PREFIX}/man/man1/mencoder.1
	@${MKDIR} ${DATADIR}
	@${CHMOD} 755 ${DATADIR}
	@${MKDIR} ${DATADIR}/tools
	@${CHMOD} 755 ${DATADIR}/tools
.for tool in ${TOOLFILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/TOOLS/${tool} ${DATADIR}/tools
.endfor

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not detect CPU correctly on ia64 or sparc64
.endif

.include <bsd.port.post.mk>
