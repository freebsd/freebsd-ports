# ex:ts=8
# New ports collection makefile for:    vnelvis
# Version required:     1.4
# Date created:         Tue Dec 3, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.1.1.1 1996/12/06 12:37:38 obrien Exp $
#

DISTNAME=	vnelvis
PKGNAME=	vn-vnelvis-1.4
CATEGORIES=	vietnamese
MASTER_SITES=	ftp://ftp.media.mit.edu/pub/Vietnet/Viscii/Unix/  \
		ftp://ftp.monash.edu.au/pub/vietnam/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@cs.ucdavis.edu

CFLAGS+=	-I../../include
MAN1=		vnelvis.1 vnvi.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/vnelvis.1V ${PREFIX}/man/man1/vnelvis.1
	${INSTALL_MAN} ${WRKSRC}/vnelvis.1V ${PREFIX}/man/man1/vnvi.1

.include <bsd.port.mk>
