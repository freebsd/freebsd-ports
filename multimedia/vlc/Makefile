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
# WITHOUT_HTTPD=yes
#  Web interface to control streaming media
#   * recommended if you want to stream media
#
# WITH_NCURSES=yes
#  Ncurses (console) interface
#
# WITH_SKINS
#  This Interface supports a skinned gtk2.0 interface
#  Skins can be found at http://www.videolan.org/vlc/download-skins.html
#
# WITHOUT_WXWINDOWS=yes
#  WxWindows/Gtk 2.x Interface
#  This is the default and most supported
#  x11 interface
#
# Audio Knobs:
#
# WITH_ARTS=yes
#  Arts Support
#
# WITHOUT_DTS=yes
#  DTS decoder Support
#  useful for many dvds
#
# WITH_ESOUND=yes
#  Esound Support
#
# WITH_FAAC=yes
# Faac audio encoder (mp4/aac) Support
#
# WITHOUT_FAAD=yes
#  Faad audio decoder (mp4/aac) Support
#
# WITHOUT_FLAC=yes
#  Flac Support
#
# WITH_LAME=yes
#  Mp3 encoder Support
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
# WITH_SPEEX=yes
#  Speex voice codec Support
#  Note: you need audio/speex-devel
#
# WITH_TOOLAME=yes
#  Toolame Support
#
# WITHOUT_VORBIS=yes
#  Ogg/Vorbis Support
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
# WITHOUT_SDL=yes
#  SDL video output
#
# WITH_SVG=yes
#
# WITH_SVGALIB=yes
#  SVGAlib video output
#
# WITH_XOSD=yes
#
# Multimedia Knbos:
#
# WITH_H264
#  Enable H.264/AVC Video Support
#
# WITHOUT_LIBMATROSKA=yes
#  Matroska Container Format Support
#
# WITHOUT_LIBMPEG2=yes
#
# WITH_LIBTHEORA=yes
#
# WITHOUT_TRANSCODE=yes
#  Disable transcode of multimedia via transcode (multimedia/transcode).
#  This option allows you to convert a media file, dvd, A/V stream, etc
#  in to another format. This also allows you to transcode multimedia
#  on-the-fly and stream to a network and/or local playback.
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
# WITHOUT_DVBPSI=yes
#  TS MUX and DEMUX support
#
# WITHOUT_DVD=yes
#  Disable all dvd support
#
# WITHOUT_LIVEMEDIA=yes
#  Support for rstp/rtp/sdp protocols
#  Only versions 2004.11.11 and higher are supported.
#  * recommended if you want to stream media.
#
# WITH_MOZILLA_PLUGIN= [mozilla|mozilla-devel|firefox]
#  Enable A mozilla plugin for VLC
#  See http://www.videolan.org/doc/vlc-user-guide/en/ch07.html#id2529837
#  for more info on using this plugin.
#   defaults to www/mozilla
#
# WITH_OPENGL=yes
#  Enable OpenGL visual plugin (not playback, play back is default with X11)
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
# WITH_VLC_DEFAULT_FONT=/path/to/font
#  default: ${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf
#  This option lets you change the default font for subtitles
#
# NOPORTDOCS=yes
#  Do not install Vlc's Documents
#

PORTNAME=	vlc
PORTVERSION=	0.8.1
PORTREVISION=	9
CATEGORIES=	multimedia audio ipv6 net www
MASTER_SITES=	http://download.videolan.org/pub/videolan/vlc/${PORTVERSION}/ \
		http://ftp.snt.utwente.nl/pub/software/videolan/vlc/${PORTVERSION}/ \
		ftp://ftp.crans.org/pub/videolan/vlc/${PORTVERSION}/ \
		ftp://videolan.cs.pu.edu.tw/Windows/VideoLAN/vlc/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL:S|$|:mozilla|}
MASTER_SITE_SUBDIR=	ahze/:mozilla
PKGNAMESUFFIX?=	${ESOUND_SUFFIX}${MOZILLA_SUFFIX}${PKGNAMESUFFIX2}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		vlc-intf-mozilla-plugin${EXTRACT_SUFX}:mozilla

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Multimedia streaming server and player for various audio/video formats

