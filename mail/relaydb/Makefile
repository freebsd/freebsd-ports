# New ports collection makefile for:	relaydb
# Date created:				10 August 2003
# Whom:					Matt Jibson <dolmant@dolmant.net>
#
# $FreeBSD$
#

PORTNAME=	relaydb
PORTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spam relay database

MAN8=		relaydb.8
MANCOMPRESSED=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/relaydb ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/relaydb.8.gz ${PREFIX}/man/man8

.include <bsd.port.mk>
