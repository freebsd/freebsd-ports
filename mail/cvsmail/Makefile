# New ports collection makefile for:	cvsmail
# Date created:		23rd August, 2000
# Whom:			Ben Smithurst <ben@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsmail
PORTVERSION=	1.9
CATEGORIES=	mail
MASTER_SITES=	http://www.smithurst.org/ben/software/mail/dists/
DISTNAME=	mailutils-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	cvsmail
MANCOMPRESSED=	no
MAN1=		cvsmail.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsmail ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsmail.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
