# New ports collection makefile for:	gopher
# Version required:	2.1
# Date created:		11 Dec 1994
# Whom:			ats
#
# $Id: Makefile,v 1.2 1995/04/01 12:48:01 jkh Exp $
#

DISTNAME=	gopher2.1
PKGNAME=	gopher-2.1
CATEGORIES+=	networking
MASTER_SITES=	ftp://boombox.micro.umn.edu/pub/gopher/Unix/
EXTRACT_SUFX=	.tar.Z

NCFTPFLAGS?=	-P -N
USE_GMAKE=	yes

pre-install:
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
