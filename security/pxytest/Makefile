# New ports collection makefile for:	pxytest
# Date created:				Fri Jun 13 05:57:43 EDT 2003
# Whom:					Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	pxytest
PORTVERSION=	1.36
CATEGORIES=	security
MASTER_SITES=	http://www.unicom.com/sw/pxytest/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=	# defined

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Test remote system for unsecured mail proxies

USE_PERL5=	yes

NO_WRKSUBDIR=	yes

MAN1=		pxytest.1
PLIST_FILES=	bin/pxytest

pre-patch:
	@${SED} '1s:^#!/usr/bin/perl:#!${PERL}:' < ${_DISTDIR}${DISTFILES} > ${WRKSRC}/pxytest

do-build:
	@pod2man ${WRKSRC}/pxytest > ${WRKSRC}/pxytest.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/pxytest ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/pxytest.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
