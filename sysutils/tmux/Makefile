# New ports collection makefile for:	tmux
# Date created:				28 May 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tmux
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Terminal Multiplexer

HAS_CONFIGURE=	yes

MAN1=		tmux.1

PLIST_FILES=	bin/tmux

PORTDOCS=	CHANGES FAQ NOTES
PORTEXAMPLES=	*

CFLAGS+=	-I${LOCALBASE}/include
#LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

OPTIONS=		KQUEUE   "Build without define HAVE_BROKEN_KQUEUE " On \
			LIBEVENT_STATIC	"Build with static libevent" Off

# Now I set tmux build without #define HAVE_BROKEN_KQUEUE as default and an option,
# If it still hang the system or other run error, try as upstream suggest:
# http://sourceforge.net/mailarchive/forum.php?thread_name=20110125092121.GA15934%40yelena.nicm.ath.cx&forum_name=tmux-users

.include <bsd.port.pre.mk>

.if defined(WITH_LIBEVENT_STATIC)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent
.else
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent
.endif

.if !defined(WITHOUT_KQUEUE)
.if ${OSVERSION} < 702104
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-kqueue_and_fb7
.else
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-kqueue
.endif
.else
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-fb7
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/Makefile
.if defined(WITH_LIBEVENT_STATIC)
	@${REINPLACE_CMD} -e 's|-levent|${LOCALBASE}/lib/libevent.a|g' \
		${WRKSRC}/configure
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tmux ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/tmux.1 ${MANPREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
