# New ports collection makefile for:	gstreamer plugins
# Date created:		Wed Jul 10 23:38:01 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.6.4
PORTREVISION=	3
CATEGORIES=	multimedia audio
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gst-plugins/0.6
PKGNAMESUFFIX=	-plugins
DISTNAME=	gst-plugins-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GStreamer written collection of plugins handling several media types

LIB_DEPENDS=	gstreamer-0.6.1:${PORTSDIR}/multimedia/gstreamer \
		popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack \
		gnomehier \
		gnomeprefix \
		pkgconfig \
		gconf2
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-alsa \
		--disable-cdrom \
		--disable-mjpegtools \
		--disable-qcam \
		--disable-v4l2 \
		--disable-v4l
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib -L${LOCALBASE}/lib"
CONFIGURE_TARGET=
PLIST_SUB=	\
		VERSION="${PORTVERSION:C/..$//}" \
		SHLIB_VERSION="${SHLIB_VERSION}"
INSTALLS_SHLIB=	yes

# for esound detection
WANT_GNOME=	yes

MAN1=	gst-launch-ext.1 gst-visualise.1

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"
SDL_CONFIG?="${LOCALBASE}/bin/sdl11-config"
XMMS_CONFIG?="${LOCALBASE}/bin/xmms-config"

# library minor number
SHLIB_VERSION=  1

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
# no linux/cdrom.h
	@${REINPLACE_CMD} -E -e \
		's|^#include[[:space:]]+.+linux/cdrom\.h.*$$||' \
		${WRKSRC}/ext/dvdread/dvdreadsrc.c
# malloc.h was deprecated in favor of stdlib.h
# inttypes.h not stdint.h
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|malloc.h|stdlib.h|; \
		s|stdint.h|inttypes.h|'
# use GMAKE, not MAKE
	@${REINPLACE_CMD} -E -e \
		's|make|${GMAKE}|' \
		${WRKSRC}/gst-libs/ext/ffmpeg/Makefile.in
# force libaudiofile detection
	@${REINPLACE_CMD} -E -e \
		's|^.*afOpenVirtualFile[[:space:]]*\(\);|;|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
# CC safeness
	@${ECHO_CMD} "CC=${CC}" >> \
		${WRKSRC}/gst-libs/ext/ffmpeg/ffmpeg/config.mak

.include <bsd.port.pre.mk>

post-install:
.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
# register plugins
	@-${X11BASE}/bin/gst-register 2>/dev/null
.else
	@${X11BASE}/bin/gst-register 2>/dev/null
.endif

# Fix build on ia64.  This patch breaks other archs, so include it
# conditionally
.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
EXTRA_PATCHES=	${FILESDIR}/ia64-patch-ffmpeg::configure
.endif

# hermes is required for gstreamer-player to work
# since it is currently the only colorspace plugin available
WITH_HERMES=	yes
# gnomevfs is required for gstreamer-player to work
WITH_GNOMEVFS=	yes

##
## auto detect possible plugins
##

# aalib
.if exists(${LOCALBASE}/lib/libaa.a)
WITH_AALIB=yes
.endif

# arts
.if exists(${LOCALBASE}/lib/libartsc.so.0)
WITH_ARTS=yes
.endif

# avifile
.if exists(${LOCALBASE}/lib/libaviplay.a)
WITH_AVIFILE=yes
.endif

# cdparanoia
.if exists(${LOCALBASE}/lib/libcdda_paranoia.a)
WITH_CDPARANOIA=yes
.endif

# esound
.if (${HAVE_GNOME:Mesound}!="")
WITH_ESOUND=yes
.endif

# flac
.if exists(${LOCALBASE}/lib/libFLAC.a)
WITH_FLAC=yes
.endif

# freetype
.if exists(${LOCALBASE}/lib/libfreetype.a)
WITH_FREETYPE=yes
.endif

# lame
.if exists(${LOCALBASE}/lib/libmp3lame.a)
WITH_LAME=yes
.endif

# gnomevfs
.if ${HAVE_GNOME:Mgnomevfs2}!=""
WITH_GNOMEVFS=yes
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
# XXX libdvdnav needs to be updated to 0.1.9 or higher
#.if exists(${LOCALBASE}/lib/libdvdnav.so)
.undef WITH_LIBDVDNAV
#.endif

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

# libshout
.if exists(${LOCALBASE}/lib/libshout.a)
WITH_LIBSHOUT=yes
.endif

# libsidplay
.if exists(${LOCALBASE}/lib/libsidplay.a)
WITH_LIBSIDPLAY=yes
.endif

# mad
.if exists(${LOCALBASE}/lib/libmad.a)
WITH_MAD=yes
.endif

# openquicktime
.if exists(${LOCALBASE}/lib/libopenquicktime.so)
WITH_OPENQUICKTIME=yes
.endif

# png
.if exists(${LOCALBASE}/lib/libpng.a)
WITH_PNG=yes
.endif

# sdl
.if exists(${LOCALBASE}/lib/libSDL-1.1.a)
WITH_SDL=yes
.endif

# swfdec
.if exists(${X11BASE}/lib/libswfdec.a)
WITH_SWFDEC=yes
.endif

# vorbis
.if exists(${LOCALBASE}/lib/libvorbis.a)
WITH_VORBIS=yes
.endif

# xmms
.if exists(${X11BASE}/lib/libxmms.a)
#WITH_XMMS=yes
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

# avifile
.ifndef(WITH_AVIFILE)
CONFIGURE_ARGS+=	--disable-avifile
PLIST_SUB+=	AVIFILE="@comment "
.else
LIB_DEPENDS+=	aviplay.0:${PORTSDIR}/multimedia/avifile

PLIST_SUB+=	AVIFILE=""
.endif

