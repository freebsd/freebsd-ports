# Created by: Brian Somers <brian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vlc
DISTVERSION=	2.0.8a
PORTREVISION=	2
PORTEPOCH=	4
CATEGORIES=	multimedia audio ipv6 net www
MASTER_SITES=	http://download.videolan.org/pub/videolan/${PORTNAME}/${DISTVERSION:S/a$//}/ \
		http://ftp.snt.utwente.nl/pub/software/videolan/${PORTNAME}/${DISTVERSION:S/a$//}/ \
		ftp://ftp.crans.org/pub/videolan/${PORTNAME}/${DISTVERSION:S/a$//}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Qt4 based multimedia player and streaming server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt \
		proxy:${PORTSDIR}/net/libproxy \
		dvbpsi:${PORTSDIR}/multimedia/libdvbpsi
BUILD_DEPENDS=	ffmpeg${FFMPEG_SUFFIX}>=1.0:${PORTSDIR}/multimedia/ffmpeg${FFMPEG_SUFFIX}
RUN_DEPENDS=	ffmpeg${FFMPEG_SUFFIX}>=1.0:${PORTSDIR}/multimedia/ffmpeg${FFMPEG_SUFFIX}

OPTIONS_DEFINE=	A52 AALIB ASS AVAHI CACA DBUS DIRAC DOCS DTS DVDREAD \
		DVDNAV FAAD FLAC FLUID FRIBIDI GLX GNOMEVFS GNUTLS GOOM \
		HTTPD JACK LIBSSH2 LIRC LIVEMEDIA LUA MAD MATROSKA MODPLUG \
		MPEG2 MTP MUSEPACK NCURSES NLS NOTIFY OPTIMIZED_CFLAGS OGG \
		OPUS PNG PORTAUDIO PROJM PULSEAUDIO QT4 REALAUDIO RUNROOT \
		SAMBA SCHROED SDL SHOUTCAST SKINS STREAM SPEEX SQLITE SVG \
		TAGLIB THEORA TWOLAME UPNP V4L VAAPI VCD VORBIS \
		X11 X264 XCB XOSD XVIDEO ZVBI SERVER_ONLY DEBUG \
		GME NO_DVD LIBBLURAY SAMPLERATE SIDPLAY
OPTIONS_DEFAULT=A52 AVAHI DBUS DTS DVDREAD DVDNAV FAAD FLAC GLX GNUTLS \
		HTTPD LUA MAD MATROSKA MPEG2 OGG OPUS PNG QT4 REALAUDIO \
		SDL SKINS STREAM SPEEX TAGLIB THEORA TWOLAME V4L \
		VCD VORBIS X11 X264 XCB XVIDEO SAMPLERATE
ASS_DESC=	ASS/SSA subtitle rendering
DTS_DESC=	DTS DVD audio decoder
DVDREAD_DESC=	DVD Playback support
DVDNAV_DESC=	DVD menu navigation
FLUID_DESC=	Fluidsynth MIDI support
GME_DESC=	Game_Music_Emu (libgme) support
GNOMEVFS_DESC=	Gnome VFS support
GOOM_DESC=	the Goom visual effect library
LIBSSH2_DESC=	SCP/SFTP support via libssh2
NCURSES_DESC=	ncurses (console) interface
OPUS_DESC=	Opus audio format
PROJM_DESC=	ProjectM visualizations
REALAUDIO_DESC=	Real Audio(R) support
RUNROOT_DESC=	Enable running as root
SAMBA_DESC=	SAMBA Access module
SCHROED_DESC=	Schroedinger decoder
SIDPLAY_DESC=	C64 sid demux support
SKINS_DESC=	winamp skins interface
STREAM_DESC=	stream output
TAGLIB_DESC=	ID3 tag and Ogg comment support
V4L_DESC=	Video4Linux video capture compatibility
VCD_DESC=	Video CD support
XCB_DESC=	Use X C Bindings for X11 output
XOSD_DESC=	X11 On Screen Display support
ZVBI_DESC=	VBI decoding support
SERVER_ONLY_DESC=	Only build server parts
UNSAFE_PLUGINS_DESC=	Install unsafe, unsupported plugins
NO_DVD_DESC=	disable DVD specific features

