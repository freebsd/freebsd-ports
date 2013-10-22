# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	tmux
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Terminal Multiplexer

LICENSE=	BSD

GNU_CONFIGURE=	yes
USES=		pkgconfig shebangfix

SHEBANG_FILES=	examples/tmux_backup.sh

PLIST_FILES=	bin/tmux \
		man/man1/tmux.1.gz \
		etc/bash_completion.d/tmux
PLIST_DIRSTRY=	etc/bash_completion.d

PORTDOCS=	CHANGES FAQ README TODO
PORTEXAMPLES=	*

OPTIONS_DEFINE=	LIBEVENT2 LIBEVENT_STATIC BACKSPACE

LIBEVENT2_DESC=	Use libevent version 2
LIBEVENT_STATIC_DESC=	Build with static libevent
BACKSPACE_DESC=	Build with tty/keys patch

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBEVENT2}
CONFIGURE_ENV+=	LIBEVENT_CFLAGS="-I${LOCALBASE}/include/event2/compat" \
		LIBEVENT_LIBS="-L${LOCALBASE}/lib/event2 -levent"
. if ${PORT_OPTIONS:MLIBEVENT_STATIC}
BUILD_DEPENDS+=	${LOCALBASE}/lib/event2/libevent.a:${PORTSDIR}/devel/libevent2
LESTATIC=	${LOCALBASE}/lib/event2/libevent.a
. else
LIB_DEPENDS=	libevent-2.0.so:${PORTSDIR}/devel/libevent2
. endif
.else
CONFIGURE_ENV+=	LIBEVENT_CFLAGS="-I${LOCALBASE}/include" \
		LIBEVENT_LIBS="-L${LOCALBASE}/lib -levent"
. if ${PORT_OPTIONS:MLIBEVENT_STATIC}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent
LESTATIC=	${LOCALBASE}/lib/libevent.a
. else
LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent
. endif
.endif

.if ${PORT_OPTIONS:MBACKSPACE}
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-tty-keys.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/tmux.conf|${PREFIX}/etc/tmux.conf|g' \
		${WRKSRC}/tmux.1 ${WRKSRC}/tmux.h ${WRKSRC}/CHANGES
	@${REINPLACE_CMD} -e '/LIBS=/s/-lrt//' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
.if defined(WITH_LIBEVENT_STATIC)
	${REINPLACE_CMD} -e '/LIBS/s|-levent[^[:blank:]]*|${LESTATIC}|' \
		${WRKSRC}/${MAKEFILE}
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tmux ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/tmux.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${INSTALL_DATA} ${WRKSRC}/examples/bash_completion_tmux.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/tmux
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
