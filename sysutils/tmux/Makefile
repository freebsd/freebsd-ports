# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	tmux
DISTVERSION=	1.9a
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Terminal Multiplexer

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USES=		pkgconfig shebangfix

SHEBANG_FILES=	examples/tmux_backup.sh

PLIST_FILES=	bin/tmux \
		man/man1/tmux.1.gz \
		etc/bash_completion.d/tmux
PLIST_DIRSTRY=	etc/bash_completion.d

PORTDOCS=	CHANGES FAQ README TODO
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES LIBEVENT2 LIBEVENT_STATIC BACKSPACE

LIBEVENT2_DESC=	Use libevent version 2
LIBEVENT_STATIC_DESC=	Build with static libevent
BACKSPACE_DESC=	Build with tty/keys patch

CFLAGS+=	-Wno-pointer-sign

BACKSPACE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-tty-keys.c
LIBEVENT2_CONFIGURE_ENV=	LIBEVENT_CFLAGS="-I${LOCALBASE}/include/event2/compat" \
				LIBEVENT_LIBS="-L${LOCALBASE}/lib/event2 -levent"
LIBEVENT2_CONFIGURE_ENV_OFF=	LIBEVENT_CFLAGS="-I${LOCALBASE}/include" \
				LIBEVENT_LIBS="-L${LOCALBASE}/lib -levent"
LIBEVENT2_LIB_DEPENDS=		libevent-2.0.so:${PORTSDIR}/devel/libevent2
LIBEVENT2_LIB_DEPENDS_OFF=	libevent-1.4.so:${PORTSDIR}/devel/libevent

PORTSCOUT=	ignore:1.9	# 1.9a was released as an errata to 1.9;
				# this port was never updated to 1.9.

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/tmux.conf|${PREFIX}/etc/tmux.conf|g' \
		${WRKSRC}/tmux.1 ${WRKSRC}/tmux.h ${WRKSRC}/CHANGES
	@${REINPLACE_CMD} -e '/LIBS=/s/-lrt//' ${WRKSRC}/${CONFIGURE_SCRIPT}

.if ${PORT_OPTIONS:MLIBEVENT_STATIC}
.if ${PORT_OPTIONS:MLIBEVENT2}
LESTATIC=	${LOCALBASE}/lib/event2/libevent.a
.else
LESTATIC=	${LOCALBASE}/lib/libevent.a
.endif
post-configure:
	${REINPLACE_CMD} -e '/LIBS/s|-levent[^[:blank:]]*|${LESTATIC}|' \
		${WRKSRC}/${MAKEFILE}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tmux ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tmux.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/examples/bash_completion_tmux.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/tmux
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
