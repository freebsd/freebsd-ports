# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#
# Options to define Features:
# WITH_AUTODETECT=yes
#
# WITH_GNOME=yes
#  Gnome Interface
#
# WITHOUT_GTKVLC=yes
#  Gtk12 Interface (Default interface)
#
# WITH_ESOUND=yes
#
# WITH_AALIB=yes
#
# WITH_CDDB=yes
#
# WITH_DTS=yes
#
# WITH_FRIBIDI=yes
#
# WITH_GGI=yes
#
# WITH_LIBDVBPSI=yes
#
# WITH_LIBID3TAG=yes
#
# WITH_LIBMATROSKA=yes
#
# WITH_LIBMPEG2=yes
#
# WITH_LIBTHEORA=yes
#
# WITH_LIVEMEDIA=yes
#
# WITH_NCURSES=yes
#  Ncurses interface
#
# WITH_SPEEX=yes
#
# WITH_SVGALIB=yes
#
# WITH_XOSD=yes
#
# WITHOUT_XVID=yes
#
# WITH_WXWINDOWS=yes
#  WxWindows Interface
#
# WITH_OPTIMIZED_CFLAGS=yes
#
# WITH_DVD_DEVICE=/dev/somedevice (5.x: default is acd0, 4:x default is acd0c)
# WITH_CDROM_DEVICE=/dev/somedevice
#
# WITHOUT_NLS=yes
#
# WITHOUT_LIBID3TAG=yes

PORTNAME=	vlc
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/vlc/${PORTVERSION}/
PKGNAMESUFFIX?=	${GNOME_SUFFIX}${ESOUND_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Multimedia streaming server and player for various audio/video formats

LIB_DEPENDS=	dvdnav.3:${PORTSDIR}/multimedia/libdvdnav \
		mad.2:${PORTSDIR}/audio/libmad \
		avcodec.0:${PORTSDIR}/${FFMPEG_PORT} \
		a52.0:${PORTSDIR}/audio/liba52 \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		FLAC.5:${PORTSDIR}/audio/flac \
		faad.0:${PORTSDIR}/audio/faad \
		slp.1:${PORTSDIR}/net/openslp \
		vcdinfo.0:${PORTSDIR}/multimedia/vcdimager

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_ICONV=	yes
USE_REINPLACE=	yes
USE_SDL=	sdl
USE_XLIB=	yes
USE_ICONV=	yes

PLIST=		${WRKDIR}/plist
FAKEDIR=	${WRKDIR}/fake

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PATH_GTKCONFIG="${GTK_CONFIG}" CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--with-dvdcss=${LOCALBASE} \
		--with-dvdread=${LOCALBASE} \
		--with-mad=${LOCALBASE} \
		--with-faad=${LOCALBASE} \
		--with-a52=${LOCALBASE} \
		--enable-ffmpeg \
		--with-ffmpeg=${LOCALBASE} \
		--disable-libcdio \
		--disable-skins2 \
		--without-libintl-prefix
CONFIGURE_TARGET+=-build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		vlc.1 \
		vlc-config.1

FFMPEG_PORT?=	multimedia/ffmpeg
CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
CFLAGS+=	${CPPFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
BREAKS_IF_PEDANTIC=	yes

# Broken
WITHOUT_SPEEX=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

.if ${HAVE_GNOME:Mgnomelibs}!="" && !defined(WITHOUT_GNOME)
WITH_GNOME=	yes
.endif

.if ${HAVE_GNOME:Mesound}!="" && !defined(WITHOUT_ESOUND)
WITH_ESOUND=	yes
.endif

.if defined(WITH_AUTODETECT) && !defined(BATCH)

.if exists(${LOCALBASE}/lib/libaa.so.1) && !defined(WITHOUT_AALIB)
WITH_AALIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libcddb.so.1) && !defined(WITHOUT_CDDB)
WITH_CDDB=	yes
.endif

.if exists(${LOCALBASE}/lib/libdts.a) && !defined(WITHOUT_DTS)
WITH_DTS=	yes
.endif

.if exists(${LOCALBASE}/bin/fribidi-config) && !defined(WITHOUT_FRIBIDI)
WITH_FRIBIDI=	yes
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

.if exists(${LOCALBASE}/lib/libmatroska.a) && !defined(WITHOUT_LIBMATROSKA)
WITH_LIBMATROSKA=yes
.endif

.if exists(${LOCALBASE}/lib/libspeex.so.3) && !defined(WITHOUT_SPEEX)
WITH_SPEEX=	yes
.endif

.if exists(${LOCALBASE}/lib/lib/vga.so.1) && !defined(WITHOUT_SVGALIB)
WITH_SVGALIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libxosd.so.4) && !defined(WITHOUT_XOSD)
WITH_XOSD=	yes
.endif

.endif

.if defined(WITH_MATROSKA)
WITH_LIBMATROSKA=yes
.endif

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

