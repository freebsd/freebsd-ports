# New ports collection makefile for:	mplayer
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#			with lots of help from Vladimir Kushnir
# $FreeBSD$
#

PORTNAME=	mplayer
PORTVERSION=	0.90.0.102
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www1.mplayerhq.hu/MPlayer/releases/ \
		http://www2.mplayerhq.hu/MPlayer/releases/ \
		http://ftp.lug.udel.edu/MPlayer/releases/ \
		http://www4.mplayerhq.hu/MPlayer/releases/ \
		ftp://ftp1.mplayerhq.hu/MPlayer/releases/ \
		ftp://ftp2.mplayerhq.hu/MPlayer/releases/ \
		ftp://ftp.lug.udel.edu/MPlayer/releases/ \
		http://www.rrr.de/~riggs/mplayer/
DISTNAME=	MPlayer-0.90rc2

MAINTAINER=	riggs@rrr.de

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		iconv.3:${PORTSDIR}/converters/libiconv \
		mp3lame.0:${PORTSDIR}/audio/lame

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS} \
		TMPDIR="${WRKSRC}"
CONFIGURE_ARGS=	--with-extralibdir=${LOCALBASE}/lib \
		--with-extraincdir=${LOCALBASE}/include \
		--with-x11libdir=${X11BASE}/lib \
		--with-x11incdir=${X11BASE}/include \
		--enable-png \
		--disable-tv-v4l \
		--disable-vidix

USE_GNOMENG=	yes
WANT_GNOME=	yes
MAN1=		mplayer.1
MLINKS=		mplayer.1 mencoder.1
MANCOMPRESSED=	no

CONFFILES=	codecs.conf example.conf input.conf menu.conf
DOCFILES=	bugreports.html cd-dvd.html codecs-in.html \
		codecs.html documentation.html faq.html skin-en.html \
		encoding.html formats.html sound.html \
		users_against_developers.html \
		video.html

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libartsc.so.0)
WITH_ARTS=	yes
.endif

.if exists(${LOCALBASE}/lib/libdv.so.2)
WITH_LIBDV=	yes
.endif

.if exists(${LOCALBASE}/lib/libdvdcss.so.2)
WITH_DVD=	yes
.endif

.if exists(${LOCALBASE}/lib/libdvdnav.so.1)
WITH_LIBDVDNAV=	yes
.endif

.if exists(${LOCALBASE}/lib/libmad.so.1)
WITH_MAD=	yes
.endif

.if exists(${LOCALBASE}/lib/libvga.so.1)
WITH_SVGALIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libSDL-1.1.so.5)
WITH_SDL=	yes
.endif

.if exists(${LOCALBASE}/lib/libvorbis.so.2)
WITH_VORBIS=	yes
.endif

.if exists(${LOCALBASE}/lib/libjpeg.so.9)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
.endif

.if exists(${X11BASE}/bin/xanim)
WITH_XANIM=	yes
.endif

.if exists(${LOCALBASE}/lib/RealPlayer8/realplay)
WITH_REALPLAYER=	yes
.endif

.if exists(${LOCALBASE}/live/liveMedia/libliveMedia.a)
WITH_LIVEMEDIA=	yes
.endif

.if exists(${LOCALBASE}/lib/libxvidcore.so)
WITH_XVID=	yes
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

.if ${HAVE_GNOME:Mgtk12}!=""
WITH_GUI=	yes
PLIST_SUB+=	GMPLAYER=""
.else
PLIST_SUB+=	GMPLAYER="@comment "
.endif

.if defined(WITH_GUI)
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
CONFIGURE_ARGS+=	--enable-gui
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts

CONFIGURE_ARGS+=	--enable-arts
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if defined(WITH_DVD)
.if !defined(WITH_LIBDVDREAD)
LIB_DEPENDS+=	dvdcss.2:${PORTSDIR}/multimedia/libdvdcss
.else
LIB_DEPENDS+=	dvdread.2:${PORTSDIR}/multimedia/libdvdread
.endif
.if defined(WITH_LIBDVDNAV)
LIB_DEPENDS+=	dvdnav.1:${PORTSDIR}/graphics/libdvdnav

CONFIGURE_ARGS+=	--enable-dvdnav
.else
CONFIGURE_ARGS+=	--disable-dvdnav
.endif

CONFIGURE_ARGS+=	--enable-css \
			--with-csslibdir=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-css
.endif

.if defined(WITH_LIBDV)
LIB_DEPENDS+=	dv.2:${PORTSDIR}/multimedia/libdv

