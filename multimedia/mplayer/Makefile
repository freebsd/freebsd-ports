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
# MPLAYER_GENERIC_BUILD
# default: undefined
# By default, the mplayer port creates a custom build based on personal
# preferences.
# If you want to build a generic package with certain fixed options,
# suitable for any CPU within ${ARCH}, define this knob.
# Note: The following knobs will have no effect in this case!
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
# WITH_NVIDIA
# default: disabled
# Enable nvidia XVMC support for nvidia video cards
# Note: This is highly experimental at the moment and works only for
#       MPEG1/2 using -vo xvmc -vc ffmpeg12mc on FreeBSD-5
#
# WITHOUT_MENCODER
# default: undefined
# the default is to build mplayer with mencoder. If you're sure that you
# don't want to encode or recode any media file, then define this.
#
# WITHOUT_X11
# default: undefined
# the default is to build mplayer with X11 support because of its capabilities
# as a video player. If you don't want to install any X11 environment and use
# mplayer as a multi-format audio-only player, this one is for you.
#
# WITH_GTK1|WITH_GTK2
# default: autodetect GTK1
# if you want mplayer to have gui abilities, you can use this knob to define
# which graphical toolkit set mplayer is built with.
# It defaults to detect and use GTK1 if it finds a working installation on the
# system. This can be overridden by choosing WITH_GTK2 or disable graphical
# user interface by defining WITHOUT_GUI
# Note: If you define WITH_GTK* *and* WITHOUT_GUI, mplayer will be built without
#       gui capabilities.
#       At the moment there is no current gtk2 patch available, so defining this
#       knob has no effect right now.
#
# WITHOUT_GUI
# default: undefined
# normally mplayer comes with gmplayer if gtk is installed on the system.
# If you want to force mplayer to disable the graphical user interface and
# build without gui ability, define this.
#
# WITHOUT_SKINS
# default: undefined
# removes the run dependency on the mplayer-skins port, _even if_ built with
# GUI. This is useful e.g. if you don't want the skins installed system-wide.
# Please note that 'gmplayer' *must* have at least one default skin to run.
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
# WITH_KERN_HZ
# default: 1024
# This option allows you to control the default kern.hz when using RTC support.
# If you have a older/slower processor you may want to lower the default level.
# ie. 512 seems to produce better quality video on a PII 400MHz than 1024 does
# CAUTION: lower than 512 may produce jerky video.
#
# Feature options:
# These options influence, which libraries mplayer is linked to.
# Note: The libraries are needed to play the particular files under
# particular circumstances.
# ("autodetect" in this sections means: If the ports system finds
# the libary on your system, it is used, otherwise not.
# If you define it, it will be built and installed as dependency.)
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
# WITH_LIBDVDNAV
# default: autodetect
# NOTE: This is disabled in the development tree at the moment
#       because it simply doesn't work, so defining it has no
#       effect until it works again.
#
# WITH_LIBUNGIF
# default: autodetect
#
# WITH_ARTS
# default: autodetect
# Note: arts audio output cannot work together with mplayer's gtk1-gui
# 	because of conflicting glib versions, so it it is disabled if
# 	mplayer is built with gtk1 graphical user interface
#
# WITHOUT_ARTS
# default: undefined
# By setting this option you can explicitly override WITH_ARTS or
# autodetection if arts is found. Some configurations experienced
# problems with arts, so this knob is provided to manually exclude
# it from build.
#
# WITH_FRIBIDI
# default: autodetect
#
# WITH_CDPARANOIA
# default: autodetect
#
# WITH_LIBCACA
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
# WITH_THEORA
# default: autodetect
#
# WITH_X264
# default: autodetect
#
# WITH_TREMOR
# default: autodetect
# By setting this option mplayer will use libtremor (integer only vorbis
# decoding lib) instead of libvorbis even if libvorbis is installed.
# Note: This is disabled at the moment due to unresolved build problems
#
# WITH_SDL
# default: autodetect
# (implies WITH_AALIB)
#
# WITH_ESOUND
# default: autodetect
#
# WITHOUT_ESOUND
# default: undefined
# By setting this option you can explicitly override WITH_ESOUND or
# autodetection if esound is found. Some configurations experienced
# problems with esound, so this knob is provided to manually exclude
# it from build.
#
# WITH_VORBIS
# default: autodetect
# If vorbis libs are not available on the system, mplayer includes
# an internal vorbis codec based on tremor. If the libs are present
# or this knob is defined, mplayer links to the shared system-wide
# installation of ogg/vorbis.
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
# WITH_MATROSKA
# default: autotedect
#
# WITH_XVID
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
PORTVERSION=	0.99.7
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
DISTNAME=	MPlayer-1.0pre7

