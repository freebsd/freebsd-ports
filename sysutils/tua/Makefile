# New ports collection makefile for:	tua
# Version required:     4.0
# Date created:		11 Feb. 1995
# Whom:			torstenb
#
# $Id: Makefile,v 1.1.1.1 1995/02/15 23:51:22 torstenb Exp $
#

DISTNAME=       tua-4.0
MASTER_SITES=   ftp://itnsg1.cineca.it/local/tua/
CATEGORIES+=	utilities
GNU_CONFIGURE=	YES

pre-install:
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/man/man1
	mkdir -p ${PREFIX}/info
	mkdir -p ${PREFIX}/lib

.include <bsd.port.mk>
