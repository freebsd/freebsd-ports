# New ports collection makefile for:	mplayer
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#			with lots of help from Vladimir Kushnir
# $FreeBSD$
#

PORTNAME=	mplayer
PORTVERSION=	0.18
CATEGORIES=	graphics
MASTER_SITES=	http://MPlayerHQ.hu/MPlayer/releases/ \
		http://www.stud.uni-karlsruhe.de/~uedc/mplayer/
DISTNAME=	MPlayer-${PORTVERSION}pre
EXTRACT_SUFX=	.tgz

MAINTAINER=	riggs@rrr.de

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/MPlayer-${PORTVERSION}pre5
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer

MAN1=		mplayer.1
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XLIB=	yes

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${PREFIX}/share/mplayer/fonts:${PORTSDIR}/graphics/mplayer-fonts

CONFIGURE_ARGS+=--disable-esd

.include <bsd.port.pre.mk>

.if defined(WITH_SDL)
LIB_DEPENDS+=    SDL-1.1.3:${PORTSDIR}/devel/sdl12
.else
BUILD_DEPENDS+=  nasm:${PORTSDIR}/devel/nasm
.endif
.if !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
CONFIGURE_ARGS+=--enable-3dnow
.endif
.if !defined(WITHOUT_3DNOWEX) && !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
CONFIGURE_ARGS+=--enable-3dnowex
.endif
.if !defined(WITHOUT_MMX2)
CONFIGURE_ARGS+=--enable-mmx2
.endif
.if defined(WITH_SSE)
CONFIGURE_ARGS+=--enable-sse
.endif
.if defined(USE_AVIFILE_CODECS)
BUILD_DEPENDS+=	${PREFIX}/lib/win32:${PORTSDIR}/graphics/win32-codecs
.else
BUILD_DEPENDS+=	${PREFIX}/lib/mplayer-codecs:${PORTSDIR}/graphics/mplayer-codecs
CONFIGURE_ARGS+=--with-win32libdir=${LOCALBASE}/lib/mplayer-codecs
.endif

pre-extract:

.if !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
	@${ECHO_MSG} "You can disable 3DNow! support by defining WITHOUT_3DNOW"
.endif

.if !defined(WITHOUT_3DNOWEX) && !defined(WITHOUT_3DNOW) && ${OSVERSION} >= 400021
	@${ECHO_MSG} "You can disable K7 3DNow! extension support by defining WITHOUT_3DNOWEX"
.endif
.if !defined(WITHOUT_MMX2)
	@${ECHO_MSG} "You can disable MMX2 support by defining WITHOUT_MMX2"
.endif
.if !defined(WITH_SSE)
	@${ECHO_MSG} "You can enable SSE optimized decoding by defining WITH_SSE"
	@${ECHO_MSG} "You have to enable \"options CPU_ENABLE_SSE\" in your kernel"
	@${ECHO_MSG} "config in order to enable kernel support for SSE."
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/mplayer
	@${CHMOD} 755 ${PREFIX}/share/mplayer
	@${INSTALL_DATA} ${WRKSRC}/DOCS/codecs.conf ${PREFIX}/share/mplayer
	@${INSTALL_DATA} ${WRKSRC}/DOCS/example.conf ${PREFIX}/share/mplayer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mplayer
	@${CHMOD} 755 ${PREFIX}/share/doc/mplayer
	@${INSTALL_DATA} ${WRKSRC}/DOCS/DGA ${PREFIX}/share/doc/mplayer
	@${INSTALL_DATA} ${WRKSRC}/DOCS/FREEBSD ${PREFIX}/share/doc/mplayer
	@${INSTALL_DATA} ${WRKSRC}/DOCS/MPlayer-FAQ ${PREFIX}/share/doc/mplayer
	@${INSTALL_DATA} ${WRKSRC}/DOCS/OpenDivX ${PREFIX}/share/doc/mplayer
	@${INSTALL_DATA} ${WRKSRC}/DOCS/README ${PREFIX}/share/doc/mplayer
	@${INSTALL_DATA} ${WRKSRC}/DOCS/SDL ${PREFIX}/share/doc/mplayer
	@${INSTALL_DATA} ${WRKSRC}/DOCS/VIDEOCARDS ${PREFIX}/share/doc/mplayer
.endif
	@${CAT} pkg-message

install-user:
	@${PERL} ${FILESDIR}/install-user

.include <bsd.port.post.mk>
