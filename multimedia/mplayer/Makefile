# New ports collection makefile for:	mplayer
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#			with lots of help from Vladimir Kushnir
# $FreeBSD$
#
#
# Some of the knobs are not tunable by the OPTIONS framework. These are
# explained here in detail.
#
# Core funcionality:
#
# MPLAYER_GENERIC_BUILD
# default: undefined
# By default, the mplayer port creates a custom build based on personal
# preferences.
# If you want to build a generic package with certain fixed options,
# suitable for any CPU within ${ARCH}, define this knob.
# Note: Other knobs and especially OPTIONS
#
# CPU features:
#
# The following is only of interest if you haven't enabled
# RTCPU in your OPTIONS selection.
# The correct instruction set of your processor is normally
# auto-detected, so there is probably no necessity to change them.
# Note that disabling SIMD via the OPTIONS framework completely
# disables utilization of vector engines, i.e. it implies
# WITHOUT_MMX, WITHOUT_3DNOW and WITHOUT_SSE
#
# WITHOUT_MMX
# default: autodetected
# disables using of mmx code
#
# WITHOUT_3DNOW
# default: autodetected
# disables using of 3dNow! instructions on AMD CPUs
#
# WITHOUT_SSE
# default: autodetected
# disables all mmx2 and sse/sse2 code
# CAUTION: There are some Athlon CPUs which claim to be sse-able but
# aren't. If you encounter strange problems on such a CPU, try
# to build mplayer with this knob and report the problem
# NOTE: SSE is available only if "options CPU_ENABLE_SSE" in your
# kernel config. This is standard for 5.x and newer systems on I686_CPU
# and later. 4.x users will have to define this explicitly.
#
# WITH_KERN_HZ=<frequency>
# default: 1024
# This option allows you to control the default kern.hz when using RTC support.
# If you have a older/slower processor you may want to lower the default level.
# ie. 512 seems to produce better quality video on a PII 400MHz than 1024 does
# CAUTION: lower than 512 may produce jerky video.
#
# Feature options:
# These options influence some general behaviour of mplayer. Most of the featues,
# for example all the codecs, are selected via the OPTIONS framework.
#
# WITH_DVD_DEVICE=/path/to/desired/device
# default 5.x: /dev/acd0
# default 4.x: /dev/acd0c
# This option changes the default device where mplayer looks for
# a DVD medium
#
# WITH_CDROM_DEVICE=/path/to/desired/device
# default 5.x: /dev/acd0
# default 4.x: /dev/acd0c
# This option changes the default cdrom device, maybe useful for VCDs
#
# WITH_LANG=<your choice>
# default: en
# Enables language support bg, cz, de, dk, en, es, fr, gr, hu, it, ko, nl, no, pl, pt_BR, ro, ru, sk, tr, uk, zh
#
# Additional knobs:
#
# NOPORTDOCS
# default: undefined
# This knob prevents the ports system from installing additional
# documentation. If you define this, only the manpage is going
# to be installed.
#

PORTNAME=	mplayer
PORTVERSION=	0.99.10
PORTREVISION=	6
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www1.mplayerhq.hu/MPlayer/releases/ \
		http://www2.mplayerhq.hu/MPlayer/releases/ \
		http://ftp.lug.udel.edu/MPlayer/releases/ \
		http://www4.mplayerhq.hu/MPlayer/releases/ \
		http://mirrors.xmission.com/MPlayer/releases/ \
		ftp://ftp1.mplayerhq.hu/MPlayer/releases/ \
		ftp://ftp2.mplayerhq.hu/MPlayer/releases/ \
		ftp://ftp.lug.udel.edu/MPlayer/releases/ \
		ftp://mirrors.xmission.com/MPlayer/releases/ \
		http://www.rrr.de/~riggs/mplayer/
DISTNAME=	MPlayer-1.0rc1

MAINTAINER=	riggs@rrr.de
COMMENT=	High performance media player/encoder supporting many formats

PATCH_SITES=	http://www.mplayerhq.hu/MPlayer/patches/
PATCHFILES+=	asmrules_fix_20061231.diff

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS} \
		TMPDIR="${WRKSRC}"
