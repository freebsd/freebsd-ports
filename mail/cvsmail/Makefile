# New ports collection makefile for:	cvsmail
# Date created:		23rd August, 2000
# Whom:			Ben Smithurst <ben@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsmail
PORTVERSION=	2.2
CATEGORIES=	mail
MASTER_SITES=	http://www.bensmithurst.com/software/mail/dists/
DISTNAME=	mailutils-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small program to add cvsweb links to FreeBSD commit messages

DEPRECATED=	Look like an abandonware, no more public distifles
EXPIRATION_DATE=	2011-08-01

ALL_TARGET=	cvsmail
MANCOMPRESSED=	no
MAN1=		cvsmail.1
PLIST_FILES=	bin/cvsmail

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsmail ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsmail.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
