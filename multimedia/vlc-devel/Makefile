# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#
# NOTES about VLC Knobs:
# Below you will see a number of knobs, if it starts with WITHOUT_ it is
# enabled by default, if it starts with WITH_ it is disabled by default
# and will be autodetected to enable
#
# If you define for example WITH_FAAD and WITHOUT_FAAD
# the WITHOUT_ will always over ride the WITH_.
#
# Interface Knobs:
#
# WITH_CORBA
#  Enable a Corba interface via orbit2
#
# WITH_NCURSES=yes
#  Ncurses (console) interface
#
# WITH_SKINS
#  This Interface supports a skinned gtk2.0 interface
#  Skins can be found at http://www.videolan.org/vlc/download-skins.html
#
# WITHOUT_WXGTK=yes
#  WxWindows/Gtk 2.x Interface
#  This is the default and most supported
#  x11 interface
#
# WITH_WXGTK_VER=[2.4|2.6]
#  Choose a WxGTK version you want to use.
#  Defaults to 26
#
# Audio Knobs:
#
# WITH_ARTS=yes
#  Arts Support
#
# WITH_DAAP=yes
#  Enable libopendaap to connect to iTunes(R) music shares.
#
# WITHOUT_DTS=yes
#  DTS decoder Support
#  useful for many dvds
#
# WITH_ESOUND=yes
#  Esound Support
#
# WITH_FAAC=yes
#  Faac audio encoder (mp4/aac) Support
#  ** Only enable this if you compiled multimedia/ffmpeg-devel with WITH_FAAC knob **
#
# WITH_FAAD=yes
#  Faad audio decoder (mp4/aac) Support
#
# WITHOUT_FLAC=yes
#  Flac Support
#
# WITHOUT_LAME=yes
#  Mp3 encoder Support
#   ** NOT DEFINED if PACKAGE_BUILDING is defined **
#
# WITHOUT_LIBA52=yes
#  liba52 audio Support
#
# WITH_LIBTREMOR
#  Interger-only Ogg Vorbis decoder
#   !!experimental!!
#
# WITHOUT_MAD=yes
#  Mad mp3 audio decoder Support
#
# WITHOUT_OGG=yes
#  Ogg audio decoder Support
#
# WITH_SPEEX=yes
#  Speex voice codec Support
#
# WITH_TOOLAME=yes
#  Toolame Support
#
# WITH_TWOLAME=yes
#  Twolame Mpeg layer 2 audio Support
#
# WITHOUT_VORBIS=yes
#  Vorbis Support
#
# Graphics Knobs:
#
# WITH_AALIB=yes
#  Console Graphics Support
#
# WITH_FRIBIDI=yes
#
# WITH_GGI=yes
#
# WITH_LIBCACA=yes
#  Console Graphics Support (implies WITH_AALIB)
#
# WITH_SDL=yes
#  SDL video output
#
# WITH_SVG=yes
#
# WITH_SVGALIB=yes
#  SVGAlib video output
#
# WITH_XOSD=yes
#
# Multimedia Knobs:
#
# WITH_DIRAC
#  Enable dirac general-purpose video codec
#
# WITH_X264
#  Enable H.264/AVC Video Support
#
# WITHOUT_LIBMATROSKA=yes
#  Matroska Container Format Support
#
# WITHOUT_LIBMPEG2=yes
#  Mpeg-2 A/V Decoder Support
#
# WITH_LIBTHEORA=yes
#  Video codec for OGG/Vorbis Support
#
# WITH_TRANSCODE=yes
#  Disable transcode of multimedia via transcode (multimedia/transcode).
#  This option allows you to convert a media file, dvd, A/V stream, etc
#  in to another format. This also allows you to transcode multimedia
#  on-the-fly and stream to a network and/or local playback.
#
# Streaming Knobs:
#
# WITHOUT_HTTPD=yes
#  Web interface to control streaming media
#
# WITHOUT_LIVEMEDIA=yes
#  Support for rstp/rtp/sdp protocols
#  Only versions 2004.11.11 and higher are supported.
#
# WITHOUT_STREAM_PLUGINS=yes
#  Disable build and install of Streaming plugins
#
# Other Knobs:
#
# DEBUG=yes
#  Enable debuging support
#
# WITHOUT_CDROM=yes
#  Disable cddb and vcd support
#   and other cdrom support
#
# WITHOUT_CDPARANOIA=yes
#  Disable Cdparanoia support
#
# WITHOUT_DVBPSI=yes
#  TS MUX and DEMUX support
#
# WITHOUT_DVDNAV=yes
#  Disable DVD (dvd menus) support
#
# WITH_DVDREAD=yes
#  Enable Regular DVD support (non-menu)
#
# WITH_MOZILLA=	[mozilla|mozilla-devel|firefox]
# WITH_MOZILLA_PLUGIN= yes
#  Enable A mozilla plugin for VLC
#  See http://www.videolan.org/doc/vlc-user-guide/en/ch07.html#id2529837
#  for more info on using this plugin.
#   defaults to www/mozilla
#
# WITH_OPENGL=yes
#  Enable OpenGL visual plugin (not playback, play back is default with X11)
#
# WITH_SMB=yes
#  Enable SAMBA Access module
#
# WITH_SSL=yes
#  Enable TLS/SSL Support for web (httpd) interface
#
# WITHOUT_SLP=yes
#  Disable SLP service discovery support
#  * recommended if you want to stream media
#
# WITH_OPTIMIZED_CFLAGS=yes
#  Compile with -O2 -ffast-math -fomit-frame-pointer
#
# WITH_DVD_DEVICE=/dev/somedevice
#  default 5.x and above: /dev/acd0
#  default 4.x and below: /dev/acd0c
#  This option changes the default dvd device
#
# WITH_CDROM_DEVICE=/dev/somedevice
#  default 5.x and above: /dev/acd0
#  default 4.x and below: /dev/acd0c
#  This option changes the default cdrom device
#
# WITHOUT_NLS=yes
#  Disable Languarge Support
#
# WITHOUT_STREAM_PLUGINS=yes
#  Disable ALL streaming plugins.
#
# WITH_VLC_DEFAULT_FONT=/path/to/font
#  default: ${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf
#  This option lets you change the default font for subtitles
#
# NOPORTDOCS=yes
#  Do not install Vlc's Documents
#

