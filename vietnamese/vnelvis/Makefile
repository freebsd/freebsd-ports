# ex:ts=8
# Ports collection makefile for:    vnelvis
# Version required: 0.0
# Date created:         Tue Dec 3, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

DISTNAME=	vnelvis
PKGNAME=	vi-vnelvis-1.4
CATEGORIES=	vietnamese editors
MASTER_SITES=	ftp://ftp.media.mit.edu/pub/Vietnet/Viscii/Unix/  \
		ftp://ftp.monash.edu.au/pub/vietnam/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@FreeBSD.org

CFLAGS+=	-I../../include
MAN1=		vnelvis.1 vnvi.1

post-extract:
	@ cd ${WRKSRC} ; make clean
	@ cd ${WRKSRC}/../lib ; make clean

post-install:
	${INSTALL_MAN} ${WRKSRC}/vnelvis.1V ${PREFIX}/man/man1/vnelvis.1
	${INSTALL_MAN} ${WRKSRC}/vnelvis.1V ${PREFIX}/man/man1/vnvi.1

.include <bsd.port.mk>
