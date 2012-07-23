# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vlc
DISTVERSION=	1.1.13
PORTREVISION=	12
PORTEPOCH=	3
CATEGORIES=	multimedia audio ipv6 net www
MASTER_SITES=	http://download.videolan.org/pub/videolan/${PORTNAME}/${DISTVERSION}/ \
		http://ftp.snt.utwente.nl/pub/software/videolan/${PORTNAME}/${DISTVERSION}/ \
		ftp://ftp.crans.org/pub/videolan/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	Qt4 based multimedia player and streaming server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	avcodec:${PORTSDIR}/multimedia/ffmpeg \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		proxy:${PORTSDIR}/net/libproxy

OPTIONS_DEFINE=	A52 AALIB ASS AVAHI CACA DBUS DIRAC DOCS DTS DVB DVDREAD \
		DVDNAV FAAD FLAC FLUID FRIBIDI GGI GLX GNOMEVFS GNUTLS GOOM \
		HTTPD JACK LIVEMEDIA LUA MAD MATROSKA MODPLUG MPEG2 MTP \
		MUSEPACK NCURSES NLS NOTIFY OPTIMIZED_CFLAGS OGG OPENGL PLUGIN \
		PNG PORTAUDIO PROJM PULSEAUDIO QT4 REALAUDIO REMOTEOSD RUNROOT \
		SAMBA SCHROED SDL SHOUTCAST SKINS STREAM SPEEX SQLITE SVG \
		SVGALIB TAGLIB THEORA TREMOR TWOLAME UPNP V4L VAAPI VCD \
		VORBIS X11 X264 XCB XOSD XVIDEO ZVBI SERVER_ONLY DEBUG \
		UNSAFE_PLUGINS
OPTIONS_DEFAULT=A52 AVAHI DBUS DTS DVB DVDREAD DVDNAV FAAD FLAC GLX GNUTLS \
		HTTPD LIVEMEDIA LUA MAD MATROSKA MPEG2 OGG PNG QT4 REALAUDIO \
		REMOTEOSD SDL SKINS STREAM SPEEX TAGLIB THEORA TWOLAME V4L \
		VCD VORBIS X11 X264 XCB XVIDEO
A52_DESC=	A52 DVD audio decoder
AALIB_DESC=	Aalib Console Graphics Support
ASS_DESC=	ASS/SSA subtitle rendering
CACA_DESC=	libcaca Console Graphics Support
DBUS_DESC=	D-Bus control support
DIRAC_DESC=	Dirac support
DTS_DESC=	DTS DVD audio decoder
DVB_DESC=	Digital Video Broadcasting support
DVDREAD_DESC=	DVD Playback support
DVDNAV_DESC=	DVD menu navigation
FAAD_DESC=	Faad audio decoder (mp4/aac) support
FLAC_DESC=	Flac audio codec support
FLUID_DESC=	Fluidsynth MIDI support
FRIBIDI_DESC=	FriBidi bidirectional unicode support
GGI_DESC=	General Graphic Interface support
GLX_DESC=	X11 OpenGL rendering
GNOMEVFS_DESC=	Gnome VFS support
GOOM_DESC=	the Goom visual effect library
LIVEMEDIA_DESC=	Support for rstp/rtp/sdp protocols
MATROSKA_DESC=	Matroska Container Format support
MPEG2_DESC=	Mpeg-2 audio/video decoder Support
MTP_DESC=	support for the Music Transport Protocol
NCURSES_DESC=	ncurses (console) interface
OGG_DESC=	Ogg audio decoder support
OPENGL_DESC=	OpenGL acceleration support
PLUGIN_DESC=	VLC Mozilla Plugin
PNG_DESC=	PNG graphics format support
PROJM_DESC=	ProjectM visualizations
QT4_DESC=	Qt4 Interface
REALAUDIO_DESC=	Real Audio(R) support
REMOTEOSD_DESC=	Remote OSD support
RUNROOT_DESC=	Enable running as root
SAMBA_DESC=	SAMBA Access module
SCHROED_DESC=	Schroedinger decoder
SKINS_DESC=	winamp skins interface
STREAM_DESC=	stream output
SQLITE_DESC=	SQLite database support
SVGALIB_DESC=	SVGALIB video output
TAGLIB_DESC=	ID3 tag and Ogg comment support
THEORA_DESC=	OGG/Vorbis video codec support
TREMOR_DESC=	Tremor voice audio (redundant with Vorbis)
TWOLAME_DESC=	Twolame mpeg2 audio encoder support
UPNP_DESC=	UPnP network device control
V4L_DESC=	Video4Linux video capture compatibility
VAAPI_DESC=	Support hardware decoding via VAAPI
VCD_DESC=	Video CD support
XCB_DESC=Use X C Bindings for X11 output
XOSD_DESC=X11 On Screen Display support
XVIDEO_DESC=X11 video rendering
ZVBI_DESC=VBI decoding support
SERVER_ONLY_DESC=	Only build server parts
UNSAFE_PLUGINS_DESC=	Install unsafe, unsupported plugins

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5_BUILD=yes
MAKE_JOBS_SAFE=	yes
WANT_GNOME=	yes

