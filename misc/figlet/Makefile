# New ports collection makefile for:    figlet
# Version required:     2.1.1
# Date created:         Sat July 20, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.1.1.1 1996/08/09 04:17:16 asami Exp $
#

DISTNAME=	figlet2.1.1
PKGNAME=	figlet-2.1.1
CATEGORIES+=	misc
MASTER_SITES=	ftp://ftp.nicoh.com/pub/figlet/program/unix/  \
		ftp://ftp.wwa.com/pub/Scarecrow/Figlet/Unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@cs.ucdavis.edu

post-install:
	${COMPRESS_MAN} ${PREFIX}/man/man6/figlet.6

.include <bsd.port.mk>
