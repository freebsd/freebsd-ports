# New ports collection makefile for:	tmux
# Date created:				28 May 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tmux
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Terminal Multiplexer

LICENSE=	BSD

HAS_CONFIGURE=	yes

MAN1=		tmux.1

PLIST_FILES=	bin/tmux

PORTDOCS=	CHANGES FAQ NOTES
PORTEXAMPLES=	*

OPTIONS=	LIBEVENT2	"Use libevent version 2" Off \
		LIBEVENT_STATIC	"Build with static libevent" Off \
		BACKSPACE 	"Build with tty/keys patch" Off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBEVENT2)
LIB_DEPENDS=	event-2.0:${PORTSDIR}/devel/libevent2
CPPFLAGS+=	-I${LOCALBASE}/include/event2/compat -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/event2
. if defined(WITH_LIBEVENT_STATIC)
LESTATIC=	${LOCALBASE}/lib/event2/libevent.a
. endif
.else
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
. if defined(WITH_LIBEVENT_STATIC)
LESTATIC=	${LOCALBASE}/lib/libevent.a
. endif
.endif

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

.if defined(WITH_BACKSPACE)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-tty-keys.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/tmux.conf|${PREFIX}/etc/tmux.conf|g' \
		${WRKSRC}/tmux.1 ${WRKSRC}/tmux.h ${WRKSRC}/CHANGES
	${REINPLACE_CMD} -e '/LIBS=/s/-lrt//' ${WRKSRC}/${CONFIGURE_SCRIPT}
.if defined(WITH_LIBEVENT_STATIC)
	${REINPLACE_CMD} -e '4534s|$$ac_res |${LESTATIC} |' ${WRKSRC}/${CONFIGURE_SCRIPT}
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
