# ex:ts=8
# Ports collection makefile for:	bibcursed
# Date created:			Aug 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bibcursed
PORTVERSION=	2.0.0
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple curses-based editor for BibTeX bibliography files

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	Makefile.ncurses

MAN1=		bibcursed.1
PLIST_FILES=	bin/bibcursed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bibcursed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bibcursed.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
