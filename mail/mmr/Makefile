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
COMMENT=	Curses based MIME Mail Reader

ALL_TARGET=	# empty

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

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

.include <bsd.port.post.mk>
