# New ports collection makefile for:    figlet
# Version required:     2.1.1
# Date created:         Sat July 20, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id$
#

DISTNAME=	figlet2.1.1
PKGNAME=	figlet-2.1.1
CATEGORIES+=	misc
MASTER_SITES=	ftp://ftp.nicoh.com/pub/figlet/program/unix/  \
		ftp://ftp.wwa.com/pub/Scarecrow/Figlet/Unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@cs.ucdavis.edu

post-install:
.if !defined{NOMANCOMPRESS}
.for mp in figlet.6
	gzip -9nf ${PREFIX}/man/man6/${mp}
.endfor
.endif

.include <bsd.port.mk>