MAINTAINER=	riggs@rrr.de
COMMENT=	High performance media player/encoder supporting many formats

PATCH_SITES=	http://www.win.net/~ardneh/patches/ \
		http://www.rrr.de/~riggs/mplayer/
PATCH_DIST_STRIP=	-p1

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
		--enable-png \
		--enable-menu \
		--disable-libfame \
		--disable-external-faad \
		--disable-tv-v4l \
		--disable-tremor

.if !defined(MPLAYER_GENERIC_BUILD)
.if defined(WITHOUT_X11)
WITHOUT_GUI=	yes
BUILD_DEPENDS+=	imake:${X_IMAKE_PORT}
CONFIGURE_ARGS+=--disable-x11
.else
USE_XLIB=	yes
CONFIGURE_ARGS+=--with-x11libdir=${X11BASE}/lib \
		--with-x11incdir=${X11BASE}/include
.endif

.if defined(WITH_LANG)
CONFIGURE_ARGS+=--language=${WITH_LANG}
.endif
.else
USE_XLIB=	yes
CONFIGURE_ARGS+=--with-x11libdir=${X11BASE}/lib \
		--with-x11incdir=${X11BASE}/include
.endif #MPLAYER_GENERIC_BUILD

WANT_GNOME=	yes
WANT_SDL=	yes
USE_REINPLACE=	yes
MAN1=		mplayer.1
MANCOMPRESSED=	no

CONFFILES=	example.conf input.conf menu.conf
TOOLFILES=	calcbpp.pl countquant.pl \
		dvd2divxscript.pl menc2pass \
		mencvcd mp.pl sws-test w32codec_dl.pl \
		x2mpsub.sh

.include <bsd.port.pre.mk>

# Can't run mplayer/nvidia-driver WITH_NVIDIA on FreeBSD 4.X now
.if ${OSVERSION} < 500000 && defined(WITH_NVIDIA)
IGNORE=	does not run on 4.x when WITH_NVIDIA is defined
.endif

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

#.if exists(${X11BASE}/lib/libXvMCNVIDIA.so.1)
#WITH_NVIDIA=	yes
#.endif

.if exists(${LOCALBASE}/lib/libfribidi.so.0)
WITH_FRIBIDI=	yes
.endif

.if !defined(WITHOUT_ARTS) && exists(${LOCALBASE}/lib/libartsc.so.0)
WITH_ARTS=	yes
.endif

.if exists(${LOCALBASE}/lib/libcdda_paranoia.so)
WITH_CDPARANOIA=	yes
.endif

.if exists(${LOCALBASE}/lib/libcaca.a)
WITH_LIBCACA=		yes
.endif

.if exists(${LOCALBASE}/lib/libdv.so.4)
WITH_LIBDV=	yes
.endif

.if exists(${LOCALBASE}/lib/libungif.so.5)
WITH_LIBUNGIF=	yes
.endif

.if exists(${LOCALBASE}/lib/libmad.so.2)
WITH_MAD=	yes
.endif

.if exists(${LOCALBASE}/lib/libvga.so.1)
WITH_SVGALIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libtheora.so.1)
WITH_THEORA=	yes
.endif

.if exists(${LOCALBASE}/lib/libx264.so.1)
WITH_X264=	yes
.endif

.if exists(${LOCALBASE}/lib/libaa.so.1)
WITH_AALIB=	yes
.endif

.if ${HAVE_SDL:Msdl}!=""
WITH_SDL=	yes
WITH_AALIB=	yes
.endif

.if !defined(WITHOUT_ESOUND) && ${HAVE_GNOME:Mesound}!=""
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

.if exists(${LOCALBASE}/lib/RealPlayer/realplay.bin)
WITH_REALPLAYER=	yes
.endif

.if exists(${LOCALBASE}/live/liveMedia/libliveMedia.a)
WITH_LIVEMEDIA=	yes
.endif

.if exists(${LOCALBASE}/lib/libxvidcore.so)
WITH_XVID=	yes
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

# Esablish de-facto dependencies for either building generic mplayer
# binary-suitable package or custom build

