# New ports collection makefile for:	inn
# Version required:	1.4
# Date created:		20 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.2 1995/04/01 12:49:08 jkh Exp $
#

DISTNAME=	inn1.4sec
PKGNAME=	inn-1.4
CATEGORIES+=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/nntp/inn/
EXTRACT_SUFX=	.tar.Z

NO_WRKSUBDIR=	YES

pre-install:
	mkdir -p ${PREFIX}/etc
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/man
	mkdir -p ${PREFIX}/news

.include <bsd.port.mk>