# cdparanoia
.ifndef(WITH_CDPARANOIA)
CONFIGURE_ARGS+=	--disable-cdparanoia
PLIST_SUB+=	CDPARANOIA="@comment "
.else
LIB_DEPENDS+=	cdda_interface.0:${PORTSDIR}/audio/cdparanoia

PLIST_SUB+=	CDPARANOIA=""
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

# Hermes
.ifndef(WITH_HERMES)
CONFIGURE_ARGS+=	--disable-hermes
PLIST_SUB+=	HERMES="@comment "
.else
LIB_DEPENDS+=	Hermes.1:${PORTSDIR}/graphics/Hermes
PLIST_SUB+=	HERMES=""
.endif

# http
.ifndef(WITH_HTTP)
CONFIGURE_ARGS+=	--disable-http
PLIST_SUB+=	HTTP="@comment "
.else
USE_GNOME+=	libghttp
PLIST_SUB+=	HTTP=""
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

# libdv
.ifndef(WITH_LIBDV)
CONFIGURE_ARGS+=	--disable-libdv
PLIST_SUB+=	LIBDV="@comment "
.else
LIB_DEPENDS+=	dv.3:${PORTSDIR}/multimedia/libdv

PLIST_SUB+=	LIBDV=""
.endif

# libdvdnav
.ifndef(WITH_LIBDVDNAV)
CONFIGURE_ARGS+=	--disable-dvdnav
PLIST_SUB+=	LIBDVDNAV="@comment "
.else
LIB_DEPENDS+=	dvdnav.1:${PORTSDIR}/multimedia/libdvdnav

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
LIB_DEPENDS+=	fame-0.9.0:${PORTSDIR}/multimedia/libfame

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

CONFIGURE_ARGS+=	--with-mpeg2dec-prefix=${LOCALBASE}
PLIST_SUB+=	LIBMPEG2=""
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

# mad
.ifndef(WITH_MAD)
CONFIGURE_ARGS+=	--disable-mad
PLIST_SUB+=	LIBMAD="@comment "
.else
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad \
		id3tag.2:${PORTSDIR}/audio/libid3tag

PLIST_SUB+=	LIBMAD=""
.endif

# openquicktime
.ifndef(WITH_OPENQUICKTIME)
CONFIGURE_ARGS+=	--disable-openquicktime
PLIST_SUB+=	OPENQUICKTIME="@comment "
.else
LIB_DEPENDS+=	openquicktime.0:${PORTSDIR}/multimedia/openquicktime

PLIST_SUB+=	OPENQUICKTIME=""
.endif

# oss
.ifdef(WITHOUT_OSS)
CONFIGURE_ARGS+=	--disable-oss
PLIST_SUB+=	OSS="@comment "
.else
PLIST_SUB+=	OSS=""
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
LIB_DEPENDS+=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

CONFIGURE_ARGS+=	--with-sdl-prefix=${LOCALBASE}  \
			--with-sdl-exec-prefix=${LOCALBASE}
CONFIGURE_ENV+=		SDL_CONFIG=${SDL_CONFIG}
PLIST_SUB+=	SDL=""
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

# xmms
.ifndef(WITH_XMMS)
CONFIGURE_ARGS+=	--disable-xmms
PLIST_SUB+=	XMMS="@comment "
.else
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms

CONFIGURE_ARGS+=	--with-xmms-prefix=${X11BASE} \
			--with-xmms-exec-prefix=${X11BASE}
CONFIGURE_ENV+=		XMMS_CONFIG=${XMMS_CONFIG}
PLIST_SUB+=	XMMS=""
.endif

pre-everything::
.ifndef(WITH_AALIB)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_AALIB to enable aalib Video plugin'
.endif
.ifndef(WITH_ARTS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_ARTS to enable arts Audio plugin'
.endif
.ifndef(WITH_AVIFILE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_AVIFILE to enable avifile Video plugin'
.endif
.ifndef(WITH_CDPARANOIA)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_CDPARANOIA to enable cdparanoia Audio plugin'
.endif
.ifndef(WITH_ESOUND)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_ESOUND to enable esound Audio plugin'
.endif
.ifndef(WITH_FLAC)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_FLAC to enable flac Audio plugin'
.endif
.ifndef(WITH_FREETYPE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_FREETYPE to enable freetype support'
.endif
.ifndef(WITH_GSM)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_GSM to enable gsm Audio plugin'
.endif
.ifndef(WITH_GNOMEVFS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_GNOMEVFS to enable gnomevfs Network plugin'
.endif
.ifndef(WITH_HERMES)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_HERMES to enable Hermes colorspace plugin'
.endif
.ifndef(WITH_HTTP)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_HTTP to enable http Network plugin'
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
.ifndef(WITH_LIBSHOUT)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBSHOUT to enable libshout Audio plugin'
.endif
.ifndef(WITH_LIBSIDPLAY)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBSIDPLAY to enable libsidplay Audio plugin'
.endif
.ifndef(WITH_MAD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_MAD to enable mad Audio plugin'
.endif
.ifndef(WITH_OPENQUICKTIME)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_OPENQUICKTIME to enable openquicktime Video plugin'
.endif
.ifndef(WITHOUT_OSS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITHOUT_OSS to disable OSS Audio plugin'
.endif
.ifndef(WITH_PNG)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_PNG to enable png Video plugin'
.endif
.ifndef(WITH_SDL)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_SDL to enable SDL Video plugin'
.endif
.ifndef(WITH_SWFDEC)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_SWFDEC to enable Flash Video plugin'
.endif
.ifndef(WITH_VORBIS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_VORBIS to enable vorbis Audio plugin'
.endif
.ifndef(WITH_XMMS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_XMMS to enable xmms Audio plugin'
.endif

.include <bsd.port.post.mk>
