# New ports collection makefile for:	mplayer
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#			with lots of help from Vladimir Kushnir
# $FreeBSD$
#
# There are many knobs to tune mplayer towards your specific wishes
# and preferences.
# You can activate a knob by typing something like
# "make -DKNOB" or "make KNOB=yes" instead of just "make"
#
# A description of the several possibilities is available here:
#
# Core funcionality:
#
# WITH_OPTIMIZED_CFLAGS
# default: undefined
# define if you want to enable -O3 -ffast-math -fomit-frame-pointer
# on gcc build commands. This will improve speed on most machines.
#
# WITHOUT_RUNTIME_CPUDETECTION
# default: undefined
# by default, mplayer is built with support for changing the used cpu
# instruction set while playing. This is necessary for package building.
# If you want to compile a specific version of mplayer working faster
# but only on your cpu type, then define this knob.
# If you define this, there are several additional knobs to explicitly
# disable some possible CPU features. See below.
#
# WITHOUT_MENCODER
# default: undefined
# the default is to build mplayer with mencoder. If you're sure that you
# don't want to encode or recode any media file, then define this.
#
# WITH_GUI
# default: defined if gtk12 libs are installed on the system
# defining this knob will force the ports system to install gtk12 first
# (if not available) and then link mplayer against it. Then you'll
# be able to use gmplayer, the graphical version of mplayer
# Note: Defining both WITH_GUI and WITHOUT_GUI will build mplayer without
#       grapical inteface.

# WITHOUT_GUI
# default: undefined
# normally mplayer comes with gmplayer if gtk is installed on the system.
# If you want to force mplayer to disable the graphical user interface and
# build without gui ability, define this.
#
#
# WITHOUT_FREETYPE
# default: undefined
# since freetype is installed on almost any system people might want
# to run mplayer on, this port now defaults to freetype unless not
# defined otherwise
#
#
# CPU features:
#
# The following is only of interest if you have enabled
# WITHOUT_RUNTIME_CPUDETECTION
# Further, the correct instruction set of your processor is normally
# auto-detected, so there is probably no necissity to change them.
#
# WITHOUT_MMX
# default: autodetected
# disables using of mmx code
#
# WITHOUT_3DNOW
# default: autodetected
# disables using of 3dNow! instructions on AMD CPUs
#
# WITHOUT_DSP
# default: autodetected
# disables using of AMD Athlon DSP extentions
#
# WITHOUT_SSE
# default: autodetected
# disables all mmx2 and sse/sse2 code
# CAUTION: There are some Athlon CPUs which claim to be sse-able but
# they aren't. If you have strange problems on this subject, try
# to build mplayer with this knob and report the problem
# NOTE: SSE is available only if "options CPU_ENABLE_SSE" in your
# kernel config. This is standard for 5.x systems on I686_CPU and above.
# 4.x users will have to define this explicitly.
#
# WITH_RTC
# default: undefined
# This option enables support for real time clock timing instead of
# defaulting to usleep() timing. This can improve cpu load as well
# as run-time accuracy.
#
# Feature options:
# These options influence, which libraries mplayer is linked to.
# Note: The libraries are needed to play the particular files under
# particular circumstances.
# ("autodetect" in this sections means: If the ports system finds
# the libary on your system, it is used, otherwise not.
# If you define it, it will be built and installed as dependency.)
#
# WITH_DVD
# default: autodetect
#
# WITH_DVD_DEVICE
# default 5.x: /dev/acd0
# default 4.x: /dev/acd0c
# change the default dvd device
#
# WITH_CDROM_DEVICE
# default 5.x: /dev/acd0
# default 4.x: /dev/acd0c
# change the default cdrom device
# useful for VCD's
#
# WITH_LIBDVDREAD
# default: disabled
# define this if you prefer the use of libdvdread instead of the
# mplayer-internal dvd reading routine (which is derived from
# libdvdread). This only affect mplayer if WITH_DVD is used.
#
# WITH_LIBDVDNAV
# Completely disabled at the moment because of incompatibility issues
# with the new libdvdnav. This will probably be fixed in mplayer-1.0.
#
# WITH_LIBUNGIF
# default: autodetect
#
# WITH_ARTS
# default: autodetect
# Note: arts audio output cannot work together with mplayer's gtk1-gui
# 	because of conflicting glib versions, so it it is disabled if
# 	mplayer is built with graphical user interface
#
# WITH_CDPARANOIA
# default: autodetect
#
# WITH_LIBDV
# default: autodetect
#
# WITH_MAD
# default: autodetect
#
# WITH_SVGALIB
# default: autodetect
#
# WITH_AALIB
# default: autodetect
#
# WITH_SDL
# default: autodetect
# (implies WITH_AALIB)
#
# WITH_ESOUND
# default: autodetect
#
# WITH_VORBIS
# default: autodetect
#
# WITH_XANIM
# default: autodetect
#
# WITH_REALPLAYER
# default: autodetect
#
# WITH_LIVEMEDIA
# default: autotedect
#
# WITH_XVID
# default: autodetect
#
# WITH_FAAD
# default: autodetect
#
# WITH_LZO
# default: autodetect
#
# WITH_XMMS
# default: autodetect
#
# WITH_LANG
# default: en
# Enables language support bg, cz, de, dk, en, es, fr, gr, hu, it, ko, nl, no, pl, pt_BR, ro, ru, sk, tr, uk, zh
#
# WITHOUT_WIN32_CODECS
# default: undefined
# By default, mplayer depends on and uses the win32-codecs collection.
# Of course, thanks to Microsoft's very cool hyper-super-multi-platform
# support, this is only available on x86 architecture.
# If you're working on x86 and want to disable using of the windows codecs,
# define this knob.
#
#
# Additional knobs:
#
# NOPORTDOCS
# default: undefined
# This knob prevents the ports system from installing additional
# documentation. If you define this, only the manpage is going
# to be installed.

