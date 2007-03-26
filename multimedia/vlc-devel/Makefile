# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/vlc-devel/Makefile,v 1.21 2006/10/01 18:16:43 ahze Exp $
#      $Id: Makefile 6 2006-09-27 14:05:34Z buhnux $
# *** PLEASE READ Makefile.inc for more information on knobs ***
#

PORTNAME=	vlc
DISTVERSION=	0.8.6a
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	multimedia audio ipv6 net www
MASTER_SITES=	http://download.videolan.org/pub/videolan/vlc/${DISTVERSION}/ \
		http://ftp.snt.utwente.nl/pub/software/videolan/vlc/${DISTVERSION}/ \
		ftp://ftp.crans.org/pub/videolan/vlc/${DISTVERSION}/ \
		ftp://videolan.cs.pu.edu.tw/Windows/VideoLAN/vlc/${DISTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Multimedia streaming server and player for various audio/video formats

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg-devel

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera

OPTIONS+=	A52 "a52 audio support, many DVDs use this" On
OPTIONS+=	AALIB "Aalib Console Graphics Support" Off
OPTIONS+=	AVAHI "Avahi (Rendezvous/Bonjour (R) ) networking" On
OPTIONS+=	CACA "Libcaca Console Graphics Support" Off
OPTIONS+=	ARTS "Enable arts sound support" Off
OPTIONS+=	CORBA "Enable a Corba interface via orbit2" Off
OPTIONS+=	DAAP "Connect to iTunes(R) music shares" On
OPTIONS+=	DEBUG "Enable debuging support" Off
OPTIONS+=	DTS "DTS decoder support, many DVDs use this" On
OPTIONS+=	ESOUND "Esound Support" Off
OPTIONS+=	FAAC "Faac audio encoder (mp4/aac) support" Off
OPTIONS+=	FAAD "Faad audio decoder (mp4/aac) support" Off
OPTIONS+=	FLAC "Flac audio codec support" Off
OPTIONS+=	HTTPD "Streaming media control via http" On
OPTIONS+=	LAME "Lame mp3 audio encoder support" On
OPTIONS+=	LIVEMEDIA "Support for rstp/rtp/sdp protocols" On
OPTIONS+=	MAD "Mad mp3 audio decoder support" On
OPTIONS+=	MATROSKA "Matroska Container Format support" On
OPTIONS+=	MPEG2 "Mpeg-2 audio/video decoder Support" On
OPTIONS+=	NCURSES "Enable ncueses (console) interface" Off
OPTIONS+=	OGG "Ogg audio decoder support" On
OPTIONS+=	REALAUDIO "Real audio(R) support" On
OPTIONS+=	SAMBA "SAMBA Access module" On
OPTIONS+=	SDL "SDL video output" On
OPTIONS+=	SVG "SVG graphics support" Off
OPTIONS+=	SVGALIB "SVGALIB video output" Off
OPTIONS+=	SHOUT "Shout2 support" Off
OPTIONS+=	SKINS "Enable GTK+ skinsned interface" Off
OPTIONS+=	SPEEX "Speex voice codec support" On
OPTIONS+=	THEORA "OGG/Vorbis video codec support" Off
OPTIONS+=	TWOLAME "Twolame mpeg2 audio encoder support" Off
OPTIONS+=	VORBIS "Vorbis support" On
OPTIONS+=	WIN32_CODECS "win32 multimedia DLL's" Off
OPTIONS+=	X264 "Enable H.264/AVC codec support" On

CONFLICTS=	vlc-[0-9]*

