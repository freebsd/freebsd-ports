# ex:ts=8
# New ports collection makefile for:    vnpstext
# Version required:     1.1
# Date created:         Sat Dec 7, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

DISTNAME=	vnpstext
PKGNAME=	vi-vnpstext-1.1
CATEGORIES=	vietnamese print
MASTER_SITES=	ftp://ftp.media.mit.edu/pub/Vietnet/Viscii/Unix/  \
		ftp://ftp.monash.edu.au/pub/vietnam/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@FreeBSD.org

CFLAGS+=	-I../../include
MAN1=		vnpstext.1

do-install:
	@${MKDIR} ${PREFIX}/share/vn-fonts
	${INSTALL_PROGRAM} ${WRKSRC}/vnpstext ${PREFIX}/bin
	(cd ${WRKSRC} ; \
	${INSTALL_DATA} *.ps prologs/*.pro ${PREFIX}/share/vn-fonts)
	${INSTALL_MAN} ${WRKSRC}/vnpstext.1V ${PREFIX}/man/man1/vnpstext.1

.include <bsd.port.mk>
