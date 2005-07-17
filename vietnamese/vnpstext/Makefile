# ex:ts=8
# Ports collection makefile for:    vnpstext
# Date created:         Sat Dec 7, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	vnpstext
PORTVERSION=	1.1
CATEGORIES=	vietnamese print
MASTER_SITES=	ftp://ftp.monash.edu.au/pub/vietnam/unix/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Converts 8-bit VISCII Vietnamese text into PostScript

CFLAGS+=	-I../../include
MAN1=		vnpstext.1

do-install:
	@${MKDIR} ${PREFIX}/share/vn-fonts
	${INSTALL_PROGRAM} ${WRKSRC}/vnpstext ${PREFIX}/bin
	(cd ${WRKSRC} ; \
	${INSTALL_DATA} *.ps prologs/*.pro ${PREFIX}/share/vn-fonts)
	${INSTALL_MAN} ${WRKSRC}/vnpstext.1V ${PREFIX}/man/man1/vnpstext.1

.include <bsd.port.mk>