PORTNAME=	mplayer
PORTVERSION=	0.92.1
PORTREVISION=	1
CATEGORIES=	multimedia audio ipv6
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
DISTNAME=	MPlayer-0.92.1

PATCH_SITES=	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/kame/misc/&,}
PATCHFILES=	mplayer-0.9.2-v6-20030930.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	riggs@rrr.de
COMMENT=	High performance media player/encoder supporting many formats

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS} \
		TMPDIR="${WRKSRC}"
CONFIGURE_ARGS=	--with-extralibdir=${LOCALBASE}/lib \
		--with-extraincdir=${LOCALBASE}/include \
		--with-x11libdir=${X11BASE}/lib \
		--with-x11incdir=${X11BASE}/include \
		--enable-png \
		--disable-libfame \
		--disable-tv-v4l \
		--disable-dvdnav

.if defined(WITH_LANG)
CONFIGURE_ARGS+=--language=${WITH_LANG}
.endif

WANT_GNOME=	yes
WANT_SDL=	yes
USE_REINPLACE=	yes
MAN1=		mplayer.1
MANCOMPRESSED=	no

CONFFILES=	codecs.conf example.conf input.conf menu.conf
DOCFILES=	bugreports.html cd-dvd.html codecs-in.html \
		codecs.html documentation.html faq.html skin.html \
		encoding.html formats.html sound.html \
		users_against_developers.html \
		video.html
TOOLFILES=	calcbpp.pl countquant.pl \
		dvd2divxscript.pl menc2pass \
		mencvcd mp.pl sws-test w32codec_dl.pl \
		x2mpsub.sh

.include <bsd.port.pre.mk>

#Building of vidix dependent shared libs is only possible
#on i386 at the moment.
.if ${ARCH} == "i386"
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/mplayer/vidix
PLIST_SUB+=	VIDIX=""
.else
CONFIGURE_ARGS+=--disable-vidix
PLIST_SUB+=	VIDIX="@comment "
.endif

