# New ports collection makefile for:	mencoder
# Date created:		23 June 2007
# Whom:			Thomas E. Zander
# $FreeBSD$
#

PORTNAME=	mencoder
PORTVERSION=	${MPLAYER_PORT_VERSION}
PORTREVISION=	1
COMMENT=	Convenient video file and movie encoder
RESTRICTED=	Port has restricted dependencies

.include "${.CURDIR}/../mplayer/Makefile.shared"

OPTIONS=	DEBUG "Include debug symbols in mencoder's binary" off
OPTIONS+=	BLURAY "Build with libbluray suport" off
OPTIONS+=	FONTCONFIG "Enable fontconfig support" off
OPTIONS+=	RTCPU "Allow runtime CPU detection" on
OPTIONS+=	OCFLAGS "Use optimized compiler flags" on
OPTIONS+=	IPV6 "Include inet6 network support" on
OPTIONS+=	JACK "Enable JackIt audio server support" off
OPTIONS+=	NAS "Enable NAS sound server support" off
OPTIONS+=	OPENAL "Enable OpenAL sound support" off
OPTIONS+=	PULSE "Enable PulseAudio" off
OPTIONS+=	LIBUNGIF "Enable gif support" on
OPTIONS+=	OPENJPEG "Enable JPEG2000 support" off
OPTIONS+=	MNG "Enable MNG input support" off
OPTIONS+=	LIBDV "Enable libdv support" off
OPTIONS+=	MAD "Enable mad MPEG audio engine support" off
OPTIONS+=	AMR "Enable opencore AMR audio codec support" off
OPTIONS+=	TWOLAME "Enable twolame MPEG audio codec support" off
OPTIONS+=	FAAC "Enable FAAC audio codec support" off
OPTIONS+=	LADSPA "Enable LADSPA plugin support" off
OPTIONS+=	SPEEX "Enable speex audio codec support" off
OPTIONS+=	WIN32 "Enable win32 codec set on the IA32 arch" on
OPTIONS+=	THEORA "Enable ogg theora video support" off
OPTIONS+=	XVID "Enable XVID video codec support" on
OPTIONS+=	X264 "Enable x264 (H.264) video codec support" on
OPTIONS+=	VPX "Enable VP8 video via libvpx" off
OPTIONS+=	DIRAC "Enable dirac video codec support" off
OPTIONS+=	SCHROEDINGER "Dirac codec via libschroedinger" off
OPTIONS+=	REALPLAYER "Enable real player plugin" off
OPTIONS+=	LIVEMEDIA "Enable LIVE555 streaming support" off
OPTIONS+=	SMB "Enable Samba input support" off
OPTIONS+=	FRIBIDI "Enable FriBiDi support" off
OPTIONS+=	LIBCDIO "Enable libcdio support" off
OPTIONS+=	CDPARANOIA "Enable cdparanoia support" off
OPTIONS+=	LIBLZO "Enable external liblzo library" off
OPTIONS+=	V4L "Enable Video4Linux TV support" off
OPTIONS+=	LIBRTMP "Enable RTMPDump Streaming Media support" off

MAN1=		mencoder.1

PATCHDIR=	${.CURDIR}/../mplayer/files
DATADIR=	${PREFIX}/share/mplayer

TOOLFILES=	aconvert.sh binary_codecs.sh calcbpp.pl \
		checktree.sh countquant.pl divx2svcd.sh \
		dvd2divxscript.pl edgedetect.fp edgeenh.fp \
		emboss.fp mencvcd.sh midentify.sh \
		mpconsole.sh mplmult.sh plotpsnr.pl \
		psnr-video.sh qepdvcd.sh subedit.pl \
		subsearch.sh w32codec_dl.pl wma2ogg.pl \

.include <bsd.port.pre.mk>

LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame

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
			--disable-ssse3 \
			--disable-mpg123 \
			--disable-musepack

ALL_TARGET=	mencoder

.include "${.CURDIR}/../mplayer/Makefile.options"

.if defined(WITH_FONTCONFIG)
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
.else
CONFIGURE_ARGS+=	--disable-fontconfig
.endif

.if defined(WITH_TWOLAME)
LIB_DEPENDS+=	twolame.0:${PORTSDIR}/audio/twolame
.else
CONFIGURE_ARGS+=	--disable-twolame
.endif

.if defined(WITH_FAAC)
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
.else
CONFIGURE_ARGS+=	--disable-faac
.endif

.if !defined(WITHOUT_X264)
LIB_DEPENDS+=	x264.110:${PORTSDIR}/multimedia/x264
.else
CONFIGURE_ARGS+=	--disable-x264
.endif

.if !defined(WITHOUT_XVID)
LIB_DEPENDS+=		xvidcore.4:${PORTSDIR}/multimedia/xvid
.else
CONFIGURE_ARGS+=	--disable-xvid
.endif

.ifdef(WITH_DIRAC)
LIB_DEPENDS+=		dirac_encoder.1:${PORTSDIR}/multimedia/dirac
.else
CONFIGURE_ARGS+=	--disable-libdirac-lavc
.endif


pre-everything::
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "There are some knobs which *can* *not* be selected via the"
	@${ECHO_MSG} "OPTIONS framework. As this one is a slave port of multimedia/"
	@${ECHO_MSG} "mplayer, you might want to check mplayer's Makefile(s) in"
	@${ECHO_MSG} "order to learn more about them."

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
		-e 's|-L$$_prefix/lib|-L${LOCALBASE}/lib|' \
		-e 's|-I$$_prefix/include|-I${LOCALBASE}/include|' \
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

post-configure:
	@${REINPLACE_CMD} -e 's#-pthread#${PTHREAD_LIBS}#g' \
		${WRKSRC}/config.mak
	@${REINPLACE_CMD} \
		-e 's#HAVE_FAST_CMOV 1#HAVE_FAST_CMOV 0#g' \
		-e 's#HAVE_LOG2 1#HAVE_LOG2 0#g' \
		-e 's#HAVE_LOG2F 1#HAVE_LOG2F 0#g' \
		${WRKSRC}/config.h

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
