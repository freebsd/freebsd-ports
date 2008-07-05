# New ports collection makefile for:	tmux
# Date created:				28 May 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tmux
DISTVERSION=	0.4a
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Terminal Multiplexer

MAN1=		tmux.1

PLIST_FILES=	bin/tmux

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tmux ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tmux.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
