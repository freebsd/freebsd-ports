# New ports collection makefile for:	tua
# Version required:     4.0
# Date created:		11 Feb. 1995
# Whom:			torstenb
#
# $Id: Makefile,v 1.2 1995/04/01 12:50:34 jkh Exp $
#

DISTNAME=       tua-4.0
CATEGORIES+=	utilities
MASTER_SITES=   ftp://itnsg1.cineca.it/local/tua/

GNU_CONFIGURE=	yes

pre-install:
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/man/man1
	mkdir -p ${PREFIX}/info
	mkdir -p ${PREFIX}/lib

.include <bsd.port.mk>