.if defined(MPLAYER_GENERIC_BUILD)
#Compiler flags
CFLAGS=		#let mplayer decide on this
CONFIGURE_ARGS+=--enable-runtime-cpudetection
#GUI
USE_GNOME+=	gtk12
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gtk
.else
PKGNAMESUFFIX=	-gtk
.endif
CONFIGURE_ARGS+=	--enable-gui
PLIST_SUB+=	GMPLAYER=""
RUN_DEPENDS+=	${LOCALBASE}/share/mplayer/Skin:${PORTSDIR}/multimedia/mplayer-skins
#RTC
CONFIGURE_ARGS+=	--disable-rtc
#lame for mencoder
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
#mencoder
MLINKS+=	mplayer.1 mencoder.1
PLIST_SUB+=	MENCODER=""
#ARTS
CONFIGURE_ARGS+=	--disable-arts
#Fribidi
CONFIGURE_ARGS+=	--disable-fribidi
#Cdparanoia
CONFIGURE_ARGS+=	--disable-cdparanoia
#Caca
CONFIGURE_ARGS+=	--disable-caca
#Libungif
CONFIGURE_ARGS+=	--disable-gif
#Libdv
CONFIGURE_ARGS+=	--disable-libdv
#Mad
CONFIGURE_ARGS+=	--disable-mad
#Theora
CONFIGURE_ARGS+=	--disable-theora
#x264
CONFIGURE_ARGS+=	--disable-x264
#Svgalib
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
#Aalib
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
#SDL
USE_SDL=	sdl
#Esound
CONFIGURE_ARGS+=	--disable-esd
#Vorbis
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
#Live media
CONFIGURE_ARGS+=	--disable-live
#XviD
CONFIGURE_ARGS+=	--enable-xvid
LIB_DEPENDS+=		xvidcore.4:${PORTSDIR}/multimedia/xvid
#LZO
CONFIGURE_ARGS+=	--disable-liblzo
#Freetype
CONFIGURE_ARGS+=	--with-extraincdir=${LOCALBASE}/include/freetype2 \
			--enable-freetype
LIB_DEPENDS+=		freetype.9:${PORTSDIR}/print/freetype2
#XAnim codecs
BUILD_DEPENDS+=	xanim:${PORTSDIR}/multimedia/xanim
CONFIGURE_ARGS+=	--enable-xanim \
			--with-xanimlibdir=${X11BASE}/lib/X11/xanim
#Optical drive descriptors
.if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
DEFAULT_CDROM_DEVICE=/dev/acd0c
.else
DEFAULT_DVD_DEVICE=/dev/acd0
DEFAULT_CDROM_DEVICE=/dev/acd0
.endif
#Kernel granularity
DEFAULT_KERN_HZ=1024
.else #MPLAYER_GENERIC_BUILD
CFLAGS+=	-fno-force-addr
.if defined(DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

#.if ${HAVE_GNOME:Mgtk12}!="" && !defined(WITH_GTK2) && !defined(WITHOUT_GUI)
.if ${HAVE_GNOME:Mgtk12}!="" && !defined(WITHOUT_GUI)
WITH_GTK1=	yes
.endif

.if !defined(WITHOUT_GUI)
PLIST_SUB+=	GMPLAYER=""
.if !defined(WITHOUT_SKINS)
RUN_DEPENDS+=	${LOCALBASE}/share/mplayer/Skin:${PORTSDIR}/multimedia/mplayer-skins
.endif
.else
PLIST_SUB+=	GMPLAYER="@comment "
.endif

#.if defined(WITH_GTK2) && !defined(WITH_GTK1) && !defined(WITHOUT_GUI)
#.if ( ${OSVERSION} < 500000 )
#USE_GCC=	3.4
#.endif
#USE_GNOME+=	gtk20
#PATCHFILES+=	mplayer1.0pre5-gtk2-20040730.patch.bz2
#.if defined(PKGNAMESUFFIX)
#PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gtk2
#.else
#PKGNAMESUFFIX=	-gtk2
#.endif
#CONFIGURE_ARGS+=	--enable-gui
#.if defined(WITH_LANG)
#WITH_LANG=	""
#.endif
#.endif

#.if defined(WITH_GTK1) && !defined(WITH_GTK2) && !defined(WITHOUT_GUI)
.if defined(WITH_GTK1) && !defined(WITHOUT_GUI)
USE_GNOME+=	gtk12
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gtk
.else
PKGNAMESUFFIX=	-gtk
.endif
CONFIGURE_ARGS+=	--enable-gui
.endif

.if defined(WITHOUT_GUI)
CONFIGURE_ARGS+=	--disable-gui
.endif

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

.if defined(WITH_NVIDIA)
LIB_DEPENDS+=	XvMCNVIDIA.1:${PORTSDIR}/x11/nvidia-driver
CONFIGURE_ARGS+=	--enable-xvmc \
			--enable-xvmclib=XvMCNVIDIA
.endif

.if defined(WITH_ARTS) && !defined(WITHOUT_ARTS) && !defined(WITH_GTK1)
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

.if defined(WITH_THEORA)
LIB_DEPENDS+=	theora.1:${PORTSDIR}/multimedia/libtheora
.else
CONFIGURE_ARGS+=	--disable-theora
.endif

.if defined(WITH_X264)
LIB_DEPENDS+=	x264.1:${PORTSDIR}/multimedia/x264
.else
CONFIGURE_ARGS+=	--disable-x264
.endif

#.if defined(WITH_TREMOR)
#LIB_DEPENDS+=	vorbisidec.1:${PORTSDIR}/audio/libtremor
#CONFIGURE_ARGS+=	--enable-tremor
#.else
#CONFIGURE_ARGS+=	--disable-tremor
#.endif

.if defined(WITH_SDL)
USE_SDL=	sdl
.endif

.if defined(WITH_ESOUND) && !defined(WITHOUT_ESOUND)
USE_GNOME+=	esound
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-esound
.else
PKGNAMESUFFIX=	-esound
.endif
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if defined(WITH_VORBIS)
CONFIGURE_ARGS+=	--disable-internal-tremor
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_REALPLAYER)
CONFIGURE_ARGS+=	--enable-real \
			--with-reallibdir=${LOCALBASE}/lib/RealPlayer/codecs