FAKEDIR=	${WRKDIR}/fake${PREFIX}
PLIST=		${WRKDIR}/plist

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${FAKEDIR}/include -I${WRKSRC}/include \
		-I${LOCALBASE}/include -I${LOCALBASE}/ffmpeg \
		${PTHREAD_CFLAGS}
CONFIGURE_ENV=	LIBS="-lc"
LDFLAGS+=	-L${FAKEDIR}/lib \
		-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lc

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
			--disable-hd1000a \
			--disable-hd1000v \
			--disable-loader \
			--disable-osso_screensaver \
			--disable-telx \
			--disable-udev \
			--disable-update-check

MAN1=		vlc.1 \
		vlc-config.1 \
		vlc-wrapper.1

.include <bsd.port.options.mk>

# Macro section
# Use these for batch control of certain types of builds

# Disable DVD specific features
.if !${PORT_OPTIONS:MDVD}
WITHOUT_A52=yes
WITHOUT_DTS=yes
WITHOUT_DVDREAD=yes
WITHOUT_DVDNAV=yes
.endif

# Use this to disable all UI and output modules
.if ${PORT_OPTIONS:MSERVER_ONLY}
WITHOUT_LUA=yes
WITHOUT_QT4=yes
WITH_RUNROOT=yes
WITHOUT_XCB=yes
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

.include <bsd.port.pre.mk>

# OS specific hacks
.if (${OSVERSION} < 800040)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules__misc__inhibit__xdg.c \
		${FILESDIR}/extra-patch-modules__misc__inhibit__xscreensaver.c
.endif

.if ${ARCH} == "powerpc64"
CONFIGURE_ARGS+=--enable-altivec # VLC's config script doesn't know to do this
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
WITH_VLC_DEFAULT_FONT=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera
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

.if ${PORT_OPTIONS:MDVB}
.if ${PORT_OPTIONS:MV4L}
LIB_DEPENDS+=	dvbpsi:${PORTSDIR}/multimedia/libdvbpsi
CONFIGURE_ARGS+=--enable-dvb --enable-dvbpsi \
		--with-dvbpsi=${LOCALBASE}
.else
IGNORE=	DVB option requires V4L option
.endif
.else
CONFIGURE_ARGS+=--disable-dvb --disable-dvbpsi
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

.if ${PORT_OPTIONS:MGGI}
LIB_DEPENDS+=	ggi:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--enable-ggi
.else
CONFIGURE_ARGS+=--disable-ggi
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

.if ${PORT_OPTIONS:MGNOMEVFS}
USE_GNOME=	gnomevfs2
CONFIGURE_ARGS+=--enable-gnomevfs
.else
COFIGURE_ARGS+=--disable-gnomevfs
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

