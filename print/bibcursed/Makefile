# ex:ts=8
# Ports collection makefile for:	bibcursed
# Date created:			Aug 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bibcursed
PORTVERSION=	2.0.1
CATEGORIES=	print
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple curses-based editor for BibTeX bibliography files

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME} -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
