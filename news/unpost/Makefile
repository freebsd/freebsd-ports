# New ports collection makefile for:	unpoost
# Date created:		14 october 1997
# Whom:			volf@oasis.IAEhv.nl
#
# $FreeBSD$
#

PORTNAME=	unpost
PORTVERSION=	2.3.4
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	steve

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extract binary files from multi-segment uuencoded postings

MAKEFILE=	makefils/linux.mkf
MAN1=		unpost.1
PLIST_FILES=	bin/unpost

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unpost ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/unpost.doc ${PREFIX}/man/man1/unpost.1

.include <bsd.port.mk>