USE_XZ=		yes
USES=		iconv perl5 gmake pkgconfig
USE_PERL5=	build
USE_GL=		yes
USE_CSTD=	gnu99
WANT_GNOME=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}

FAKEDIR=	${WRKDIR}/fake${PREFIX}
PLIST=		${WRKDIR}/plist

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
FFMPEG_SUFFIX=	1
FFMPEG_INCDIR=	${LOCALBASE}/include/ffmpeg${FFMPEG_SUFFIX}
FFMPEG_LIBDIR=	${LOCALBASE}/lib/ffmpeg${FFMPEG_SUFFIX}
CPPFLAGS+=	-I${FAKEDIR}/include -I${WRKSRC}/include \
		-I${FFMPEG_INCDIR} \
		${PTHREAD_CFLAGS}
CONFIGURE_ENV=	LIBS="-lc"
LDFLAGS+=	-L${FAKEDIR}/lib \
		${PTHREAD_LIBS} -lc
CONFIGURE_ENV+=	AVCODEC_CFLAGS="-I${FFMPEG_INCDIR}" AVCODEC_LIBS="-L${FFMPEG_LIBDIR} -Wl,-rpath -Wl,${FFMPEG_LIBDIR} -lavcodec${FFMPEG_SUFFIX}"
CONFIGURE_ENV+=	AVFORMAT_CFLAGS="-I${FFMPEG_INCDIR}" AVFORMAT_LIBS="-L${FFMPEG_LIBDIR} -Wl,-rpath -Wl,${FFMPEG_LIBDIR} -lavformat${FFMPEG_SUFFIX}"
CONFIGURE_ENV+=	POSTPROC_CFLAGS="-I${FFMPEG_INCDIR}" POSTPROC_LIBS="-L${FFMPEG_LIBDIR} -Wl,-rpath -Wl,${FFMPEG_LIBDIR} -lpostproc${FFMPEG_SUFFIX}"
CONFIGURE_ENV+=	SWSCALE_CFLAGS="-I${FFMPEG_INCDIR}" SWSCALE_LIBS="-L${FFMPEG_LIBDIR} -Wl,-rpath -Wl,${FFMPEG_LIBDIR} -lswscale${FFMPEG_SUFFIX}"

CONFIGURE_ARGS+=	--enable-vlc \
			--enable-avcodec \
			--enable-avformat \
			--enable-oss \
			--enable-postproc \
			--enable-sftp \
			--enable-libgcrypt \
			--disable-alsa \
			--disable-dc1394 \
			--disable-directfb \
			--disable-dv \
			--disable-loader \
			--disable-telx \
			--disable-udev \
			--disable-update-check

MAN1=		vlc.1 \
		vlc-wrapper.1

NO_STAGE=	yes

.include <bsd.port.options.mk>

# Macro section
# Use these for batch control of certain types of builds

# Disable DVD specific features
.if ${PORT_OPTIONS:MNO_DVD}
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}
PORT_OPTIONS:=	${PORT_OPTIONS:NA52}
PORT_OPTIONS:=	${PORT_OPTIONS:NDVDREAD}
PORT_OPTIONS:=	${PORT_OPTIONS:NDVDNAV}
.endif

# Use this to disable all UI and output modules
.if ${PORT_OPTIONS:MSERVER_ONLY}
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}
PORT_OPTIONS:=	${PORT_OPTIONS:NGLX}
PORT_OPTIONS:=	${PORT_OPTIONS:NLUA}
PORT_OPTIONS:=	${PORT_OPTIONS:NQT4}
PORT_OPTIONS:=	${PORT_OPTIONS:NSKINS}
PORT_OPTIONS:=	${PORT_OPTIONS:NXCB}
PORT_OPTIONS:=	${PORT_OPTIONS:NXVIDEO}
.if empty(PORT_OPTIONS:MRUNROOT)
PORT_OPTIONS+=	RUNROOT
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}
.endif
.endif

# WITH_UNSAFE_PLUGINS
# This knob allows installation of misbehaving plugins that do not function as
# intended on FreeBSD. They are considered unsupported. Use if you would like to
# help fix them.