.if ${PORT_OPTIONS:MLIVEMEDIA}
BUILD_DEPENDS+=	${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
CONFIGURE_ARGS+=--enable-live555 \
		--with-live555-tree=${LOCALBASE}/live
.else
CONFIGURE_ARGS+=--disable-live555
.endif

# This may become mandantory in the future
.if ${PORT_OPTIONS:MLUA}
USE_LUA=5.1+
WANT_LUA_VER=5.1
CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
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
CONFIGURE_ARGS+=--enable-ncurses
.else
CONFIGURE_ARGS+=--disable-ncurses
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
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
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=--enable-ogg
.else
WITHOUT_VORBIS=	yes
CONFIGURE_ARGS+=--disable-ogg
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=yes
CONFIGURE_ARGS+=--enable-opengl
.else
CONFIGURE_ARGS+=--disable-opengl
.endif

.if ${PORT_OPTIONS:MPLUGIN}
USE_GECKO=	libxul
USE_WEBPLUGINS=	gecko*
WEBPLUGINS_FILES=libvlcplugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
CONFIGURE_ARGS+=--enable-mozilla	\
		--with-mozilla-pkg=${LOCALBASE}/libdata/pkgconfig/mozilla-plugin.pc
.else
CONFIGURE_ARGS+=--disable-mozilla
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--enable-png
.else
CONFIGURE_ARGS+=--disable-png
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
LIB_DEPENDS+=	portaudio:${PORTSDIR}/audio/portaudio2
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
CONFIGURE_ARGS+=--disable-pulse
.endif

# WITHOUT_QT4
# Before .include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MREALAUDIO}
CONFIGURE_ARGS+=--enable-real --enable-realrtsp
.else
CONFIGURE_ARGS+=--disable-real --disable-realrtsp
.endif

.if ${PORT_OPTIONS:MREMOTEOSD}
CONFIGURE_ARGS+=--enable-remoteosd
.else
CONFIGURE_ARGS+=--disable-remoteosd
.endif

.if ${PORT_OPTIONS:MRUNROOT}
CONFIGURE_ARGS+=--enable-run-as-root
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

.if ${PORT_OPTIONS:MSVGALIB}
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--enable-svgalib
.else
CONFIGURE_ARGS+=--disable-svgalib
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

.if ${PORT_OPTIONS:MTREMOR} && !${PORT_OPTIONS:MVORBIS}
# Tremor is integer based Vorbis subset, using both is redundant
LIB_DEPENDS+=	vorbisidec:${PORTSDIR}/audio/libtremor
.else
CONFIGURE_ARGS+=--disable-tremor
.endif

.if ${PORT_OPTIONS:MTWOLAME}
LIB_DEPENDS+=		twolame:${PORTSDIR}/audio/twolame
CONFIGURE_ARGS+=	--enable-twolame
.else
CONFIGURE_ARGS+=	--disable-twolame
.endif

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	upnp:${PORTSDIR}/devel/upnp
CONFIGURE_ARGS+=--enable-upnp
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules__services_discovery__upnp_intel.cpp
.else
CONFIGURE_ARGS+=--disable-upnp
.endif

.if ${PORT_OPTIONS:MV4L} || ${PORT_OPTIONS:MDVB}
LIB_DEPENDS+=	v4l1:${PORTSDIR}/multimedia/libv4l
CONFIGURE_ARGS+=--enable-v4l --enable-v4l2
.else
CONFIGURE_ARGS+=--disable-v4l --disable-v4l2
.endif

.if ${PORT_OPTIONS:MVAAPI}
LIB_DEPENDS+=	va:${PORTSDIR}/multimedia/libva
CONFIGURE_ARGS+=--enable-libva
.else
CONFIGURE_ARGS+=--disable-libva
.endif

.if ${PORT_OPTIONS:MVCD}
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
USE_XORG=	xpm
LIB_DEPENDS+=	xcb:${PORTSDIR}/x11/libxcb \
		xcb-keysyms:${PORTSDIR}/x11/xcb-util-keysyms
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

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e '\|LIBS|s|-lrt||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf|${WITH_VLC_DEFAULT_FONT}|' \
		${WRKSRC}/modules/misc/freetype.c
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${WITH_CDROM_DEVICE}|g' \
		-e 's|/dev/dvd|${WITH_DVD_DEVICE}|g' \
		${WRKSRC}/include/vlc_config.h
	${REINPLACE_CMD} -e 's|portaudio\.h|portaudio2/&|g' \
		${WRKSRC}/modules/audio_output/portaudio.c

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
	${ECHO_CMD} "@dirrmtry share/applications" >> ${PLIST}
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
.endif
.for locale in ach cgg ckb co ff fur kk km lg my oc ps tet tl zu
	${ECHO_CMD} "@dirrmtry share/locale/${locale}/LC_MESSAGES" >> ${PLIST}
	${ECHO_CMD} "@dirrmtry share/locale/${locale}" >> ${PLIST}
.endfor

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
	${INSTALL_MAN} ${WRKSRC}/doc/vlc-config.1 ${MANPREFIX}/man/man1/
	if [ ! -d ${PREFIX}/share/applications ]; then \
		${MKDIR} ${PREFIX}/share/applications ; \
	fi

.include <bsd.port.post.mk>
