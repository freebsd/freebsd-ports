# New ports collection makefile for:	mplayer
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#			with lots of help from Vladimir Kushnir
# $FreeBSD$
#

PORTNAME=	mplayer
PORTVERSION=	${MPLAYER_PORT_VERSION}
PORTREVISION=	13

COMMENT=	High performance media player supporting many formats

.include "${.CURDIR}/Makefile.shared"

OPTIONS=	DEBUG "Include debug symbols in mplayer's binary files" off
OPTIONS+=	RTCPU "Let mplayer dynamically check for CPU features" on
OPTIONS+=	OCFLAGS "Use optimized compiler flags" on
OPTIONS+=	SIMD "Allow mplayer to use vector engines (MMX...)" on
OPTIONS+=	IPV6 "Include inet6 network support" on
OPTIONS+=	X11 "Enable X11 support for mplayer's video output" on
OPTIONS+=	X11XV "X11 video drivers: XV" on
OPTIONS+=	X11DGA "X11 video drivers: DGA" on
OPTIONS+=	X11GL "X11 video drivers: OpenGL" on
OPTIONS+=	X11XIN "X11 video drivers: Xinerama" on
OPTIONS+=	X11VM "X11 VidMode support" on
OPTIONS+=	X11XVMC "Enable XvMC acceleration" off
OPTIONS+=	GUI "Enable GTK2 graphical user interface with X11" on
OPTIONS+=	SDL "Enable SDL video output" off
OPTIONS+=	VIDIX "Enable VIDIX video output on supported archs" on
OPTIONS+=	SKINS "Force dependency on mplayer-skins" on
OPTIONS+=	FREETYPE "Use freetype for OSD fonts (TrueType!)" on
OPTIONS+=	RTC "Add support for kernel real time clock timing" off
OPTIONS+=	ARTS "Enable KDE sound system support" off
OPTIONS+=	ESOUND "Enable GNOME esound support" off
OPTIONS+=	JACK "Enable JackIt audio server support" off
#OPTIONS+=	POLYP "Enable polyp sound server support" off
OPTIONS+=	NAS "Enable NAS sound server support" off
OPTIONS+=	OPENAL "Enable OpenAL sound support" off
OPTIONS+=	LIBUNGIF "Enable gif support" on
OPTIONS+=	AALIB "Enable aalib support" off
OPTIONS+=	LIBCACA "Enable libcaca support" off
OPTIONS+=	SVGALIB "Enable svgalib support" off
OPTIONS+=	LIBDV "Enable libdv support" off
OPTIONS+=	MAD "Enable mad MPEG audio engine support" off
OPTIONS+=	DTS "Enable DTS audio codec support" on
OPTIONS+=	LIBMPCDEC "Enable libmpcdec support" off
OPTIONS+=	LADSPA "Enable LADSPA plugin support" off
OPTIONS+=	SPEEX "Enable speex audio codec support" on
OPTIONS+=	TREMOR "Use built-in tremor instead of libvorbis" off
OPTIONS+=	XMMS "Enable XMMS plugin support" off
OPTIONS+=	THEORA "Enable ogg theora video support" off
.if !defined(PACKAGE_BUILDING)
OPTIONS+=	WIN32 "Enable win32 codec set on the IA32 arch" on
OPTIONS+=	AMR "Enable AMR audio codec support" off
.endif
OPTIONS+=	X264 "Enable x264 (H.264) video codec support" off
OPTIONS+=	XANIM "Enable xanim DLL support" off
OPTIONS+=	XVID "Enable XVID video codec support" on
OPTIONS+=	REALPLAYER "Enable real player plugin" off
OPTIONS+=	LIVEMEDIA "Enable LIVE555 streaming support" off
OPTIONS+=	SMB "Enable Samba input support" off
OPTIONS+=	FRIBIDI "Enable FriBiDi support" off
OPTIONS+=	LIRC "Enable lirc support" off
OPTIONS+=	LIBCDIO "Enable libcdio support" off
OPTIONS+=	CDPARANOIA "Enable cdparanoia support" off
OPTIONS+=	LIBLZO "Enable external liblzo library" off
OPTIONS+=	JOYSTICK "Enable joystick support" off

MAN1=		mplayer.1
MANCOMPRESSED=	no

SUB_FILES=	pkg-message

CONFFILES=	example.conf input.conf menu.conf dvb-menu.conf

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--disable-ssse3 \
			--disable-directfb \
			--disable-faac \
			--disable-twolame \
			--disable-mencoder

.include "${.CURDIR}/Makefile.options"

#Building of vidix dependent shared libs is only possible
#on i386 and amd64 at the moment.
.if !defined(WITHOUT_VIDIX)
.if !(${ARCH} == "i386" || ${ARCH} == "amd64")
CONFIGURE_ARGS+=--disable-vidix-internal
.endif
.else
CONFIGURE_ARGS+=--disable-vidix-internal
.endif

.if !defined(WITHOUT_GUI) && !defined(WITHOUT_X11)
PLIST_SUB+=	GMPLAYER=""
DESKTOP_ENTRIES=	"MPlayer" "High performance media player" "${DATADIR}/skins/Blue/icons/icon32x32.png" "gmplayer" "" false
.if !defined(WITHOUT_SKINS)
RUN_DEPENDS+=	${LOCALBASE}/share/mplayer/skins:${PORTSDIR}/multimedia/mplayer-skins
.endif

USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--enable-gui

.if defined(WITH_LANG)
WITH_LANG=	""
.endif

.else
PLIST_SUB+=	GMPLAYER="@comment "
.endif #WITHOUT_GUI

.if !defined(WITHOUT_FREETYPE)
CONFIGURE_ARGS+=	--with-extraincdir=${LOCALBASE}/include/freetype2 \
			--enable-freetype
LIB_DEPENDS+=		freetype.9:${PORTSDIR}/print/freetype2
.else
.if !defined(WITHOUT_X11)
RUN_DEPENDS+=	${LOCALBASE}/share/mplayer/fonts:${PORTSDIR}/multimedia/mplayer-fonts
.endif
CONFIGURE_ARGS+=	--disable-freetype
.endif

.if !defined(WITHOUT_X11)
USE_XORG=	x11
.if !defined(WITHOUT_X11XV)
USE_XORG+=	xv
.else
CONFIGURE_ARGS+=--disable-xv
.endif
.if !defined(WITHOUT_X11DGA)
USE_XORG+=	xxf86dga
.else
CONFIGURE_ARGS+=--disable-dga1 --disable-dga2
.endif
.if !defined(WITHOUT_X11GL)
USE_XORG+=	glproto
LIB_DEPENDS+=	GL.1:${PORTSDIR}/graphics/libGL
.else
CONFIGURE_ARGS+=--disable-gl
.endif
.if !defined(WITHOUT_X11XIN)
USE_XORG+=	xinerama xineramaproto
.else
CONFIGURE_ARGS+=--disable-xinerama
.endif
.if !defined(WITHOUT_X11VM)
USE_XORG+=	xxf86vm
.else
CONFIGURE_ARGS+=--disable-vm
.endif
.if defined(WITH_X11XVMC)
USE_XORG+=	xvmc
CONFIGURE_ARGS+=--enable-xvmc --with-xvmclib=XvMCW
.endif
.else				#WITHOUT_X11
CONFIGURE_ARGS+=--disable-x11 \
		--disable-fontconfig
.endif

.if defined(WITH_RTC)
BUILD_DEPENDS+=	${LOCALBASE}/modules/rtc.ko:${PORTSDIR}/emulators/rtc
RUN_DEPENDS+=	${LOCALBASE}/modules/rtc.ko:${PORTSDIR}/emulators/rtc
CONFIGURE_ARGS+=	--enable-rtc
CONFIGURE_ENV+=		CFLAGS+="-I/${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=	--disable-rtc
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--enable-arts
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if defined(WITH_LIBCACA)
LIB_DEPENDS+=caca.0:${PORTSDIR}/graphics/libcaca
.else
CONFIGURE_ARGS+=	--disable-caca
.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=	--enable-lirc
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif

.if defined(WITH_SDL)
USE_SDL=	sdl
WITH_AALIB=	yes
.undef(WITHOUT_AALIB)
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
.else
CONFIGURE_ARGS+=	--disable-svga
.endif

.if defined(WITH_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
.else
CONFIGURE_ARGS+=	--disable-aa
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if defined(WITH_KERN_HZ)
DEFAULT_KERN_HZ=${WITH_KERN_HZ}
.else
DEFAULT_KERN_HZ=1024
.endif

.if defined(WITH_JOYSTICK)
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
CONFIGURE_ARGS+=--enable-joystick
.else
CONFIGURE_ARGS+=--disable-joystick
.endif

pre-everything::
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "There are some knobs which *can* *not* be selected via the"
	@${ECHO_MSG} "OPTIONS framework. You might want to check the Makefile in"
	@${ECHO_MSG} "order to learn more about them."

.if !defined(WITHOUT_GUI) && !defined(WITHOUT_X11)
	@${ECHO_MSG} "If you want to use the GUI, you can either install"
	@${ECHO_MSG} "${PORTSDIR}/multimedia/mplayer-skins"
	@${ECHO_MSG} "or download official skin collections from"
	@${ECHO_MSG} "http://www.mplayerhq.hu/homepage/dload.html"
.endif

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
.if defined(WITH_RTC)
	@${REINPLACE_CMD} -e \
		's|irqp = 1024|irqp = ${DEFAULT_KERN_HZ}|' \
		${WRKSRC}/mplayer.c
.endif

post-configure:
	@${REINPLACE_CMD} -e 's#-pthread#${PTHREAD_LIBS}#g' \
		${WRKSRC}/config.mak

post-install:
	@${MKDIR} ${DATADIR}
	@${CHMOD} 755 ${DATADIR}
	@${MKDIR} ${DATADIR}/examples/etc
	@${CHMOD} 755 ${DATADIR}/examples/etc
.for conf in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${conf} ${DATADIR}/examples/etc
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CHMOD} 755 ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/DOCS/HTML/en/* ${DOCSDIR}
.endif
.if !defined(WITHOUT_GUI) && !defined(WITHOUT_X11)
	@${LN} -sf ${PREFIX}/bin/mplayer ${PREFIX}/bin/gmplayer
.endif
	@${CAT} ${PKGMESSAGE}

install-user:
	@${PERL} ${FILESDIR}/install-user

.include <bsd.port.post.mk>
