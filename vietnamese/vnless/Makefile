# ex:ts=8
# New ports collection makefile for:    vnless
# Version required:     1.0
# Date created:         Tue Dec 3, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.1.1.1 1996/08/09 04:17:16 asami Exp $
#

DISTNAME=	vnless
PKGNAME=	vn-vnless-1.0
CATEGORIES=	vietnamese
MASTER_SITES=	ftp://ftp.media.mit.edu/pub/Vietnet/Viscii/Unix/  \
		ftp://ftp.monash.edu.au/pub/vietnam/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@cs.ucdavis.edu

ALL_TARGET=	clobber all
MAN1=		vnless.1 vnlesskey.1

post-install:
	@strip ${PREFIX}/bin/vnless*
	@chmod a+rx ${PREFIX}/bin/vnless*
	@chmod a+r ${PREFIX}/share/misc/vnless.help
	@chmod a+r ${PREFIX}/man/man1/vnless*.1*

.include <bsd.port.mk>
