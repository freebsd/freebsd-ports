# New ports collection makefile for:	mmr
# Date created:				23 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	mmr
PORTVERSION=	1.5.5
CATEGORIES=	mail
MASTER_SITES=	http://www.devolution.com/~slouken/projects/mmr/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Curses based MIME Mail Reader

ALL_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmr ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/mmr
	${INSTALL_DATA} ${WRKSRC}/DOT-mmrc ${PREFIX}/share/examples/mmr/dot.mmrc.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mmr
.for file in BUGS CHANGES Features README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/mmr
.endfor
.endif

.include <bsd.port.mk>
