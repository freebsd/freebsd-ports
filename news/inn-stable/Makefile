# New ports collection makefile for:	inn
# Version required:	1.4
# Date created:		20 Oct 1994
# Whom:			torstenb
#
# $Id:$
#

DISTNAME=	inn1.4sec
NO_WRKSUBDIR=	YES
MASTER_SITES=	ftp://ftp.uu.net/networking/news/nntp/inn/
EXTRACT_SUFX=	.tar.Z

pre-install:
	mkdir -p ${PREFIX}/etc
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/man
	mkdir -p ${PREFIX}/news

.include <bsd.port.mk>