RUN_DEPEDNS=	${X11BASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera
LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg

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
USE_GNOME=	gnometarget
USE_REINPLACE=	yes
WANT_SDL=	yes
USE_XLIB=	yes
USE_ICONV=	yes

FAKEDIR=	${WRKDIR}/fake
PLIST=		${WRKDIR}/plist

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PATH_GTKCONFIG="${GTK_CONFIG}" CFLAGS="${CFLAGS}" \
		CPPFLAGS="-I${WRKSRC}/include/vlc/ -I${LOCALBASE}/ffmpeg ${CPPFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"

CONFIGURE_ARGS+=	--enable-ffmpeg \
			--with-ffmpeg=${LOCALBASE} \
			--with-ffmpeg-zlib \
			--disable-gnome \
			--disable-gtk \
			--without-libintl-prefix

MAN1=		vlc.1 \
		vlc-config.1

.if defined(WITH_MOZILLA_PLUGIN)
.if ${WITH_MOZILLA_PLUGIN}=="firefox"
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
.if ${WITH_MOZILLA_PLUGIN}=="mozilla-devel"
HEADERS_SUFX=	-devel
.else
HEADERS_SUFX=
.endif
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000 && defined(WITH_MOZILLA_PLUGIN)
.if ${WITH_MOZILLA}=="mozilla-devel"
USE_GCC=	3.4
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

.if exists(${LOCALBASE}/bin/fribidi-config) && !defined(WITHOUT_FRIBIDI)
WITH_FRIBIDI=	yes
.endif

.if exists(${LOCALBASE}/lib/libggi.so.2) && !defined(WITHOUT_GGI)
WITH_GGI=	yes
.endif

.if exists(${LOCALBASE}/lib/libx264.a) && !defined(WITHOUT_H264)
WITH_H264=	yes
.endif

.if exists(${LOCALBASE}/lib/libmp3lame.a) && !defined(WITHOUT_LAME)
WITH_LAME=	yes
.endif

.if exists(${LOCALBASE}/lib/libtheora.so.1) && !defined(WITHOUT_LIBTHEORA)
WITH_LIBTHEORA=	yes
.endif

.if exists(${LOCALBASE}/lib/libspeex.a) && !defined(WITHOUT_SPEEX)
.if exists(${LOCALBASE}/include/speex.h)
WITHOUT_SPEEX=	yes
.else
WITH_SPEEX=	yes
.endif
.endif

.if  exists(${LOCALBASE}/lib/libgnutls.a) && !defined(WITHOUT_SSL)
WITH_SSL=	yes
.endif

.if exists(${X11BASE}/lib/librsvg-2.a) && !defined(WITHOUT_SVG)
WITH_SVG=	yes
.endif

.if exists(${LOCALBASE}/lib/lib/vga.so.1) && !defined(WITHOUT_SVGALIB)
WITH_SVGALIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libvorbisidec.a)
WITH_LIBTREMOR=	yes
.endif

.if exists(${LOCALBASE}/bin/toolame)
WITH_TOOLAME=	yes
.endif

.if exists(${LOCALBASE}/lib/libxosd.so.4) && !defined(WITHOUT_XOSD)
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
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2
CONFIGURE_ARGS+=--enable-skins2 --enable-skins
.else
CONFIGURE_ARGS+=--disable-skins2
.endif

.if !defined(WITHOUT_WXWINDOWS)
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2
USE_GNOME+=	gnomehier
CONFIGURE_ARGS+=--enable-wxwindows
CONFIGURE_ENV+=	WX_CONFIG=${X11BASE}/bin/wxgtk2-2.4-config
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
		cdio.4:${PORTSDIR}/sysutils/libcdio
CONFIGURE_ARGS+=--enable-vcd \
		--enable-libcddb \
		--enable-libcdio
.else
CONFIGURE_ARGS+=--disable-vcd \
		--disable-libcddb \
		--disable-libcdio
.endif

.if !defined(WITHOUT_DVBPSI)
LIB_DEPENDS+=	dvbpsi.3:${PORTSDIR}/multimedia/libdvbpsi
CONFIGURE_ARGS+=--enable-dvbpsi \
		--with-dvbpsi=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-dvbpsi
.endif

.if !defined(WITHOUT_DVD)
LIB_DEPENDS+=	dvdnav.3:${PORTSDIR}/multimedia/libdvdnav
CONFIGURE_ARGS+=--enable-dvdnav \
		--enable-dvdread \
		--with-dvdcss=${LOCALBASE} \
		--with-dvdread=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-dvdnav \
		--disable-dvdread
.endif

.if defined(WITH_ESOUND) && !defined(WITHOUT_ESOUND)
ESOUND_SUFFIX=	-esound
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
.endif

.if defined(WITH_FAAC) && !defined(WITHOUT_FAAC)
CONFIGURE_ARGS+=--with-ffmpeg-faac
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
.endif

.if !defined(WITHOUT_FAAD)
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
.endif

