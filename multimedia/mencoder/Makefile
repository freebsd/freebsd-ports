# New ports collection makefile for:	mencoder
# Date created:		23 June 2007
# Whom:			Thomas E. Zander
# $FreeBSD$
#

PORTNAME=	mencoder
PORTVERSION=	${MPLAYER_PORT_VERSION}
PORTREVISION=	4
COMMENT=	Convenient video file and movie encoder
NO_PACKAGE=	Port has restricted dependencies

.include "${.CURDIR}/../mplayer/Makefile.shared"

OPTIONS=	DEBUG "Include debug symbols in mencoder's binary files" off
OPTIONS+=	RTCPU "Let mplayer dynamically check for CPU features" on
OPTIONS+=	OCFLAGS "Use optimized compiler flags" on
OPTIONS+=	SIMD "Allow mplayer to use vector engines (MMX...)" on
OPTIONS+=	IPV6 "Include inet6 network support" on
OPTIONS+=	JACK "Enable JackIt audio server support" off
#OPTIONS+=	POLYP "Enable polyp sound server support" off
OPTIONS+=	NAS "Enable NAS sound server support" off
OPTIONS+=	OPENAL "Enable OpenAL sound support" off
OPTIONS+=	LIBUNGIF "Enable gif support" on
OPTIONS+=	LIBDV "Enable libdv support" off
OPTIONS+=	MAD "Enable mad MPEG audio engine support" off
OPTIONS+=	TWOLAME "Enable twolame MPEG audio codec support" off
OPTIONS+=	DTS "Enable DTS audio codec support" on
OPTIONS+=	LIBMPCDEC "Enable libmpcdec support" off
OPTIONS+=	FAAC "Enable FAAC audio codec support" off
OPTIONS+=	LADSPA "Enable LADSPA plugin support" off
OPTIONS+=	SPEEX "Enable speex audio codec support" off
OPTIONS+=	TREMOR "Use built-in tremor instead of libvorbis" off
OPTIONS+=	XMMS "Enable XMMS plugin support" off
OPTIONS+=	WIN32 "Enable win32 codec set on the IA32 arch" on
OPTIONS+=	THEORA "Enable ogg theora video support" off
.if !defined(PACKAGE_BUILDING)
OPTIONS+=	AMR "Enable AMR audio codec support" off
.endif
OPTIONS+=	X264 "Enable x264 (H.264) video codec support" off
OPTIONS+=	XANIM "Enable xanim DLL support" off
OPTIONS+=	XVID "Enable XVID video codec support" on
OPTIONS+=	REALPLAYER "Enable real player plugin" off
OPTIONS+=	LIVEMEDIA "Enable LIVE555 streaming support" off
OPTIONS+=	SMB "Enable Samba input support" off
OPTIONS+=	FRIBIDI "Enable FriBiDi support" off
OPTIONS+=	LIBCDIO "Enable libcdio support" off
OPTIONS+=	CDPARANOIA "Enable cdparanoia support" off
OPTIONS+=	LIBLZO "Enable external liblzo library" off

MLINKS=		mplayer.1 mencoder.1

PATCHDIR=	${.CURDIR}/../mplayer/files
DATADIR=	${PREFIX}/share/mplayer

TOOLFILES=	calcbpp.pl checktree.sh countquant.pl \
		dvd2divxscript.pl mencvcd \
		mplmult.sh plotpsnr.pl psnr-video.sh \
		qepdvcd.sh subedit.pl subsearch.sh \
		w32codec_dl.pl wma2ogg.pl

.include <bsd.port.pre.mk>

LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
BUILD_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer

CONFIGURE_ARGS+=	--disable-vidix-internal \
			--disable-freetype \
			--disable-x11 \
			--disable-fontconfig \
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
			--disable-ssse3

.include "${.CURDIR}/../mplayer/Makefile.options"

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

pre-everything::
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "There are some knobs which *can* *not* be selected via the"
	@${ECHO_MSG} "OPTIONS framework. As this one is a slave port of multimedia/"
	@${ECHO_MSG} "mplayer, you might want to check mplayer's Makefile(s) in"
	@${ECHO_MSG} "order to learn more about them."

post-patch:
	@${REINPLACE_CMD} -e \
		's|libxmms.so.1|libxmms.so|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|; \
		s|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's!/usr/local!${PREFIX}!' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
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

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mencoder ${PREFIX}/bin

post-install:
	@${MKDIR} ${DATADIR}
	@${CHMOD} 755 ${DATADIR}
	@${MKDIR} ${DATADIR}/tools
	@${CHMOD} 755 ${DATADIR}/tools
.for tool in ${TOOLFILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/TOOLS/${tool} ${DATADIR}/tools
.endfor

.include <bsd.port.post.mk>
