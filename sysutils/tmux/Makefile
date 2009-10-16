# New ports collection makefile for:	tmux
# Date created:				28 May 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tmux
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Terminal Multiplexer

HAS_CONFIGURE=	yes

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
.for i in h-boetes.conf n-marriott.sh n-marriott.conf screen-keys.conf tmux.vim
	${INSTALL_DATA} ${WRKSRC}/examples/${i} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
