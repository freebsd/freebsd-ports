# New ports collection makefile for:	tua
# Version required:     4.0
# Date created:		11 Feb. 1995
# Whom:			torstenb
#
# $Id: Makefile,v 1.5 1995/04/23 13:02:47 asami Exp $
#

DISTNAME=       tua-4.0
CATEGORIES+=	utilities
MASTER_SITES=   ftp://itnsg1.cineca.it/pub/local/tua/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	gzip -9nf ${PREFIX}/man/man1/tua.1

.include <bsd.port.mk>