# This was the pre-1.1.0 DEBUG option. It differs in function than bsd.port.mk's
# knob and is not needed by most users. Put here for those who need/want it.
.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

# End Macro section

# Qt bits must be included before bsd.port.pre.mk
.if ${PORT_OPTIONS:MQT4}
CONFIGURE_ARGS+=--enable-qt4
USE_QT4=	gui corelib moc_build rcc_build uic_build
.else
CONFIGURE_ARGS+=--disable-qt4
.endif

# OPTIONS
# Keep these organized!

.if ${PORT_OPTIONS:MA52}
CONFIGURE_ARGS+=--enable-a52
LIB_DEPENDS+=	a52:${PORTSDIR}/audio/liba52
.else
CONFIGURE_ARGS+=--disable-a52
.endif

.if ${PORT_OPTIONS:MAALIB}
LIB_DEPENDS+=	aa:${PORTSDIR}/graphics/aalib
CONFIGURE_ARGS+=--enable-aa
.else
CONFIGURE_ARGS+=--disable-aa
.endif

.if ${PORT_OPTIONS:MASS}
LIB_DEPENDS+=	ass:${PORTSDIR}/multimedia/libass
CONFIGURE_ARGS+=--enable-libass
.else
CONFIGURE_ARGS+=--disable-libass
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-common:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=--enable-bonjour
.else
CONFIGURE_ARGS+=--disable-bonjour
.endif

.if ${PORT_OPTIONS:MCACA}
.if ${PORT_OPTIONS:MAALIB}
LIB_DEPENDS+=	caca:${PORTSDIR}/graphics/libcaca
CONFIGURE_ARGS+=--enable-caca
.else
IGNORE=	CACA option requires AALIB option
.endif
.else
CONFIGURE_ARGS+=--disable-caca
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=--enable-dbus
.else
CONFIGURE_ARGS+=--disable-dbus
.endif

.if ${PORT_OPTIONS:MDIRAC}
LIB_DEPENDS+=	dirac_decoder:${PORTSDIR}/multimedia/dirac
CONFIGURE_ARGS+=--enable-dirac
CPPFLAGS+=	-I${LOCALBASE}/include/dirac
.else
CONFIGURE_ARGS+=--disable-dirac
.endif

.if ${PORT_OPTIONS:MDTS}
LIB_DEPENDS+=	dca:${PORTSDIR}/multimedia/libdca
CONFIGURE_ARGS+=--enable-dca
.else
CONFIGURE_ARGS+=--disable-dca
.endif

.if ${PORT_OPTIONS:MDVDREAD}
LIB_DEPENDS+=	dvdread:${PORTSDIR}/multimedia/libdvdread
CONFIGURE_ARGS+=--enable-dvdread
.else
CONFIGURE_ARGS+=--disable-dvdread
.endif

.if ${PORT_OPTIONS:MDVDNAV}
LIB_DEPENDS+=	dvdnav:${PORTSDIR}/multimedia/libdvdnav
CONFIGURE_ARGS+=--enable-dvdnav
.else
CONFIGURE_ARGS+=--disable-dvdnav
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	faad:${PORTSDIR}/audio/faad
CONFIGURE_ARGS+=--enable-faad
.else
CONFIGURE_ARGS+=--disable-faad
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--enable-flac
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if ${PORT_OPTIONS:MFLUID}
LIB_DEPENDS+=	fluidsynth:${PORTSDIR}/audio/fluidsynth
CONFIGURE_ARGS+=--enable-fluidsynth
.else
CONFIGURE_ARGS+=--disable-fluidsynth
.endif

.if ${PORT_OPTIONS:MFRIBIDI}
LIB_DEPENDS+=	fribidi:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=--enable-fribidi
.else
CONFIGURE_ARGS+=--disable-fribidi
.endif

.if ${PORT_OPTIONS:MGLX}
.if ${PORT_OPTIONS:MXCB}
CONFIGURE_ARGS+=--enable-glx
.else
IGNORE=	GLX option requires XCB option
.endif
.else
CONFIGURE_ARGS+=--disable-glx
.endif

