# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/multimedia/vlc/Makefile,v 1.6 2009/01/09 23:41:21 mezz Exp $
#      $Id: Makefile 6 2006-09-27 14:05:34Z buhnux $
# *** PLEASE READ Makefile.inc for more information on knobs ***
#

PORTNAME=	vlc
DISTVERSION=	1.0.0
PORTREVISION=	3
PORTEPOCH=	3
CATEGORIES=	multimedia audio ipv6 net www
MASTER_SITES=	http://download.videolan.org/pub/videolan/${PORTNAME}/${DISTVERSION}/ \
		http://ftp.snt.utwente.nl/pub/software/videolan/${PORTNAME}/${DISTVERSION}/ \
		ftp://ftp.crans.org/pub/videolan/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	jsa@wickedmachine.net
COMMENT=	Multimedia streaming server and player for various audio/video formats

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat \
		${LOCALBASE}/include/X11/xpm.h:${PORTSDIR}/x11/libXpm
LIB_DEPENDS=	tar.0:${PORTSDIR}/devel/libtar \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera

OPTIONS=	A52 "a52 audio support, many DVDs use this" On \
		AALIB "Aalib Console Graphics Support" Off \
		ARTS "Enable arts sound support" Off \
		AVAHI "Avahi (Rendezvous/Bonjour (R) ) networking" On \
		CACA "Libcaca Console Graphics Support" Off \
		DBUS "Enable D-Bus control support" On \
		DEBUG "Enable debuging support" Off \
		DTS "DTS decoder support, many DVDs use this" On \
		ESOUND "Esound Support" Off \
		FAAC "Faac audio encoder (mp4/aac) support" Off \
		FAAD "Faad audio decoder (mp4/aac) support" On \
		FLAC "Flac audio codec support" On \
		GNOMEVFS "Gnome VFS support" On \
		HTTPD "Streaming media control via http" On \
		LIVEMEDIA "Support for rstp/rtp/sdp protocols" On \
		LUA "Enable lua scripting" Off \
		MAD "Mad mp3 audio decoder support" On \
		MATROSKA "Matroska Container Format support" On \
		MPEG2 "Mpeg-2 audio/video decoder Support" On \
		NCURSES "Enable ncurses (console) interface" Off \
		OGG "Ogg audio decoder support" On \
		QT4 "QT4 Interface (requires X11)" On \
		REALAUDIO "Real audio(R) support" On \
		SAMBA "SAMBA Access module" On \
		SDL "SDL video output" On \
		SVG "SVG graphics support" Off \
		SVGALIB "SVGALIB video output" Off \
		SHOUT "Shout2 support" Off \
		SKINS "Enable winamp skins interface (requires QT4)" On \
		SPEEX "Speex voice codec support" On \
		THEORA "OGG/Vorbis video codec support" On \
		TWOLAME "Twolame mpeg2 audio encoder support" On \
		V4L "Enable Video for Linux" On \
		VORBIS "Vorbis support" On \
		WIN32_CODECS "win32 multimedia DLL's" Off \
		X264 "Enable H.264/AVC codec support" On \
		X11 "Enable X11 (disable for stream only server)" On

USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnometarget libxml2
WANT_SDL=	yes
USE_ICONV=	yes
USE_PERL5_BUILD=yes

FAKEDIR=	${WRKDIR}/fake/${PREFIX}
PLIST=		${WRKDIR}/plist

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${FAKEDIR}/include -I${WRKSRC}/include ${CPPFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/ffmpeg ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${FAKEDIR}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS} -lc" \
		LIBS="-lc"

CONFIGURE_ARGS+=	--enable-vlc \
			--enable-release \
			--enable-avcodec \
			--enable-avformat \
			--enable-postproc \
			--without-dv-raw1394 \
			--disable-dv \
			--disable-galaktos

MAN1=		vlc.1 \
		vlc-config.1 \
		vlc-wrapper.1

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 701000)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_misc_thread.c
.endif

WITH_VLC_DEFAULT_FONT?=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf

.if ${PERL_LEVEL} < 500800
BROKEN=	Does not compile with perl ${PERL_VERSION}
.endif

.if !defined(WITHOUT_QT4)
USE_QT_VER+=	4
QT_COMPONENTS+=	gui corelib moc_build rcc_build uic_build
CONFIGURE_ARGS+=--enable-qt4
.else
CONFIGURE_ARGS+=--disable-qt4
.endif

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=--disable-dbus
.else
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=--enable-dbus
.endif

# compatible knobs.
.if defined(WITH_DEBUG)
DEBUG=	yes
.endif

.if defined(WITH_LIBMPEG2)
WITH_MPEG2=yes
.endif

.if defined(WITH_LIBCACA)
WITH_CACA=yes
.endif

.if defined(WITH_LIBA52)
WITH_A52=yes
.endif