#.if exists(${LOCALBASE}/modules/rtc.ko)
#WITH_RTC=	yes
#.endif

.if exists(${LOCALBASE}/lib/libartsc.so.0)
WITH_ARTS=	yes
.endif

.if exists(${LOCALBASE}/lib/libcdda_paranoia.so)
WITH_CDPARANOIA=	yes
.endif

.if exists(${LOCALBASE}/lib/libdv.a)
WITH_LIBDV=	yes
.endif

.if exists(${LOCALBASE}/lib/libdvdcss.so.2)
WITH_DVD=	yes
.endif

#.if exists(${LOCALBASE}/lib/libdvdnav.so.3)
#WITH_LIBDVDNAV=	yes
#.endif

.if exists(${LOCALBASE}/lib/libungif.so.5)
WITH_LIBUNGIF=	yes
.endif

.if exists(${LOCALBASE}/lib/libmad.so.2)
WITH_MAD=	yes
.endif

.if exists(${LOCALBASE}/lib/libvga.so.1)
WITH_SVGALIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libaa.so.1)
WITH_AALIB=	yes
.endif

.if ${HAVE_SDL:Msdl}!=""
WITH_SDL=	yes
WITH_AALIB=	yes
.endif

.if ${HAVE_GNOME:Mesound}!=""
WITH_ESOUND=	yes
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so.3)
WITH_VORBIS=	yes
.endif

.if exists(${LOCALBASE}/lib/libjpeg.so.9)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
.endif

.if exists(${X11BASE}/bin/xanim)
WITH_XANIM=	yes
.endif

.if exists(${LOCALBASE}/lib/RealPlayer8/realplay)
WITH_REALPLAYER=	yes
.endif

.if exists(${LOCALBASE}/live/liveMedia/libliveMedia.a)
WITH_LIVEMEDIA=	yes
.endif

.if exists(${LOCALBASE}/lib/libxvidcore.so)
WITH_XVID=	yes
.endif

.if exists(${LOCALBASE}/lib/libfaad.so)
WITH_FAAD=	yes
.endif

.if exists(${X11BASE}/lib/libxmms.so)
WITH_XMMS=	yes
.endif

.if exists(${LOCALBASE}/lib/liblzo.so)
WITH_LZO=	yes
.endif

.if exists(${LOCALBASE}/lib/libfreetype.so.9) && !defined(WITHOUT_FREETYPE)
WITH_FREETYPE=	yes
.endif