CONFIGURE_ARGS=	--with-extralibdir=${LOCALBASE}/lib \
		--with-extraincdir=${LOCALBASE}/include \
		--cc=${CC} \
		--as=${AS} \
		--enable-png \
		--enable-menu \
		--disable-libfame \
		--disable-faad-external \
		--disable-vidix-external \
		--disable-tv-v4l1 \
		--disable-tv-v4l2

OPTIONS=	DEBUG "Include debug symbols in mplayer's binary files" off

#Collect OPTIONS menu
.if !defined(MPLAYER_GENERIC_BUILD)
OPTIONS+=	RTCPU "Let mplayer dynamically check for CPU features" on
OPTIONS+=	OCFLAGS "Use optimized compiler flags" on
OPTIONS+=	SIMD "Allow mplayer to use vector engines (MMX...)" on
OPTIONS+=	MENCODER "Support encoding of multimedia files" on
OPTIONS+=	IPV6 "Include inet6 network support" on
OPTIONS+=	X11 "Enable X11 support for mplayer's video output" on
OPTIONS+=	GUI "Enable GTK2 graphical user interface with X11" on
OPTIONS+=	SDL "Enable SDL video output" off
OPTIONS+=	VIDIX "Enable VIDIX video output on supported archs" on
OPTIONS+=	NVIDIA "Enable experimental nvidia xvmc driver" off
OPTIONS+=	SKINS "Force dependency on mplayer-skins" on
OPTIONS+=	FREETYPE "Use freetype for OSD fonts (TrueType!)" on
OPTIONS+=	RTC "Add support for kernel real time clock timing" off
OPTIONS+=	ARTS "Enable KDE sound system support" off
OPTIONS+=	ESOUND "Enable GNOME esound support" off
OPTIONS+=	JACK "Enable JackIt audio server support" off
OPTIONS+=	POLYP "Enable polyp sound server support" off
OPTIONS+=	NAS "Enable NAS sound server support" off
OPTIONS+=	OPENAL "Enable OpenAL sound support" off
OPTIONS+=	LIBUNGIF "Enable gif support" on
OPTIONS+=	AALIB "Enable aalib support" off
OPTIONS+=	LIBCACA "Enable libcaca support" off
OPTIONS+=	SVGALIB "Enable svgalib support" off
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
OPTIONS+=	THEORA "Enable ogg theora video support" off
OPTIONS+=	WIN32 "Enable win32 codec set on the IA32 arch" on
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
.endif

WANT_GNOME=	yes
WANT_SDL=	yes
MAN1=		mplayer.1
MANCOMPRESSED=	no

SUB_FILES=	pkg-message

CONFFILES=	example.conf input.conf menu.conf dvb-menu.conf
TOOLFILES=	calcbpp.pl countquant.pl dvd2divxscript.pl \
		menc2pass mencvcd mp.pl subedit.pl subsearch.sh \
		sws-test w32codec_dl.pl wma2ogg.pl x2mpsub.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4+
CFLAGS+=	-Duint_fast64_t=uint64_t
CFLAGS+=	-Droundf=rintf
CFLAGS+=	-Dllrint=rint
.if ${ARCH} == "i386"
CFLAGS+=	-DPRId64=\\\"lld\\\"
CFLAGS+=	-DPRIu64=\\\"llu\\\"
CFLAGS+=	-DPRIx64=\\\"llx\\\"
CFLAGS+=	-DPRIX64=\\\"llX\\\"
.else
CFLAGS+=	-DPRId64=\\\"ld\\\"
CFLAGS+=	-DPRIu64=\\\"lu\\\"
CFLAGS+=	-DPRIx64=\\\"lx\\\"
CFLAGS+=	-DPRIX64=\\\"lX\\\"
.endif
.endif

#Building of vidix dependent shared libs is only possible
#on i386 and amd64 at the moment.
.if !defined(WITHOUT_VIDIX)
.if ${ARCH} == "i386" || ${ARCH} == "amd64"
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/mplayer/vidix
PLIST_SUB+=	VIDIX=""
.else
CONFIGURE_ARGS+=--disable-vidix-internal
PLIST_SUB+=	VIDIX="@comment "
.endif
.else
CONFIGURE_ARGS+=--disable-vidix-internal
PLIST_SUB+=	VIDIX="@comment "
.endif

# Esablish de-facto dependencies for either building generic mplayer
# binary-suitable package or custom build