.if ${PORT_OPTIONS:MGME}
LIB_DEPENDS+=	gme:${PORTSDIR}/audio/libgme
CONFIGURE_ARGS+=--enable-gme
.else
CONFIGURE_ARGS+=--disable-gme
.endif

.if ${PORT_OPTIONS:MGNOMEVFS}
USE_GNOME+=	gnomevfs2
CONFIGURE_ARGS+=--enable-gnomevfs
.else
CONFIGURE_ARGS+=--disable-gnomevfs
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--enable-gnutls
.else
CONFIGURE_ARGS+=--disable-gnutls
.endif

.if ${PORT_OPTIONS:MGOOM}
LIB_DEPENDS+=	goom2:${PORTSDIR}/graphics/goom
CONFIGURE_ARGS+=--enable-goom
.else
CONFIGURE_ARGS+=--disable-goom
.endif

.if ${PORT_OPTIONS:MHTTPD}
CONFIGURE_ARGS+=--enable-httpd
.else
CONFIGURE_ARGS+=--disable-httpd
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=--enable-jack
.else
CONFIGURE_ARGS+=--disable-jack
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
LIB_DEPENDS+=	bluray:${PORTSDIR}/multimedia/libbluray
CONFIGURE_ARGS+=--enable-bluray
.else
CONFIGURE_ARGS+=--disable-bluray
.endif

.if ${PORT_OPTIONS:MLIBSSH2}
LIB_DEPENDS+=	ssh2:${PORTSDIR}/security/libssh2
CONFIGURE_ARGS+=--enable-sftp
.else
CONFIGURE_ARGS+=--disable-sftp
.endif

.if ${PORT_OPTIONS:MLIRC}
CONFIGURE_ARGS+=--enable-lirc
LIB_DEPENDS+=	lirc_client:${PORTSDIR}/comms/lirc
.else
CONFIGURE_ARGS+=--disable-lirc
.endif

