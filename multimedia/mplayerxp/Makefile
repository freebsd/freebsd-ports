# New ports collection makefile for:	mplayer
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#			with lots of help from Vladimir Kushnir
# $FreeBSD$
#

PORTNAME=	mplayer
PORTVERSION=	0.50.0.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.mplayerhq.hu/MPlayer/releases/ \
		http://www.stud.uni-karlsruhe.de/~uedc/mplayer/ \
		http://www.rrr.de/~riggs/mplayer/
DISTNAME=	MPlayer-0.50

MAINTAINER=	riggs@rrr.de

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		SDL-1.1.3:${PORTSDIR}/devel/sdl12
RUN_DEPENDS=	${LOCALBASE}/share/mplayer/fonts:${PORTSDIR}/graphics/mplayer-fonts

NO_PACKAGE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-esd

MAN1=		mplayer.1
MANCOMPRESSED=	no

CONFFILES=	codecs.conf example.conf
DOCFILES=       DVB bugreports.html cd-dvd.html codecs-in.html \
		codecs.html documentation.html faq.html skin-en.html \
		sound.html video.html tech/tech-eng.txt

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=       -O3 -ffast-math -fomit-frame-pointer
.endif

.if defined(WITH_GUI)
USE_GTK=	yes
CONFIGURE_ARGS+=	--enable-gui
.endif

.if defined(WITH_DVD)
LIB_DEPENDS+=	dvdcss.0:${PORTSDIR}/graphics/libdvdcss \
		dvdread.2:${PORTSDIR}/graphics/libdvdread
.endif

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.1:${PORTSDIR}/audio/libvorbis
.endif

# "enable" build for other archs
.if ${ARCH} == "i386"
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
.if !defined(WITH_SVGALIB)
CONFIGURE_ARGS+=--disable-svga
.endif
.if !defined(WITH_VORBIS)
CONFIGURE_ARGS+=--disable-vorbis
.endif
.if !defined(WITHOUT_WIN32_CODECS)
RUN_DEPENDS+=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CONFIGURE_ARGS+=	--with-win32libdir=${LOCALBASE}/lib/win32

CODEC_PORT=	${PORTSDIR}/graphics/win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
.endif
.endif # ARCH == i386

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif
.if !defined(WITH_GUI)
	@${ECHO_MSG} "You can enable GTK GUI by defining WITH_GUI."
.endif
.if !defined(WITH_DVD)
	@${ECHO_MSG} "You can enable DVD support by defining WITH_DVD."
.endif
.if !defined(WITH_SVGALIB)
	@${ECHO_MSG} "You can enable SVGALIB support by defining WITH_SVGALIB."
.endif
.if !defined(WITH_VORBIS)
	@${ECHO_MSG} "You can enable VORBIS sound support by defining WITH_VORBIS."
.endif
.if ${ARCH} == "i386"
.if !defined(WITHOUT_WIN32_CODECS)
	@${ECHO_MSG} "You can disable support (this turns this into a X86 only port)"
	@${ECHO_MSG} "for Win32 codecs"
.endif
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
.endif # ARCH == i386

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
	@${CAT} pkg-message

install-user:
	@${PERL} ${FILESDIR}/install-user

.include <bsd.port.post.mk>