.if defined(MPLAYER_GENERIC_BUILD)
#Compiler flags
CFLAGS=		#let mplayer decide the flags

#Defaults for generic build
INCL_MODULES=	RTCPU IPV6 X11 GUI SDL SKINS FREETYPE AALIB TREMOR \
		WIN32 XVID
EXCL_MODULES=	OCFLAGS MENCODER VIDIX NVIDIA RTC ARTS ESOUND \
		JACK POLYP NAS OPENAL LIBUNGIF LIBCACA SVGALIB \
		LIBDV MAD TWOLAME DTS LIBMPCDEC FAAC LADSPA SPEEX \
		XMMS THEORA X264 XANIM REALPLAYER LIVEMEDIA SMB \
		FRIBIDI LIRC LIBCDIO CDPARANOIA LIBLZO

.for module in ${EXCL_MODULES}
WITHOUT_${module}=yes
.undef(WITH_${module})
.endfor

.for module in ${INCL_MODULES}
WITH_${module}=yes
.undef(WITHOUT_${module})
.endfor

.undef(WITH_DVD_DEVICE)
.undef(WITH_CDROM_DEVICE)
.undef(WITH_LANG)

#Kernel granularity
DEFAULT_KERN_HZ=1024
CFLAGS+=	-fno-force-addr
.endif 	#MPLAYER_GENERIC_BUILD

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.else
WITHOUT_GUI=	yes
CONFIGURE_ARGS+=--disable-x11 \
		--disable-fontconfig
.endif

.if defined(WITH_LANG)
CONFIGURE_ARGS+=--language=${WITH_LANG}
.endif

