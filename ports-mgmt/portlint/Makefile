# New ports collection makefile for:	portlint
# Version required:     (self contained)
# Date created:		13 Jun 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.20 1998/06/27 05:18:50 asami Exp $
#

DISTNAME=       portlint-2.0
CATEGORIES=	devel

MAINTAINER=	itojun@itojun.org

NO_WRKDIR=	yes
NO_EXTRACT=	yes
NO_BUILD=	yes

SRCDIR=		${.CURDIR}/src

MAN1=		portlint.1

do-fetch:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portlint.pl ${PREFIX}/bin/portlint
	${INSTALL_MAN} ${WRKSRC}/portlint.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
