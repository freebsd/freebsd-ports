# New ports collection makefile for:	tmux
# Date created:				28 May 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tmux
DISTVERSION=	0.8
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Terminal Multiplexer

MAN1=		tmux.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tmux ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tmux.1 ${MANPREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in CHANGES FAQ NOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for i in n-marriott.sh n-marriott.conf screen-keys.conf tmux.vim
	${INSTALL_DATA} ${WRKSRC}/examples/${i} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