.if !defined(WITHOUT_OCFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-inet6
.else
CATEGORIES+=	ipv6
.endif

.if !defined(WITHOUT_GUI)
PLIST_SUB+=	GMPLAYER=""
DESKTOP_ENTRIES=	"MPlayer" "High performance media player" "" "gmplayer" "" false
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

.if defined(WITH_RTC)
BUILD_DEPENDS+=	${LOCALBASE}/modules/rtc.ko:${PORTSDIR}/emulators/rtc
RUN_DEPENDS+=	${LOCALBASE}/modules/rtc.ko:${PORTSDIR}/emulators/rtc
CONFIGURE_ARGS+=	--enable-rtc
CONFIGURE_ENV+=		CFLAGS+="-I/${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=	--disable-rtc
.endif

.if !defined(WITHOUT_MENCODER)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
MLINKS+=	mplayer.1 mencoder.1
PLIST_SUB+=	MENCODER=""
.else
CONFIGURE_ARGS+=	--disable-mencoder
PLIST_SUB+=	MENCODER="@comment "
.endif

.if defined(WITH_NVIDIA) && ${OSVERSION} < 600033
LIB_DEPENDS+=	XvMCNVIDIA.1:${PORTSDIR}/x11/nvidia-driver
CONFIGURE_ARGS+=	--enable-xvmc \
			--enable-xvmclib=XvMCNVIDIA
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--enable-arts
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if defined(WITH_FRIBIDI)
LIB_DEPENDS+=	fribidi.0:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=	--enable-fribidi
.else
CONFIGURE_ARGS+=	--disable-fribidi
.endif

.if defined(WITH_LIBCDIO) && !defined(WITH_CDPARANOIA)
BUILD_DEPENDS+=	${LOCALBASE}/include/cdio/cdio.h:${PORTSDIR}/sysutils/libcdio
.else
CONFIGURE_ARGS+=	--disable-libcdio
.endif

.if defined(WITH_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
.else
CONFIGURE_ARGS+=	--disable-cdparanoia
.endif

.if defined(WITH_LIBCACA)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcaca.a:${PORTSDIR}/graphics/libcaca
.else
CONFIGURE_ARGS+=	--disable-caca
.endif

.if !defined(WITHOUT_LIBUNGIF)
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
#CONFIGURE_ARGS+=	--enable-gif
.else
CONFIGURE_ARGS+=	--disable-gif
.endif

.if defined(WITH_LIBDV)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=	--enable-libdv
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=	--enable-lirc
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif

.if defined(WITH_TWOLAME)
LIB_DEPENDS+=	twolame.0:${PORTSDIR}/audio/twolame
.else
CONFIGURE_ARGS+=	--disable-twolame
.endif

.if defined(WITH_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad

CONFIGURE_ARGS+=	--enable-mad \
			--with-madlibdir=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-mad
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

.if defined(WITH_THEORA)
LIB_DEPENDS+=	theora.2:${PORTSDIR}/multimedia/libtheora
.else
CONFIGURE_ARGS+=	--disable-theora
.endif

.if defined(WITH_X264)
LIB_DEPENDS+=	x264.50:${PORTSDIR}/multimedia/x264
.else
CONFIGURE_ARGS+=	--disable-x264
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if defined(WITH_POLYP)
CONFIGURE_ARGS+=	--enable-polyp
LIB_DEPENDS+=		polyp-0.7.0:${PORTSDIR}/audio/polypaudio
.else
CONFIGURE_ARGS+=	--disable-polyp
.endif

.if defined(WITH_NAS)
CONFIGURE_ARGS+=	--enable-nas
LIB_DEPENDS+=		audio.2:${PORTSDIR}/audio/nas
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

.if defined(WITH_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
.else
CONFIGURE_ARGS+=	--disable-openal
.endif

.if !defined(WITH_TREMOR)
CONFIGURE_ARGS+=	--disable-tremor-internal
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_REALPLAYER)
CONFIGURE_ARGS+=	--enable-real \
			--with-reallibdir=${X11BASE}/lib/RealPlayer/codecs
RUN_DEPENDS+=		realplay:${PORTSDIR}/multimedia/linux-realplayer
BUILD_DEPENDS+=		realplay:${PORTSDIR}/multimedia/linux-realplayer
.else
.if !defined(WITHOUT_WIN32)
CONFIGURE_ARGS+=	--enable-real \
			--with-reallibdir=${LOCALBASE}/lib/win32
.else
CONFIGURE_ARGS+=	--disable-real
.endif
.endif

.if defined(WITH_LIVEMEDIA)
CONFIGURE_ARGS+=	--enable-live \
			--with-livelibdir=${LOCALBASE}/live
RUN_DEPENDS+=		${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
BUILD_DEPENDS+=		${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
.else
CONFIGURE_ARGS+=	--disable-live
.endif

.if defined(WITH_SMB)
CONFIGURE_ARGS+=	--enable-smb
LIB_DEPENDS+=		smbclient.0:${PORTSDIR}/net/samba-libsmbclient
.else
CONFIGURE_ARGS+=	--disable-smb
.endif

.if !defined(WITHOUT_XVID)
CONFIGURE_ARGS+=	--enable-xvid
LIB_DEPENDS+=		xvidcore.4:${PORTSDIR}/multimedia/xvid
.else
CONFIGURE_ARGS+=	--disable-xvid
.endif

.if defined(WITH_XMMS)
CONFIGURE_ARGS+=	--enable-xmms
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
.else
CONFIGURE_ARGS+=	--disable-xmms
.endif

.if !defined(WITHOUT_DTS)
CFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-libdts
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdts.a:${PORTSDIR}/multimedia/libdts
.else
CONFIGURE_ARGS+=	--disable-libdts
.endif

.if defined(WITH_LIBMPCDEC)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec
.else
CONFIGURE_ARGS+=	--disable-musepack
.endif

.if defined(WITH_FAAC)
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
.else
CONFIGURE_ARGS+=	--disable-faac
.endif

.if defined(WITH_LADSPA)
RUN_DEPENDS+=	${LOCALBASE}/lib/ladspa/amp.so:${PORTSDIR}/audio/ladspa
.else
CONFIGURE_ARGS+=	--disable-ladspa
.endif

.if !defined(WITHOUT_SPEEX)
CONFIGURE_ARGS+=	--enable-speex
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=	--disable-speex
.endif

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

.if defined(WITH_XANIM)
BUILD_DEPENDS+=	xanim:${PORTSDIR}/multimedia/xanim
CONFIGURE_ARGS+=--enable-xanim --with-xanimlibdir=${X11BASE}/lib/X11/xanim
.else
CONFIGURE_ARGS+=--disable-xanim
.endif

.if defined(WITH_LIBLZO)
LIB_DEPENDS+=		lzo.1:${PORTSDIR}/archivers/lzo
.else
CONFIGURE_ARGS+=	--disable-liblzo
.endif

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
.if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif
.endif

.if defined(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
.if ${OSVERSION} < 500000
DEFAULT_CDROM_DEVICE=/dev/acd0c
.else
DEFAULT_CDROM_DEVICE=/dev/acd0
.endif
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

# "enable" build for other archs
.if ${ARCH} == "i386" || ${ARCH} == "amd64"
.if !defined(WITHOUT_RTCPU)
CONFIGURE_ARGS+=--enable-runtime-cpudetection
.else #WITH_RTCPU
.if defined(WITHOUT_MMX) || defined(WITHOUT_SIMD)
CONFIGURE_ARGS+=--disable-mmx
.endif
.if defined(WITHOUT_3DNOW) || defined(WITHOUT_SIMD) || ${OSVERSION} < 400021
CONFIGURE_ARGS+=--disable-3dnow --disable-3dnowext
.endif
.if defined(WITHOUT_SSE) || defined(WITHOUT_SIMD)
CONFIGURE_ARGS+=--disable-mmxext --disable-sse --disable-sse2
.endif
.endif #WITH_RTCPU
.if !defined(WITHOUT_WIN32)
RUN_DEPENDS+=	${CODEC_DETECTION_FILE}:${CODEC_PORT}
CONFIGURE_ARGS+=	--with-win32libdir=${LOCALBASE}/lib/win32
CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
.else
CONFIGURE_ARGS+=	--disable-win32 \
			--disable-qtx-codecs
.endif
.endif # ARCH == i386/amd64

pre-everything::
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "There are some knobs which *can* *not* be selected via the"
	@${ECHO_MSG} "OPTIONS framework. You might want to check the Makefile in"
	@${ECHO_MSG} "order to learn more about them."

.if !defined(WITHOUT_GUI)
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
			-e 's|/usr/X11R6|${X11BASE}|'
	@${FIND} ${WRKSRC}/DOCS/man -name "mplayer.1" | ${XARGS} ${REINPLACE_CMD} -E -e \
		's|/usr/\\:local/\\:etc/\\:mplayer|${DATADIR:S/\//\/\\\:/g}|g ; \
		 s|/dev/\\:(dvd[[:alnum:]]*[[:>:]])|${DEFAULT_DVD_DEVICE:S/dev\//dev\/\\\:/}|g ; \
		 s|/dev/\\:(cdrom[[:alnum:]]*[[:>:]])|${DEFAULT_CDROM_DEVICE:S/dev\//dev\/\\\:/}|g'
.if defined(WITH_RTC)
	@${REINPLACE_CMD} -e \
		's|irqp = 1024|irqp = ${DEFAULT_KERN_HZ}|' \
		${WRKSRC}/mplayer.c
.endif
.if defined(MPLAYER_GENERIC_BUILD) && defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e \
		's|1.0pre8|1.0pre8-FreeBSD-generic-debug|' \
		${WRKSRC}/version.sh
.elif defined(MPLAYER_GENERIC_BUILD)
	@${REINPLACE_CMD} -e \
		's|1.0pre8|1.0pre8-FreeBSD-generic|' \
		${WRKSRC}/version.sh
.endif

post-configure:
	@${REINPLACE_CMD} -e 's#-pthread#${PTHREAD_LIBS}#g' \
		${WRKSRC}/config.mak

post-install:
	@${MKDIR} ${DATADIR}
	@${CHMOD} 755 ${DATADIR}
	@${MKDIR} ${DATADIR}/tools
	@${CHMOD} 755 ${DATADIR}/tools
	@${MKDIR} ${DATADIR}/examples/etc
	@${CHMOD} 755 ${DATADIR}/examples/etc
.for conf in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${conf} ${DATADIR}/examples/etc
.endfor
.for tool in ${TOOLFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/TOOLS/${tool} ${DATADIR}/tools
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CHMOD} 755 ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/DOCS/HTML/en/* ${DOCSDIR}
.endif
.if !defined(WITHOUT_GUI)
	@${LN} -sf ${PREFIX}/bin/mplayer ${PREFIX}/bin/gmplayer
.endif
	@${CAT} ${PKGMESSAGE}

install-user:
	@${PERL} ${FILESDIR}/install-user

.include <bsd.port.post.mk>