.if defined(WITH_GNOME) && !defined(WITHOUT_GNOME)
GNOME_SUFFIX=	-gnome
USE_GNOME+=	gnomelibs
CONFIGURE_ARGS+=--enable-gnome
.endif

.if defined(WITHOUT_GTKVLC)
CONFIGURE_ARGS+=--disable-gtk
.endif

.if defined(WITH_WXWINDOWS) && !defined(WITHOUT_WXWINDOWS)
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2
CONFIGURE_ARGS+=--enable-wxwindows
CONFIGURE_ENV+=	WX_CONFIG=${X11BASE}/bin/wxgtk2-2.4-config
.else
CONFIGURE_ARGS+=--disable-wxwindows
.endif

.if defined(WITH_ESOUND) && !defined(WITHOUT_ESOUND)
ESOUND_SUFFIX=	-esound
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
.endif

.if defined(WITH_FRIBIDI) && !defined(WITHOUT_FRIBIDI)
LIB_DEPENDS+=	fribidi.0:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=--enable-fribidi
.endif

.if !defined(WITHOUT_LIBID3TAG)
LIB_DEPENDS+=	id3tag.2:${PORTSDIR}/audio/libid3tag
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

.if defined(WITH_DTS) && !defined(WITHOUT_DTS)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdts.a:${PORTSDIR}/multimedia/libdts
CONFIGURE_ARGS+=--enable-dts
.else
CONFIGURE_ARGS+=--disable-dts
.endif

.if defined(WITH_GGI) && !defined(WITHOUT_GGI)
LIB_DEPENDS+=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--enable-ggi
.else
CONFIGURE_ARGS+=--disable-ggi
.endif

.if defined(WITH_LIBDVBPSI) && !defined(WITHOUT_LIBDVBPSI)
LIB_DEPENDS+=	dvbpsi.3:${PORTSDIR}/multimedia/libdvbpsi
CONFIGURE_ARGS+=--with-dvbpsi=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-dvbpsi
.endif

.if defined(WITH_LIBMATROSKA) && !defined(WITHOUT_LIBMATROSKA)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmatroska.a:${PORTSDIR}/multimedia/libmatroska
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
.else
CONFIGURE_ARGS+=--disable-theora
.endif

.if defined(WITH_LIVEMEDIA) && !defined(WITHOUT_LIVEMEDIA)
BUILD_DEPENDS+=	${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
CONFIGURE_ARGS+=--enable-livedotcom \
		--with-livedotcom-tree=${LOCALBASE}/live
.else
CONFIGURE_ARGS+=--disable-livedotcom
.endif

.if defined(WITH_NCURSES) && !defined(WITHOUT_NCURSES)
CONFIGURE_ARGS+=--enable-ncurses
.endif

.if defined(WITH_SPEEX) && !defined(WITHOUT_SPEEX)
LIB_DEPENDS+=	speex.3:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=--enable-speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if defined(WITH_SVGALIB) && !defined(WITHOUT_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--enable-svgalib
.else
CONFIGURE_ARGS+=--disable-svgalib
.endif

.if defined(WITH_XOSD) && !defined(WITHOUT_XOSD)
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=--enable-xosd
.else
CONFIGURE_ARGS+=--disable-xosd
.endif

.if !defined(WITHOUT_XVID)
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=--enable-xvideo
.else
CONFIGURE_ARGS+=--disable-xvideo
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

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
# libstdc++.a(eh_terminate.o): gp-relative relocation against dynamic symbol __cxxabiv1::__terminate_handler
BROKEN=		"gp-relative relocation against dynamic symbol"
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Take a careful look into the Makefile in order"
	@${ECHO_MSG} "to learn how to tune VLC towards you personal preferences!"
	@${ECHO_MSG} "For example, make WITH_AUTODETECT=yes"

post-patch:
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/' \
		-e 's/-lc_r/${PTHREAD_LIBS}/' \
		-e 's|postproc/postprocess.h|ffmpeg/postproc/postprocess.h|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|; \
		s|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/include/vlc_config.h

pre-install:
	${RM} -rf ${PLIST} ${FAKEDIR}
	${MKDIR} ${FAKEDIR}
	${TOUCH} -f ${PLIST}
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
	cd ${FAKEDIR}/share/vlc && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/vlc/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm share/vlc/|' >> ${PLIST}
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

do-install:
	cd ${FAKEDIR}/bin && ${FIND} . | \
		${CPIO} -pdm -R ${BINOWN}:${BINGRP} ${PREFIX}/bin
	cd ${FAKEDIR}/include && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include
	cd ${FAKEDIR}/lib && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib
	cd ${FAKEDIR}/share && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN} ${PREFIX}/share
	${INSTALL_MAN} ${WRKSRC}/doc/vlc.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/vlc-config.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
