# New ports collection makefile for:	relaydb
# Date created:				10 August 2003
# Whom:					Matt Jibson <dolmant@dolmant.net>
#
# $FreeBSD$
#

PORTNAME=	relaydb
PORTVERSION=	1.7
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	mike@tric.tomsk.gov.ru
COMMENT=	Spam relay database

MAN8=		relaydb.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/relaydb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/relaydb ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/relaydb.8.gz ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
