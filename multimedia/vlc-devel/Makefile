# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#
# Options to define Features:
# WITH_AUTODETECT=yes
# WITH_GNOME=yes
# WITH_ESOUND=yes
# WITH_AALIB=yes
# WITH_CDDB=yes
# WITH_GGI=yes
# WITH_LIBDVBPSI=yes
# WITH_LIBID3TAG=yes
# WITH_LIBMATROSKA=yes
# WITH_LIBMPEG2=yes
# WITH_LIBTHEORA=yes	
# WITH_LIVEMEDIA=yes
# WITH_SPEEX=yes
# WITH_SVGALIB=yes
# WITH_XOSD=yes
# WITH_OPTIMIZED_CFLAGS=yes
# WITHOUT_LIBID3TAG=yes

PORTNAME=	vlc
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/vlc/${PORTVERSION}/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An X11 video streaming client/server solution

LIB_DEPENDS=	dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread \
		mad.2:${PORTSDIR}/audio/libmad \
		avcodec.0:${PORTSDIR}/multimedia/ffmpeg \
		a52.0:${PORTSDIR}/audio/liba52 \
		iconv.3:${PORTSDIR}/converters/libiconv \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		FLAC.5:${PORTSDIR}/audio/flac \
		faad.0:${PORTSDIR}/audio/faad \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2 \
		slp.1:${PORTSDIR}/net/openslp

USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_SDL=	sdl
USE_XLIB=	yes
USE_GCC=	3.2

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG="${GTK_CONFIG}" \
		CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS=-L${LOCALBASE}/lib WX_CONFIG=${X11BASE}/bin/wxgtk2-2.4-config
CONFIGURE_ARGS+=--with-dvdcss=${LOCALBASE} \
		--with-dvdread=${LOCALBASE} \
		--with-mad=${LOCALBASE} \
		--with-faad=${LOCALBASE} \
		--with-a52=${LOCALBASE} \
		--enable-ffmpeg \
		--with-ffmpeg=${LOCALBASE} \
		--disable-libcdio \
		--program-prefix="" \
		--without-libintl-prefix \
		--without-libiconv-prefix

MAN1=		vlc.1 \
		vlc-config.1

.include <bsd.port.pre.mk>

.if defined(WITH_AUTODETECT) && !defined(BATCH)

.if ${HAVE_GNOME:Mgnomelibs}!="" && !defined(WITHOUT_GNOME)
WITH_GNOME=	yes
.endif

.if ${HAVE_GNOME:Mesound}!="" && !defined(WITHOUT_ESOUND)
WITH_ESOUND=	yes
.endif

.if exists(${LOCALBASE}/lib/libaa.so.1) && !defined(WITHOUT_AALIB)
WITH_AALIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libcddb.so.1) && !defined(WITHOUT_CDDB)
WITH_CDDB=	yes
.endif

.if exists(${LOCALBASE}/lib/libggi.so.2) && !defined(WITHOUT_GGI)
WITH_GGI=	yes
.endif

.if exists(${LOCALBASE}/lib/libdvbpsi.so.3) && !defined(WITHOUT_LIBDVBPSI)
WITH_LIBDVBPSI=	yes
.endif

.if exists(${LOCALBASE}/lib/libtheora.so.0) && !defined(WITHOUT_LIBTHEORA)
WITH_LIBTHEORA=	yes
.endif

.if exists(${LOCALBASE}/live/liveMedia/libliveMedia.a) && !defined(WITHOUT_LIVEMEDIA)
WITH_LIVEMEDIA=	yes
.endif

.if exists(${LOCALBASE}/lib/libspeex.so.2) && !defined(WITHOUT_SPEEX)
WITH_SPEEX=	yes
.endif

.if exists(${LOCALBASE}/lib/lib/vga.so.1) && !defined(WITHOUT_SVGALIB)
WITH_SVGALIB=	yes
.endif

.if exists(${LOCALBASE}/libxosd.so.4) && !defined(WITHOUT_XOSD)
WITH_XOSD=	yes
.endif

.endif

.if defined(WITH_GNOME) && !defined(WITHOUT_GNOME)
USE_GNOME+=	gnomelibs
CONFIGURE_ARGS+=--enable-gnome
PKGNAMESUFFIX=	-gnome
PLIST_FILES+=	bin/gnome-vlc \
		lib/vlc/gui/libgnome_plugin.so \
		lib/vlc/misc/libgnome_main_plugin.so
.else
CONFIGURE_ARGS+=--enable-gtk
.endif

