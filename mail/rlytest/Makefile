# New ports collection makefile for:	rlytest
# Date created:		16 January 1999
# Whom:			Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	rlytest
PORTVERSION=	1.22
CATEGORIES=	mail security
MASTER_SITES=	http://www.unicom.com/sw/rlytest/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=	# defined

MAINTAINER=	paul+ports@it.ca
COMMENT=	Test remote system for unsecured mail relay

USE_PERL5=	yes

NO_WRKSUBDIR=	yes

MAN1=		rlytest.1
PLIST_FILES=	bin/rlytest

pre-patch:
	@${SED} '1s:^#!/usr/local/bin/perl:#!${PERL}:' < ${_DISTDIR}${DISTFILES} > ${WRKSRC}/rlytest

do-build:
	@pod2man ${WRKSRC}/rlytest > ${WRKSRC}/rlytest.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/rlytest ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/rlytest.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
