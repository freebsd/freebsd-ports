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
USE_GCC=	2.95

PORTDOCS=	BUGS CHANGES Features README TODO
PLIST_FILES=	bin/mmr ${EXAMPLESDIR:S,${PREFIX}/,,}/dot.mmrc.sample
PLIST_DIRS=	${EXAMPLESDIR:S,${PREFIX}/,,}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmr ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DOT-mmrc ${EXAMPLESDIR}/dot.mmrc.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
