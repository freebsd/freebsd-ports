# New ports collection makefile for:	scanssh
# Date created:		09 September 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	scanssh
PORTVERSION=	1.60b
CATEGORIES=	security net
MASTER_SITES=	http://www.monkey.org/~provos/
DISTNAME=	${PORTNAME}-1.6b

MAINTAINER=	kris@FreeBSD.org

GNU_CONFIGURE=	YES

MAN1=		scanssh.1
WRKSRC=		${WRKDIR}/scanssh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scanssh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scanssh.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/scanssh/
	${TOUCH} ${PREFIX}/share/scanssh/exclude.list

.include <bsd.port.mk>
