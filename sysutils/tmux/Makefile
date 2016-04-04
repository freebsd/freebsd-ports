# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	tmux
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/tmux/tmux/releases/download/${PORTVERSION}/ \
		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:S/a$//}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Terminal Multiplexer

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc

PLIST_FILES=	bin/tmux \
		man/man1/tmux.1.gz \
		etc/bash_completion.d/tmux

PORTDOCS=	CHANGES FAQ README TODO
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES LIBEVENT_STATIC BACKSPACE

LIBEVENT_STATIC_DESC=	Build with static libevent
BACKSPACE_DESC=	Build with tty/keys patch

BACKSPACE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-tty-keys.c

LIBEVENT_STATIC_LIB_DEPENDS_OFF=	libevent.so:devel/libevent2
LIBEVENT_STATIC_BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:devel/libevent2
LIBEVENT_STATIC_VARS=	LESTATIC=${LOCALBASE}/lib/libevent.a

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/tmux.conf|${PREFIX}/etc/tmux.conf|g' ${WRKSRC}/CHANGES \
		${WRKSRC}/tmux.h

post-configure-LIBEVENT_STATIC-on:
	${REINPLACE_CMD} -e '/LIBS/s|-levent[^[:blank:]]*|${LESTATIC}|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tmux ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tmux.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/examples/bash_completion_tmux.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/tmux

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