PORTNAME=	vlc
DISTVERSION=	0.8.2-test1
PORTREVISION=	1
CATEGORIES=	multimedia audio ipv6 net www
MASTER_SITES=	http://download2.videolan.org/pub/videolan/testing/${PORTNAME}-${DISTVERSION}/ \
		${MASTER_SITE_LOCAL:S|$|:mozilla|} \
		http://people.freebsd.org/~ahze/distfiles/:mozilla
#		http://download.videolan.org/pub/videolan/vlc/${PORTVERSION}/ \
#		http://ftp.snt.utwente.nl/pub/software/videolan/vlc/${PORTVERSION}/ \
#		ftp://ftp.crans.org/pub/videolan/vlc/${PORTVERSION}/ \
#		ftp://videolan.cs.pu.edu.tw/Windows/VideoLAN/vlc/${PORTVERSION}/ \
MASTER_SITE_SUBDIR=	ahze/:mozilla
PKGNAMESUFFIX?=	-devel${ESOUND_SUFFIX}${MOZILLA_SUFFIX}${PKGNAMESUFFIX2}
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		vlc-intf-mozilla-plugin-0.1${EXTRACT_SUFX}:mozilla

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Multimedia streaming server and player for various audio/video formats

RUN_DEPEDNS=	${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera
LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg

CONFLICTS=	vlc-*-0.8.1*

#WRKSRC=		${WRKDIR}/${PORTNAME}-snapshot-${PORTVERSION:S/0.8.1.//}
### BROKEN -- Needs newer verision of toolame ###
WITHOUT_TOOLAME=	yes
### BROKEN ###

WITH_VLC_DEFAULT_FONT?=	${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget libxml2
USE_REINPLACE=	yes
WANT_SDL=	yes
USE_XLIB=	yes
USE_ICONV=	yes

FAKEDIR=	${WRKDIR}/fake
PLIST=		${WRKDIR}/plist

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${WRKSRC}/include/vlc/ -I${LOCALBASE}/ffmpeg ${CPPFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"

CONFIGURE_ARGS+=	--enable-ffmpeg \
			--with-ffmpeg=${LOCALBASE} \
			--with-ffmpeg-zlib \
			--disable-gnome \
			--disable-gtk \
			--without-libintl-prefix

MAN1=		vlc.1 \
		vlc-config.1

.if defined(WITH_MOZILLA_PLUGIN) && !defined(WITHOUT_MOZILLA_PLUGIN)
.if ${WITH_MOZILLA}=="firefox"
BUILD_DEPENDS+=	${X11BASE}/libdata/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox
RUN_DEPENDS+=	${X11BASE}/libdata/pkgconfig/firefox-plugin.pc:${PORTSDIR}/www/firefox

CONFIGURE_ENV+=	MOZILLA_CONFIG="${X11BASE}/bin/firefox-config"
.else
BUILD_DEPENDS+=	${X11BASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}
RUN_DEPENDS+=	${X11BASE}/libdata/pkgconfig/mozilla-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/mozilla${HEADERS_SUFX}

CONFIGURE_ENV+=	MOZILLA_CONFIG="${X11BASE}/lib/mozilla${HEADERS_SUFX}/mozilla-config"
.endif
MOZILLA_SUFFIX=-mozilla
CONFIGURE_ARGS+=--enable-mozilla
.if ${WITH_MOZILLA}=="mozilla-devel"
HEADERS_SUFX=	-devel
.else
HEADERS_SUFX=
.endif
.endif

.if defined(WITH_WXGTK_VER) && ${WITH_WXGTK_VER}=="2.4"
WX_CONFIG=	wxgtk2-2.4-config
WXGTK2_PORT=	wxgtk24
.else
WX_CONFIG=	wxgtk2-2.6-config
WXGTK2_PORT=	wxgtk26
CPPFLAGS+=	-I${X11BASE}/include/wx-2.6/
.endif

OPTIONS=	AALIB "Console graphics support" Off \
		ARTS "Arts audio support" Off \
		CDROM "Cddb and vcd support" On \
		CORBA "Corba interface via orbit2" Off \
		DAAP "iTunes(R) music shares support" Off \
		DIRAC "Dirac audio/video codec" Off \
		DTS "DTS audio decoder support" On \
		DVBPSI "TS MUX and DEMUX support" On \
		DVDNAV "DVD (dvd menus) support" On \
		DVDREAD "Regular dvd support (no menus)" Off \
		ESOUND "Esound audio support" Off \
		FAAC "Faac audio encoder (mp4/aac) support" Off \
		FAAD "Faad audio decoder (mp4/aac) support" On \
		FLAC "Flac audio codec support" On \
		HTTPD "Web Interface to control streaming media" On \
		LAME "Mp3 encoder support" On \
		LIBA52 "Liba52 (dolby) audio decoder support" On \
		LIBCACA "Console graphics support" Off \
		LIBMATROSKA "Matroska container format support" On \
		LIBMPEG2 "Mpeg-2 A/V decoder support" On \
		LIBTHEORA "OGG/Vorbis video codec support" Off \
		LIVEMEDIA "Support for rstp/rtp/sdp protocols" On \
		MAD "Mp3 decoder support" On \
		MOZILLA_PLUGIN "Enable mozilla plugin" Off \
		NCURSES "Ncurses (console) interface" Off \
		OGG "Ogg audio decoder support" On \
		OPENGL "OpenGL visual plugin" Off \
		OPTIMIZED_CFLAGS "Complie with -O2 -ffast-math" Off \
		SMB "SAMBA Access module" Off \
		SDL "SDL video output support" Off \
		SKINS "Skinned gtk2.0 interface" Off \
		SLP "SLP service discovery support" On \
		SPEEX "Voice codec support" Off \
		SSL "TLS/SSL support for httpd interface" Off \
		SVG "SVG graphics support" Off \
		SVGALIB "SVGAlib video out support" On \
		TRANSCODE "Depends on multimedia/transcode" Off \
		TWOLAME "Twolame Mpeg layer 2 audio Support" Off \
		VORBIS "Vorbis support (implies WITH_OGG)" On \
		X264 "H.264 AVC video codec" Off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000 && defined(WITH_MOZILLA_PLUGIN) && !defined(WITHOUT_MOZILLA_PLUGIN)
.if ${WITH_MOZILLA}=="mozilla-devel"
USE_GCC=	3.4
WITHOUT_LIVEMEDIA=	yes
.endif
.endif

.if ${HAVE_GNOME:Mesound}!="" && !defined(WITHOUT_ESOUND)
WITH_ESOUND=	yes
.endif

.if exists(${LOCALBASE}/lib/libaa.so.1) && !defined(WITHOUT_AALIB)
WITH_AALIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libcaca.a)
WITH_LIBCACA=	yes
WITH_AALIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libopendaap.a) && !defined(WITHOUT_DAAP)
WITH_DAAP=	yes
.endif

.if exists(${LOCALBASE}/lib/libdirac_decoder.a) && !defined(WITHOUT_DIRAC)
WITH_DIRAC=	yes
.endif

.if exists(${LOCALBASE}/lib/libfaad.a) && !defined(WITHOUT_FAAD)
WITH_FAAD=	yes
.endif

.if exists(${LOCALBASE}/bin/fribidi-config) && !defined(WITHOUT_FRIBIDI)
WITH_FRIBIDI=	yes
.endif

.if exists(${LOCALBASE}/lib/libggi.a) && !defined(WITHOUT_GGI)
WITH_GGI=	yes
.endif

.if exists(${LOCALBASE}/lib/libx264.a) && !defined(WITHOUT_X264)
WITH_X264=	yes
.endif

.if exists(${LOCALBASE}/lib/libmp3lame.a) && !defined(WITHOUT_LAME)
WITH_LAME=	yes
.endif

.if exists(${LOCALBASE}/lib/libtheora.a) && !defined(WITHOUT_LIBTHEORA)
WITH_LIBTHEORA=	yes
.endif

.if exists(${LOCALBASE}/lib/lib/libsmbclient.a) && !defined(WITHOUT_SMB)
WITH_SMB=	yes
.endif

.if exists(${LOCALBASE}/lib/libspeex.a) && !defined(WITHOUT_SPEEX)
WITH_SPEEX=	yes
.endif

.if  exists(${LOCALBASE}/lib/libgnutls.a) && !defined(WITHOUT_SSL)
WITH_SSL=	yes
.endif

.if exists(${X11BASE}/lib/librsvg-2.a) && !defined(WITHOUT_SVG)
WITH_SVG=	yes
.endif

.if exists(${LOCALBASE}/lib/lib/vga.a) && !defined(WITHOUT_SVGALIB)
WITH_SVGALIB=	yes
.endif

.if exists(${LOCALBASE}/bin/transcode)
WITH_TRANSCODE=	yes
.endif

.if exists(${LOCALBASE}/lib/libvorbisidec.a)
WITH_LIBTREMOR=	yes
.endif

.if exists(${LOCALBASE}/bin/toolame)
WITH_TOOLAME=	yes
.endif

.if exists(${LOCALBASE}/lib/libtwolame.a) && !defined(WITHOUT_TWOLAME)
WITH_TWOLAME=	yes
.endif

.if exists(${LOCALBASE}/lib/libxosd.a) && !defined(WITHOUT_XOSD)
WITH_XOSD=	yes
.endif

# compatible knobs.
.if defined(WITH_DEBUG)
DEBUG=	yes
.endif

.if defined(WITH_MATROSKA)
WITH_LIBMATROSKA=yes
.endif

.if defined(WITH_TREMOR)
WITH_LIBTREMOR=yes
.endif
# end compatible knobs

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
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

.if defined(WITH_SKINS) && !defined(WITHOUT_SKINS)
BUILD_DEPENDS+=	${WX_CONFIG}:${PORTSDIR}/x11-toolkits/${WXGTK2_PORT} \
		libtar:${PORTSDIR}/devel/libtar
RUN_DEPENDS+=	${WX_CONFIG}:${PORTSDIR}/x11-toolkits/${WXGTK2_PORT}
CONFIGURE_ARGS+=--enable-skins2 --enable-skins
CONFIGURE_ENV+=	WX_CONFIG="${X11BASE}/bin/${WX_CONFIG}"
.else
CONFIGURE_ARGS+=--disable-skins2
.endif

.if !defined(WITHOUT_WXGTK)
BUILD_DEPENDS+=	${WX_CONFIG}:${PORTSDIR}/x11-toolkits/${WXGTK2_PORT}
RUN_DEPENDS+=	${WX_CONFIG}:${PORTSDIR}/x11-toolkits/${WXGTK2_PORT}
CONFIGURE_ARGS+=--enable-wxwindows
CONFIGURE_ENV+=	WX_CONFIG="${X11BASE}/bin/${WX_CONFIG}"
.else
CONFIGURE_ARGS+=--disable-wxwindows
.endif

.if defined(WITH_ARTS) && !defined(WITHOUT_ARTS)
LIB_DEPENDS+=	 artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--enable-arts
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if !defined(WITHOUT_CDROM)
LIB_DEPENDS+=	vcdinfo.1:${PORTSDIR}/multimedia/vcdimager \
		cdio.5:${PORTSDIR}/sysutils/libcdio
CONFIGURE_ARGS+=--enable-vcd \
		--enable-libcddb \
		--enable-libcdio \
		--enable-cddax
.else
CONFIGURE_ARGS+=--disable-vcd \
		--disable-libcddb \
		--disable-libcdio \
		--disable-cddax
.endif

.if !defined(WITHOUT_CDPARANOIA) && !defined(WITHOUT_CDROM)
LIB_DEPENDS+=	cdda_interface.0:${PORTSDIR}/audio/cdparanoia
CONFIGURE_ARGS+=--enable-cdda \
		--enable-cddax
.else
CONFIGURE_ARGS+=--disable-cdda \
		--disable-cddax
.endif

.if defined(WITH_CORBA) && !defined(WITHOUT_CORBA)
USE_GNOME+=	orbit2
CONFIGURE_ARGS+=--enable-corba
.else
CONFIGURE_ARGS+=--disable-corba
.endif

.if !defined(WITHOUT_DVBPSI)
LIB_DEPENDS+=	dvbpsi.3:${PORTSDIR}/multimedia/libdvbpsi
CONFIGURE_ARGS+=--enable-dvbpsi \
		--with-dvbpsi=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-dvbpsi
.endif

.if !defined(WITHOUT_DVDNAV)
LIB_DEPENDS+=	dvdnav.3:${PORTSDIR}/multimedia/libdvdnav
CONFIGURE_ARGS+=--enable-dvdnav
.else
CONFIGURE_ARGS+=--disable-dvdnav
.endif

.if defined(WITH_DVDREAD) && !defined(WITHOUT_DVDREAD)
LIB_DEPENDS+=	dvdread.3:${PORTSDIR}/multimedia/libdvdread
CONFIGURE_ARGS+=--enable-dvdread
.else
CONFIGURE_ARGS+=--disable-dvdread
.endif

.if defined(WITH_ESOUND) && !defined(WITHOUT_ESOUND)
ESOUND_SUFFIX=	-esound
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
.else
CONFIGURE_ARGS+=--disable-esd
.endif

.if defined(WITH_FAAC) && !defined(WITHOUT_FAAC)
CONFIGURE_ARGS+=--with-ffmpeg-faac
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
.endif

.if defined(WITH_FAAD) && !defined(WITHOUT_FAAD)
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
CONFIGURE_ARGS+=--enable-faad
.else
CONFIGURE_ARGS+=--disable-faad
.endif

.if !defined(WITHOUT_FLAC)
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--enable-flac
.else
CONFLGIRE_ARGS+=--disable-flac
.endif

.if defined(WITH_FRIBIDI) && !defined(WITHOUT_FRIBIDI)
LIB_DEPENDS+=	fribidi.0:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=--enable-fribidi
.else
CONFIGURE_ARGS+=--disable-fribidi
.endif

.if defined(WITH_AALIB) && !defined(WITHOUT_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
CONFIGURE_ARGS+=--enable-aa
.else
CONFIGURE_ARGS+=--disable-aa
.endif

.if defined(WITH_DIRAC) && !defined(WITHOUT_DIRAC)
LIB_DEPENDS+=	dirac_encoder.0:${PORTSDIR}/multimedia/dirac
CONFIGURE_ARGS+=--enable-dirac
CPPFLAGS+=	-I${LOCALBASE}/include/dirac
.else
CONFIGURE_ARGS+=--disable-dirac
.endif

.if (defined(WITH_H264) || defined(WITH_X264)) && !defined(WITHOUT_X264)
CONFIGURE_ARGS+=--enable-x264
LIB_DEPENDS+=	x264.1:${PORTSDIR}/multimedia/x264
.else
CONFIGURE_ARGS+=--disable-x264
.endif

.if defined(WITH_LIBCACA) && !defined(WITHOUT_LIBCACA)
.if !defined(WITHOUT_AALIB)
WITH_AALIB=	yes
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcaca.a:${PORTSDIR}/graphics/libcaca
RUN_DEPENDS+=	${LOCALBASE}/lib/libcaca.a:${PORTSDIR}/graphics/libcaca

CONFIGURE_ARGS+=--enable-caca
.endif
.else
CONFIGURE_ARGS+=--disable-caca
.endif

.if defined(WITH_DAAP) && !defined(WITHOUT_DAAP)
LIB_DEPENDS+=	opendaap.0:${PORTSDIR}/devel/libopendaap
CONFIGURE_ARGS+=--enable-daap
.else
CONFIGURE_ARGS+=--disable-daap
.endif

.if !defined(WITHOUT_DTS)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdts.a:${PORTSDIR}/multimedia/libdts
CONFIGURE_ARGS+=--enable-dts
.else
CONFIGURE_ARGS+=--disable-dts
.endif

.if defined(WITHOUT_HTTPD)
CONFIGURE_ARGS+=--disable-httpd
.endif

.if defined(WITH_GGI) && !defined(WITHOUT_GGI)
LIB_DEPENDS+=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--enable-ggi
.else
CONFIGURE_ARGS+=--disable-ggi
.endif

# Do not use lame if PACKAGE_BUILDING is defined. since
# lame can NOT be packaged.
.if !defined(WITHOUT_LAME) && !defined(PACKAGE_BUILDING)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=--enable-mp3lame
.else
CONFIGURE_ARGS+=--disable-mp3lame
.endif

.if !defined(WITHOUT_LIBMATROSKA)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmatroska.a:${PORTSDIR}/multimedia/libmatroska
CONFIGURE_ARGS+=--enable-mkv
.else
CONFIGURE_ARGS+=--disable-mkv
.endif

.if !defined(WITHOUT_LIBA52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
CONFIGURE_ARGS+=--enable-a52
.else
CONFIGURE_ARGS+=--disable-a52
.endif

.if !defined(WITHOUT_LIBMPEG2)
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
CONFIGURE_ARGS+=--enable-libmpeg2
.else
CONFIGURE_ARGS+=--disable-libmpeg2
.endif

.if defined(WITH_LIBTHEORA) && !defined(WITHOUT_LIBTHEORA)
LIB_DEPENDS+=	theora.1:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=--enable-theora
.else
CONFIGURE_ARGS+=--disable-theora
.endif

.if !defined(WITHOUT_LIVEMEDIA)
BUILD_DEPENDS+=	${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
CONFIGURE_ARGS+=--enable-livedotcom \
		--with-livedotcom-tree=${LOCALBASE}/live
.else
CONFIGURE_ARGS+=--disable-livedotcom
.endif

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	id3tag.2:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--enable-mad \
		--with-mad=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if !defined(WITHOUT_OGG)
LIB_DEPENDS+=	ogg.5:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=--enable-ogg
.else
CONFIGURE_ARGS+=--disable-ogg
WITHOUT_VORBIS=	yes
.endif

.if defined(WITH_NCURSES) && !defined(WITHOUT_NCURSES)
CONFIGURE_ARGS+=--enable-ncurses
.endif

.if defined(WITH_OPENGL) && !defined(WITHOUT_OPENGL)
USE_GL=	yes
CONFIGURE_ARGS+=--enable-galaktos
.else
CONFIGURE_ARGS+=--disable-galaktos
.endif

.if defined(WITH_SMB) && !defined(WITHOUT_SMB)
LIB_DEPEND+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
CONFIGURE_ARGS+=--enable-smb
.else
CONFIGURE_ARGS+=--disable-smb
.endif

.if defined(WITH_SDL) && !defined(WITHOUT_SDL)
USE_SDL=	yes
CONFIGURE_ARGS+=--enable-sdl
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

.if defined(WITH_TRANSCODE)
RUN_DEPENDS+=	transcode:${PORTSDIR}/multimedia/transcode
.endif

.if !defined(WITHOUT_HTTPD) && defined(WITH_SSL)
LIB_DEPENDS+=	gnutls.12:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--enable-gnutls
.else
CONFIGURE_ARGS+=--disable-gnutls
.endif

.if !defined(WITHOUT_SLP)
LIB_DEPENDS+=	slp.1:${PORTSDIR}/net/openslp
.else
CONFIGURE_ARGS+=--disable-slp
.endif

.if defined(WITH_SPEEX) && !defined(WITHOUT_SPEEX)
LIB_DEPENDS+=	speex.3:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=--enable-speex
CPPFLAGS+=-I${LOCALBASE}/include/speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if defined(WITHOUT_STREAM_PLUGINS)
CONFIGURE_ARGS+=--disable-sout
.endif

.if defined(WITH_SVG) && !defined(WITHOUT_SVG)
USE_GNOME+=	librsvg2
CONFIGURE_ARGS+=--enable-svg
.else
CONFIGURE_AGRS+=--disable-svg
.endif

.if defined(WITH_SVGALIB) && !defined(WITHOUT_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--enable-svgalib
.else
CONFIGURE_ARGS+=--disable-svgalib
.endif

.if defined(WITH_LIBTREMOR) && !defined(WITHOUT_LIBTREMOR)
LIB_DEPENDS+=	vorbisidec.1:${PORTSDIR}/audio/libtremor
.else
CONFIGURE_ARGS+=--disable-tremor
.endif

.if defined(WITH_TOOLAME) && !defined(WITHOUT_TOOLAME)
BUILD_DEPENDS+=		toolame:${PORTSDIR}/audio/toolame
RUN_DEPEDNS+=		toolame:${PORTSDIR}/audio/toolame
CONFIGURE_ARGS+=	--enable-toolame
.else
CONFIGURE_ARGS+=	--disable-toolame
.endif

.if defined(WITH_TWOLAME) && !defined(WITHOUT_TWOLAME)
LIB_DEPENDS+=		twolame.0:${PORTSDIR}/audio/twolame
CONFIGURE_ARGS+=	--enable-twolame
.else
CONFIGURE_ARGS+=	--disable-twolame
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if defined(WITH_XOSD) && !defined(WITHOUT_XOSD)
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=--enable-xosd
.else
CONFIGURE_ARGS+=--disable-xosd
.endif

.if defined(DEBUG)
CONFIGURE_AGRS+=--enable-debug
.else
CONFIGURE_ARGS+=--enable-release
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -ffast-math -fomit-frame-pointer
CONFIGURE_ARGS+=--enable-release \
		--enable-optimizations
.else
CONFIGURE_ARGS+=--enable-release
.endif

.if ${OSVERSION} < 500000
CONFIGURE_ENV+=	LIBS="-L/usr/lib -lcipher"
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a careful look at the beginning of the Makefile in order"
	@${ECHO_MSG} "to learn how to tune VLC towards you personal preferences!"
	@${ECHO_MSG} ""

post-patch:
# Subtitle default font
	@${REINPLACE_CMD} -e \
	's|/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf|${WITH_VLC_DEFAULT_FONT}|' \
		${WRKSRC}/modules/misc/freetype.c
# mozilla plugin
.if defined(WITH_MOZILLA_PLUGIN) && !defined(WITHOUT_MOZILLA_PLUGIN)
	@${CP} -f ${WRKDIR}/vlc-intf-mozilla-plugin/vlcintf.h ${WRKSRC}/mozilla
	@${CP} -f ${WRKDIR}/vlc-intf-mozilla-plugin/vlcintf.xpt ${WRKSRC}/mozilla
	@${REINPLACE_CMD} -e 's|$$(libdir)/mozilla/plugins|${FAKEDIR}/mozilla|; \
		s|$$(libdir)/mozilla/components|${FAKEDIR}/mozilla|' \
			${WRKSRC}/mozilla/Makefile.in
.endif
# skins2 interface, no lrint on < 504000
.if ${OSVERSION} < 504000
	@${REINPLACE_CMD} -e 's|lrint|rint|' \
		${WRKSRC}/modules/gui/skins2/controls/ctrl_list.cpp
.endif
# s/Linux/FreeBSD/
	@${REINPLACE_CMD} -e 's|Linux|FreeBSD|' \
		${WRKSRC}/po/*
	@${RM} -f ${WRKSRC}/po/*.bak
	@${REINPLACE_CMD} -e 's|Linux OSS|FreeBSD OSS|' \
		${WRKSRC}/modules/audio_output/oss.c
# pthreads/cflags
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/' \
		-e 's/-lc_r/${PTHREAD_LIBS}/' \
		-e 's|-mcpu=pentiumpro||' \
		-e 's|postproc/postprocess.h|ffmpeg/postproc/postprocess.h|' \
		${WRKSRC}/configure
# cdrom/dvd support
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|; \
		s|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/include/vlc_config.h

pre-install:
	${RM} -rf ${PLIST} ${FAKEDIR}
	${MKDIR} ${FAKEDIR}
	${TOUCH} -f ${PLIST}
.if defined(WITH_SKINS) && !defined(WITHOUT_SKINS)
	${ECHO_CMD} "share/pixmaps/gvlc.png" >> ${PLIST}
	${ECHO_CMD} "share/applications/svlc.desktop" >> ${PLIST}
.endif
.if !defined(WITHOUT_WXGTK)
	${ECHO_CMD} "share/pixmaps/vlc.png" >> ${PLIST}
	${ECHO_CMD} "share/applications/wxvlc.desktop" >> ${PLIST}
.endif
.if defined(WITH_WXGTK) || defined(WITH_SKINS)
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/pixmaps 2>/dev/null || ${TRUE}" >> ${PLIST}
.endif
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} prefix=${FAKEDIR}
	cd ${FAKEDIR}/bin && ${FIND} -s * | \
		${SED} -e 's|^|bin/|' >> ${PLIST}
	cd ${FAKEDIR}/include && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|include/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm include/|' >> ${PLIST}
	cd ${FAKEDIR}/lib && ${FIND} -s * -type f -o -type l| \
		${SED} -e 's|^|lib/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm lib/|' >> ${PLIST}
.for dir in vlc
	cd ${FAKEDIR}/share/${dir} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/${dir}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm share/${dir}/|' >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
	cd ${FAKEDIR}/share/doc && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/doc/|' >> ${PLIST} \
		 && ${FIND} -d * -type d | \
		 ${SED} -e 's|^|@dirrm share/doc/|' >> ${PLIST}
.else
	${RM} -rf ${FAKEDIR}/share/doc
.endif
		${ECHO_MSG} "@dirrm share/vlc" >> ${PLIST}
	cd ${FAKEDIR}/share/locale &&  ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/locale/|' >> ${PLIST}
.if defined(WITH_MOZILLA_PLUGIN)
	cd ${FAKEDIR}/mozilla && ${FIND} -s * | \
		${SED} -e 's|^|lib/browser_plugins/|' >> ${PLIST}
.endif

pre-configure:
	@if [ -n "`${PKG_INFO} -xI '^ffmpeg-0.4.9.p'`" ]; then \
		${ECHO_MSG} ;\
		${ECHO_MSG} "Note: ffmpeg-0.4.9 detected, if you want ffmpeg's postprocess" ;\
		${ECHO_MSG} " features please hit ^C and remove ffmpeg-0.4.9 and" ;\
		${ECHO_MSG} " install multimedia/ffmpeg-devel" ;\
		${ECHO_MSG} ;\
		sleep 2 ;\
	fi

do-install:
	@${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|' \
		${FAKEDIR}/bin/vlc-config
	@${RM} -f ${FAKEDIR}/bin/*.bak
	cd ${FAKEDIR}/bin && ${FIND} . | \
		${CPIO} -vpdm -R ${BINOWN}:${BINGRP} ${PREFIX}/bin
	cd ${FAKEDIR}/include && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include
	cd ${FAKEDIR}/lib && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib
	cd ${FAKEDIR}/share && ${FIND} . | \
		${CPIO} -vpdm -L -R ${SHAREOWN} ${PREFIX}/share
.if defined(WITH_MOZILLA_PLUGIN)
	@${MKDIR} ${PREFIX}/lib/browser_plugins
	${INSTALL_DATA} ${FAKEDIR}/mozilla/* ${PREFIX}/lib/browser_plugins
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/vlc.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/vlc-config.1 ${MANPREFIX}/man/man1/
.if defined(WITH_SKINS) || !defined(WITHOUT_WXGTK)
	if [ ! -d ${PREFIX}/share/applications ]; then \
		${MKDIR} ${PREFIX}/share/applications ; \
	fi
	if [ ! -d ${PREFIX}/share/pixmaps ]; then \
		${MKDIR} ${PREFIX}/share/pixmaps ; \
	fi
.if defined(WITH_SKINS) && !defined(WITHOUT_SKINS)
	${INSTALL_DATA} ${FILESDIR}/svlc.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${FAKEDIR}/share/vlc/gvlc48x48.png ${PREFIX}/share/pixmaps/gvlc.png
.endif
.if !defined(WITHOUT_WXGTK)
	${INSTALL_DATA} ${FILESDIR}/wxvlc.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${FAKEDIR}/share/vlc/vlc48x48.png ${PREFIX}/share/pixmaps/vlc.png
.endif
.endif

.include <bsd.port.post.mk>
