# New ports collection makefile for:	unpoost
# Version required:	2.3.4
# Date created:		14 october 1997
# Whom:			volf@oasis.IAEhv.nl
#
# $FreeBSD$
#

DISTNAME=	unpost-2.3.4
CATEGORIES=	news
MASTER_SITES=	http://www.freebsd.org/~steve/distfiles/

MAINTAINER=	volf@oasis.IAEhv.nl

MAKEFILE=	makefils/linux.mkf
MAN1=		unpost.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unpost ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/unpost.doc ${PREFIX}/man/man1/unpost.1

.include <bsd.port.mk>
