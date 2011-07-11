# New ports collection makefile for:	tmux
# Date created:				28 May 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tmux
PORTVERSION=	1.4
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Terminal Multiplexer

LICENSE=	BSD

HAS_CONFIGURE=	yes

MAN1=		tmux.1

PLIST_FILES=	bin/tmux

PORTDOCS=	CHANGES FAQ NOTES
PORTEXAMPLES=	*

OPTIONS=	KQUEUE   	"Build without define HAVE_BROKEN_KQUEUE " On \
		LIBEVENT2	"Use libevent version 2" Off \
		LIBEVENT_STATIC	"Build with static libevent" Off \
		BACKSPACE 	"Build with tty/keys patch" Off

# Now I set tmux build without #define HAVE_BROKEN_KQUEUE as default and an option,
# If it still hang the system or other run error, try as upstream suggest:
# http://sourceforge.net/mailarchive/forum.php?thread_name=20110125092121.GA15934%40yelena.nicm.ath.cx&forum_name=tmux-users

.include <bsd.port.pre.mk>

.if defined(WITH_LIBEVENT2)
EXTRA_CPPFLAGS+=	-I${LOCALBASE}/include/event2/compat -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/event2
.else
EXTRA_CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

MAKE_ENV+=	EXTRA_CPPFLAGS="${EXTRA_CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.if defined(WITH_LIBEVENT_STATIC)
. if defined(WITH_LIBEVENT2)
_LEVENT_LIB=	${LOCALBASE}/lib/event2/libevent.a
BUILD_DEPENDS+=	${_LEVENT_LIB}:${PORTSDIR}/devel/libevent2
. else
_LEVENT_LIB=	${LOCALBASE}/lib/libevent.a
BUILD_DEPENDS+=	${_LEVENT_LIB}:${PORTSDIR}/devel/libevent
. endif
.else
. if defined(WITH_LIBEVENT2)
_LEVENT_LIB=	-levent-2.0
LIB_DEPENDS=	event-2.0:${PORTSDIR}/devel/libevent2
. else
_LEVENT_LIB=	-levent-1.4
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent
. endif
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

.if defined(WITH_BACKSPACE)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-tty-keys.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/tmux.conf|${PREFIX}/etc/tmux.conf|g' \
		${WRKSRC}/tmux.1 ${WRKSRC}/tmux.h
	@${REINPLACE_CMD} -e 's|-I/usr/local/include||g' \
		-e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|$${CPPFLAGS}$$|${CPPFLAGS} ${EXTRA_CPPFLAGS}|g' \
		-e 's|LDFLAGS+=|#LDFLAGS+=|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-levent|${_LEVENT_LIB}|g' \
		${WRKSRC}/configure

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