CONFIGURE_ARGS+=	--enable-libdv
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif

.if defined(WITH_LIBFAME)
LIB_DEPENDS+=	fame-0.9.0:${PORTSDIR}/graphics/libfame

CONFIGURE_ARGS+=	--enable-libfame
.else
CONFIGURE_ARGS+=	--disable-libfame
.endif

.if defined(WITH_MAD)
LIB_DEPENDS+=	mad.1:${PORTSDIR}/audio/mad

CONFIGURE_ARGS+=	--enable-mad \
			--with-madlibdir=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-mad
.endif

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
.endif

.if defined(WITH_SDL)
LIB_DEPENDS+=	SDL-1.1.5:${PORTSDIR}/devel/sdl12
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.2:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_REALPLAYER)
CONFIGURE_ARGS+=	--enable-real \
			--with-reallibdir=${LOCALBASE}/lib/RealPlayer8/Codecs
RUN_DEPENDS+=		realplay:${PORTSDIR}/multimedia/linux-realplayer
BUILD_DEPENDS+=		realplay:${PORTSDIR}/multimedia/linux-realplayer
.endif

.if defined(WITH_LIVEMEDIA)
CONFIGURE_ARGS+=	--enable-live \
			--with-livelibdir=${LOCALBASE}/live
RUN_DEPENDS+=		${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
BUILD_DEPENDS+=		${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
.endif

.if defined(WITH_XVID)
CONFIGURE_ARGS+=	--enable-xvid \
			--with-xvidcore=${LOCALBASE}/lib/libxvidcore.so
LIB_DEPENDS+=		xvidcore.0:${PORTSDIR}/graphics/xvid
.endif

.if defined(WITH_FREETYPE)
CONFIGURE_ARGS+=	--with-extraincdir=${LOCALBASE}/include/freetype2 \
			--enable-freetype
LIB_DEPENDS+=		freetype.9:${PORTSDIR}/print/freetype2
.else
RUN_DEPENDS+=	${LOCALBASE}/share/mplayer/fonts:${PORTSDIR}/multimedia/mplayer-fonts
.endif

.if defined(WITH_XANIM)
BUILD_DEPENDS+=	xanim:${PORTSDIR}/graphics/xanim

CONFIGURE_ARGS+=--enable-xanim --with-xanimlibdir=${X11BASE}/lib/X11/xanim
.else
CONFIGURE_ARGS+=--disable-xanim
.endif

# "enable" build for other archs
.if ${ARCH} == "i386"
.if !defined(WITHOUT_RUNTIME_CPUDETECTION)
CONFIGURE_ARGS+=--enable-runtime-cpudetection
.else #WITHOUT_RUNTIME_CPUDETECTION
.if defined(WITHOUT_MMX)
CONFIGURE_ARGS+=--disable-mmx
.endif
.if defined(WITHOUT_3DNOW) || ${OSVERSION} < 400021
CONFIGURE_ARGS+=--disable-3dnow
.endif
.if defined(WITHOUT_DSP) || defined(WITHOUT_3DNOW) || ${OSVERSION} < 400021
CONFIGURE_ARGS+=--disable-3dnowex
.endif
.if defined(WITHOUT_SSE)
CONFIGURE_ARGS+=--disable-mmx2 --disable-sse
.endif
.endif #WITHOUT_RUNTIME_CPUDETECTION
.if !defined(WITH_SVGALIB)
CONFIGURE_ARGS+=--disable-svga
.endif
.if !defined(WITH_SDL)
CONFIGURE_ARGS+=--disable-sdl
.endif
.if !defined(WITH_VORBIS)
CONFIGURE_ARGS+=--disable-vorbis
.endif
.if !defined(WITHOUT_WIN32_CODECS)
RUN_DEPENDS+=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CONFIGURE_ARGS+=	--with-win32libdir=${LOCALBASE}/lib/win32

#CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_PORT=	${.CURDIR}/../win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
.else
CONFIGURE_ARGS+=	--disable-win32 \
			-disable-qtx-codecs
.endif
.endif # ARCH == i386

pre-everything::
.if defined(WITH_GUI)
	@${ECHO_MSG} "You can download official skin collections from"
	@${ECHO_MSG} "http://www.mplayerhq.hu/homepage/dload.html"
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif
.if !defined(WITH_GUI) && ${HAVE_GNOME:Mgtk12}==""
	@${ECHO_MSG} "You can enable GTK GUI by defining WITH_GUI."
.endif
.if !defined(WITH_DVD)
	@${ECHO_MSG} "You can enable DVD support by defining WITH_DVD."
.if !defined(WITH_LIBDVDNAV)
	@${ECHO_MSG} "You can enable libdvdnav support by defining WITH_LIBDVDNAV."
.endif
.endif
.if defined(WITH_DVD) && !defined(WITH_LIBDVDREAD)
	@${ECHO_MSG} "You can replace mplayer internal DVD routines with libdvdread"
	@${ECHO_MSG} "support by defining WITH_LIBDVDREAD."
.endif
.if !defined(WITH_LIBDV)
	@${ECHO_MSG} "You can enable libdv support by defining WITH_LIBDV."
.endif
.if !defined(WITH_LIBFAME)
	@${ECHO_MSG} "You can enable libfame support by defining WITH_LIBFAME."
.endif
.if !defined(WITH_MAD)
	@${ECHO_MSG} "You can enable mad support by defining WITH_MAD."
.endif
.if !defined(WITH_SVGALIB)
	@${ECHO_MSG} "You can enable SVGALIB support by defining WITH_SVGALIB."
.endif
.if !defined(WITH_SDL)
	@${ECHO_MSG} "You can enable SDL support by defining WITH_SDL."
.endif
.if !defined(WITH_VORBIS)
	@${ECHO_MSG} "You can enable VORBIS sound support by defining WITH_VORBIS."
.endif
.if !defined(WITH_XANIM)
	@${ECHO_MSG} "You can enable XAnim DLL support by defining WITH_XANIM."
.endif
.if !defined(WITH_LIVEMEDIA)
	@${ECHO_MSG} "You can enable liveMedia support by defining WITH_LIVEMEDIA."
.endif
.if !defined(WITH_XVID)
	@${ECHO_MSG} "You can enable XviD support by defining WITH_XVID."
.endif
.if !defined(WITH_FREETYPE)
	@${ECHO_MSG} "You can enable truetype font support by defining WITH_FREETYPE."
	@${ECHO_MSG} "    But use with caution. mplayer won't use the standard fonts anymore."
.endif
.if ${ARCH} == "i386"
.if !defined(WITHOUT_WIN32_CODECS)
	@${ECHO_MSG} "You can disable support (this turns this into a X86 only port)"
	@${ECHO_MSG} "for Win32 codecs by defining WITHOUT_WIN32_CODECS"
.if !defined(WITH_REALPLAYER)
	@${ECHO_MSG} \
		"You can enable RealPlayer DLL support by defining WITH_REALPLAYER."
.endif
.endif
.if defined(WITHOUT_RUNTIME_CPUDETECTION)
.if !defined(WITHOUT_SSE)
	@${ECHO_MSG} "You have to enable \"options CPU_ENABLE_SSE\" in your kernel"
	@${ECHO_MSG} "config in order to enable kernel support for SSE/MMX2."
.endif
.if !defined(WITHOUT_MMX)
	@${ECHO_MSG} "You can disable use of MMX routines by defining WITHOUT_MMX."
.endif
.if !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
	@${ECHO_MSG} "You can disable use of 3DNow! optimized routines by defining WITHOUT_3DNOW."
.endif
.if !defined(WITHOUT_3DNOW) && !defined(WITHOUT_DSP) && ${OSVERSION} >= 400021
	@${ECHO_MSG} "You can disable support for Athlon DSP extensions by defining WITHOUT_DSP."
.endif
	@${ECHO_MSG} "Note: The cpu features are autodetected, so there is probably no need"
	@${ECHO_MSG} "to manually disable them."
.else
	@${ECHO_MSG} "You can disable runtime cpu detection features by defining WITHOUT_RUNTIME_CPUDETECTION"
.endif
.endif # ARCH == i386

pre-configure:
.if defined(WITH_LIBDVDREAD)
	@${RM} -Rf ${WRKSRC}/libmpdvdkit2/
.endif

post-install:
	@${MKDIR} ${DATADIR}
	@${CHMOD} 755 ${DATADIR}
.for conf in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${conf} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CHMOD} 755 ${DOCSDIR}
.for doc in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/DOCS/${doc} ${DOCSDIR}
.endfor
.endif
.if defined(WITH_GUI)
	@${LN} -sf ${PREFIX}/bin/mplayer ${PREFIX}/bin/gmplayer
.endif
	@${CAT} ${.CURDIR}/pkg-message

install-user:
	@${PERL} ${FILESDIR}/install-user

.include <bsd.port.post.mk>