.if ${PORT_OPTIONS:MLIVEMEDIA}
BUILD_DEPENDS+=	${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
CONFIGURE_ARGS+=--enable-live555
CPPFLAGS+=	-I${LOCALBASE}/live/liveMedia/include \
		-I${LOCALBASE}/live/BasicUsageEnvironment/include \
		-I${LOCALBASE}/live/UsageEnvironment/include \
		-I${LOCALBASE}/live/groupsock/include
LDFLAGS+=	-L${LOCALBASE}/live/groupsock \
		-L${LOCALBASE}/live/liveMedia \
		-L${LOCALBASE}/live/UsageEnvironment \
		-L${LOCALBASE}/live/BasicUsageEnvironment
.else
CONFIGURE_ARGS+=--disable-live555
.endif

# This may become mandantory in the future
.if ${PORT_OPTIONS:MLUA}
USE_LUA=5.1+
WANT_LUA_VER=5.1
CONFIGURE_ENV+=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
CONFIGURE_ARGS+=--enable-lua LUAC=luac-${WANT_LUA_VER}
.else
CONFIGURE_ARGS+=--disable-lua
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	id3tag:${PORTSDIR}/audio/libid3tag \
		mad:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--enable-mad --with-mad=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if ${PORT_OPTIONS:MMATROSKA}
LIB_DEPENDS+=	matroska:${PORTSDIR}/multimedia/libmatroska
CONFIGURE_ARGS+=--enable-mkv
.else
CONFIGURE_ARGS+=--disable-mkv
.endif

.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug
CONFIGURE_ARGS+=--enable-mod
.else
CONFIGURE_ARGS+=--disable-mod
.endif

.if ${PORT_OPTIONS:MMPEG2}
LIB_DEPENDS+=	mpeg2:${PORTSDIR}/multimedia/libmpeg2
CONFIGURE_ARGS+=--enable-libmpeg2
.else
CONFIGURE_ARGS+=--disable-libmpeg2
.endif

.if ${PORT_OPTIONS:MMTP}
LIB_DEPENDS+=	mtp:${PORTSDIR}/audio/libmtp
CONFIGURE_ARGS+=--enable-mtp
.else
CONFIGURE_ARGS+=--disable-mtp
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
LIB_DEPENDS+=	mpcdec:${PORTSDIR}/audio/musepack
CONFIGURE_ARGS+=--enable-mpc
.else
CONFIGURE_ARGS+=--disable-mpc
.endif

.if ${PORT_OPTIONS:MNCURSES}
CONFIGURE_ENV+=	NCURSES_CFLAGS="-I/usr/include" NCURSES_LIBS="-lncursesw"
CONFIGURE_ARGS+=--enable-ncurses
.else
CONFIGURE_ARGS+=--disable-ncurses
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.if ${PORT_OPTIONS:MNOTIFY}
CONFIGURE_ARGS+=--enable-notify
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-notify
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=-O3 -ffast-math -fomit-frame-pointer
CONFIGURE_ARGS+=--enable-optimizations
.endif

.if ${PORT_OPTIONS:MOGG}
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg \
		kate:${PORTSDIR}/multimedia/libkate
CONFIGURE_ARGS+=--enable-ogg --enable-kate
.else
PORT_OPTIONS:=	${PORT_OPTIONS:NVORBIS}
CONFIGURE_ARGS+=--disable-ogg --disable-kate
.endif

.if ${PORT_OPTIONS:MOPUS}
LIB_DEPENDS+=	opus:${PORTSDIR}/audio/opus
CONFIGURE_ARGS+=--enable-opus
.else
CONFIGURE_ARGS+=--disable-opus
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--enable-png
.else
CONFIGURE_ARGS+=--disable-png
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	portaudio.2:${PORTSDIR}/audio/portaudio2
CONFIGURE_ARGS+=--enable-portaudio
.else
CONFIGURE_ARGS+=--disable-portaudio
.endif

.if ${PORT_OPTIONS:MPROJM}
LIB_DEPENDS+=	projectM:${PORTSDIR}/graphics/libprojectm
CONFIGURE_ARGS+=--enable-projectm
.else
CONFIGURE_ARGS+=--disable-projectm
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--enable-pulse
.else
CONFIGURE_ARGS+=--enable-pulse=no
.endif

# WITHOUT_QT4
# Before .include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MREALAUDIO}
CONFIGURE_ARGS+=--enable-real --enable-realrtsp
.else
CONFIGURE_ARGS+=--disable-real --disable-realrtsp
.endif

.if ${PORT_OPTIONS:MRUNROOT}
CONFIGURE_ARGS+=--enable-run-as-root
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=	samplerate:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-samplerate
.else
CONFIGURE_ARGS+=--disable-samplerate
.endif

.if ${PORT_OPTIONS:MSAMBA}
LIB_DEPENDS+=	smbclient:${PORTSDIR}/net/samba-libsmbclient
CONFIGURE_ARGS+=--enable-smb
.else
CONFIGURE_ARGS+=--disable-smb
.endif

.if ${PORT_OPTIONS:MSCHROED}
LIB_DEPENDS+=	schroedinger-1:${PORTSDIR}/multimedia/schroedinger
CONFIGURE_ARGS+=--enable-schroedinger
.else
CONFIGURE_ARGS+=--disable-schroedinger
.endif

.if ${PORT_OPTIONS:MSIDPLAY}
LIB_DEPENDS+=	sidplay2:${PORTSDIR}/audio/libsidplay2
LDFLAGS+=	-L${LOCALBASE}/lib/sidplay/builders
CONFIGURE_ARGS+=--enable-sid
.else
CONFIGURE_ARGS+=--disable-sid
.endif

.if ${PORT_OPTIONS:MSDL} && ${PORT_OPTIONS:MXCB}
WANT_SDL=	yes
USE_SDL=	image
CONFIGURE_ARGS+=--enable-sdl --enable-sdl-image
.else
CONFIGURE_ARGS+=--disable-sdl --disable-sdl-image
.endif

.if ${PORT_OPTIONS:MSHOUTCAST}
LIB_DEPENDS+=	shout:${PORTSDIR}/audio/libshout2
CONFIGURE_ARGS+=--enable-shout
.else
CONFIGURE_ARGS+=--disable-shout
.endif

.if ${PORT_OPTIONS:MSKINS}
.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	tar:${PORTSDIR}/devel/libtar
CONFIGURE_ARGS+=--enable-skins2 --enable-libtar
.else
IGNORE=	SKINS option requires QT4 option
.endif
.else
CONFIGURE_ARGS+=--disable-skins2 --disable-libtar
.endif

.if ${PORT_OPTIONS:MSTREAM}
CONFIGURE_ARGS+=--enable-sout
.else
CONFIGURE_ARGS+=--disable-sout
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	speex:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=--enable-speex
CPPFLAGS+=-I${LOCALBASE}/include/speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if ${PORT_OPTIONS:MSQLITE}
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=--enable-sqlite
.else
CONFIGURE_ARGS+=--disable-sqlite
.endif

.if ${PORT_OPTIONS:MSVG} && ${PORT_OPTIONS:MXCB}
USE_GNOME+=	librsvg2
CONFIGURE_ARGS+=--enable-svg
.else
CONFIGURE_ARGS+=--disable-svg
.endif

.if ${PORT_OPTIONS:MTAGLIB}
LIB_DEPENDS+=	tag:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=--enable-taglib
.else
CONFIGURE_ARGS+=--disable-taglib
.endif

.if ${PORT_OPTIONS:MTHEORA}
LIB_DEPENDS+=	theora:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=--enable-theora
.else
CONFIGURE_ARGS+=--disable-theora
.endif

# XXX Tremor support no longer builds with 2.0.3
#.if ${PORT_OPTIONS:MTREMOR}
# Tremor is integer based Vorbis subset, using both is redundant
#LIB_DEPENDS+=	vorbisidec:${PORTSDIR}/audio/libtremor
#CONFIGURE_ARGS+=--enable-tremor
#.else
CONFIGURE_ARGS+=--disable-tremor
#.endif

.if ${PORT_OPTIONS:MTWOLAME}
LIB_DEPENDS+=		twolame:${PORTSDIR}/audio/twolame
CONFIGURE_ARGS+=	--enable-twolame
.else
CONFIGURE_ARGS+=	--disable-twolame
.endif

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	upnp:${PORTSDIR}/devel/upnp
CONFIGURE_ARGS+=--enable-upnp
.else
CONFIGURE_ARGS+=--disable-upnp
.endif

.if ${PORT_OPTIONS:MV4L} || ${PORT_OPTIONS:MDVB}
LIB_DEPENDS+=	v4l1:${PORTSDIR}/multimedia/libv4l
CONFIGURE_ARGS+=--enable-v4l2
.else
CONFIGURE_ARGS+=--disable-v4l2
.endif

.if ${PORT_OPTIONS:MVAAPI}
LIB_DEPENDS+=	va:${PORTSDIR}/multimedia/libva
CONFIGURE_ARGS+=--enable-libva
.else
CONFIGURE_ARGS+=--disable-libva
.endif

.if ${PORT_OPTIONS:MVCD}
LIB_DEPENDS+=	cddb:${PORTSDIR}/audio/libcddb
CONFIGURE_ARGS+=--enable-vcd --enable-libcddb
.else
CONFIGURE_ARGS+=--disable-vcd --disable-libcddb
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=--with-x
.else
CONFIGURE_ARGS+=--without-x
.endif

.if ${PORT_OPTIONS:MX264}
CONFIGURE_ARGS+=--enable-x264
LIB_DEPENDS+=	x264:${PORTSDIR}/multimedia/x264
.else
CONFIGURE_ARGS+=--disable-x264
.endif

.if ${PORT_OPTIONS:MXCB}
USE_XORG=	xcb xpm
LIB_DEPENDS+=	xcb-keysyms:${PORTSDIR}/x11/xcb-util-keysyms
CONFIGURE_ARGS+=--enable-xcb --with-x
.else
CONFIGURE_ARGS+=--disable-xcb --without-x
.endif

.if ${PORT_OPTIONS:MXOSD}
LIB_DEPENDS+=	xosd:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=--enable-xosd
.else
CONFIGURE_ARGS+=--disable-xosd
.endif

.if ${PORT_OPTIONS:MXVIDEO}
.if ${PORT_OPTIONS:MXCB}
CONFIGURE_ARGS+=--enable-xvideo
.else
IGNORE=	XVIDEO option requires XCB option
.endif
.else
CONFIGURE_ARGS+=--disable-xvideo
.endif

.if ${PORT_OPTIONS:MZVBI}
LIB_DEPENDS+=	zvbi:${PORTSDIR}/devel/libzvbi
CONFIGURE_ARGS+=--enable-zvbi
.else
CONFIGURE_ARGS+=--disable-zvbi
.endif

.include <bsd.port.pre.mk>

# OS specific hacks
.if (${OSVERSION} < 800000)
BROKEN=		doesn't build on such an old FreeBSD version
.endif

.if (${OSVERSION} < 800040)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules__misc__inhibit__xdg.c \
		${FILESDIR}/extra-patch-modules__misc__inhibit__xscreensaver.c
.endif

# base clang in 9.0 builds a corrupted lib/vlc/plugins/gui/libqt4_plugin.so
.if (${CC:T:Mclang} == "clang") && \
	(${OSVERSION} >= 900014) && (${OSVERSION} < 900506)
IGNORE=		base clang version too old, set NO_IGNORE to override
.endif

.if ${ARCH} == "powerpc64"
CONFIGURE_ARGS+=--enable-altivec # VLC's config script doesn't know to do this
.endif

# prefer clang on 9.1+
.if (${OSVERSION} >= 901000) && exists(${DESTDIR}/usr/bin/clang)
CC=	clang
CXX=	clang++
CPP=	clang-cpp
.else
.if ${ARCH} == "i386"
USE_GCC?=	yes # sse/3dnow detection on i386 needs newer GCC
.endif
.endif

# End OS specific hacks

# User tunables

# Define these to override
# FreeBSD 9.x uses CAM devices
.if (${OSVERSION} > 900037)
WITH_CDROM_DEVICE?=/dev/cd0
WITH_DVD_DEVICE?=/dev/cd0
.else
WITH_CDROM_DEVICE?=/dev/acd0
WITH_DVD_DEVICE?=/dev/acd0
.endif

# If you change this value, the dependancy will not be recorded
.if !defined(WITH_VLC_DEFAULT_FONT)
WITH_VLC_DEFAULT_FONT=		${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf
WITH_VLC_DEFAULT_MONO_FONT=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/VeraMono.ttf
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e '\|LIBS|s|-lrt||' \
		-e '/PKG_CONFIG.*lib.*</s|libavcodec <|libavcodec${FFMPEG_SUFFIX} <|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf|${WITH_VLC_DEFAULT_FONT}|' \
		${WRKSRC}/modules/text_renderer/freetype.c
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${WITH_CDROM_DEVICE}|g' \
		-e 's|/dev/dvd|${WITH_DVD_DEVICE}|g' \
		${WRKSRC}/include/vlc_config.h
	${REINPLACE_CMD} -e 's|portaudio\.h|portaudio2/&|g' \
		${WRKSRC}/modules/audio_output/portaudio.c
	${REINPLACE_CMD} -e "s|/usr/share/projectM|${LOCALBASE}/share/projectM|g" \
		-e "s|/usr/share/fonts/truetype/ttf-dejavu/DejaVuSans.ttf|${WITH_VLC_DEFAULT_FONT}|g" \
		-e "s|/usr/share/fonts/truetype/ttf-dejavu/DejaVuSansMono.ttf|${WITH_VLC_DEFAULT_MONO_FONT}|g" \
		${WRKSRC}/modules/visualization/projectm.cpp

pre-configure:
.if ${PORT_OPTIONS:MPLUGIN}
	${REINPLACE_CMD} -e 's|npvlcdir = $$(libdir)/mozilla/plugins|npvlcdir = ${WEBPLUGINS_DIR}|g' \
		${WRKSRC}/projects/mozilla/Makefile.am \
		${WRKSRC}/projects/mozilla/Makefile.in
.endif

pre-install:
	${RM} -rf ${PLIST} ${FAKEDIR}
	${MKDIR} ${FAKEDIR}
	${TOUCH} -f ${PLIST}
	${ECHO_CMD} "share/pixmaps/vlc.png" >> ${PLIST}
	${ECHO_CMD} "share/applications/vlc.desktop" >> ${PLIST}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} prefix=${FAKEDIR}
	${RM} -f ${FAKEDIR}/share/locale/locale.alias
	cd ${FAKEDIR}/bin && ${FIND} -s * | \
		${SED} -e 's|^|bin/|' >> ${PLIST}
	cd ${FAKEDIR}/include && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|include/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrmtry include/|' >> ${PLIST}
.if ${PORT_OPTIONS:MUNSAFE_PLUGINS}
	${RM} -f ${FAKEDIR}/lib/vlc/plugins/services_discovery/libsap_plugin.la
	${RM} -f ${FAKEDIR}/lib/vlc/plugins/services_discovery/libsap_plugin.so
.endif
.if ${PORT_OPTIONS:MPLUGIN}
. for ext in so la
	${ECHO_CMD} "${WEBPLUGINS_DIR}/libvlcplugin.${ext}" | \
		${SED} -e 's|${PREFIX}/||' >> ${PLIST}
. endfor
	${ECHO_CMD} "@dirrmtry ${WEBPLUGINS_DIR}" | \
		${SED} -e 's|${PREFIX}/||' >> ${PLIST}
.endif
	${MKDIR} ${FAKEDIR}/libdata
	${MV} ${FAKEDIR}/lib/pkgconfig ${FAKEDIR}/libdata/pkgconfig
	cd ${FAKEDIR}/lib && ${FIND} -s * -type f -o -type l| \
		${SED} -e 's|^|lib/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrmtry lib/|' >> ${PLIST}
	cd ${FAKEDIR}/libdata && ${FIND} -s * -type f -o -type l| \
		${SED} -e 's|^|libdata/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrmtry libdata/|' >> ${PLIST}
.for dir in icons kde4 vlc
	if [ -d ${FAKEDIR}/share/${dir} ]; then \
	cd ${FAKEDIR}/share/${dir} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/${dir}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrmtry share/${dir}/|' >> ${PLIST} \
		&& ${ECHO_CMD} "@dirrmtry share/${dir}" >> ${PLIST} ; \
	fi
.endfor
.if ${PORT_OPTIONS:MDOCS}
	cd ${FAKEDIR}/share/doc && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/doc/|' >> ${PLIST} \
		 && ${FIND} -d * -type d | \
		 ${SED} -e 's|^|@dirrmtry share/doc/|' >> ${PLIST}
.else
	${RM} -rf ${FAKEDIR}/share/doc
.endif
.if ${PORT_OPTIONS:MNLS}
	cd ${FAKEDIR}/share/locale && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/locale/|' >> ${PLIST}
.for locale in ach an az cgg bn_IN ckb co ff fur gd ia kk km kmr kn ky lg my oc or_IN ps tet tl zu
	${ECHO_CMD} "@dirrmtry share/locale/${locale}/LC_MESSAGES" >> ${PLIST}
	${ECHO_CMD} "@dirrmtry share/locale/${locale}" >> ${PLIST}
.endfor
.endif

do-install:
	cd ${FAKEDIR}/bin && ${FIND} . | \
		${CPIO} -vpdm -R ${BINOWN}:${BINGRP} ${PREFIX}/bin
	cd ${FAKEDIR}/include && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include
	cd ${FAKEDIR}/lib && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib
	${INSTALL_DATA} ${FAKEDIR}/share/icons/hicolor/48x48/apps/vlc.png \
		${PREFIX}/share/pixmaps/vlc.png
	if [ -d ${FAKEDIR}/libdata ]; then \
	cd ${FAKEDIR}/libdata && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/libdata ; \
	fi
	cd ${FAKEDIR}/share && ${FIND} . | \
		${CPIO} -vpdm -L -R ${SHAREOWN} ${PREFIX}/share
	${INSTALL_MAN} ${WRKSRC}/doc/vlc.1 ${MANPREFIX}/man/man1/
	if [ ! -d ${PREFIX}/share/applications ]; then \
		${MKDIR} ${PREFIX}/share/applications ; \
	fi

.include <bsd.port.post.mk>
