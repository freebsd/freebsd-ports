# ex:ts=8
# Ports collection makefile for:    vn7to8
# Date created:         Tue Dec 3, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#
#	version # is VISCII version supported + .<edit_revision>

DISTNAME=	vn7to8
PKGNAME=	vi-vn7to8-1.1.1
CATEGORIES=	vietnamese
MASTER_SITES=	ftp://ftp.media.mit.edu/pub/Vietnet/Viscii/Unix/  \
		ftp://ftp.monash.edu.au/pub/vietnam/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@FreeBSD.org

CFLAGS+=	-I../../include
MAN1=		vn7to8.1 vn8to7.1 vn80to81.1

post-install:
	@${INSTALL_MAN} ${FILESDIR}/vn7to8.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${FILESDIR}/vn80to81.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${FILESDIR}/vn8to7.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