.if defined(WITH_SMB)
WITH_SAMBA=yes
.endif

.if defined(WITH_LIBMATROSKA)
WITH_MATROSKA=yes
.endif

.if defined(WITH_LIBTREMOR)
WITH_TREMOR=yes
.endif
# end compatible knobs

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
.endif

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif

.if !defined(WITHOUT_GNOMEVFS)
USE_GNOME+=	gnomevfs2
CONFIGURE_ARGS+=	--enable-gnomevfs
.else
CONFIGURE_ARGS+=	--disable-gnomevfs
.endif

.if defined(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
DEFAULT_CDROM_DEVICE=/dev/acd0
.endif

.if !defined(WITHOUT_LIBNOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-notify
.else
CONFIGURE_ARGS+=--disable-notify
.endif

.if defined(WITH_SKINS) && !defined(WITHOUT_SKINS) && !defined(WITHOUT_QT4)
CONFIGURE_ARGS+=--enable-skins2
.else
CONFIGURE_ARGS+=--disable-skins2
.endif

.if ${ARCH}=="i386" && defined(WITH_WIN32_CODECS)
RUN_DEPENDS+=	${LOCALBASE}/lib/win32/wmv8ds32.ax:${PORTSDIR}/multimedia/win32-codecs
CONFIGURE_ARGS+=--enable-loader
.else
CONFIGURE_ARGS+=--disable-loader
.endif

.if defined(WITH_JACK) && !defined(WITHOUT_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=--enable-jack
.else
CONFIGURE_ARGS+=--disable-jack
.endif

.if defined(WITH_REMOTE_OSD)
LIB_DEPENDS+=	gcrypt.16:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--enable-remoteosd
.else
CONFIGURE_ARGS+=--disable-remoteosd
.endif

.if defined(WITH_PULSEAUDIO) && !defined(WITHOUT_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--enable-pulse
.else
CONFIGURE_ARGS+=--disable-pulse
.endif

.if defined(WITH_FLUIDSYNTH) && !defined(WITHOUT_FLUIDSYNTH)
LIB_DEPENDS+=	fluidsynth.2:${PORTSDIR}/audio/fluidsynth
CONFIGURE_ARGS+=--enable-fluidsynth
.else
CONFIGURE_ARGS+=--disable-fluidsynth
.endif

.if !defined(WITHOUT_ZVBI)
LIB_DEPENDS+=	zvbi.13:${PORTSDIR}/devel/libzvbi
CONFIGURE_ARGS+=--enable-zvbi
.else
CONFIGURE_ARGS+=--disable-zvbi
.endif

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=--enable-hal
.else
CONFIGURE_ARGS+=--disable-hal
.endif

.if (defined(WITH_ARTS) || exists(${LOCALBASE}/lib/libartsc.so)) && !defined(WITHOUT_ARTS)
LIB_DEPENDS+=	 artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--enable-arts
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if !defined(WITHOUT_AVAHI)
LIB_DEPENDS+=	avahi-common.3:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=	--enable-bonjour
.else
CONFIGUE_ARGS+=		--disable-bonjour
.endif

.if !defined(WITHOUT_CDROM)
LIB_DEPENDS+=	vcdinfo.2:${PORTSDIR}/multimedia/vcdimager \
		cdio.8:${PORTSDIR}/sysutils/libcdio
CONFIGURE_ARGS+=--enable-vcd \
		--enable-libcddb \
		--disable-cddax
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

.if !defined(WITHOUT_DVBPSI)
LIB_DEPENDS+=	dvbpsi.5:${PORTSDIR}/multimedia/libdvbpsi
CONFIGURE_ARGS+=--enable-dvbpsi \
		--with-dvbpsi=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-dvbpsi
.endif

.if !defined(WITHOUT_DVDNAV)
LIB_DEPENDS+=	dvdnav.4:${PORTSDIR}/multimedia/libdvdnav
CONFIGURE_ARGS+=--enable-dvdnav
.else
CONFIGURE_ARGS+=--disable-dvdnav
.endif

.if defined(WITH_DVDREAD) && !defined(WITHOUT_DVDREAD)
LIB_DEPENDS+=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
CONFIGURE_ARGS+=--enable-dvdread
.else
CONFIGURE_ARGS+=--disable-dvdread
.endif

.if (defined(WITH_ESOUND) || ${HAVE_GNOME:Mesound}!="") && !defined(WITHOUT_ESOUND)
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
.else
CONFIGURE_ARGS+=--disable-esd
.endif

.if defined(WITH_FAAC) && !defined(WITHOUT_FAAC)
CONFIGURE_ARGS+=--with-ffmpeg-faac
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
.endif

.if (defined(WITH_FAAD) || exists(${LOCALBASE}/lib/libfaad.a)) && !defined(WITHOUT_FAAD)
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
CONFIGURE_ARGS+=--enable-faad
.else
CONFIGURE_ARGS+=--disable-faad
.endif

.if (defined(WITH_FLAC) || exists(${LOCALBASE}/lib/libFLAC.a)) && !defined(WITHOUT_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--enable-flac
.else
CONFLGIRE_ARGS+=--disable-flac
.endif

.if (defined(WITH_FRIBIDI) || exists(${LOCALBASE}/bin/fribidi-config)) && !defined(WITHOUT_FRIBIDI)
LIB_DEPENDS+=	fribidi.3:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=--enable-fribidi
.else
CONFIGURE_ARGS+=--disable-fribidi
.endif

.if (defined(WITH_AALIB) || exists(${LOCALBASE}/lib/libaa.so.1)) && !defined(WITHOUT_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
CONFIGURE_ARGS+=--enable-aa
.else
CONFIGURE_ARGS+=--disable-aa
.endif

.if (defined(WITH_DIRAC) || exists(${LOCALBASE}/lib/libdirac_decoder.a)) && !defined(WITHOUT_DIRAC)
BROKEN=		doesn't build with dirac
LIB_DEPENDS+=	dirac_encoder.0:${PORTSDIR}/multimedia/dirac
CONFIGURE_ARGS+=--enable-dirac
CPPFLAGS+=	-I${LOCALBASE}/include/dirac
.else
CONFIGURE_ARGS+=--disable-dirac
.endif

.if defined(WITH_SCHROEDINGER) && !defined(WITHOUT_SCHROEDINGER)
LIB_DEPENDS+=	schroedinger-1.0.2:${PORTSDIR}/multimedia/schroedinger
CONFIGURE_ARGS+=--enable-schroedinger
.else
CONFIGURE_ARGS+=--disable-schroedinger
.endif

.if !defined(WITHOUT_X264)
CONFIGURE_ARGS+=--enable-x264
LIB_DEPENDS+=	x264.65:${PORTSDIR}/multimedia/x264
.else
CONFIGURE_ARGS+=--disable-x264
.endif

.if (defined(WITH_LUA) || exists(${LOCALBASE}/lib/lua51/liblua.a)) && !defined(WITHOUT_LUA)
USE_LUA=5.1+
WANT_LUA_VER=5.1
CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
CONFIGURE_ARGS+=--enable-lua
.else
CONFIGURE_ARGS+=--disable-lua
.endif

.if (defined(WITH_CACA) || exists(${LOCALBASE}/lib/libcaca.a)) && !defined(WITHOUT_CACA)
.if !defined(WITHOUT_AALIB)
WITH_AALIB=	yes
LIB_DEPENDS+=	caca.0:${PORTSDIR}/graphics/libcaca
CONFIGURE_ARGS+=--enable-caca
.endif
.else
CONFIGURE_ARGS+=--disable-caca
.endif

.if !defined(WITHOUT_DTS)
LIB_DEPENDS+=	dca.0:${PORTSDIR}/multimedia/libdca
CONFIGURE_ARGS+=--enable-dca
.else
CONFIGURE_ARGS+=--disable-dca
.endif

.if defined(WITHOUT_HTTPD)
CONFIGURE_ARGS+=--disable-httpd
.endif

.if (defined(WITH_GGI) || exists(${LOCALBASE}/lib/libggi.a)) && !defined(WITHOUT_GGI)
LIB_DEPENDS+=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--enable-ggi
.else
CONFIGURE_ARGS+=--disable-ggi
.endif

.if !defined(WITHOUT_MATROSKA)
LIB_DEPENDS+=	matroska.0:${PORTSDIR}/multimedia/libmatroska
CONFIGURE_ARGS+=--enable-mkv
.else
CONFIGURE_ARGS+=--disable-mkv
.endif

.if !defined(WITHOUT_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
CONFIGURE_ARGS+=--enable-a52
.else
CONFIGURE_ARGS+=--disable-a52
.endif

.if defined(WITH_VLC_MOZILLA_PLUGIN) && !defined(WITHOUT_VLC_MOZILLA_PLUGIN)
USE_GECKO=	firefox xulrunner seamonkey
USE_WEBPLUGINS=	gecko*
WEBPLUGINS_FILES=libvlcplugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
CONFIGURE_ENV+=	MOZILLA_CONFIG="${GECKO_CONFIG}" \
		XPIDL="${XPIDL}" \
		XPIDL_INCL="${XPIDL_INCL}"
CONFIGURE_ARGS+=--enable-mozilla
.endif

.if !defined(WITHOUT_MPEG2)
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
CONFIGURE_ARGS+=--enable-libmpeg2
.else
CONFIGURE_ARGS+=--disable-libmpeg2
.endif

.if !defined(WITHOUT_REALAUDIO)
CONFIGURE_ARGS+=	--enable-real \
			--enable-realrtsp
.endif

.if (defined(WITH_SHOUT) || exists(${LOCALBASE}/lib/libshout.a)) && !defined(WITHOUT_SHOUT)
LIB_DEPENDS+=	shout.5:${PORTSDIR}/audio/libshout2
CONFIGURE_ARGS+=	--enable-shout
.endif

.if (defined(WITH_THEORA) || exists(${LOCALBASE}/lib/libtheora.a)) && !defined(WITHOUT_THEORA)
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=--enable-theora
.else
CONFIGURE_ARGS+=--disable-theora
.endif

.if (defined(WITH_LIVEMEDIA) || exists(${LOCALBASE}/live/liveMedia/libliveMedia.a)) && !defined(WITHOUT_LIVEMEDIA)
BUILD_DEPENDS+=	${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
CONFIGURE_ARGS+=--enable-live555 \
		--with-live555-tree=${LOCALBASE}/live
.else
CONFIGURE_ARGS+=--disable-live555
.endif

.if !defined(WITHOUT_TAGLIB)
LIB_DEPENDS+=	tag.6:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=--enable-taglib
.else
CONFIGURE_ARGS+=--disable-taglib
.endif

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	id3tag.0:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--enable-mad \
		--with-mad=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if !defined(WITHOUT_MODDEMUX)
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug
CONFIGURE_ARGS+=--enable-mod
.else
CONFIGURE_ARGS+=--disable-mod
.endif

.if !defined(WITHOUT_MPCDEMUX)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec
CONFIGURE_ARGS+=--enable-mpc
.else
CONFIGURE_ARGS+=--disable-mpc
.endif

.if !defined(WITHOUT_OGG)
LIB_DEPENDS+=	ogg.6:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=--enable-ogg
.else
CONFIGURE_ARGS+=--disable-ogg
WITHOUT_VORBIS=	yes
.endif

.if defined(WITH_NCURSES) && !defined(WITHOUT_NCURSES)
CONFIGURE_ARGS+=--enable-ncurses
.endif

.if !defined(WITHOUT_SAMBA)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
CONFIGURE_ARGS+=--enable-smb
.else
CONFIGURE_ARGS+=--disable-smb
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	image
CONFIGURE_ARGS+=--enable-sdl
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

.if defined(WITH_TRANSCODE) || exists(${LOCALBASE}/bin/transcode)
RUN_DEPENDS+=	transcode:${PORTSDIR}/multimedia/transcode
.endif

.if !defined(WITHOUT_HTTPD)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--enable-gnutls
.else
CONFIGURE_ARGS+=--disable-gnutls
.endif

.if !defined(WITHOUT_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=--enable-speex
CPPFLAGS+=-I${LOCALBASE}/include/speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if defined(WITHOUT_STREAM_PLUGINS)
CONFIGURE_ARGS+=--disable-sout
.endif

.if (defined(WITH_SVG) || ${HAVE_GNOME:Mlibrsvg2}!="") && !defined(WITHOUT_SVG)
USE_GNOME+=	librsvg2
CONFIGURE_ARGS+=--enable-svg
.else
CONFIGURE_ARGS+=--disable-svg
.endif

.if (defined(WITH_SVGALIB) || exists(${LOCALBASE}/lib/lib/vga.a)) && !defined(WITHOUT_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--enable-svgalib
.else
CONFIGURE_ARGS+=--disable-svgalib
.endif

.if (defined(WITH_TREMOR) || exists(${LOCALBASE}/lib/libvorbisidec.a)) && !defined(WITHOUT_TREMOR)
LIB_DEPENDS+=	vorbisidec.1:${PORTSDIR}/audio/libtremor
.else
CONFIGURE_ARGS+=--disable-tremor
.endif

.if (defined(WITH_TWOLAME) || exists(${LOCALBASE}/lib/libtwolame.a)) && !defined(WITHOUT_TWOLAME)
LIB_DEPENDS+=		twolame.0:${PORTSDIR}/audio/twolame
CONFIGURE_ARGS+=	--enable-twolame
.else
CONFIGURE_ARGS+=	--disable-twolame
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if (defined(WITH_XOSD) || exists(${LOCALBASE}/lib/libxosd.a)) && !defined(WITHOUT_XOSD)
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=--enable-xosd
.else
CONFIGURE_ARGS+=--disable-xosd
.endif

.if defined(DEBUG)
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--enable-release
.endif

.if defined(WITH_OCFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
CONFIGURE_ARGS+=--enable-optimizations
.endif

.if defined(WITHOUT_V4L)
CONFIGURE_ARGS+=--disable-v4l
.else
CONFIGURE_ARGS+=--enable-v4l
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-x11
.else
USE_XORG=	xpm
CONFIGURE_ARGS+=--enable-x11
.endif

.include "${.CURDIR}/Makefile.inc"
.include <bsd.port.post.mk>
