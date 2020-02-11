# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	tmux
PORTVERSION=	3.0a
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/tmux/tmux/releases/download/${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Terminal Multiplexer

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses pkgconfig

USE_GITHUB=	nodefault
GH_TUPLE=	imomaliev:tmux-bash-completion:ef56d3e:bash

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-utempter \
		--sysconfdir=${PREFIX}/etc

CONFLICTS_INSTALL=	tmux23

PLIST_FILES=	bin/tmux \
		etc/bash_completion.d/tmux \
		man/man1/tmux.1.gz

PORTDOCS=	CHANGES README
PORTEXAMPLES=	*

OPTIONS_DEFINE=	BACKSPACE DOCS EXAMPLES LIBEVENT_STATIC UTF8PROC

BACKSPACE_DESC=		Build with tty/keys patch
LIBEVENT_STATIC_DESC=	Build with static libevent
UTF8PROC_DESC=		Build with utf8proc support

BACKSPACE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-tty-keys.c

LIBEVENT_STATIC_BUILD_DEPENDS=		${LOCALBASE}/lib/libevent.a:devel/libevent
LIBEVENT_STATIC_LIB_DEPENDS_OFF=	libevent.so:devel/libevent
LIBEVENT_STATIC_VARS=			LESTATIC=${LOCALBASE}/lib/libevent.a

UTF8PROC_CONFIGURE_ENABLE=	utf8proc
UTF8PROC_LIB_DEPENDS=		libutf8proc.so:textproc/utf8proc

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/tmux.conf|${PREFIX}/etc/tmux.conf|g' ${WRKSRC}/CHANGES \
		${WRKSRC}/tmux.h

post-configure-LIBEVENT_STATIC-on:
	${REINPLACE_CMD} -e '/LIBS/s|-levent[^[:blank:]]*|${LESTATIC}|' \
		${WRKSRC}/${MAKEFILE}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC_bash}/completions/tmux ${STAGEDIR}${PREFIX}/etc/bash_completion.d/tmux

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