.if defined(WITH_ESOUND) && !defined(WITHOUT_ESOUND)
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
PLIST_FILES+=	lib/vlc/audio_output/libesd_plugin.so
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-esound
.else
PKGNAMESUFFIX=	-esound
.endif
.endif

.if !defined(WITHOUT_LIBID3TAG)
LIB_DEPENDS+=   id3tag.2:${PORTSDIR}/audio/libid3tag
PLIST_FILES+=	lib/vlc/demux/libid3tag_plugin.so
.endif

.if defined(WITH_AALIB) && !defined(WITHOUT_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
CONFIGURE+=	--enable-aa
.endif

.if defined(WITH_CDDB) && !defined(WITHOUT_CDDB)
LIB_DEPENDS+=	cddb.1:${PORTSDIR}/audio/libcddb
CONFIGURE_ARGS+=--enable-libcddb
.else
CONFIGURE_ARGS+=--disable-libcddb
.endif

.if defined(WITH_GGI) && !defined(WITHOUT_GCI)
LIB_DEPENDS+=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--enable-ggi
PLIST_FILES+=	lib/vlc/video_output/libggi_plugin.so
.endif

.if defined(WITH_LIBDVBPSI) && !defined(WITHOUT_LIBDVBPSI)
LIB_DEPENDS+=	dvbpsi.3:${PORTSDIR}/multimedia/libdvbpsi
CONFIGURE_ARGS+=--with-dvbpsi=${LOCALBASE}
PLIST_FILES+=	lib/vlc/demux/libts_dvbpsi_plugin.so \
		lib/vlc/mux/libmux_ts_dvbpsi_plugin.so
.else
CONFIGURE_ARGS+=--disable-dvbpsi
.endif

.if defined(WITH_LIBMATROSKA) && !defined(WITHOUT_LIBMATROSKA)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmatroska.a:${PORTSDIR}/multimedia/libmatroska
PLIST_FILES+=	lib/vlc/demux/libmkv_plugin.so
.endif

# After libmpeg2 release 0.3.2
.if defined(WITH_LIBMPEG2) && !defined(WITHOUT_LIBMPEG2)
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
CONFIGURE_ARGS+=--enable-libmpeg2
.else
CONFIGURE_ARGS+=--disable-libmpeg2
.endif

.if defined(WITH_LIBTHEORA) && !defined(WITHOUT_LIBTHEORA)
LIB_DEPENDS+=	theora.0:${PORTSDIR}/graphics/libtheora
EXTRA_PATCHES+=	${PATCHDIR}/theora.c-patch
CONFIGURE_ARGS+=--enable-theora
PLIST_FILES+=	lib/vlc/libtheora.a
.endif

.if defined(WITH_LIVEMEDIA) && !defined(WITHOUT_LIVEMEDIA)
BUILD_DEPENDS+=	${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
CONFIGURE_ARGS+=--enable-livedotcom \
		--with-livedotcom-tree=${LOCALBASE}/live
PLIST_FILES+=	lib/vlc/liblivedotcom.a
.endif

.if defined(WITH_SPEEX) && !defined(WITHOUT_SPEEX)
LIB_DEPENDS+=	speex.2:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=--enable-speex
PLIST_FILES+=	lib/vlc/codec/libspeex_plugin.so
.endif

.if defined(WITH_SVGALIB) && !defined(WITHOUT_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--enable-svgalib
PLIST_FILES+=	lib/vlc/video_output/libsvgalib_plugin.so
.endif

.if defined(WITH_XOSD) && !defined(WITHOUT_XOSD)
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=--enable-xosd
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.else
CONFIGURE_ARGS+=--disable-optimizations
.endif

.if defined(WITH_OPTIMIZED_CFLAGS) && (${ARCH} == "i386")
CONFIGURE_ARGS+=--with-tuning=i686
.endif

.if ${OSVERSION} < 500000
CONFIGURE_ENV+=	LIBS="-L/usr/lib -lcipher"
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	MMX=""
.else
PLIST_SUB+=	MMX="@comment "
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a careful look into the Makefile in order"
	@${ECHO_MSG} "to learn how to tune VLC towards you personal preferences!"
	@${ECHO_MSG} "For example, make WITH_AUTODETECT=yes"

post-patch:
	@${REINPLACE_CMD} -e 's/-lpthread/-lpthread-broken/' \
		-e 's/-lc_r/${PTHREAD_LIBS}/' ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/vlc.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/vlc-config.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