RUN_DEPENDS+=		realplay:${PORTSDIR}/multimedia/linux-realplayer
BUILD_DEPENDS+=		realplay:${PORTSDIR}/multimedia/linux-realplayer
.endif

.if defined(WITH_LIVEMEDIA)
CONFIGURE_ARGS+=	--enable-live \
			--with-livelibdir=${LOCALBASE}/live
RUN_DEPENDS+=		${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
BUILD_DEPENDS+=		${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
.else
CONFIGURE_ARGS+=	--disable-live
.endif

.if defined(WITH_XVID)
CONFIGURE_ARGS+=	--enable-xvid
LIB_DEPENDS+=		xvidcore.4:${PORTSDIR}/multimedia/xvid
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

.if defined(WITH_KERN_HZ)
DEFAULT_KERN_HZ=${WITH_KERN_HZ}
.else
DEFAULT_KERN_HZ=1024
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
.endif #MPLAYER_GENERIC_BUILD

pre-everything::
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a careful look into the Makefile in order"
	@${ECHO_MSG} "to learn how to tune mplayer towards you personal preferences!"
	@${ECHO_MSG} "For example,"
	@${ECHO_MSG} "make WITH_GTK1"
	@${ECHO_MSG} "builds MPlayer with GTK1-GUI support."

.if !defined(WITHOUT_GUI)
	@${ECHO_MSG} "If you want to use the GUI, you can either install"
	@${ECHO_MSG} "${PORTSDIR}/multimedia/mplayer-skins"
	@${ECHO_MSG} "or download official skin collections from"
	@${ECHO_MSG} "http://www.mplayerhq.hu/homepage/dload.html"
.endif

#.if defined(WITH_GTK2) && !defined(WITHOUT_GUI)
#	@${ECHO_MSG} "=====================> <Caution> <======================"
#	@${ECHO_MSG} "GTK2 and UTF8 language options cannot peacefully coexist"
#	@${ECHO_MSG} "If you have defined WITH_LANG=<something> and WITH_GTK2"
#	@${ECHO_MSG} "your language options are ignored."
#	@${ECHO_MSG} "====================> </Caution> <======================"
#.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|libxmms.so.1|libxmms.so|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|; \
		s|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's!/usr/local!${PREFIX}!' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${WRKSRC}/DOCS/man -name "mplayer.1" | ${XARGS} ${REINPLACE_CMD} -E -e \
		's|/usr/\\:local/\\:etc/\\:mplayer|${DATADIR:S/\//\/\\\:/g}|g ; \
		 s|/dev/\\:(dvd[[:alnum:]]*[[:>:]])|${DEFAULT_DVD_DEVICE:S/dev\//dev\/\\\:/}|g ; \
		 s|/dev/\\:(cdrom[[:alnum:]]*[[:>:]])|${DEFAULT_CDROM_DEVICE:S/dev\//dev\/\\\:/}|g'
.if defined(WITH_RTC)
	@${REINPLACE_CMD} -e \
		's|irqp = 1024|irqp = ${DEFAULT_KERN_HZ}|' \
		${WRKSRC}/mplayer.c
.endif
.if defined(MPLAYER_GENERIC_BUILD)
	@${REINPLACE_CMD} -e \
		's|1.0pre7|1.0pre7-FreeBSD-generic|' \
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
.for conf in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${conf} ${DATADIR}
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
	@${CAT} ${.CURDIR}/pkg-message

install-user:
	@${PERL} ${FILESDIR}/install-user

.include <bsd.port.post.mk>
