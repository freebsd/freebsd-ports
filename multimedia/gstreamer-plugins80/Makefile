# New ports collection makefile for:	gstreamer plugins
# Date created:		Wed Jul 10 23:38:01 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.3
CATEGORIES=	multimedia audio
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://gstreamer.freedesktop.org/src/gst-plugins/
MASTER_SITE_SUBDIR=	sources/gst-plugins/0.8
PKGNAMESUFFIX=	-plugins
DISTNAME=	gst-plugins-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GStreamer written collection of plugins handling several media types

LIB_DEPENDS=	gstreamer-0.8.4:${PORTSDIR}/multimedia/gstreamer \
		popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack \
		gnomehier \
		gnomeprefix \
		pkgconfig \
		gconf2
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--disable-tests \
		--disable-alsa \
		--enable-cdrom \
		--disable-divx \
		--disable-dxr3 \
		--disable-http \
		--disable-qcam \
		--disable-raw1394 \
		--disable-v4l2 \
		--disable-v4l \
		--disable-osx_audio \
		--disable-sunaudio \
		--disable-dependency-tracking \
		--enable-xshm \
		--enable-x \
		--enable-xvideo \
		--enable-static

# list of plugins that need some work in one way or the other to work
# probable the lib needs to be ported, disable them for now.
CONFIGURE_ARGS+=\
		--disable-tarkin \
		--disable-lcs \
		--disable-mplex \
		--disable-shout2 \
		--disable-libvisual \
		--disable-dirac \
		--disable-librfb

CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib -L${LOCALBASE}/lib"
CONFIGURE_TARGET=
PLIST_SUB=	\
		VERSION="${GST_VERSION}" \
		SHLIB_VERSION="${SHLIB_VERSION}"
INSTALLS_SHLIB=	yes

# for various GNOME-related component detection
WANT_GNOME=	yes

