# New ports collection makefile for:	rlytest
# Date created:		16 January 1999
# Whom:			Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	rlytest
PORTVERSION= 	1.20
CATEGORIES=	mail security
MASTER_SITES=	http://www.unicom.com/sw/rlytest/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=

MAINTAINER=	paul@it.ca

USE_PERL5=	yes
EXTRACT_ONLY=	# defined
NO_BUILD=

pre-patch:
	perl -pe 's,^#!/usr/local/bin/perl$$,#!/usr/bin/perl,' < ${_DISTDIR}${DISTFILES} > ${WRKDIR}/rlytest

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rlytest ${PREFIX}/bin/rlytest

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