.if defined(WITH_AALIB) && !defined(WITHOUT_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
CONFIGURE_ARGS+=--enable-aa
.endif

.if defined(WITH_H264) && !defined(WITHOUT_H264)
CONFIGURE_ARGS+=--enable-x264
LIB_DEPENDS+=	x264.0:${PORTSDIR}/multimedia/x264
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

.if defined(WITH_LAME) && !defined(WITHOUT_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=--enable-mp3lame
.else
CONFIGURE_ARGS+=--disable-mp3lame
.endif

.if !defined(WITHOUT_LIBMATROSKA)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmatroska.a:${PORTSDIR}/multimedia/libmatroska
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

.if defined(WITH_NCURSES) && !defined(WITHOUT_NCURSES)
CONFIGURE_ARGS+=--enable-ncurses
.endif

.if defined(WITH_OPENGL) && !defined(WITHOUT_OPENGL)
USE_GL=	yes
CONFIGURE_ARGS+=--enable-galaktos
.else
CONFIGURE_ARGS+=--disable-galaktos
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	yes
CONFIGURE_ARGS+=--enable-sdl
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

.if !defined(WITHOUT_TRANSCODE)
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
LIB_DEPENDS+=	speex.3:${PORTSDIR}/audio/speex-devel
CONFIGURE_ARGS+=--enable-speex
CPPFLAGS+=-I${LOCALBASE}/include/speex
.else
CONFIGURE_ARGS+=--disable-speex
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
CONFIGURE_ARGS+=--enable-release
.else
CONFIGURE_ARGS+=--disable-optimizations
.endif

.if ${OSVERSION} < 500000
CONFIGURE_ENV+=	LIBS="-L/usr/lib -lcipher"
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a careful look at the beginning of the Makefile in order"
	@${ECHO_MSG} "to learn how to tune VLC towards you personal preferences!"
	@${ECHO_MSG} "For example, make WITH_MOZILLA_PLUGIN=firefox"
.if defined(WITH_SPEEX) && exists(${LOCALBASE}/include/speex.h)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "**** WARNING ****"
	@${ECHO_MSG} "Speex 1.0 was detected, if you want Speex support"
	@${ECHO_MSG} "Please upgrade speex to audio/speex-devel (1.1.x)"
	@${ECHO_MSG} ""
.endif

post-patch:
# Subtitle default font
	@${REINPLACE_CMD} -e \
	's|/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf|${WITH_VLC_DEFAULT_FONT}|' \
		${WRKSRC}/modules/misc/freetype.c
# mozilla plugin
.if defined(WITH_MOZILLA_PLUGIN)
	@${CP} -f ${WRKDIR}/vlc-intf-mozilla-plugin/vlcintf.h ${WRKSRC}/mozilla
	@${CP} -f ${WRKDIR}/vlc-intf-mozilla-plugin/vlcintf.xpt ${WRKSRC}/mozilla
	@${REINPLACE_CMD} -e 's|$$(libdir)/mozilla/plugins|${FAKEDIR}/mozilla|; \
		s|$$(libdir)/mozilla/components|${FAKEDIR}/mozilla|' \
			${WRKSRC}/mozilla/Makefile.in
.endif
# skins2 interface
	@${REINPLACE_CMD} -e 's|lrint|rint|' \
		${WRKSRC}/modules/gui/skins2/controls/ctrl_list.cpp
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
	@${REINPLACE_CMD} -e 's|cflags_tuning=|# cflags_tuning=|' \
		${WRKSRC}/vlc-config.in
# cdrom/dvd support
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|; \
		s|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/include/vlc_config.h

pre-install:
	${RM} -rf ${PLIST} ${FAKEDIR}
	${MKDIR} ${FAKEDIR}
	${TOUCH} -f ${PLIST}
.if !defined(WITHOUT_WXWINDOWS)
	${ECHO_CMD} "share/gnome/applications/vlc.desktop" >> ${PLIST}
	${ECHO_CMD} "share/gnome/pixmaps/vlc.png" >> ${PLIST}
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

do-install:
.if !defined(WITHOUT_WXWINDOWS)
	if [ ! -d ${PREFIX}/share/gnome/applications ]; then \
		${MKDIR} ${PREFIX}/share/gnome/applications ; \
	fi
	${INSTALL_DATA} ${FILESDIR}/vlc.desktop ${PREFIX}/share/gnome/applications
	if [ ! -d ${PREFIX}/share/gnome/pixmaps ]; then \
		${MKDIR} ${PREFIX}/share/gnome/pixmaps ; \
	fi
	${INSTALL_DATA} ${FAKEDIR}/share/vlc/vlc48x48.png ${PREFIX}/share/gnome/pixmaps/vlc.png
.endif
	@${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|' \
		${FAKEDIR}/bin/vlc-config
	@${RM} -f ${FAKEDIR}/bin/*.bak
	cd ${FAKEDIR}/bin && ${FIND} . | \
		${CPIO} -pdm -R ${BINOWN}:${BINGRP} ${PREFIX}/bin
	cd ${FAKEDIR}/include && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include
	cd ${FAKEDIR}/lib && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib
	cd ${FAKEDIR}/share && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN} ${PREFIX}/share
.if defined(WITH_MOZILLA_PLUGIN)
	@${MKDIR} ${PREFIX}/lib/browser_plugins
	${INSTALL_DATA} ${FAKEDIR}/mozilla/* ${PREFIX}/lib/browser_plugins
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/vlc.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/vlc-config.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
