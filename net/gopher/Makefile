# New ports collection makefile for:	gopher
# Version required:	2.1.3
# Date created:		11 Dec 1994
# Whom:			ats
#
# $Id: Makefile,v 1.5 1995/04/24 07:53:09 asami Exp $
#

DISTNAME=	gopher2_1_3
PKGNAME=	gopher-2.1.3
CATEGORIES+=	net
MASTER_SITES=	ftp://boombox.micro.umn.edu/pub/gopher/Unix/
EXTRACT_SUFX=	.tar.Z

USE_GMAKE=	yes

pre-install:
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