.if defined (DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

.if ${HAVE_GNOME:Mgtk12}!=""
WITH_GUI=	yes
.endif

.if defined(WITH_GUI) && !defined(WITHOUT_GUI)
PLIST_SUB+=	GMPLAYER=""
.else
PLIST_SUB+=	GMPLAYER="@comment "
.endif

.if defined(WITH_RTC)
BUILD_DEPENDS+=	${LOCALBASE}/modules/rtc.ko:${PORTSDIR}/emulators/rtc
RUN_DEPENDS+=	${LOCALBASE}/modules/rtc.ko:${PORTSDIR}/emulators/rtc
CONFIGURE_ARGS+=	--enable-rtc
CONFIGURE_ENV+=		CFLAGS+="-I/${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=	--disable-rtc
.endif

.if defined(WITH_GUI) && !defined(WITHOUT_GUI)
USE_GNOME+=	gtk12
RUN_DEPENDS+=	${LOCALBASE}/share/mplayer/Skin:${PORTSDIR}/multimedia/mplayer-skins
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gtk
.else
PKGNAMESUFFIX=	-gtk
.endif
CONFIGURE_ARGS+=	--enable-gui
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.if !defined(WITHOUT_MENCODER)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
MLINKS+=	mplayer.1 mencoder.1
PLIST_SUB+=	MENCODER=""
.else
CONFIGURE_ARGS+=	--disable-mencoder
PLIST_SUB+=	MENCODER="@comment "
.endif

.if defined(WITH_ARTS) && (!defined(WITH_GUI) || defined(WITHOUT_GUI))
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts

CONFIGURE_ARGS+=	--enable-arts
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if defined(WITH_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
.else
CONFIGURE_ARGS+=	--disable-cdparanoia
.endif

.if defined(WITH_DVD)
.if !defined(WITH_LIBDVDREAD)
LIB_DEPENDS+=	dvdcss.2:${PORTSDIR}/multimedia/libdvdcss
.else
LIB_DEPENDS+=	dvdread.3:${PORTSDIR}/multimedia/libdvdread
.endif
#.if defined(WITH_LIBDVDNAV)
#LIB_DEPENDS+=	dvdnav.3:${PORTSDIR}/multimedia/libdvdnav

#CONFIGURE_ARGS+=	--enable-dvdnav
#.else
#CONFIGURE_ARGS+=	--disable-dvdnav
#.endif

CONFIGURE_ARGS+=	--enable-css \
			--with-csslibdir=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-css
.endif

.if defined(WITH_LIBUNGIF)
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

.if defined(WITH_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad

CONFIGURE_ARGS+=	--enable-mad \
			--with-madlibdir=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-mad
.endif

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
.endif

.if defined(WITH_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
.endif

.if defined(WITH_SDL)
USE_SDL=	sdl
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-esound
.else
PKGNAMESUFFIX=	-esound
.endif
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_REALPLAYER)
CONFIGURE_ARGS+=	--enable-real \
			--with-reallibdir=${LOCALBASE}/lib/RealPlayer8/Codecs
RUN_DEPENDS+=		realplay:${PORTSDIR}/multimedia/linux-realplayer
BUILD_DEPENDS+=		realplay:${PORTSDIR}/multimedia/linux-realplayer
.endif

.if defined(WITH_LIVEMEDIA)
CONFIGURE_ARGS+=	--enable-live \
			--with-livelibdir=${LOCALBASE}/live
RUN_DEPENDS+=		${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
BUILD_DEPENDS+=		${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
.endif

.if defined(WITH_XVID)
CONFIGURE_ARGS+=	--enable-xvid \
			--with-xvidcore=${LOCALBASE}/lib/libxvidcore.so
LIB_DEPENDS+=		xvidcore.2:${PORTSDIR}/multimedia/xvid
.endif

.if defined(WITH_LZO)
LIB_DEPENDS+=	lzo.1:${PORTSDIR}/archivers/lzo
.else
CONFIGURE_ARGS+=	--disable-liblzo
.endif

.if defined(WITH_XMMS)
CONFIGURE_ARGS+=	--enable-xmms
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
.endif

.if defined(WITH_FAAD)
CONFIGURE_ARGS+=	--enable-faad
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
.endif

.if defined(WITH_FREETYPE)
CONFIGURE_ARGS+=	--with-extraincdir=${LOCALBASE}/include/freetype2 \
			--enable-freetype
LIB_DEPENDS+=		freetype.9:${PORTSDIR}/print/freetype2
.else
RUN_DEPENDS+=	${LOCALBASE}/share/mplayer/fonts:${PORTSDIR}/multimedia/mplayer-fonts
CONFIGURE_ARGS+=	--disable-freetype
.endif

.if defined(WITH_XANIM)
BUILD_DEPENDS+=	xanim:${PORTSDIR}/multimedia/xanim

CONFIGURE_ARGS+=--enable-xanim --with-xanimlibdir=${X11BASE}/lib/X11/xanim
.else
CONFIGURE_ARGS+=--disable-xanim
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

# "enable" build for other archs
.if ${ARCH} == "i386"
.if !defined(WITHOUT_RUNTIME_CPUDETECTION)
CONFIGURE_ARGS+=--enable-runtime-cpudetection
.else #WITHOUT_RUNTIME_CPUDETECTION
.if defined(WITHOUT_MMX)
CONFIGURE_ARGS+=--disable-mmx
.endif
.if defined(WITHOUT_3DNOW) || ${OSVERSION} < 400021
CONFIGURE_ARGS+=--disable-3dnow
.endif
.if defined(WITHOUT_DSP) || defined(WITHOUT_3DNOW) || ${OSVERSION} < 400021
CONFIGURE_ARGS+=--disable-3dnowex
.endif
.if defined(WITHOUT_SSE)
CONFIGURE_ARGS+=--disable-mmx2 --disable-sse
.endif
.endif #WITHOUT_RUNTIME_CPUDETECTION
.if !defined(WITH_SVGALIB)
CONFIGURE_ARGS+=--disable-svga
.endif
.if !defined(WITH_AALIB)
CONFIGURE_ARGS+=--disable-aa
.endif
.if !defined(WITH_SDL)
CONFIGURE_ARGS+=--disable-sdl
.endif
.if !defined(WITH_VORBIS)
CONFIGURE_ARGS+=--disable-vorbis
.endif
.if !defined(WITHOUT_WIN32_CODECS)
RUN_DEPENDS+=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CONFIGURE_ARGS+=	--with-win32libdir=${LOCALBASE}/lib/win32

CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
.else
CONFIGURE_ARGS+=	--disable-win32 \
			--disable-qtx-codecs
.endif
.endif # ARCH == i386

pre-everything::
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a careful look into the Makefile in order"
	@${ECHO_MSG} "to learn how to tune mplayer towards you personal preferences!"
	@${ECHO_MSG} "For example,"
	@${ECHO_MSG} "make WITH_GUI=yes"
	@${ECHO_MSG} "builds MPlayer with GUI support."

.if defined(WITH_GUI) && !defined(WITHOUT_GUI)
	@${ECHO_MSG} "If you want to use the GUI, you can either install"
	@${ECHO_MSG} "${PORTSDIR}/multimedia/mplayer-skins"
	@${ECHO_MSG} "or download official skin collections from"
	@${ECHO_MSG} "http://www.mplayerhq.hu/homepage/dload.html"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|libxmms.so.1|libxmms.so|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -Ee 's#-pthread|-lc_r#${PTHREAD_LIBS}#g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|; \
		s|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
		${WRKSRC}/configure
.if defined(WITH_RTC)
	@${REINPLACE_CMD} -e \
		's|<linux/rtc.h>|<rtc.h>|' \
		${WRKSRC}/mplayer.c
	@${REINPLACE_CMD} -e \
		's|RTC_IRQP_SET|RTCIO_IRQP_SET|' \
		${WRKSRC}/mplayer.c
	@${REINPLACE_CMD} -e \
		's|RTC_PIE_ON|RTCIO_PIE_ON|' \
		${WRKSRC}/mplayer.c
	@${REINPLACE_CMD} -e \
		's|rtc_fd|rtc|' \
		${WRKSRC}/mplayer.c
.endif

pre-configure:
.if defined(WITH_LIBDVDREAD)
	@${RM} -Rf ${WRKSRC}/libmpdvdkit2/
.endif

post-configure:
	@${REINPLACE_CMD} -e 's#-pthread#${PTHREAD_LIBS}#g' \
		${WRKSRC}/config.mak

post-install:
	@${MKDIR} ${DATADIR}
	@${CHMOD} 755 ${DATADIR}
	@${MKDIR} ${DATADIR}/tools
	@${CHMOD} 755 ${DATADIR}/tools
.for conf in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${conf} ${DATADIR}
.endfor
.for tool in ${TOOLFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/TOOLS/${tool} ${DATADIR}/tools
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CHMOD} 755 ${DOCSDIR}
.for doc in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/DOCS/${doc} ${DOCSDIR}
.endfor
.endif
.if defined(WITH_GUI) && !defined(WITHOUT_GUI)
	@${LN} -sf ${PREFIX}/bin/mplayer ${PREFIX}/bin/gmplayer
.endif
	@${CAT} ${.CURDIR}/pkg-message

install-user:
	@${PERL} ${FILESDIR}/install-user

.include <bsd.port.post.mk>
