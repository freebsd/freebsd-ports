# New ports collection makefile for:	tua
# Version required:     4.0
# Date created:		11 Feb. 1995
# Whom:			torstenb
#
# $Id: Makefile,v 1.3 1995/04/15 03:45:59 asami Exp $
#

DISTNAME=       tua-4.0
CATEGORIES+=	utilities
MASTER_SITES=   ftp://itnsg1.cineca.it/pub/local/tua/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

pre-install:
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/man/man1
	mkdir -p ${PREFIX}/info
	mkdir -p ${PREFIX}/lib

.include <bsd.port.mk>