MAN1=	gst-launch-ext-${GST_VERSION}.1 gst-visualise-${GST_VERSION}.1

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"
SDL_CONFIG?="${LOCALBASE}/bin/sdl11-config"
GST_VERSION=${PORTVERSION:C/..$//}

# library minor number
SHLIB_VERSION=	1

## Additional directories which should be both built and installed
## but configure neglected to correctly identify them
# cdrom/vcd support
EXTRA_BUILD_DIR+=	sys/vcd
# modplug
EXTRA_BUILD_DIR+=	gst/modplug

post-extract:
# for cdrom/vcd support
# taken from mplayer distfile
# MD5 (MPlayer-1.0pre4.tar.bz2) = 83ebac0f05b192516a41fca2350ca01a
	@${CP} ${FILESDIR}/bsdi_dvd.h ${WRKSRC}/sys/vcd/

post-patch:
# as of this writing, FreeBSD does not support lrint* C99 math functions
	@${REINPLACE_CMD} -E -e \
		's|^#define.*LRINT.*$$||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# respect CFLAGS
	@${FIND} ${WRKSRC} -type f -name Makefile.in | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E -e \
		's,-O(2|3),,; \
		s|-mcpu=i486||'
# mcopidl takes the file as the last argument
	@${REINPLACE_CMD} -E -e \
		's|(mcopidl.+)(\$$<)(.+)$$|\1 \3 \2|' \
		${WRKSRC}/ext/arts/Makefile.in
# malloc.h was deprecated in favor of stdlib.h
# inttypes.h not stdint.h
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|; \
		s|stdint\.h|inttypes.h|'
# force libaudiofile detection
	@${REINPLACE_CMD} -E -e \
		's|^.*afOpenVirtualFile[[:space:]]*\(\);|;|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# cdrom default device
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
		${WRKSRC}/ext/cdparanoia/gstcdparanoia.c \
		${WRKSRC}/sys/cdrom/gstcdplayer.c \
		${WRKSRC}/sys/vcd/vcdsrc.c
# dvd default device
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/ext/dvdnav/dvdnavsrc.c \
		${WRKSRC}/ext/dvdread/dvdreadsrc.c
# cdrom/vcd support
	@${REINPLACE_CMD} -e 's|<linux/cdrom.h>|"bsdi_dvd.h"|' \
		${WRKSRC}/sys/cdrom/gstcdplayer_ioctl.c \
		${WRKSRC}/sys/vcd/vcdsrc.c \
		${WRKSRC}/sys/vcd/vcdsrc.h
# KDE libkio required thread support
	${REINPLACE_CMD} -E \
		 -e 's|(KIO_CFLAGS=.+)"$$|\1 ${PTHREAD_CFLAGS}"|' \
		 -e 's|(KIO_LIBS=.+)"$$|\1 ${PTHREAD_LIBS}"|' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>

# hermes is required for gstreamer-player to work
# since it is currently the only colorspace plugin available
WITH_HERMES=	yes
# gnomevfs is required for gstreamer-player to work
WITH_GNOMEVFS=	yes
# Add default MAD support.  This is required for rhythmbox to work.
WITH_MAD=	yes

##
## auto detect possible plugins
##

# aalib
.if exists(${LOCALBASE}/lib/libaa.a)
WITH_AALIB=yes
.endif

# arts
.if exists(${LOCALBASE}/lib/libartsc.so.0) && !defined(WITHOUT_ARTS)
WITH_ARTS=yes
.endif

# cdparanoia
.if exists(${LOCALBASE}/lib/libcdda_paranoia.a)
WITH_CDPARANOIA=yes
.endif

# dts
.if exists(${LOCALBASE}/lib/libdts_pic.a)
WITH_DTS=yes
.endif

# faac
.if exists(${LOCALBASE}/lib/libfaac.a)
WITH_FAAC=yes
.endif

# esound
.if (${HAVE_GNOME:Mesound}!="")
WITH_ESOUND=yes
.endif

# faad
.if exists(${LOCALBASE}/lib/libfaad.a)
WITH_FAAD=yes
.endif

# flac
.if exists(${LOCALBASE}/lib/libFLAC.a)
WITH_FLAC=yes
.endif

# freetype
.if exists(${LOCALBASE}/lib/libfreetype.a)
WITH_FREETYPE=yes
.endif

# gdkpixbuf
.if ${HAVE_GNOME:Mgtk20}!=""
WITH_GDKPIXBUF=yes
.endif

# lame
.if exists(${LOCALBASE}/lib/libmp3lame.a)
WITH_LAME=yes
.endif

# gnomevfs
.if ${HAVE_GNOME:Mgnomevfs2}!=""
WITH_GNOMEVFS=yes
.endif

# jack
.if exists(${LOCALBASE}/lib/libjack.so.0)
WITH_JACK=YES
.endif

# KIO
.if exists(${LOCALBASE}/lib/libkio.so)
WITH_KIO=yes
.endif

# libcaca
.if exists(${LOCALBASE}/lib/libcaca.a)
WITH_LIBCACA=yes
.endif

# gsm
.if exists(${LOCALBASE}/lib/libgsm.a)
WITH_GSM=yes
.endif

# Hermes
.if exists (${LOCALBASE}/lib/libHermes.a)
WITH_HERMES=yes
.endif

# jpeg
.if exists(${LOCALBASE}/lib/libjpeg.a)
WITH_JPEG=yes
.endif

# ladspa
.if exists(${LOCALBASE}/include/ladspa.h)
WITH_LADSPA=yes
.endif

# liba52
.if exists(${LOCALBASE}/lib/liba52.a)
WITH_LIBA52=yes
.endif

# libaudiofile
.if exists(${LOCALBASE}/lib/libaudiofile.a)
WITH_LIBAUDIOFILE=yes
.endif

# libdv
.if exists(${LOCALBASE}/lib/libdv.a)
WITH_LIBDV=yes
.endif

# libdvdnav
.if exists(${LOCALBASE}/lib/libdvdnav.so)
WITH_LIBDVDNAV=yes
.endif

# libdvdread
.if exists(${LOCALBASE}/lib/libdvdread.a)
WITH_LIBDVDREAD=yes
.endif

# libfame
.if exists(${LOCALBASE}/lib/libfame.a)
WITH_LIBFAME=yes
.endif

# libmikmod
.if exists(${LOCALBASE}/lib/libmikmod.a)
WITH_LIBMIKMOD=yes
.endif

# libmpeg2
.if exists(${LOCALBASE}/lib/libmpeg2.a)
WITH_LIBMPEG2=yes
.endif

# libmusicbrainz
.if exists(${LOCALBASE}/lib/libmusicbrainz.a)
WITH_LIBMUSICBRAINZ=yes
.endif

# libshout
.if exists(${LOCALBASE}/lib/libshout.so.2)
WITH_LIBSHOUT=yes
.endif

# libsidplay
.if exists(${LOCALBASE}/lib/libsidplay.a)
WITH_LIBSIDPLAY=yes
.endif

# libsndfile
.if exists(${LOCALBASE}/lib/libsndfile.a)
WITH_LIBSNDFILE=yes
.endif

# libtheora
.if exists(${LOCALBASE}/lib/libtheora.a)
WITH_LIBTHEORA=yes
.endif

# mad
.if exists(${LOCALBASE}/lib/libmad.a)
WITH_MAD=yes
.endif

# mjpegtools
.if exists(${LOCALBASE}/lib/libmjpegutils.a)
WITH_MJPEGTOOLS=yes
.endif

# nas
.if exists(${X11BASE}/lib/libaudio.a)
WITH_NAS=YES
.endif

# ogg
.if exists(${LOCALBASE}/lib/libogg.a)
WITH_OGG=yes
.endif

# pango
.if exists(${X11BASE}/lib/libpangoft2-1.0.a)
WITH_PANGO=yes
.endif

# png
.if exists(${LOCALBASE}/lib/libpng.a)
WITH_PNG=yes
.endif

# sdl
.if exists(${LOCALBASE}/lib/libSDL-1.1.a)
WITH_SDL=yes
.endif

# smoothwave
.if exists(${X11BASE}/lib/libgtk-x11-2.0.a)
WITH_SMOOTHWAVE=yes
.endif

# speex
.if exists(${LOCALBASE}/lib/libspeex.a)
WITH_SPEEX=yes
.endif

# swfdec
.if exists(${X11BASE}/lib/libswfdec.a)
WITH_SWFDEC=yes
.endif

# vorbis
.if exists(${LOCALBASE}/lib/libvorbis.a)
WITH_VORBIS=yes
.endif

# vorbisidec
.if exists(${LOCALBASE}/lib/libvorbisidec.a)
WITH_VORBISIDEC=yes
.endif

# xine
# this plugins is meant to support plugins that gstreamer doesn't have (yet)
.if exists(${X11BASE}/lib/libxine.so.9)
WITH_XINE=yes
.endif

# xvid
.if exists(${LOCALBASE}/lib/libxvidcore.so.4)
WITH_XVID=yes
.endif

##
## control CONFIGURE options
##

# aalib
.ifndef(WITH_AALIB)
CONFIGURE_ARGS+=	--disable-aalib \
			--disable-aalibtest
PLIST_SUB+=	AALIB="@comment "
.else
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib

CONFIGURE_ARGS+=	--with-aalib-prefix=${LOCALBASE}  \
			--with-aalib-exec-prefix=${LOCALBASE}
PLIST_SUB+=	AALIB=""
.endif

# arts
.ifndef(WITH_ARTS)
CONFIGURE_ARGS+=	--disable-arts \
			--disable-artsc \
			--disable-artstest
PLIST_SUB+=	ARTS="@comment "
.else
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts

CONFIGURE_ARGS+=	--with-arts-prefix=${LOCALBASE} \
			--with-arts-exec-prefix=${LOCALBASE}
PLIST_SUB+=	ARTS=""
.endif

# cdparanoia
.ifndef(WITH_CDPARANOIA)
CONFIGURE_ARGS+=	--disable-cdparanoia
PLIST_SUB+=	CDPARANOIA="@comment "
.else
LIB_DEPENDS+=	cdda_interface.0:${PORTSDIR}/audio/cdparanoia

PLIST_SUB+=	CDPARANOIA=""
.endif

# cdrom default device
.ifdef(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
. if ${OSVERSION} < 500000
DEFAULT_CDROM_DEVICE=/dev/acd0c
. else
DEFAULT_CDROM_DEVICE=/dev/acd0
. endif
.endif

# dts
.ifndef(WITH_DTS)
CONFIGURE_ARGS+=	--disable-dts
PLIST_SUB+=	DTS="@comment "
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdts_pic.a:${PORTSDIR}/multimedia/libdts
RUN_DEPENDS+=	${LOCALBASE}/lib/libdts_pic.a:${PORTSDIR}/multimedia/libdts
PLIST_SUB+=	DTS=""
.endif

# dvd default device
.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
. if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
. else
DEFAULT_DVD_DEVICE=/dev/acd0
. endif
.endif

# esound
.ifndef(WITH_ESOUND)
CONFIGURE_ARGS+=	--disable-esd \
			--disable-esdtest
PLIST_SUB+=	ESOUND="@comment "
.else
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--with-esd-prefix=${LOCALBASE}  \
			--with-esd-exec-prefix=${LOCALBASE}
PLIST_SUB+=	ESOUND=""
.endif

# faac
.ifndef(WITH_FAAC)
CONFIGURE_ARGS+=	--disable-faac
PLIST_SUB+=	FAAC="@comment "
.else
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
PLIST_SUB+=	FAAC=""
.endif

# faad
.ifndef(WITH_FAAD)
CONFIGURE_ARGS+=	--disable-faad
PLIST_SUB+=	FAAD="@comment "
.else
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
PLIST_SUB+=	FAAD=""
.endif

# flac
.ifndef(WITH_FLAC)
CONFIGURE_ARGS+=	--disable-flac
PLIST_SUB+=	FLAC="@comment "
.else
LIB_DEPENDS+=	FLAC.5:${PORTSDIR}/audio/flac

PLIST_SUB+=	FLAC=""
.endif

# freetype
.ifndef(WITH_FREETYPE)
CONFIGURE_ARGS+=	--disable-freetypetest
PLIST_SUB+=	FREETYPE="@comment "
.else
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2

CONFIGURE_ARGS+=	--with-ft-prefix=${LOCALBASE}  \
			--with-ft-exec-prefix=${LOCALBASE}
PLIST_SUB+=	FREETYPE=""
.endif

# gdkpixbuf
.ifndef(WITH_GDKPIXBUF)
CONFIGURE_ARGS+=	--disable-gdk_pixbuf
PLIST_SUB+=	GDKPIXBUF="@comment "
.else
USE_GNOME+=	gtk20
PLIST_SUB+=	GDKPIXBUF=""
.endif

# gnomevfs
.ifndef(WITH_GNOMEVFS)
CONFIGURE_ARGS+=	--disable-gnome_vfs
PLIST_SUB+=	GNOMEVFS="@comment "
.else
USE_GNOME+=	gnomevfs2
PLIST_SUB+=	GNOMEVFS=""
.endif

# gsm
.ifndef(WITH_GSM)
CONFIGURE_ARGS+=	--disable-gsm
PLIST_SUB+=	GSM="@comment "
.else
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm

PLIST_SUB+=	GSM=""
.endif

# jack
.ifndef(WITH_JACK)
CONFIGURE_ARGS+=	--disable-jack
PLIST_SUB+=	JACK="@comment "
.else
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.endif

# KIO
.ifndef(WITH_KIO)
CONFIGURE_ARGS+=	--disable-kio
PLIST_SUB+=	KIO="@comment "
.else
LIB_DEPENDS+=	kio.6:${PORTSDIR}/x11/kdelibs3

CONFIGURE_ENV+=	KDE_PREFIX="${LOCALBASE}" \
		KDE_MOC="${X11BASE}/bin/moc" \
		QTDIR="${X11BASE}"
PLIST_SUB+=	KIO=""
.endif

# Hermes
.ifndef(WITH_HERMES)
CONFIGURE_ARGS+=	--disable-hermes
PLIST_SUB+=	HERMES="@comment "
.else
LIB_DEPENDS+=	Hermes.1:${PORTSDIR}/graphics/Hermes
PLIST_SUB+=	HERMES=""
.endif

# jpeg
.ifndef(WITH_JPEG)
CONFIGURE_ARGS+=	--disable-jpeg
PLIST_SUB+=	JPEG="@comment "
.else
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg

PLIST_SUB+=	JPEG=""
.endif

# ladspa
.ifndef(WITH_LADSPA)
CONFIGURE_ARGS+=	--disable-ladspa
PLIST_SUB+=	LADSPA="@comment "
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

PLIST_SUB+=	LADSPA=""
.endif

# lame
.ifndef(WITH_LAME)
CONFIGURE_ARGS+=	--disable-lame
PLIST_SUB+=	LAME="@comment "
.else
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame

PLIST_SUB+=	LAME=""
.endif

# liba52
.ifndef(WITH_LIBA52)
CONFIGURE_ARGS+=	--disable-a52dec
PLIST_SUB+=	LIBA52="@comment "
.else
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52

CONFIGURE_ARGS+=	--with-a52dec-prefix=${LOCALBASE}
PLIST_SUB+=	LIBA52=""
.endif

# libaudiofile
.ifndef(WITH_LIBAUDIOFILE)
CONFIGURE_ARGS+=	--disable-audiofile
PLIST_SUB+=	LIBAUDIOFILE="@comment "
.else
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile

PLIST_SUB+=	LIBAUDIOFILE=""
.endif

# libcaca
.ifndef(WITH_LIBCACA)
CONFIGURE_ARGS+=	--disable-libcaca
PLIST_SUB+=	LIBCACA="@comment "
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcaca.a:${PORTSDIR}/graphics/libcaca
PLIST_SUB+=	LIBCACA=""
.endif

# libdv
.ifndef(WITH_LIBDV)
CONFIGURE_ARGS+=	--disable-libdv
PLIST_SUB+=	LIBDV="@comment "
.else
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv

PLIST_SUB+=	LIBDV=""
.endif

# libdvdnav
.ifndef(WITH_LIBDVDNAV)
CONFIGURE_ARGS+=	--disable-dvdnav
PLIST_SUB+=	LIBDVDNAV="@comment "
.else
LIB_DEPENDS+=	dvdnav.3:${PORTSDIR}/multimedia/libdvdnav

PLIST_SUB+=	LIBDVDNAV=""
.endif

# libdvdread
.ifndef(WITH_LIBDVDREAD)
CONFIGURE_ARGS+=	--disable-dvdread
PLIST_SUB+=	LIBDVDREAD="@comment "
.else
LIB_DEPENDS+=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

PLIST_SUB+=	LIBDVDREAD=""
.endif

# libfame
.ifndef(WITH_LIBFAME)
CONFIGURE_ARGS+=	--disable-libfame \
			--disable-libfametest
PLIST_SUB+=	LIBFAME="@comment "
.else
LIB_DEPENDS+=	fame-0.9.1:${PORTSDIR}/multimedia/libfame

CONFIGURE_ARGS+=	--with-libfame-prefix=${LOCALBASE} \
			--with-libfame-exec-prefix=${LOCALBASE}
PLIST_SUB+=	LIBFAME=""
.endif

# libmikmod
.ifndef(WITH_LIBMIKMOD)
CONFIGURE_ARGS+=	--disable-libmikmodtest \
			--disable-mikmod
PLIST_SUB+=	LIBMIKMOD="@comment "
.else
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod

CONFIGURE_ARGS+=	--with-libmikmod-prefix=${LOCALBASE} \
			--with-libmikmod-exec-prefix=${LOCALBASE}
PLIST_SUB+=	LIBMIKMOD=""
.endif

# libmpeg2
.ifndef(WITH_LIBMPEG2)
CONFIGURE_ARGS+=	--disable-mpeg2dec
PLIST_SUB+=	LIBMPEG2="@comment "
.else
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2

PLIST_SUB+=	LIBMPEG2=""
.endif

# libmusicbrainz
.ifndef(WITH_LIBMUSICBRAINZ)
CONFIGURE_ARGS+=	--disable-musicbrainz
PLIST_SUB+=	LIBMUSICBRAINZ="@comment "
.else
LIB_DEPENDS+=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz
PLIST_SUB+=	LIBMUSICBRAINZ=""
.endif

# libshout
.ifndef(WITH_LIBSHOUT)
CONFIGURE_ARGS+=	--disable-shout
PLIST_SUB+=	LIBSHOUT="@comment "
.else
LIB_DEPENDS+=	shout.2:${PORTSDIR}/audio/libshout

PLIST_SUB+=	LIBSHOUT=""
.endif

# libsidplay
.ifndef(WITH_LIBSIDPLAY)
CONFIGURE_ARGS+=	--disable-sidplay
PLIST_SUB+=	LIBSIDPLAY="@comment "
.else
LIB_DEPENDS+=	sidplay.1:${PORTSDIR}/audio/libsidplay

PLIST_SUB+=	LIBSIDPLAY=""
.endif

# libsndfile
.ifndef(WITH_LIBSNDFILE)
CONFIGURE_ARGS+=	--disable-sndfile
PLIST_SUB+=	LIBSNDFILE="@comment "
.else
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
PLIST_SUB+=	LIBSNDFILE=""
.endif

# libtheora
.ifndef(WITH_LIBTHEORA)
CONFIGURE_ARGS+=	--disable-theora
PLIST_SUB+=	LIBTHEORA="@comment "
.else
LIB_DEPENDS+=	theora.0:${PORTSDIR}/graphics/libtheora
PLIST_SUB+=	LIBTHEORA=""
.endif

# mad
.ifndef(WITH_MAD)
CONFIGURE_ARGS+=	--disable-mad
PLIST_SUB+=	LIBMAD="@comment "
.else
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad \
		id3tag.2:${PORTSDIR}/audio/libid3tag

PLIST_SUB+=	LIBMAD=""
.endif

# mjpegtools
.ifndef(WITH_MJPEGTOOLS)
CONFIGURE_ARGS+=	--disable-mpeg2enc
PLIST_SUB+=	MJPEGTOOLS="@comment "
.else
LIB_DEPENDS+=	lavjpeg-1.6.2:${PORTSDIR}/multimedia/mjpegtools

# XXX - make sure CONFIGURE works with mpeg2enc even with "ccache
# c++" ... weird but necessary
CONFIGURE_ENV+=	HAVE_CXX=yes

PLIST_SUB+=	MJPEGTOOLS=""
.endif

# nas
.ifndef(WITH_NAS)
CONFIGURE_ARGS+=	--disable-nas
PLIST_SUB+=	NAS="@comment "
.else
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas

PLIST_SUB+=	NAS=""
.endif

# ogg
.ifndef(WITH_OGG)
CONFIGURE_ARGS+=	--disable-ogg \
			--disable-oggtest
PLIST_SUB+=	OGG="@comment "
.else
LIB_DEPENDS+=	ogg.5:${PORTSDIR}/audio/libogg
PLIST_SUB+=	OGG=""
.endif

# oss
.ifdef(WITHOUT_OSS)
CONFIGURE_ARGS+=	--disable-oss
PLIST_SUB+=	OSS="@comment "
.else
PLIST_SUB+=	OSS=""
.endif

# pango
.ifndef(WITH_PANGO)
CONFIGURE_ARGS+=	--disable-pango
PLIST_SUB+=	PANGO="@comment "
.else
USE_GNOME+=	pango
PLIST_SUB+=	PANGO=""
.endif

# png
.ifndef(WITH_PNG)
CONFIGURE_ARGS+=	--disable-libpng
PLIST_SUB+=	PNG="@comment "
.else
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png

PLIST_SUB+=	PNG=""
.endif

# sdl
.ifndef(WITH_SDL)
CONFIGURE_ARGS+=	--disable-sdl \
			--disable-sdltest
PLIST_SUB+=	SDL="@comment "
.else
USE_SDL=	sdl

CONFIGURE_ARGS+=	--with-sdl-prefix=${LOCALBASE}  \
			--with-sdl-exec-prefix=${LOCALBASE}
CONFIGURE_ENV+=		SDL_CONFIG=${SDL_CONFIG}
PLIST_SUB+=	SDL=""
.endif

# smoothwave
.ifndef(WITH_SMOOTHWAVE)
CONFIGURE_ARGS+=	--disable-smoothwave
PLIST_SUB+=	SMOOTHWAVE="@comment "
.else
USE_GNOME+=	gtk20
PLIST_SUB+=	SMOOTHWAVE=""
.endif

# speex
.ifndef(WITH_SPEEX)
CONFIGURE_ARGS+=	--disable-speex
PLIST_SUB+=	SPEEX="@comment "
.else
LIB_DEPENDS+=	speex.3:${PORTSDIR}/audio/speex
PLIST_SUB+=	SPEEX=""
.endif

# swfdec
.ifndef(WITH_SWFDEC)
CONFIGURE_ARGS+=	--disable-swfdec
PLIST_SUB+=	SWFDEC="@comment "
.else
LIB_DEPENDS+=	swfdec.0:${PORTSDIR}/graphics/swfdec

CONFIGURE_ARGS+=	--enable-swfdec
PLIST_SUB+=	SWFDEC=""
.endif

# vorbis
.ifndef(WITH_VORBIS)
CONFIGURE_ARGS+=	--disable-vorbis \
			--disable-vorbistest
PLIST_SUB+=	VORBIS="@comment "
.else
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis

CONFIGURE_ARGS+=	--with-vorbis=${LOCALBASE} \
			--with-vorbis-libraries=${LOCALBASE}/lib \
			--with-vorbis-includes=${LOCALBASE}/include
PLIST_SUB+=	VORBIS=""
.endif

# vorbisidec
.ifndef(WITH_VORBISIDEC)
CONFIGURE_ARGS+=	--disable-ivorbis
PLIST_SUB+=	IVORBIS="@comment "
.else
LIB_DEPENDS+=	vorbisidec.1:${PORTSDIR}/audio/libtremor
PLIST_SUB+=	IVORBIS=""
.endif

# xine
.ifndef(WITH_XINE)
CONFIGURE_ARGS+=	--disable-xine
PLIST_SUB+=	XINE="@comment "
.else
CONFIGURE_ARGS+=	--enable-xine
LIB_DEPENDS+=	xine.9:${PORTSDIR}/multimedia/libxine

PLIST_SUB+=	XINE=""
.endif

# xvid
.ifndef(WITH_XVID)
CONFIGURE_ARGS+=	--disable-xvid
PLIST_SUB+=	XVID="@comment "
.else
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
PLIST_SUB+=	XVID=""
.endif

post-build:
.ifdef(EXTRA_BUILD_DIR)
. for dir in ${EXTRA_BUILD_DIR}
	@cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
. endfor
.endif

post-install:
.ifdef(EXTRA_BUILD_DIR)
. for dir in ${EXTRA_BUILD_DIR}
	@cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
. endfor
.endif
# register plugins
	-@${X11BASE}/bin/gst-register-${GST_VERSION} \
		--gst-registry=${PREFIX}/share/gnome/cache/gstreamer-${GST_VERSION}/registry.xml 2>/dev/null

pre-everything::
.ifndef(WITH_AALIB)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_AALIB to enable aalib Video plugin'
.endif
.ifdef(WITH_ARTS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITHOUT_ARTS to disable aRts Audio plugin'
.else
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_ARTS to enable aRts Audio plugin'
.endif
.ifndef(WITH_CDPARANOIA)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_CDPARANOIA to enable cdparanoia Audio plugin'
.endif
.ifndef(WITH_CDROM_DEVICE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> The default CDROM device is ${DEFAULT_CDROM_DEVICE}'
	@${ECHO_MSG} '===> Define WITH_CDROM_DEVICE if you want to change the default'
	@${ECHO_MSG} '===> For example, make WITH_CDROM_DEVICE="/dev/somedevice"'
.endif
.ifndef(WITH_DTS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_DTS to enable DTS decoding support'
.endif
.ifndef(WITH_DVD_DEVICE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> The default DVD device is ${DEFAULT_DVD_DEVICE}'
	@${ECHO_MSG} '===> Define WITH_DVD_DEVICE if you want to change the default'
	@${ECHO_MSG} '===> For example, make WITH_DVD_DEVICE="/dev/somedevice"'
.endif
.ifndef(WITH_ESOUND)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_ESOUND to enable esound Audio plugin'
.endif
.ifndef(WITH_FAAC)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_FAAC to enable faac Audio plugin'
.endif
.ifndef(WITH_FAAD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_FAAD to enable faad Audio plugin'
.endif
.ifndef(WITH_FLAC)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_FLAC to enable flac Audio plugin'
.endif
.ifndef(WITH_FREETYPE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_FREETYPE to enable freetype support'
.endif
.ifndef(WITH_GDKPIXBUF)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_GDKPIXBUF to enable gdk-pixbuf plugin'
.endif
.ifndef(WITH_GSM)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_GSM to enable gsm Audio plugin'
.endif
.ifndef(WITH_GNOMEVFS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_GNOMEVFS to enable gnomevfs Network plugin'
.endif
.ifndef(WITH_JACK)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_JACK to enable jackd audio plugin'
.endif
.ifndef(WITH_KIO)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_KIO to enable support for KIO slave sources'
.endif
.ifndef(WITH_HERMES)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_HERMES to enable Hermes colorspace plugin'
.endif
.ifndef(WITH_JPEG)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_JPEG to enable jpeg Video plugin'
.endif
.ifndef(WITH_LADSPA)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LADSPA to enable LADSPA framework Audio plugin'
.endif
.ifndef(WITH_LAME)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LAME to enable lame MP3 Audio plugin'
.endif
.ifndef(WITH_LIBA52)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBA52 to enable liba52 AC3 Audio plugin'
.endif
.ifndef(WITH_LIBAUDIOFILE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBAUDIOFILE to enable libaudiofile Audio plugin'
.endif
.ifndef(WITH_LIBCACA)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBCACA to enable libcaca Video plugin'
.endif
.ifndef(WITH_LIBDV)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBDV to enable libdv Video plugin'
.endif
.ifndef(WITH_LIBDVDNAV)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBDVDNAV to enable libdvdnav Video plugin'
.endif
.ifndef(WITH_LIBDVDREAD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBDVDREAD to enable libdvdread Video plugin'
.endif
.ifndef(WITH_LIBFAME)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBFAME to enable libfame Video plugin'
.endif
.ifndef(WITH_LIBMIKMOD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBMIKMOD to enable libmikmod Audio plugin'
.endif
.ifndef(WITH_LIBMPEG2)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBMPEG2 to enable libmpeg2 Video plugin'
.endif
.ifndef(WITH_LIBMUSICBRAINZ)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBMUSICBRAINZ to enable libmusicbrainz Audio plugin'
.endif
.ifndef(WITH_LIBSHOUT)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBSHOUT to enable libshout Audio plugin'
.endif
.ifndef(WITH_LIBSIDPLAY)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBSIDPLAY to enable libsidplay Audio plugin'
.endif
.ifndef(WITH_LIBSNDFILE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBSNDFILE to enable libsndfile Audio plugin'
.endif
.ifndef(WITH_LIBTHEORA)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBTHEORA to enable libtheora Video plugin'
.endif
.ifndef(WITH_MAD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_MAD to enable mad Audio plugin'
.endif
.ifndef(WITH_NAS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_NAS to enable nas Audio plugin'
.endif
.ifndef(WITHOUT_OSS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITHOUT_OSS to disable OSS Audio plugin'
.endif
.ifndef(WITH_PANGO)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_PANGO to enable pango textoverlay plugin'
.endif
.ifndef(WITH_PNG)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_PNG to enable png Video plugin'
.endif
.ifndef(WITH_SDL)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_SDL to enable SDL Video plugin'
.endif
.ifndef(WITH_SMOOTHWAVE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_SMOOTHWAVE to enable Smoothwave Video plugin'
.endif
.ifndef(WITH_SPEEX)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_SPEEX to enable Speex Video plugin'
.endif
.ifndef(WITH_SWFDEC)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_SWFDEC to enable Flash Video plugin'
.endif
.ifndef(WITH_VORBIS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_VORBIS to enable vorbis Audio plugin'
.endif
.ifndef(WITH_VORBISIDEC)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_VORBISIDEC to enable vorbisidec Audio plugin'
.endif
.ifndef(WITH_XINE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_XINE to enable xine plugin'
.endif
.ifndef(WITH_XVID)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_XVID to enable xvid Video plugin'
.endif

.include <bsd.port.post.mk>
