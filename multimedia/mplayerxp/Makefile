# New ports collection makefile for:	mplayer
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#			with lots of help from Vladimir Kushnir
# $FreeBSD$
#

PORTNAME=	mplayer
PORTVERSION=	0.50.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.mplayerhq.hu/MPlayer/releases/ \
		http://www.stud.uni-karlsruhe.de/~uedc/mplayer/ \
		http://www.rrr.de/~riggs/mplayer/
DISTNAME=	MPlayer-0.50pre1

MAINTAINER=	riggs@rrr.de

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		SDL-1.1.3:${PORTSDIR}/devel/sdl12
RUN_DEPENDS=	${LOCALBASE}/share/mplayer/fonts:${PORTSDIR}/graphics/mplayer-fonts

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-esd
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN1=		mplayer.1
MANCOMPRESSED=	no

CONFFILES=	codecs.conf example.conf
DOCFILES=       DVB bugreports.html cd-dvd.html codecs-in.html \
		codecs.html documentation.html faq.html skin-en.html \
		sound.html video.html tech/tech-eng.txt

.include <bsd.port.pre.mk>

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

# hack to cope with dmesg standard vs ports standard
.if (WITH_3DNow!)
WITH_3DNOW=	yes
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=       -O3 -ffast-math -fomit-frame-pointer
.endif

.if defined(WITH_GUI)
USE_GTK=	yes
CONFIGURE_ARGS+=	--enable-gui
.endif

# "enable" build for other archs
.if ${ARCH} == "i386"
.if defined(WITH_MMX)
CONFIGURE_ARGS+=--enable-mmx
.endif
.if defined(WITH_3DNOW) && ${OSVERSION} >= 400021
CONFIGURE_ARGS+=--enable-3dnow
.endif
.if defined(WITH_DSP) && defined(WITH_3DNOW) && ${OSVERSION} >= 400021
CONFIGURE_ARGS+=--enable-3dnowex
.endif
.if defined(WITH_SSE)
CONFIGURE_ARGS+=--enable-mmx2 --enable-sse
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
	@${ECHO} "You can enable GTK GUI by defining WITH_GUI."
.endif
.if ${ARCH} == "i386"
.if !defined(WITHOUT_WIN32_CODECS)
	@${ECHO_MSG} "You can disable support (this turns this into a X86 only port)"
	@${ECHO_MSG} "for Win32 codecs"
.endif
.if defined(WITH_SSE)
	@${ECHO_MSG} "You have to enable \"options CPU_ENABLE_SSE\" in your kernel"
	@${ECHO_MSG} "config in order to enable kernel support for SSE/MMX2."
.endif
.endif # ARCH == i386

pre-configure:
	@${RM} -f "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
	@${MKDIR} "${WRKDIRPREFIX}${.CURDIR}"
	@${SETENV} TEMPDIR="${WRKDIRPREFIX}${.CURDIR}" ${PERL} ${FILESDIR}/get-feat

post-configure:
	@${RM} -f "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"

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
