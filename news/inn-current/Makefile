# New ports collection makefile for:	inn
# Version required:	1.4
# Date created:		20 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.1.1.1 1994/10/23 01:42:20 torstenb Exp $
#

DISTNAME=	inn1.4sec
NO_WRKSUBDIR=	YES
MASTER_SITES=	ftp://ftp.uu.net/networking/news/nntp/inn/
CATEGORIES+=	news
EXTRACT_SUFX=	.tar.Z

pre-install:
	mkdir -p ${PREFIX}/etc
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/man
	mkdir -p ${PREFIX}/news

.include <bsd.port.mk>
