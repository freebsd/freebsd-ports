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
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	Makefile.ncurses

MAN1=	bibcursed.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bibcursed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bibcursed.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