WITH_VLC_DEFAULT_FONT?=	${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget libxml2
WANT_SDL=	yes
USE_ICONV=	yes
USE_PERL5_BUILD=yes

FAKEDIR=	${WRKDIR}/fake/${PREFIX}
PLIST=		${WRKDIR}/plist

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${FAKEDIR}/include -I${WRKSRC}/include ${CPPFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include -I${LOCALBASE}/ffmpeg ${PTHREAD_CFLAGS} -DHAVE_POSTPROC_POSTPROCESS_H" \
		LDFLAGS="${LDFLAGS} -L${FAKEDIR}/lib -L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS} -lc" \
		LIBS="-lc"

CONFIGURE_ARGS+=	--enable-ffmpeg \
			--with-ffmpeg=${LOCALBASE} \
			--with-libiconv-prefix=${LOCALBASE} \
			--with-libintl-prefix=${LOCALBASE} \
			--with-ffmpeg-zlib \
			--disable-gnome \
			--disable-gtk \
			--without-libintl-prefix \
			--without-dv-raw1394 \
			--disable-dv

MAN1=		vlc.1 \
		vlc-config.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BROKEN=	Does not compile with perl ${PERL_VERSION}
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

.if !defined(WITHOUT_GNOMEVFS)
USE_GNOME+=	gnomevfs2
CONFIGURE_ARGS+=	--enable-gnomevfs
.else
CONFIGURE_ARGS+=	--disable-gnomevfs
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
LIB_DEPENDS+=	tar.0:${PORTSDIR}/devel/libtar
CONFIGURE_ARGS+=--enable-skins2
.undef WITHOUT_WXGTK
.else
CONFIGURE_ARGS+=--disable-skins2
.endif

.if ${ARCH}=="i386" && defined(WITH_WIN32_CODECS)
RUN_DEPENDS+=	${LOCALBASE}/lib/win32/wmv8ds32.ax:${PORTSDIR}/multimedia/win32-codecs
CONFIGURE_ARGS+=--enable-loader
.else
CONFIGURE_ARGS+=--disable-loader
.endif

.if !defined(WITHOUT_WXGTK)
USE_WX=		2.6
WX_UNICODE=	yes
CONFIGURE_ARGS+=--enable-wxwidgets
.else
CONFIGURE_ARGS+=--disable-wxwidgets
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
LIB_DEPENDS+=	avahi-common.3:${PORTSDIR}/net/avahi
CONFIGURE_ARGS+=	--enable-bonjour
.else
CONFIGUE_ARGS+=		--disable-bonjour
.endif

.if !defined(WITHOUT_CDROM)
LIB_DEPENDS+=	vcdinfo.2:${PORTSDIR}/multimedia/vcdimager \
		cdio.7:${PORTSDIR}/sysutils/libcdio
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

.if defined(WITH_CORBA) && !defined(WITHOUT_CORBA)
USE_GNOME+=	orbit2
CONFIGURE_ARGS+=--enable-corba
.else
CONFIGURE_ARGS+=--disable-corba
.endif

.if !defined(WITHOUT_DVBPSI)
LIB_DEPENDS+=	dvbpsi.4:${PORTSDIR}/multimedia/libdvbpsi
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
LIB_DEPENDS+=	dvdread.3:${PORTSDIR}/multimedia/libdvdread
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
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
CONFIGURE_ARGS+=--enable-faad
.else
CONFIGURE_ARGS+=--disable-faad
.endif

.if (defined(WITH_FLAC) || exists(${LOCALBASE}/lib/libFLAC.a)) && !defined(WITHOUT_FLAC)
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--enable-flac
.else
CONFLGIRE_ARGS+=--disable-flac
.endif

.if (defined(WITH_FRIBIDI) || exists(${LOCALBASE}/bin/fribidi-config)) && !defined(WITHOUT_FRIBIDI)
LIB_DEPENDS+=	fribidi.0:${PORTSDIR}/converters/fribidi
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
LIB_DEPENDS+=	dirac_encoder.0:${PORTSDIR}/multimedia/dirac
CONFIGURE_ARGS+=--enable-dirac
CPPFLAGS+=	-I${LOCALBASE}/include/dirac
.else
CONFIGURE_ARGS+=--disable-dirac
.endif

.if !defined(WITHOUT_X264)
CONFIGURE_ARGS+=--enable-x264
LIB_DEPENDS+=	x264.50:${PORTSDIR}/multimedia/x264
.else
CONFIGURE_ARGS+=--disable-x264
.endif

.if (defined(WITH_CACA) || exists(${LOCALBASE}/lib/libcaca.a)) && !defined(WITHOUT_CACA)
.if !defined(WITHOUT_AALIB)
WITH_AALIB=	yes
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcaca.a:${PORTSDIR}/graphics/libcaca
RUN_DEPENDS+=	${LOCALBASE}/lib/libcaca.a:${PORTSDIR}/graphics/libcaca

CONFIGURE_ARGS+=--enable-caca
.endif
.else
CONFIGURE_ARGS+=--disable-caca
.endif

.if !defined(WITHOUT_DAAP)
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

.if (defined(WITH_GGI) || exists(${LOCALBASE}/lib/libggi.a)) && !defined(WITHOUT_GGI)
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
USE_GECKO=	firefox mozilla seamonkey nvu
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
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
LIB_DEPENDS+=	theora.2:${PORTSDIR}/multimedia/libtheora
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
LIB_DEPENDS+=	gnutls.15:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--enable-gnutls
.else
CONFIGURE_ARGS+=--disable-gnutls
.endif

.if !defined(WITHOUT_SLP)
LIB_DEPENDS+=	slp.1:${PORTSDIR}/net/openslp
.else
CONFIGURE_ARGS+=--disable-slp
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
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
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

.include "${.CURDIR}/Makefile.inc"
.include <bsd.port.post.mk>
